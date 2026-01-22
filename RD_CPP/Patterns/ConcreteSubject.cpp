#include "ConcreteSubject.h"

void ConcreteSubject::setState(const std::string& newState) {
    state = newState;
    notify(state);
}

std::string ConcreteSubject::getState() const {
    return state;
}