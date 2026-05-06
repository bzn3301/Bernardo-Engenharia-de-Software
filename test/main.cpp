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
#include <iostream>
#include "bib.hpp"

int main() {
    // Teste Fatorial (Funcionalidade 1)
    if (fatorial(5) == 120) std::cout << "Fatorial: OK" << std::endl;

    // Teste Fibonacci (Funcionalidade 2 - TDD)
    // O quinto número de Fibonacci (0, 1, 1, 2, 3, 5...) é 5
    if (fibonacci(5) == 5) {
        std::cout << "Fibonacci: OK! Teste Passou!" << std::endl;
        return 0;
    } else {
        std::cout << "Fibonacci: FALHOU!" << std::endl;
        return 1;
    }
}