#include "Character.h"
#include <iostream>

Character::Character(int health, const Stats& stats)
    : health(health), baseStats(stats), currentStats(stats) {
}

void Character::recalculateStats() {
    currentStats = baseStats;

    for (const auto& item : passiveItems) {
        const Stats& bonus = item->getBonusStats();
        currentStats.strength += bonus.strength;
        currentStats.intelligence += bonus.intelligence;
        currentStats.agility += bonus.agility;
        currentStats.speed += bonus.speed;
    }
}

void Character::pickWeapon(std::unique_ptr<Weapon> newWeapon) {
    if (weapon) std::cout << "Swapped weapon\n";
    else std::cout << "Picked up weapon\n";
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
    if (weapon) weapon->updateCooldown(deltaTime);
}

void Character::addPassiveItem(std::unique_ptr<PassiveItem> item) {
    if (passiveItems.size() >= 3) {
        std::cout << "Inventory full!\n";
        return;
    }
    passiveItems.push_back(std::move(item));
    recalculateStats();
    std::cout << "Item added to inventory\n";
}

void Character::printStats() const {
    std::cout << "--- Character Stats ---\n"
        << "HP: " << health << "\n"
        << "Strength: " << currentStats.strength << "\n"
        << "Intelligence: " << currentStats.intelligence << "\n"
        << "Agility: " << currentStats.agility << "\n"
        << "Speed: " << currentStats.speed << "\n"
        << "-----------------------\n";
}