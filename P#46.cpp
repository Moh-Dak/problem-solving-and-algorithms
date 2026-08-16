#include <iostream>

int ReadNumber();

int GetAbsoluteValue(int Number);

void PrintAbsoluteValue(int Number);

int main(void)
{
    int Number = ReadNumber();

    int Result = GetAbsoluteValue(Number);

    PrintAbsoluteValue(Result);

    return 0;
}

int ReadNumber()
{
    int Number = 0;

    std::cout << "Enter a number:\n";

    std::cin >> Number;

    return Number;
}

int GetAbsoluteValue(int Number)
{
    if (Number < 0)
    {
        Number = -Number;
    }

    return Number;
}

void PrintAbsoluteValue(int Number)
{
    std::cout << "Absolute Value: " << Number << '\n';
}