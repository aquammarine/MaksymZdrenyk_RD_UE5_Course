#pragma once
#include "Subject.h"
#include <string>

class ConcreteSubject : public Subject {
private:
    std::string state;

public:
    void setState(const std::string& newState);
    std::string getState() const;
};
