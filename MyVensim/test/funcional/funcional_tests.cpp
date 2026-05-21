#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"

//Metodo do teste funcional do exponencial
void exponentialFuncionalTest() {
    std::cout << "Executando Teste Exponencial..." << std::endl;

    //Crio o modelo
    Model* mod = new Model("Modelo Exponencial");
    //Crio os sistemas
    System* pop1 = new System("pop1", 100.0);
    System* pop2 = new System("pop2", 0.0);
    //Crio o fluxo
    ExponencialFlow* exp = new ExponencialFlow("Fluxo Exponencial");

    //Defino o destino e origem
    exp->setSource(pop1); //origem 
    exp->setTarget(pop2); //destino

    //Adiciono os sistemas e fluxo no modelo
    mod->add(pop1);
    mod->add(pop2);
    mod->add(exp);

    //Executo a simulação
    mod->run(0, 100);

    //Validação com assert
    //Faço com que a diferença seja menor que 0.0001 para dar certo
    assert(std::fabs(pop1->getValue() - 36.6032) < 0.0001); 
    assert(std::fabs(pop2->getValue() - 63.3968) < 0.0001); 

    std::cout << "Teste Exponencial Passou!" << std::endl;

    //Limpo os ponteiros
    delete mod;
    delete pop1;
    delete pop2;
    delete exp;
}

//Metodo do teste funcional do logistico
void logisticalFuncionalTest() {
    std::cout << "Executando Teste Logistico..." << std::endl;

    //Crio o modelo e os sistemas
    Model* mod = new Model("Modelo Logistico");
    System* p1 = new System("p1", 100.0);
    System* p2 = new System("p2", 10.0);
    //Crio o fluxo
    LogisticaFlow* log = new LogisticaFlow("Fluxo Logistico");

    //Defino o destino e origem
    log->setSource(p1); //origem
    log->setTarget(p2); //destino

    //Adiciono sistemas e fluxo no modelo
    mod->add(p1);
    mod->add(p2);
    mod->add(log);

    //Executo a simulacao
    mod->run(0, 100);

    //Validação com assert
    //Faço com que a diferença seja menor que 0.0001 para dar certo
    assert(std::fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(std::fabs(p2->getValue() - 21.7833) < 0.0001);

    std::cout << "Teste Logistico Passou!" << std::endl;

    //Deleto os ponteiros
    delete mod;
    delete p1;
    delete p2;
    delete log;
}

void complexFuncionalTest() {
    std::cout << "Executando Teste Complexo (Sistema Q)..." << std::endl;

    //Criação dos 5 sistemas soltos na memória
    System* q1 = new System("Q1", 100.0);
    System* q2 = new System("Q2", 0.0);
    System* q3 = new System("Q3", 100.0);
    System* q4 = new System("Q4", 0.0);
    System* q5 = new System("Q5", 0.0);

    //Criação e vinculação das 6 engrenagens de fluxos complexos
    FlowComplex* f = new FlowComplex("f"); f->setSource(q1); f->setTarget(q2);
    FlowComplex* g = new FlowComplex("g"); g->setSource(q1); g->setTarget(q3);
    FlowComplex* r = new FlowComplex("r"); r->setSource(q2); r->setTarget(q5);
    FlowComplex* t = new FlowComplex("t"); t->setSource(q2); t->setTarget(q3);
    FlowComplex* u = new FlowComplex("u"); u->setSource(q3); u->setTarget(q4);
    FlowComplex* v = new FlowComplex("v"); v->setSource(q4); v->setTarget(q1);

    //Adicionando todos ao modelo por Agregação
    Model* m = new Model("Complex Model Q");
    m->add(q1); m->add(q2); m->add(q3); m->add(q4); m->add(q5);
    m->add(f); m->add(g); m->add(r); m->add(t); m->add(u); m->add(v);

    //Executando a simulação por 100 iterações
    m->run(0, 100);

    // teste (imprime qual a precisao do 77.1143 em 10 casas)
    // std::cout << std::fixed << std::setprecision(10)
    //     << q3->getValue() << " diff "
    //     << std::fabs(q3->getValue() - 77.1143) << std::endl;

          
    //Validação de alta precisao (tive que colocar a funcao round4 para que o codigo pare de falhar quando muda a ultima casa decimal) 
    auto round4 = [](double v) {
        return std::round(v * 10000.0) / 10000.0;
    };

    //verificacao do novo valor
    // std::cout << std::fixed << std::setprecision(10)
    //     << round4(q3->getValue());

    assert(round4(q1->getValue()) == 31.8513);
    assert(round4(q2->getValue()) == 18.4003);
    assert(round4(q3->getValue()) == 77.1143);
    assert(round4(q4->getValue()) == 56.1728);
    assert(round4(q5->getValue()) == 16.4612);



    
    std::cout << "Teste Complexo Passou!" << std::endl;

    //Limpeza manual da memóriaHeap para evitar vazamentos (Memory Leak)
    delete m;
    delete q1; delete q2; delete q3; delete q4; delete q5;
    delete f; delete g; delete r; delete t; delete u; delete v;
}