#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "system.h"
#include "flow.h"

class Model {
private:
    //Atributos
    std::string name;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    //Construtor vazio
    Model();                 
    //Construtor de copia         
    Model(const Model& mod); 
    // Construtor com nome
    Model(std::string name); 
    //Destrutor       
    virtual ~Model();       
    //Sobrecarga           
    Model& operator=(const Model& mod); 

    // Métodos de adicionar sistemas e flow no modelo
    void add(System* s);
    void add(Flow* f);

    //Metodo para simulação
    void run(int t_initial, int t_end);

    //Get e set de nome
    std::string getName() const;
    void setName(std::string name);
};

#endif