#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow {
protected:
    //Atributos
    std::string name;
    System *source;
    System *target;

public:
    //Construtor vazio
    Flow();
    //Construtor de cópia
    Flow(const Flow &fl); 
    // Construtor com nome
    Flow(std::string name);
    //Destrutor                
    virtual ~Flow();  
    //Sobrecarga                    
    Flow &operator=(const Flow &fl);  

    //Get e set de origem, destino e nome
    void setSource(System *s);
    void setTarget(System *t);
    System *getSource() const;
    System *getTarget() const;
    std::string getName() const;
    void setName(std::string name);

    //Metodo virtual puro para que as subclasses façam
    virtual double execute() const = 0;
};

#endif