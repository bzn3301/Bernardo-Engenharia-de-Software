#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
public:
    System(std::string name = "", double value = 0.0);
    System(const System& other);
    System& operator=(const System& other);
    virtual ~System();

    const std::string& getName() const;
    void setName(const std::string& name);

    double getValue() const;
    void setValue(double value);

private:
    std::string name;
    double value;
};

#endif
