#include <iostream>

double ReadNumber();

int RoundNumber(double Number);

void PrintRoundedValue(int Number);

int main(void)
{
    double Number = ReadNumber();

    int Rounded = RoundNumber(Number);

    PrintRoundedValue(Rounded);

    return 0;
}

double ReadNumber()
{
    double Number = 0.0;

    std::cout << "Enter a number:\n";

    std::cin >> Number;

    return Number;
}

int RoundNumber(double Number)
{
    int Truncated = static_cast<int>(Number);

    double Fraction = Number - Truncated;

    if (Fraction < 0)
    {
        Fraction = -Fraction;
    }

    if (Fraction >= 0.5)
    {
        if (Number >= 0)
        {
            Truncated++;
        }
        else
        {
            Truncated--;
        }
    }

    return Truncated;
}

void PrintRoundedValue(int Number)
{
    std::cout << "Rounded Value: " << Number << '\n';
}