#include "model.h"

//Construtor vazio
Model::Model() : name("") {}

//Construtor com nome
Model::Model(std::string name) : name(name) {}

// Construtor de quando um modelo vai copiar o outro
Model::Model(const Model& mod) {
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
}

// Destrutor vazio
Model::~Model() {}

//Sobre carga do operador
Model& Model::operator=(const Model& mod) {
    if (this == &mod) {
        return *this;
    }
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
    return *this;
}

// Get e set de nome
std::string Model::getName() const { 
    return name; 
}

void Model::setName(std::string n) { 
    name = n; 
}

//Metodo para adicionar sistema ao vetor de sistemas
void Model::add(System* s) {
    systems.push_back(s);
}

//Metodo para adicionar fluxos do vetor de fluxos
void Model::add(Flow* f) {
    flows.push_back(f);
}

//Função run assincrona
void Model::run(int t_initial, int t_end) {
    //Enquanto o tempo nao acabar
    for (int tempo = t_initial; tempo < t_end; ++tempo) {
        //Crio um vetor de resultados
        std::vector<double> results;
        
        //Executo os fluxos e coloco o resultado no vetor de resultados
        for (size_t i = 0; i < flows.size(); ++i) {
            results.push_back(flows[i]->execute());
        }
        
        //Pego os sistemas de origem e destino dos fluxos
        for (size_t i = 0; i < flows.size(); ++i) {
            System* origem = flows[i]->getSource();
            System* destino = flows[i]->getTarget();
            //Se não forem nulos, atualizo os valores ao mesmo tempo para não ter inconsistência
            if (origem != nullptr) {
                origem->setValue(origem->getValue() - results[i]);
            }
            if (destino != nullptr) {
                destino->setValue(destino->getValue() + results[i]);
            }
        }
    }
}