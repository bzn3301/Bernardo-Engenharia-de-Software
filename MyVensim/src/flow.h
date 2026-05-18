#ifndef FLOW_H
#define FLOW_H

#include <string>

class System;

class Flow {
public:
    Flow(std::string name = "", System* source = nullptr, System* target = nullptr);
    Flow(const Flow& other);
    Flow& operator=(const Flow& other);
    virtual ~Flow();

    const std::string& getName() const;
    void setName(const std::string& name);

    System* getSource() const;
    void setSource(System* source);

    System* getTarget() const;
    void setTarget(System* target);

    virtual double execute() const;
    virtual Flow* clone() const;

private:
    std::string name;
    System* source;
    System* target;
};

#endif
