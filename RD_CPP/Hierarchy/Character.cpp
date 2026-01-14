#include "Character.h"
#include <iostream>

Character::Character(int health, const Stats& stats)
    : health(health), baseStats(stats), currentStats(stats) {
}

void Character::pickWeapon(std::unique_ptr<Weapon> newWeapon) {
    if (weapon)
        std::cout << "Swapped weapon\n";
    else
        std::cout << "Picked up weapon\n";

    weapon = std::move(newWeapon);
}

void Character::useWeapon() {
    if (!weapon) {
        std::cout << "You have no weapon\n";
        return;
    }
    weapon->use();
}

void Character::update(float deltaTime) {
    if (weapon)
        weapon->updateCooldown(deltaTime);
}

void Character::addPassiveItem(std::unique_ptr<PassiveItem> item) {
    if (passiveItems.size() >= 3) {
        std::cout << "You've reached max passive items\n";
        return;
    }
    currentStats.strength += item->getBonusStats().strength;
    currentStats.intelligence += item->getBonusStats().intelligence;
    currentStats.agility += item->getBonusStats().agility;

    passiveItems.push_back(std::move(item));
}

void Character::printStats() const {
    std::cout << "HP: " << health << "\n"
        << "Strength: " << currentStats.strength << "\n"
        << "Intelligence: " << currentStats.intelligence << "\n"
        << "Agility: " << currentStats.agility << "\n";
}