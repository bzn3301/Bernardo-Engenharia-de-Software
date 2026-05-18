#include "system.h"

#include <utility>

System::System(std::string name, double value)
    : name(std::move(name)), value(value)
{
}

System::System(const System& other)
    : name(other.name), value(other.value)
{
}

System& System::operator=(const System& other)
{
    if (this != &other) {
        name = other.name;
        value = other.value;
    }

    return *this;
}

System::~System()
{
}

const std::string& System::getName() const
{
    return name;
}

void System::setName(const std::string& name)
{
    this->name = name;
}

double System::getValue() const
{
    return value;
}

void System::setValue(double value)
{
    this->value = value;
}
