#include "flow.h"

#include <utility>

Flow::Flow(std::string name, System* source, System* target)
    : name(std::move(name)), source(source), target(target)
{
}

Flow::Flow(const Flow& other)
    : name(other.name), source(other.source), target(other.target)
{
}

Flow& Flow::operator=(const Flow& other)
{
    if (this != &other) {
        name = other.name;
        source = other.source;
        target = other.target;
    }

    return *this;
}

Flow::~Flow()
{
}

const std::string& Flow::getName() const
{
    return name;
}

void Flow::setName(const std::string& name)
{
    this->name = name;
}

System* Flow::getSource() const
{
    return source;
}

void Flow::setSource(System* source)
{
    this->source = source;
}

System* Flow::getTarget() const
{
    return target;
}

void Flow::setTarget(System* target)
{
    this->target = target;
}

double Flow::execute() const
{
    return 0.0;
}

Flow* Flow::clone() const
{
    return new Flow(*this);
}
