#include <iostream>

double ReadNumber();

int CeilNumber(double Number);

void PrintCeilValue(int Number);

int main(void)
{
    double Number = ReadNumber();

    int Ceil = CeilNumber(Number);

    PrintCeilValue(Ceil);

    return 0;
}

double ReadNumber()
{
    double Number = 0.0;

    std::cout << "Enter a number:\n";

    std::cin >> Number;

    return Number;
}

int CeilNumber(double Number)
{
    int Truncated = static_cast<int>(Number);

    if (Number > 0 && Truncated != Number)
    {
        Truncated++;
    }

    return Truncated;
}

void PrintCeilValue(int Number)
{
    std::cout << "Ceil Value: " << Number << '\n';
}