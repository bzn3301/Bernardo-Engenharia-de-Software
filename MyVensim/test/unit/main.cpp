#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include <iostream>

#include "unit_tests.h"

int main()
{
    testSystem();
    testSystemCanonicalForm();
    testFlowCanonicalForm();
    testModelStructure();
    testModelCanonicalForm();
    testTransferBetweenSystems();

    std::cout << "Todos os testes unitarios passaram." << std::endl;
    return 0;
}

#endif
