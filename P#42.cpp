// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// struct OddArrayData
// {
//     int SizeOfArray = 0;

//     int Elements[100] = {0};

//     int CountOddNumbers = 0;
// };

// int ReadSizeOfArray(const std::string &Message);

// void FillArrayWithRandomElements(OddArrayData &Data);

// void PrintArrayElements(const OddArrayData &Data);

// void CountOddNumbers(OddArrayData &Data);

// void PrintOddNumbersCounter(const OddArrayData &Data);

// int main(void)
// {
//     srand(static_cast<unsigned int>(time(0)));

//     const std::string Message = "Enter The Size Of The Array:\n";

//     OddArrayData Data;

//     Data.SizeOfArray = ReadSizeOfArray(Message);

//     FillArrayWithRandomElements(Data);

//     PrintArrayElements(Data);

//     CountOddNumbers(Data);

//     PrintOddNumbersCounter(Data);

//     return 0;
// }

// int ReadSizeOfArray(const std::string &Message)
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

//     return SizeOfArray;
// }

// void FillArrayWithRandomElements(OddArrayData &Data)
// {
//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         Data.Elements[i] = rand() % 101;
//     }
// }

// void PrintArrayElements(const OddArrayData &Data)
// {
//     std::cout << "Array Elements:\n";

//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         std::cout << Data.Elements[i] << " ";
//     }

//     std::cout << '\n';
// }

// void CountOddNumbers(OddArrayData &Data)
// {
//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         Data.CountOddNumbers += (Data.Elements[i] % 2);
//     }
// }

// void PrintOddNumbersCounter(const OddArrayData &Data)
// {
//     std::cout << "Odd Elements Counter:\n";

//     std::cout << Data.CountOddNumbers << '\n';
// }

#include <iostream>
#include <cstdint>
#include <random>

struct OddArrayData
{
    uint8_t SizeOfArray = 0;

    uint8_t Elements[100] = {0};

    uint8_t CountOddNumbers = 0;
};

// uint8_t instead of int for SizeOfArray, Elements[100], CountOddNumbers. All these values fit in 0–100, which is well within a single byte's range (0–255). int is typically 4 bytes, so this is a genuine 4x reduction in memory footprint for the array and related fields. This matters more as arrays get larger — at 100 elements it saves ~300 bytes, which is trivial, but it's the correct habit: always size your type to the actual range of your data, not out of default reflex.
uint8_t ReadSizeOfArray(const std::string &Message);

void FillArrayWithRandomElements(OddArrayData &Data);

void PrintArrayElements(const OddArrayData &Data);

void CountOddNumbers(OddArrayData &Data);

void PrintOddNumbersCounter(const OddArrayData &Data);

int main(void)
{
    // disables synchronization between C++ and C's I/O streams, making cin/cout operations faster. Real, measurable, standard professional habit — though only noticeable with heavy I/O, not a handful of prints like here.
    std::ios_base::sync_with_stdio(false);

    OddArrayData Data;

    Data.SizeOfArray = ReadSizeOfArray("Enter The Size Of The Array:\n");

    FillArrayWithRandomElements(Data);

    PrintArrayElements(Data);

    CountOddNumbers(Data);

    PrintOddNumbersCounter(Data);

    return 0;
}

// ReadSizeOfArray no longer builds a throwaway struct — cleaner and more honest about intent, but not a performance-relevant change at this scale.
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

    // static_cast<int>(...) when printing uint8_t values — this is a necessary consequence of choice #1, not an optimization itself. uint8_t is a character type under the hood, so cout would print it as an ASCII character instead of a number without this cast.
    return static_cast<uint8_t>(SizeOfArray);
}

void FillArrayWithRandomElements(OddArrayData &Data)
{
    // std::mt19937 + std::uniform_int_distribution declared static, constructed once. Two real wins here: (a) it avoids the modulo-bias problem rand() % 101 has (some values are statistically slightly more likely — a genuine correctness/quality issue in random generation, not just performance), and (b) static means the generator and distribution objects are built exactly once across all calls to this function, instead of being rebuilt every single call — real savings if this function were ever called repeatedly in a loop elsewhere.
    static std::mt19937 Generator(std::random_device{}());

    static std::uniform_int_distribution<int> Distribution(0, 100);

    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Elements[i] = static_cast<uint8_t>(Distribution(Generator));
    }
}

void PrintArrayElements(const OddArrayData &Data)
{
    std::cout << "Array Elements:\n";

    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << static_cast<int>(Data.Elements[i]) << ' ';
    }

    std::cout << '\n';
}

void CountOddNumbers(OddArrayData &Data)
{
    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        // Data.CountOddNumbers += (Data.Elements[i] & 1); instead of % 2. & 1 (bitwise AND with 1) checks the lowest bit directly, which is what determines odd/even in binary. % 2 almost always compiles to the exact same instruction on modern compilers with optimizations on, so this isn't a guaranteed win — but it's a real technique worth knowing for older/less-optimizing compilers or embedded contexts where you can't rely on the compiler doing this substitution for you. This one is genuinely a minor, real optimization, not just style.
        Data.CountOddNumbers += (Data.Elements[i] & 1);
    }
}

void PrintOddNumbersCounter(const OddArrayData &Data)
{
    std::cout << "Odd Elements Counter:\n";

    std::cout << static_cast<int>(Data.CountOddNumbers) << '\n';
}