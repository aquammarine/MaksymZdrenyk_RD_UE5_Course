#include "ConcreteSubject.h"
#include "ConcreteObserver.h"

int main() {
    ConcreteSubject newsAgency;

    ConcreteObserver user1("Alice");
    ConcreteObserver user2("Bob");

    newsAgency.attach(&user1);
    newsAgency.attach(&user2);

    newsAgency.setState("Breaking News: Observer Pattern Implemented!");

    newsAgency.detach(&user1);
    newsAgency.setState("Second Update: Alice is gone.");

    return 0;
}