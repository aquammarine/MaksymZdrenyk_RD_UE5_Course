#include "Weapon.h"
#include <iostream>

Weapon::Weapon(int damage, float cooldown, const std::string& icon)
	:damage(damage), cooldown(cooldown), Item(icon), currentCooldown(0) {}

bool Weapon::isReady() const
{
	return currentCooldown <= 0;
}

void Weapon::use()
{
	if (!isReady())
	{
		std::cout << "On cooldown\n";
		return;
	}
	std::cout << "You caused " << damage << " damage\n";
	currentCooldown = cooldown;
}

void Weapon::updateCooldown(float deltaTime)
{
	if (currentCooldown > 0)
		currentCooldown -= deltaTime;
}
