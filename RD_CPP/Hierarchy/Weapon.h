#pragma once
#include "Item.h"

class Weapon : public Item {
private:
	int damage;
	float cooldown;
	float currentCooldown;

public:
	Weapon(int damage, float cooldown, const std::string& icon);

	bool isReady() const;
	void use();
	void updateCooldown(float deltaTime);
};