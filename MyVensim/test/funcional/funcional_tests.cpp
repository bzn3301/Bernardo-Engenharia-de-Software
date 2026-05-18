#include <algorithm>
#include <cassert>
#include <cmath>

#include "funcional_tests.h"
#include "../../src/model.h"

class ExponentialFlow : public Flow {
public:
    ExponentialFlow(const std::string& name, System* source, System* target)
        : Flow(name, source, target)
    {
    }

    double execute() const override
    {
        return 0.3 * getTarget()->getValue();
    }

    Flow* clone() const override
    {
        return new ExponentialFlow(*this);
    }
};

class LogisticFlow : public Flow {
public:
    LogisticFlow(const std::string& name, System* source, System* target, System* limit)
        : Flow(name, source, target), limit(limit)
    {
    }

    double execute() const override
    {
        const double population = getTarget()->getValue();
        return 0.3 * population * (1.0 - population / limit->getValue());
    }

    Flow* clone() const override
    {
        return new LogisticFlow(*this);
    }

private:
    System* limit;
};

class ComplexFlow : public Flow {
public:
    ComplexFlow(const std::string& name, System* source, System* target)
        : Flow(name, source, target)
    {
    }

    double execute() const override
    {
        return 0.01 * getSource()->getValue();
    }

    Flow* clone() const override
    {
        return new ComplexFlow(*this);
    }
};

static bool closeTo(double actual, double expected, double tolerance)
{
    return std::fabs(actual - expected) <= tolerance;
}

static bool relativelyCloseTo(double actual, double expected, double tolerance)
{
    return std::fabs(actual - expected) <= tolerance * std::max(1.0, std::fabs(expected));
}

void exponentialFuncionalTest()
{
    Model model("Crescimento exponencial");
    System& population = model.createSystem("P", 10.0);

    model.createFlow<ExponentialFlow>("nascimento", nullptr, &population);
    model.run(0, 100);

    assert(relativelyCloseTo(population.getValue(), 2479335110965.981, 1e-12));
}

void logisticalFuncionalTest()
{
    Model model("Crescimento logistico");
    System& population = model.createSystem("P", 10.0);
    System& maximumPopulation = model.createSystem("Pmax", 70.0);

    model.createFlow<LogisticFlow>("nascimento", nullptr, &population, &maximumPopulation);
    model.run(0, 100);

    assert(closeTo(population.getValue(), 70.0, 1e-6));
}

void complexFuncionalTest()
{
    Model model("Modelo complexo");
    System& q1 = model.createSystem("Q1", 100.0);
    System& q2 = model.createSystem("Q2", 0.0);
    System& q3 = model.createSystem("Q3", 100.0);
    System& q4 = model.createSystem("Q4", 0.0);
    System& q5 = model.createSystem("Q5", 0.0);

    model.createFlow<ComplexFlow>("f", &q1, &q2);
    model.createFlow<ComplexFlow>("g", &q1, &q3);
    model.createFlow<ComplexFlow>("r", &q2, &q5);
    model.createFlow<ComplexFlow>("t", &q2, &q3);
    model.createFlow<ComplexFlow>("u", &q3, &q4);
    model.createFlow<ComplexFlow>("v", &q4, &q1);

    model.run(0, 100);

    assert(closeTo(q1.getValue(), 31.8513, 1e-4));
    assert(closeTo(q2.getValue(), 18.4003, 1e-4));
    assert(closeTo(q3.getValue(), 77.1143, 1e-4));
    assert(closeTo(q4.getValue(), 56.1728, 1e-4));
    assert(closeTo(q5.getValue(), 16.4612, 1e-4));
}
