#include <cassert>
#include <cmath>

#include "unit_tests.h"
#include "../../src/model.h"

class TransferFlow : public Flow {
public:
    TransferFlow(const std::string& name, System* source, System* target)
        : Flow(name, source, target)
    {
    }

    double execute() const override
    {
        return 0.1 * getSource()->getValue();
    }

    Flow* clone() const override
    {
        return new TransferFlow(*this);
    }
};

static bool closeTo(double actual, double expected, double tolerance)
{
    return std::fabs(actual - expected) <= tolerance;
}

void testSystem()
{
    System system("Populacao", 10.0);

    assert(system.getName() == "Populacao");
    assert(closeTo(system.getValue(), 10.0, 1e-9));

    system.setName("P");
    system.setValue(20.0);

    assert(system.getName() == "P");
    assert(closeTo(system.getValue(), 20.0, 1e-9));
}

void testSystemCanonicalForm()
{
    System original("Original", 10.0);
    System copied(original);
    System assigned;

    assigned = original;
    original.setName("Alterado");
    original.setValue(20.0);

    assert(copied.getName() == "Original");
    assert(closeTo(copied.getValue(), 10.0, 1e-9));
    assert(assigned.getName() == "Original");
    assert(closeTo(assigned.getValue(), 10.0, 1e-9));
}

void testFlowCanonicalForm()
{
    System source("Origem", 100.0);
    System target("Destino", 0.0);
    Flow original("Fluxo", &source, &target);
    Flow copied(original);
    Flow assigned;

    assigned = original;

    assert(copied.getName() == "Fluxo");
    assert(copied.getSource() == &source);
    assert(copied.getTarget() == &target);
    assert(assigned.getName() == "Fluxo");
    assert(assigned.getSource() == &source);
    assert(assigned.getTarget() == &target);
    assert(closeTo(original.execute(), 0.0, 1e-9));
}

void testModelStructure()
{
    Model model("Modelo basico");
    System& source = model.createSystem("Origem", 100.0);
    System& target = model.createSystem("Destino", 0.0);

    model.createFlow<TransferFlow>("transferencia", &source, &target);

    assert(model.getName() == "Modelo basico");
    assert(model.getSystems().size() == 2);
    assert(model.getFlows().size() == 1);
}

void testModelCanonicalForm()
{
    Model original("Modelo original");
    System& source = original.createSystem("Origem", 100.0);
    System& target = original.createSystem("Destino", 0.0);

    original.createFlow<TransferFlow>("transferencia", &source, &target);

    Model copied(original);
    Model assigned;
    assigned = original;

    source.setValue(50.0);
    target.setValue(50.0);

    assert(copied.getName() == "Modelo original");
    assert(copied.getSystems().size() == 2);
    assert(copied.getFlows().size() == 1);
    assert(closeTo(copied.getSystems()[0]->getValue(), 100.0, 1e-9));
    assert(closeTo(copied.getSystems()[1]->getValue(), 0.0, 1e-9));
    assert(copied.getFlows()[0]->getSource() == copied.getSystems()[0].get());
    assert(copied.getFlows()[0]->getTarget() == copied.getSystems()[1].get());

    copied.run(0, 1);

    assert(closeTo(copied.getSystems()[0]->getValue(), 90.0, 1e-9));
    assert(closeTo(copied.getSystems()[1]->getValue(), 10.0, 1e-9));

    assert(assigned.getName() == "Modelo original");
    assert(assigned.getSystems().size() == 2);
    assert(assigned.getFlows().size() == 1);
    assert(assigned.getFlows()[0]->getSource() == assigned.getSystems()[0].get());
    assert(assigned.getFlows()[0]->getTarget() == assigned.getSystems()[1].get());
}

void testTransferBetweenSystems()
{
    Model model("Transferencia");
    System& source = model.createSystem("Origem", 100.0);
    System& target = model.createSystem("Destino", 0.0);

    model.createFlow<TransferFlow>("transferencia", &source, &target);
    model.run(0, 1);

    assert(closeTo(source.getValue(), 90.0, 1e-9));
    assert(closeTo(target.getValue(), 10.0, 1e-9));
}
