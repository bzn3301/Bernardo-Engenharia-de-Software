#include "model.h"

#include <unordered_map>
#include <utility>

static System* copySystemReference(
    System* system,
    const std::unordered_map<const System*, System*>& copiedSystems)
{
    auto it = copiedSystems.find(system);

    if (it != copiedSystems.end()) {
        return it->second;
    }

    return system;
}

Model::Model(std::string name)
    : name(std::move(name))
{
}

Model::Model(const Model& other)
{
    *this = other;
}

Model& Model::operator=(const Model& other)
{
    if (this == &other) {
        return *this;
    }

    name = other.name;
    systems.clear();
    flows.clear();

    std::unordered_map<const System*, System*> copiedSystems;

    for (const auto& system : other.systems) {
        systems.push_back(std::make_unique<System>(*system));
        copiedSystems[system.get()] = systems.back().get();
    }

    for (const auto& flow : other.flows) {
        std::unique_ptr<Flow> copiedFlow(flow->clone());

        copiedFlow->setSource(copySystemReference(flow->getSource(), copiedSystems));
        copiedFlow->setTarget(copySystemReference(flow->getTarget(), copiedSystems));

        flows.push_back(std::move(copiedFlow));
    }

    return *this;
}

Model::~Model()
{
}

const std::string& Model::getName() const
{
    return name;
}

void Model::setName(const std::string& name)
{
    this->name = name;
}

System& Model::createSystem(const std::string& name, double value)
{
    systems.push_back(std::make_unique<System>(name, value));
    return *systems.back();
}

const std::vector<std::unique_ptr<System>>& Model::getSystems() const
{
    return systems;
}

const std::vector<std::unique_ptr<Flow>>& Model::getFlows() const
{
    return flows;
}

void Model::run(int startTime, int endTime)
{
    for (int time = startTime; time < endTime; ++time) {
        std::vector<double> values;
        values.reserve(flows.size());

        for (const auto& flow : flows) {
            values.push_back(flow->execute());
        }

        for (std::size_t i = 0; i < flows.size(); ++i) {
            Flow* flow = flows[i].get();
            const double value = values[i];

            if (flow->getSource() != nullptr) {
                System* source = flow->getSource();
                source->setValue(source->getValue() - value);
            }

            if (flow->getTarget() != nullptr) {
                System* target = flow->getTarget();
                target->setValue(target->getValue() + value);
            }
        }
    }
}
