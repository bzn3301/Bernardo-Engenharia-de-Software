#include "flow.h"

// Construtor padrão em que inicializa tudo "vazio"
Flow::Flow() : name(""), source(nullptr), target(nullptr) {}

// Construtor apenas com o nome
Flow::Flow(std::string name) : name(name), source(nullptr), target(nullptr) {}

// Construtor de quando um fluxo vai copiar o outro
Flow::Flow(const Flow &fl) {
    this->name = fl.name;
    this->source = fl.source; 
    this->target = fl.target;
}

// Destrutor
//Como nada é criado nele, fica vazio
Flow::~Flow() {}

// Sobrecarga do operador igual, para permitir recebimento direto
Flow &Flow::operator=(const Flow &fl) {
    //Se o objeto for o mesmo que o atual, so retorna ele mesmo
    if (this == &fl) {
        return *this;
    }
    //Se for diferente, faço a atribuição
    this->name = fl.name;
    this->source = fl.source;
    this->target = fl.target;
    return *this;
}

//Get e set de origem, destino e nome
void Flow::setSource(System *s) {
    source = s;
}

void Flow::setTarget(System *t) {
    target = t;
}

void Flow::setName(std::string n) {
    name = n;
}

System *Flow::getSource() const {
    return source;
}

System *Flow::getTarget() const {
    return target;
}

std::string Flow::getName() const {
    return name;
}