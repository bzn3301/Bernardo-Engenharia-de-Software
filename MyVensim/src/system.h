#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
private:
    //Atributos
    std::string name;
    double value;

public:
    //Construtor vazio
    System();      
    //Construtor normal                                 
    System(const std::string& name, double value); 
    //Destrutor
    virtual ~System();      
    //Construtor de copiar                        
    System(const System& other);  
    //Sobrecarga                  
    System& operator=(const System& other);         

    //Get e set dos atributos
    std::string getName() const;
    double getValue() const;
    void setValue(double value);
    void setName(std::string name);
};

#endif