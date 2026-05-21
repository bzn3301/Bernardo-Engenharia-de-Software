#include "unit_tests.h"
#include <iostream>

int main() {
    std::cout << "--- Iniciando Testes Unitarios ---" << std::endl;

    std::cout << "\n[ Testes de System ]" << std::endl;
    testSystemDefaultConstructor();
    testSystemParametrizedConstructor();
    testSystemGetters();
    testSystemSetters();

    std::cout << "\n[ Testes de Flow ]" << std::endl;
    testFlowGetters();
    testFlowSetters();
    testFlowExponentialExecute();
    testFlowLogisticExecute();

    std::cout << "\n[ Testes de Model ]" << std::endl;
    testModelGetters();
    testModelSetters();
    testModelAddSystem();
    testModelAddFlow();
    testModelRun();

    std::cout << "\n--- TODOS OS TESTES UNITARIOS PASSARAM! ---" << std::endl;
    return 0;
}