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





//#include <string>
//#include <limits>
//#include <algorithm>
//
//int readPlayerCount()
//{
//    int count;
//    std::cout << "Enter count of players: ";
//    while (!(std::cin >> count) || count <= 0)
//    {
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        std::cout << "Invalid number. Enter count of players: ";
//    }
//    return count;
//}
//
//void readPlayers(int count, std::vector<std::string>& names, std::vector<float>& healths)
//{
//    names.clear();
//    healths.clear();
//    names.reserve(count);
//    healths.reserve(count);
//
//    for (int i = 0; i < count; ++i)
//    {
//        std::string name;
//        float health;
//
//        std::cout << "Enter nickname for player " << (i + 1) << ": ";
//        std::cin >> name;
//
//        std::cout << "Enter player's health for " << name << ": ";
//        while (!(std::cin >> health))
//        {
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            std::cout << "Invalid value. Enter player's health for " << name << ": ";
//        }
//
//        names.push_back(name);
//        healths.push_back(health);
//    }
//}
//
//int readDamageDigit()
//{
//    int d;
//    std::cout << "Enter damage (single digit): ";
//    while (!(std::cin >> d) || d < 0 || d > 9)
//    {
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        std::cout << "Invalid digit. Enter damage (0-9): ";
//    }
//    return d;
//}
//
//void applyDamage(std::vector<float>& healths, float damage)
//{
//    for (auto& h : healths)
//        h -= damage;
//}
//
//int findMaxHealthIndex(const std::vector<float>& healths)
//{
//    if (healths.empty()) return -1;
//    return static_cast<int>(std::distance(healths.begin(), std::max_element(healths.begin(), healths.end())));
//}
//
//int findMinHealthIndex(const std::vector<float>& healths)
//{
//    if (healths.empty()) return -1;
//    return static_cast<int>(std::distance(healths.begin(), std::min_element(healths.begin(), healths.end())));
//}
//
//std::vector<int> getDeadPlayerIndices(const std::vector<float>& healths)
//{
//    std::vector<int> dead;
//    for (size_t i = 0; i < healths.size(); ++i)
//        if (healths[i] <= 0.0f)
//            dead.push_back(static_cast<int>(i));
//    return dead;
//}
//
//int main()
//{
//    int player_count = readPlayerCount();
//
//    std::vector<std::string> names;
//    std::vector<float> healths;
//    readPlayers(player_count, names, healths);
//
//    int damage = readDamageDigit();
//    applyDamage(healths, static_cast<float>(damage));
//
//    std::cout << "Enter query option (1 = max health, 2 = min health, 3 = dead players): ";
//    int option;
//    while (!(std::cin >> option) || option < 1 || option > 3)
//    {
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        std::cout << "Invalid option. Enter 1, 2 or 3: ";
//    }
//
//    switch (option)
//    {
//    case 1:
//    {
//        int idx = findMaxHealthIndex(healths);
//        if (idx >= 0)
//            std::cout << "Player with max health: " << names[idx] << " (health = " << healths[idx] << ")\n";
//        break;
//    }
//    case 2:
//    {
//        int idx = findMinHealthIndex(healths);
//        if (idx >= 0)
//            std::cout << "Player with min health: " << names[idx] << " (health = " << healths[idx] << ")\n";
//        break;
//    }
//    case 3:
//    {
//        auto dead = getDeadPlayerIndices(healths);
//        if (dead.empty())
//        {
//            std::cout << "No dead players.\n";
//        }
//        else
//        {
//            std::cout << "Dead players:\n";
//            for (int i : dead)
//                std::cout << "- " << names[i] << " (health = " << healths[i] << ")\n";
//        }
//        break;
//    }
//    }
//
//    return 0;
//}