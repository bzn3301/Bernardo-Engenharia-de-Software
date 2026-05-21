#include "system.h"

//Construtor vazio
System::System() : name(""), value(0.0) {}

// Construtor normal
System::System(const std::string& name, double value) {
    this->name = name;
    this->value = value;
}

// Destrutor
System::~System() {}

// Construtor de copia
System::System(const System& other) {
    this->name = other.name;
    this->value = other.value;
}

//Sobrecarga do operador
System& System::operator=(const System& other) {
    if (this == &other) { 
        return *this;
    }
    this->name = other.name;
    this->value = other.value;
    return *this;
}

// Get e set dos atributos
std::string System::getName() const {
    return name;
}

double System::getValue() const {
    return value;
}

void System::setValue(double v) {
    this->value = v;
}

void System::setName(std::string n) {
    this->name = n;
}