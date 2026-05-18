#include <iostream>

#include "model.h"

class BirthFlow : public Flow {
public:
    BirthFlow(const std::string& name, System* source, System* target)
        : Flow(name, source, target)
    {
    }

    double execute() const override
    {
        return 0.3 * getTarget()->getValue();
    }

    Flow* clone() const override
    {
        return new BirthFlow(*this);
    }
};

int main()
{
    Model model("Exemplo exponencial");
    System& population = model.createSystem("P", 10.0);

    model.createFlow<BirthFlow>("nascimento", nullptr, &population);
    model.run(0, 100);

    std::cout << "P = " << population.getValue() << std::endl;
    return 0;
}
