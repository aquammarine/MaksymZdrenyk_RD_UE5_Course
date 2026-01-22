#pragma once
#include "Observer.h"
#include <vector>

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() = default;
    virtual void attach(Observer* observer);
    virtual void detach(Observer* observer);
    virtual void notify(const std::string& message);
};
