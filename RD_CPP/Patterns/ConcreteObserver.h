#pragma once
#include "Observer.h"
#include <string>

class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& name);
    void update(const std::string& message) override;
};
