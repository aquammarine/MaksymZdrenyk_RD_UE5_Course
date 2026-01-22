#include "ConcreteObserver.h"
#include <iostream>

ConcreteObserver::ConcreteObserver(const std::string& name) : name(name) {}

void ConcreteObserver::update(const std::string& message) {
    std::cout << "Observer [" << name << "] received update: " << message << std::endl;
}