#include <iostream>

double ReadNumber();

double SquareRoot(double Number);

void PrintSquareRoot(double Number);

int main(void)
{
    double Number = ReadNumber();

    double Result = SquareRoot(Number);

    PrintSquareRoot(Result);

    return 0;
}

double ReadNumber()
{
    double Number = 0.0;

    std::cout << "Enter a number:\n";

    std::cin >> Number;

    return Number;
}

double SquareRoot(double Number)
{
    if (Number < 0)
    {
        std::cout << "Cannot compute square root of a negative number.\n";

        return 0.0;
    }

    if (Number == 0)
    {
        return 0.0;
    }

    double Guess = Number;

    double Epsilon = 0.00001;

    while ((Guess * Guess - Number > Epsilon) || (Number - Guess * Guess > Epsilon))
    {
        Guess = (Guess + Number / Guess) / 2.0;
    }

    return Guess;
}

void PrintSquareRoot(double Number)
{
    std::cout << "Square Root: " << Number << '\n';
}