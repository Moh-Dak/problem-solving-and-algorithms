// #include <iostream>
// #include <random>
// #include <cstdlib>
// #include <cstdint>
// #include <ctime>
// #include <string>

// struct NegativeOutOfRandomElementsData
// {
//     int SizeOfArray = 0;

//     int Elements[100] = {0};

//     int CountNegativeNum = 0;
// };

// uint8_t ReadSizeOfArray(const std::string &Message);

// void FillArrayWithRandomElements(NegativeOutOfRandomElementsData &Data);

// void PrintArrayElements(const NegativeOutOfRandomElementsData &Data);

// void CountNegativeNumbers(NegativeOutOfRandomElementsData &Data);

// void PrintValueOfNegativeCounter(const NegativeOutOfRandomElementsData &Data);

// int main(void)
// {
//     std::ios_base::sync_with_stdio(false);

//     srand(static_cast<unsigned int>(time(0)));

//     const std::string Message = "Enter The Size Of The Array:\n";

//     NegativeOutOfRandomElementsData Data;

//     Data.SizeOfArray = ReadSizeOfArray(Message);

//     FillArrayWithRandomElements(Data);

//     PrintArrayElements(Data);

//     CountNegativeNumbers(Data);

//     PrintValueOfNegativeCounter(Data);

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

// void FillArrayWithRandomElements(NegativeOutOfRandomElementsData &Data)
// {
//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         Data.Elements[i] = (rand() % 201) - 100; // range: -100 to 100 inclusive
//     }
// }

// void PrintArrayElements(const NegativeOutOfRandomElementsData &Data)
// {
//     std::cout << "Array Elements:\n";

//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         std::cout << Data.Elements[i] << " ";
//     }

//     std::cout << '\n';
// }

// void CountNegativeNumbers(NegativeOutOfRandomElementsData &Data)
// {
//     for (int i = 0; i < Data.SizeOfArray; i++)
//     {
//         if (Data.Elements[i] < 0)
//         {
//             Data.CountNegativeNum++;
//         }
//     }
// }

// void PrintValueOfNegativeCounter(const NegativeOutOfRandomElementsData &Data)
// {
//     std::cout << "Negative Elements Counter:\n";

//     std::cout << Data.CountNegativeNum << '\n';
// }

#include <iostream>
#include <random>
#include <cstdint>
#include <string>

struct NegativeOutOfRandomElementsData
{
    uint8_t SizeOfArray = 0;

    int8_t Elements[100] = {0};

    uint8_t CountNegativeNum = 0;
};

uint8_t ReadSizeOfArray(const std::string &Message);

void FillArrayWithRandomElements(NegativeOutOfRandomElementsData &Data);

void PrintArrayElements(const NegativeOutOfRandomElementsData &Data);

void CountNegativeNumbers(NegativeOutOfRandomElementsData &Data);

void PrintValueOfNegativeCounter(const NegativeOutOfRandomElementsData &Data);

int main(void)
{
    std::ios_base::sync_with_stdio(false);

    const std::string Message = "Enter The Size Of The Array:\n";

    NegativeOutOfRandomElementsData Data;

    Data.SizeOfArray = ReadSizeOfArray(Message);

    FillArrayWithRandomElements(Data);

    PrintArrayElements(Data);

    CountNegativeNumbers(Data);

    PrintValueOfNegativeCounter(Data);

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

void FillArrayWithRandomElements(NegativeOutOfRandomElementsData &Data)
{
    static std::mt19937 Generator(std::random_device{}());

    static std::uniform_int_distribution<int> Distribution(-100, 100);

    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Elements[i] = static_cast<int8_t>(Distribution(Generator));
    }
}

void PrintArrayElements(const NegativeOutOfRandomElementsData &Data)
{
    std::cout << "Array Elements:\n";

    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << static_cast<int>(Data.Elements[i]) << " ";
    }

    std::cout << '\n';
}

void CountNegativeNumbers(NegativeOutOfRandomElementsData &Data)
{
    for (uint8_t i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.CountNegativeNum += (Data.Elements[i] < 0);
    }
}

void PrintValueOfNegativeCounter(const NegativeOutOfRandomElementsData &Data)
{
    std::cout << "Negative Elements Counter:\n";

    std::cout << static_cast<int>(Data.CountNegativeNum) << '\n';
}

/*
    Ha, fair reaction — it looks dense, but it's actually just three familiar ideas wearing unfamiliar names. Let's break it into pieces so it stops looking scary.

    **Piece 1: `static std::mt19937 Generator(std::random_device{}());`**

    Think of `std::mt19937` as a **machine that spits out random numbers** when you ask it to — that's all it is. `mt19937` is just its technical name (Mersenne Twister, a well-known algorithm — you don't need to know how it works internally, just that it's a trusted random number engine).

    The confusing part is `(std::random_device{}())`. Break it into two smaller pieces:
    - `std::random_device{}` — this creates a small helper object whose *only* job is producing a genuinely unpredictable seed (using hardware entropy from your OS, like mouse movement timing or similar). Think of it as a "true randomness source."
    - `(...)` right after it — calling that helper object like a function gives you one actual random seed number out of it.

    So the whole line means: **"Create one random-number-generating machine, and start it off with a truly random seed so it doesn't produce the same sequence every time."** That's it. You did something conceptually similar before with `srand(time(0))` — this is just the more modern, higher-quality version of the same idea.

    **Piece 2: `static std::uniform_int_distribution<int> Distribution(-100, 100);`**

    The `Generator` machine on its own just produces huge, meaningless random numbers (like `2847293819`). You don't want that — you want a number between -100 and 100. `std::uniform_int_distribution` is a **shaping tool**: you tell it your desired range `(-100, 100)`, and it knows how to take the Generator's raw huge number and correctly reshape it into your range, evenly, without bias.

    Think of it like: `Generator` = a machine spitting out random raw numbers. `Distribution` = a funnel that only lets numbers in your chosen range through, fairly.

    **Piece 3: `Distribution(Generator)`**

    This is the moment you actually *use* both pieces together: "Hey `Distribution`, take a raw number from `Generator`, and give me back one number that fits in my -100 to 100 range." That's the whole interaction — feed the generator into the distribution, get one clean random number out.

    **Why `static`?** So you don't rebuild the Generator and Distribution machines every single loop iteration — you build them once, and reuse them for every random number you need afterward. Cheaper and correct.

    **The one-sentence version to keep in your head:**
    `Generator` makes raw random numbers → `Distribution` reshapes them into the range you want → calling `Distribution(Generator)` gives you one properly-ranged random number.

    Once that clicks, this pattern will look exactly the same in every C++ program you ever write that needs quality randomness — it's always these same three pieces, just with different ranges plugged in.
*/