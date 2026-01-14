#include "Character.h"

int main() {
    Stats heroStats(10, 5, 7);
    Character hero(100, heroStats);

    hero.useWeapon();

    hero.pickWeapon(std::make_unique<Weapon>(25, 3.0f, "sword.png"));

    hero.useWeapon();
    hero.useWeapon();

    hero.update(3.0f);
    hero.useWeapon();

    hero.addPassiveItem(
        std::make_unique<PassiveItem>(Stats(2, 1, 0), "ring.png")
    );

    hero.printStats();

    return 0;
}