// #include <iostream>
// #include <random>
// #include <cstdlib>
// #include <cstdint>
// #include <ctime>
// #include <string>

// struct PositiveOutOfRandomElementsData
// {
//     int SizeOfArray = 0;

//     int Elements[100] = {0};

//     int CountPositiveNum = 0;
// };

// uint8_t ReadSizeOfArray(const std::string &Message);

// void FillArrayWithRandomElements(PositiveOutOfRandomElementsData &Data);

// void PrintArrayElements(const PositiveOutOfRandomElementsData &Data);

// void CountPositiveNumbers(PositiveOutOfRandomElementsData &Data);

// void PrintValueOfPositiveCounter(const PositiveOutOfRandomElementsData &Data);

// int main(void)
// {
//     std::ios_base::sync_with_stdio(false);

//     srand(static_cast<unsigned int>(time(0)));

//     const std::string Message = "Enter The Size Of The Array:\n";

//     PositiveOutOfRandomElementsData Data;

//     Data.SizeOfArray = ReadSizeOfArray(Message);

//     FillArrayWithRandomElements(Data);

//     PrintArrayElements(Data);

//     CountPositiveNumbers(Data);

//     PrintValueOfPositiveCounter(Data);

//     return 0;
// }

// uint8_t ReadSizeOfArray(const std::string &Message)
// {
//     int SizeOfArray = 0;

//     do
//     {
//         std::cout << Message;

//         std::cin >> SizeOfArray;

//         if (SizeOfArray < 1 || SizeOfArray > 100)
//         {
//             std::cout << "Invalid Input. Try Again With A Valid Number (1-100).\n";
//         }
//     } while (SizeOfArray < 1 || SizeOfArray > 100);

//     return static_cast<uint8_t>(SizeOfArray);
// }

// void FillArrayWithRandomElements(PositiveOutOfRandomElementsData &Data)
// {
//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         Data.Elements[i] = (rand() % 201) - 100; // range: -100 to 100 inclusive
//     }
// }

// void PrintArrayElements(const PositiveOutOfRandomElementsData &Data)
// {
//     std::cout << "Array Elements:\n";

//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         std::cout << Data.Elements[i] << " ";
//     }

//     std::cout << '\n';
// }

// void CountPositiveNumbers(PositiveOutOfRandomElementsData &Data)
// {
//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         if (Data.Elements[i] > 0)
//         {
//             Data.CountPositiveNum++;
//         }
//     }
// }

// void PrintValueOfPositiveCounter(const PositiveOutOfRandomElementsData &Data)
// {
//     std::cout << "Positive Elements Counter:\n";

//     std::cout << Data.CountPositiveNum << '\n';
// }

/*
    Notes on decisions I made completing this:

    Elements[100] stays int, not uint8_t. This is important — uint8_t can only hold 0–255 (unsigned), so it physically cannot represent negative numbers at all. Since your range now includes negatives (-100 to 100), int is the correct choice here, not a smaller type. This ties back to the earlier lesson: always size your type to your actual data range — and here, that range genuinely needs a signed type.
    (rand() % 201) - 100 for the range. rand() % 201 gives values 0 to 200 (201 possible values), and subtracting 100 shifts that window down to -100 to 100 — 201 total values, inclusive on both ends, matching your spec exactly.
    CountPositiveNumbers checks > 0, not >= 0. "Positive" conventionally excludes zero (zero is neither positive nor negative) — if you actually want zero counted too, let me know and I'll switch it to >= 0.
    ReadSizeOfArray still returns uint8_t since the array size itself (1–100) is a small, always-positive range — that type choice is still correct and unrelated to the element range change.
*/

#include <iostream>
#include <random>
#include <cstdint>
#include <string>

struct PositiveOutOfRandomElementsData
{
    uint8_t SizeOfArray = 0;

    int8_t Elements[100] = {0};

    uint8_t CountPositiveNum = 0;
};

uint8_t ReadSizeOfArray(const std::string &Message);

void FillArrayWithRandomElements(PositiveOutOfRandomElementsData &Data);

void PrintArrayElements(const PositiveOutOfRandomElementsData &Data);

void CountPositiveNumbers(PositiveOutOfRandomElementsData &Data);

void PrintValueOfPositiveCounter(const PositiveOutOfRandomElementsData &Data);

int main(void)
{
    std::ios_base::sync_with_stdio(false);

    const std::string Message = "Enter The Size Of The Array:\n";

    PositiveOutOfRandomElementsData Data;

    Data.SizeOfArray = ReadSizeOfArray(Message);

    FillArrayWithRandomElements(Data);

    PrintArrayElements(Data);

    CountPositiveNumbers(Data);

    PrintValueOfPositiveCounter(Data);

    return 0;
}

uint8_t ReadSizeOfArray(const std::string &Message)
{
    int SizeOfArray = 0;

    do
    {
        std::cout << Message;

        std::cin >> SizeOfArray;

        if (SizeOfArray < 1 || SizeOfArray > 100)
        {
            std::cout << "Invalid Input. Try Again With A Valid Number (1-100).\n";
        }
    } while (SizeOfArray < 1 || SizeOfArray > 100);

    return static_cast<uint8_t>(SizeOfArray);
}

void FillArrayWithRandomElements(PositiveOutOfRandomElementsData &Data)
{
    static std::mt19937 Generator(std::random_device{}());

    static std::uniform_int_distribution<int> Distribution(-100, 100);

    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Elements[i] = static_cast<int8_t>(Distribution(Generator));
    }
}

void PrintArrayElements(const PositiveOutOfRandomElementsData &Data)
{
    std::cout << "Array Elements:\n";

    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << static_cast<int>(Data.Elements[i]) << " ";
    }

    std::cout << '\n';
}

void CountPositiveNumbers(PositiveOutOfRandomElementsData &Data)
{
    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.CountPositiveNum += (Data.Elements[i] > 0);
    }
}

void PrintValueOfPositiveCounter(const PositiveOutOfRandomElementsData &Data)
{
    std::cout << "Positive Elements Counter:\n";

    std::cout << static_cast<int>(Data.CountPositiveNum) << '\n';
}