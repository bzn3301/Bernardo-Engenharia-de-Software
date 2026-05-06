#include <iostream>
#include "bib.hpp"

int main() {
    // Teste simples para fatorial
    if (fatorial(5) == 120) {
        std::cout << "Teste Passou!" << std::endl;
        return 0;
    } else {
        std::cout << "Teste Falhou!" << std::endl;
        return 1;
    }
}