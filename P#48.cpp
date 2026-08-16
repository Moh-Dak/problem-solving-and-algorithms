#include <iostream>

double ReadNumber();

int FloorNumber(double Number);

void PrintFloorValue(int Number);

int main(void)
{
    double Number = ReadNumber();

    int Floor = FloorNumber(Number);

    PrintFloorValue(Floor);

    return 0;
}

double ReadNumber()
{
    double Number = 0.0;

    std::cout << "Enter a number:\n";

    std::cin >> Number;

    return Number;
}

int FloorNumber(double Number)
{
    int Truncated = static_cast<int>(Number);

    if (Number < 0 && Truncated != Number)
    {
        Truncated--;
    }

    return Truncated;
}

void PrintFloorValue(int Number)
{
    std::cout << "Floor Value: " << Number << '\n';
}