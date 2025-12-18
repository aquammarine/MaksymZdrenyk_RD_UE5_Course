#include <iostream>
#include <vector>
#include <limits>

void setPlayerCount(int& player_count)
{
    std::cout << "Enter count of players: ";
    while (!(std::cin >> player_count) || player_count <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid. Enter count: ";
    }
    std::cout << "Number of player is " << player_count << std::endl;
}

void setPlayersData(const int &player_count, std::vector<std::string> &name, std::vector<float> &health)
{
    std::string player_name;
    float player_health;
    for (int i = 0; i < player_count; i++)
    {
        std::cout << "Enter nickname for  player " << (i + 1) << ": ";
        std::cin >> player_name;

        std::cout << "Enter player's health for " << player_name << ": ";
        while (!(std::cin >> player_health))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid value. Enter player's health for " << player_name << ": ";
        }
        name.push_back(player_name);
        health.push_back(player_health);
    }
}

std::vector<float> causeDamage(std::vector<float> &health)
{
    float damage = -1;
    std::cout << "Enter amount of damage you want to cause (single digit): ";
    while (!(std::cin >> damage) || damage < 0 || damage > 9)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid value. amount of damage you want to cause(0-9):";
    }

    for (int i = 0; i < health.size(); i++)
        health[i] -= damage;
    return health;
}

float getMaxHealth(std::vector<float>& health)
{
    float maxHealth = health[0];
    for (int i = 0; i < health.size(); i++)
    {
        if (health[i] > maxHealth)
            maxHealth = health[i];
    }
    return maxHealth;
}

float getMinHealth(std::vector<float>& health)
{
    float minHealth = health[0];
    for (int i = 0; i < health.size(); i++)
    {
        if (health[i] < minHealth)
            minHealth = health[i];
    }
    return minHealth;
}

void getPlayersState(std::vector<std::string>& name, std::vector<float>& health)
{
    for (int i = 0; i < health.size(); i++)
    {
        if (health[i] <= 0)
        {
            health[i] = 0;
            std::cout << "Player " << name[i] << "(" << (i + 1) << ")" << " is dead\n";
        }
        else
        {
            std::cout << "Player " << name[i] << "(" << (i + 1) << ")" << " has " << health[i] << " hp\n";
        }
    }
}

void executeFunction(const int& player_count, std::vector<std::string>& name, std::vector<float>& health)
{
    int choice = -1;
    while (choice != 0)
    {
        std::cout << "\nAvailable options:"
            << "\n  1. Get player with MAX hp"
            << "\n  2. Get player with MIN hp"
            << "\n  3. Get dead players"
            << "\n  0. Quit"
            << "\nEnter your choice: ";
        while (!(std::cin >> choice) || choice < 0 || choice > 3)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid value. Available options arrange only 1-3:";
        }
        switch (choice)
        {
            case 0:
                break;
            case 1:
                std::cout << "Player with max health has " << getMaxHealth(health) << " hp\n";
                break;
            case 2:
                std::cout << "Player with min health has " << getMinHealth(health) << " hp\n";
                break;
            case 3:
                getPlayersState(name, health);
                break;
            default:
                std::cout << "Invalid value. Available options arrange only 1-3\n";
                break;
        }
    }
}

int main()
{
    int player_count;
    std::vector<std::string> name;
    std::vector<float> health;

    setPlayerCount(player_count);
    setPlayersData(player_count, name, health);
    causeDamage(health);
    executeFunction(player_count, name, health);



    return 0;
}