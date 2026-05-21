#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include "../../src/flow.h"
#include "../../src/system.h"

// Subclasses locais para simular e testar os comportamentos de execute nos testes unitários
class UnitExponentialFlow : public Flow {
public:
    using Flow::Flow;
    double execute() const override {
        if (getSource() != nullptr) return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

class UnitLogisticFlow : public Flow {
public:
    using Flow::Flow;
    double execute() const override {
        if (getTarget() != nullptr) {
            double p2 = getTarget()->getValue();
            return 0.01 * p2 * (1.0 - (p2 / 70.0));
        }
        return 0.0;
    }
};

// --- Assinaturas dos Testes Unitários ---
void testSystemDefaultConstructor();
void testSystemParametrizedConstructor();
void testSystemGetters();
void testSystemSetters();

void testFlowGetters();
void testFlowSetters();
void testFlowExponentialExecute();
void testFlowLogisticExecute();

void testModelGetters();
void testModelSetters();
void testModelAddSystem();
void testModelAddFlow();
void testModelRun();

#endif