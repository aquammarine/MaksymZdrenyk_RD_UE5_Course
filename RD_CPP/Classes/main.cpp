#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

class Player {
public:
    Player(const std::string& name, int x, int y, int speed)
        : name(name), coordinates(x, y), speed(speed) {
    }

    void Move(int x, int y) {
        coordinates.first += x * speed;
        coordinates.second += y * speed;
    }

    void DisplayPosition() const {
        std::cout << name << " is at (" << coordinates.first << ", " << coordinates.second << ")\n";
    }

    const std::string& GetName() const { return name; }

private:
    std::string name;
    std::pair<int, int> coordinates;
    int speed;
};

int main() {
    std::cout << "Enter number of players: ";
    int n;
    while (!(std::cin >> n) || n <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid number, enter again: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Player> players;
    for (int i = 0; i < n; ++i) {
        std::string name;
        int x = 0, y = 0, speed = 0;

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

        std::cout << "Player " << (i + 1) << " speed: ";
        while (!(std::cin >> speed) || speed <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid speed, enter a positive integer: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        players.emplace_back(name, x, y, speed);
    }

    std::cout << "Enter number of commands: ";
    int commandCount;
    while (!(std::cin >> commandCount) || commandCount <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid number, enter again: ";
    }

    for (int i = 0; i < commandCount; ++i) {
        int playerIndex, x, y;
        std::cout << "Command " << (i + 1) << " (player number, x, y): ";
        while (!(std::cin >> playerIndex >> x >> y) || playerIndex <= 0 || playerIndex > n) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid command, enter again (player number, x, y): ";
        }

        players[playerIndex - 1].Move(x, y);
    }

    std::cout << "\nPlayer positions:\n";
    for (const auto& player : players) {
        player.DisplayPosition();
    }

    return 0;
}