#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include "../../src/flow.h"
#include "../../src/system.h"

//Assinatura das funcoes
void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

//Herança, exponencial herdando de flow
class ExponencialFlow : public Flow {
public:
    //Herdando os construtores de forma canonica do flow
    using Flow::Flow;

    //Sobreescrita do metodo executa
    double execute() const override {
        //Pego a origem se for diferente de nulo
        if (getSource() != nullptr) {
            //Pego o valor atual e multiplico do 0.01
            return 0.01 * getSource()->getValue();
        }
        return 0.0;
    }
};

//Herança, logistica herdando de flow
class LogisticaFlow : public Flow {
public:
    //Herdando os construtores de forma canonica do flow
    using Flow::Flow;

    //Sobreescrita do metodo executa
    double execute() const override {
        //Pego a origem se ela nao for nula
        if (getTarget() != nullptr) {
            //Pego o valor atual
            double p2 = getTarget()->getValue();
            //Faço as contas pedidas pelo cliente
            return 0.01 * p2 * (1.0 - (p2 / 70.0));
        }
        return 0.0;
    }
};

class FlowComplex : public Flow {
public:
    //Herdando os construtores de forma canonica do flow
    using Flow::Flow;

    //Sobrescrita do metodo executa
    double execute() const override {
        if (getSource() != nullptr) {
            return 0.01 * getSource()->getValue(); // Equação base do fluxo complexo
        }
        return 0.0;
    }
};

#endif