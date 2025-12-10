#include <iostream>

void setPlayerData(std::string& nickname, std::string& characterClass, float &health)
{
	std::cout << "Enter nickname: ";
	std::cin >> nickname;

	std::cout << "Choose your class:\n1. Mage\n2. Knight\n3. Archer\nEnter your choice: ";
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			characterClass = "Mage";
			health = 50;
			break;
		case 2:
			characterClass = "Knight";
			health = 100;
			break;
		case 3:
			characterClass = "Archer";
			health = 65;
			break;
		default:
			std::cout << "Invalid class\nEnter your choice again: ";
			break;
		}
	}
}

void displayPlayerData(const std::string& nickname, const std::string& characterClass, const float& health)
{
	std::cout << "\n---------------\nPlayer Stats\n---------------"
		<< "\nName:   " << nickname
		<< "\nClass:  " << characterClass
		<< "\nHealth: " << health
		<< "\n---------------";
}

int main() {
	std::string nickname, characterClass;
	float health;

	setPlayerData(nickname, characterClass, health);
	displayPlayerData(nickname, characterClass, health);

	return 0;
}