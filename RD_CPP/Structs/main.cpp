#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

struct Player {
	Player(const std::string& name, int x, int y)
	{ 
		this->name = name;
		coordinates.first = x;
		coordinates.second = y;
	}
	std::string name;
	float health = 100.0f;
	std::pair<int, int> coordinates{ 0, 0 };
};

int main()
{
	std::cout << "Enter number of players: ";
	int n;
	while (!(std::cin >> n) || n < 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid number, enter again: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::vector<Player> players;
	for (int i = 0; i < n; ++i) {
		std::string name;
		int x = 0, y = 0;

		std::cout << "Player " << (i + 1) << " name: ";
		std::getline(std::cin, name);
		if (name.empty()) {
			--i;
			continue;
		}

		std::cout << "Player " << (i + 1) << " coordinates (x y): ";
		while (!(std::cin >> x >> y)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid coordinates, enter two integers: ";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		Player p(name, x, y);
		players.push_back(p);
	}

	std::cout << "Enter meteor coordinates (x y): ";
	int mx = 0, my = 0;
	while (!(std::cin >> mx >> my)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid coordinates, enter two integers: ";
	}

	std::cout << "Enter meteor damage (positive number): ";
	float damage = 0.0f;
	while (!(std::cin >> damage) || damage < 0.0f) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid damage, enter a non-negative number: ";
	}

	std::cout << "Enter meteor power (positive number): ";
	float power = 0.0f;
	while (!(std::cin >> power) || power < 0.0f) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid power, enter a non-negative number: ";
	}

	const double radius = 3.0 * static_cast<double>(power);
	std::vector<int> damagedIndices;
	for (size_t i = 0; i < players.size(); ++i) {
		int px = players[i].coordinates.first;
		int py = players[i].coordinates.second;
		double dx = static_cast<double>(px - mx);
		double dy = static_cast<double>(py - my);
		double dist = std::sqrt(dx * dx + dy * dy);

		if (dist <= radius) {
			players[i].health -= damage;
			damagedIndices.push_back(static_cast<int>(i));
		}
	}

	std::cout << "\nPlayers who received damage:\n";
	if (damagedIndices.empty()) {
		std::cout << "None\n";
	}
	else {
		for (int idx : damagedIndices) {
			std::cout << "- " << players[idx].name
				<< " (health: " << std::fixed << std::setprecision(1) << players[idx].health << ")\n";
		}
	}

	std::cout << "\nDead players:\n";
	bool anyDead = false;
	for (const auto& p : players) {
		if (p.health <= 0.0f) {
			std::cout << "- " << p.name << "\n";
			anyDead = true;
		}
	}
	if (!anyDead) {
		std::cout << "None\n";
	}

	return 0;
}