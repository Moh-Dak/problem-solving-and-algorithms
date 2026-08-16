#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

struct EvenArrayData
{
    uint8_t SizeOfArray = 0;

    uint8_t Elements[100] = {0};

    uint8_t CountEvenNumbers = 0;
};

uint8_t ReadSizeOfArray(const std::string &Message);

void FillArrayWithRandomElements(EvenArrayData &Data);

void PrintElementsOfArray(const EvenArrayData &Data);

void CountEvenNumbers(EvenArrayData &Data);

void PrintEvenNumbersCounter(const EvenArrayData &Data);

int main(void)
{
    std::ios_base::sync_with_stdio(false);

    srand(static_cast<unsigned int>(time(0)));

    const std::string Message = "Enter The Size Of The Array:\n";

    EvenArrayData Data;

    Data.SizeOfArray = ReadSizeOfArray(Message);

    FillArrayWithRandomElements(Data);

    PrintElementsOfArray(Data);

    CountEvenNumbers(Data);

    PrintEvenNumbersCounter(Data);

    return 0;
}

uint8_t ReadSizeOfArray(const std::string &Message)
{
    int SizeOfArray = 0;

    do
    {
        std::cout << Message;

        std::cin >> SizeOfArray;

        std::cout << '\n';

        if (SizeOfArray < 1 || SizeOfArray > 100)
        {
            std::cout << "Invalid Input. Try Again With A Valid Number (1-100).\n";
        }
    } while (SizeOfArray < 1 || SizeOfArray > 100);

    return static_cast<uint8_t>(SizeOfArray);
}

void FillArrayWithRandomElements(EvenArrayData &Data)
{
    for (uint8_t i = 0; i < Data.SizeOfArray; i++)
    {
        Data.Elements[i] = static_cast<uint8_t>(rand() % 101);
    }
}

void PrintElementsOfArray(const EvenArrayData &Data)
{
    std::cout << "Array Elements:\n";

    for (uint8_t i = 0; i < Data.SizeOfArray; i++)
    {
        std::cout << static_cast<int>(Data.Elements[i]) << " ";
    }

    std::cout << '\n';
}

void CountEvenNumbers(EvenArrayData &Data)
{
    for (uint8_t i = 0; i < Data.SizeOfArray; i++)
    {
        if (Data.Elements[i] % 2 == 0)
        {
            Data.CountEvenNumbers++;
        }
    }
}

void PrintEvenNumbersCounter(const EvenArrayData &Data)
{
    std::cout << "\nEven Elements Counter:\n";

    std::cout << static_cast<int>(Data.CountEvenNumbers) << "\n\n";
}