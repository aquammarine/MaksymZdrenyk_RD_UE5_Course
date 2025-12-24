#include <iostream>

int main()
{
    std::pair<int, int> coordinates{ 0, 0 };

    int choice = -1;
    std::cout << "Available moves:\n 1.Right\n 2.Forward\n 3.Left\n 4.Back\nEnter desired option:";
    while (!(std::cin >> choice) || choice != 0)
    {
        switch (choice)
        {
            case 0:
                break;
            case 1:
                coordinates.first++;
                break;
            case 2:
                coordinates.second++;
                break;
            case 3:
                coordinates.first--;
                break;
            case 4:
                coordinates.second--;
                break;
            default:
                std::cout << "Invalid option.";
                break;
        }
        std::cout << "X: " << coordinates.first << "\nY: " << coordinates.second << std::endl;
        std::cout << "Available moves:\n 1.Right\n 2.Forward\n 3.Left\n 4.Back\nEnter desired option:";
    }
}