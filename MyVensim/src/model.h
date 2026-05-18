#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "flow.h"
#include "system.h"

class Model {
public:
    explicit Model(std::string name = "");
    Model(const Model& other);
    Model& operator=(const Model& other);
    virtual ~Model();

    const std::string& getName() const;
    void setName(const std::string& name);

    System& createSystem(const std::string& name, double value);

    template <typename FlowType, typename... Args>
    FlowType& createFlow(Args&&... args)
    {
        auto flow = std::make_unique<FlowType>(std::forward<Args>(args)...);
        FlowType& reference = *flow;
        flows.push_back(std::move(flow));
        return reference;
    }

    const std::vector<std::unique_ptr<System>>& getSystems() const;
    const std::vector<std::unique_ptr<Flow>>& getFlows() const;

    void run(int startTime, int endTime);

private:
    std::string name;
    std::vector<std::unique_ptr<System>> systems;
    std::vector<std::unique_ptr<Flow>> flows;
};

#endif
