#pragma once
#include <vector>
#include <memory>
#include "Stats.h"
#include "Weapon.h"
#include "PassiveItem.h"

class Character {
private:
    int health;
    Stats baseStats;
    Stats currentStats;
    std::unique_ptr<Weapon> weapon;
    std::vector<std::unique_ptr<PassiveItem>> passiveItems;
    void recalculateStats();

public:
    Character(int health, const Stats& stats);

    void pickWeapon(std::unique_ptr<Weapon> newWeapon);
    void useWeapon();
    void update(float deltaTime);
    void addPassiveItem(std::unique_ptr<PassiveItem> item);
    void printStats() const;
};