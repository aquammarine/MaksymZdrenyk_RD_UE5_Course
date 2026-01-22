#include "Character.h"
#include <iostream>

int main() {
    Stats heroStats(10, 5, 7, 100);
    Character hero(100, heroStats);

    std::cout << "Initial state:";
    hero.printStats();

    hero.pickWeapon(std::make_unique<Weapon>(25, 3.0f, "sword.png"));

    auto speedBoots = std::make_unique<PassiveItem>(Stats(0, 0, 2, 20), "boots.png");
    hero.addPassiveItem(std::move(speedBoots));

    hero.addPassiveItem(std::make_unique<PassiveItem>(Stats(0, 5, 0, 10), "ring.png"));

    std::cout << "\nAfter items added:";
    hero.printStats();

    hero.useWeapon();

    return 0;
}