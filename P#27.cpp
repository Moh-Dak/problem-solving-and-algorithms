#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

struct ArrayData
{
    int Elements[100] = {0};

    int Size = 0;

    int Max = 0;

    float Avg = 0;
};

ArrayData ReadSizeOfArray(const std::string &Message);

void RandomElementsOfArray(ArrayData &Data);

void FindAvg(ArrayData &Data);

void PrintAvg(const ArrayData &Data);

int main(void)
{
    srand(static_cast<unsigned int>(time(0))); // call once in main, before any rand() calls

    const std::string Message = "Enter the size of the array\n";

    ArrayData Data = ReadSizeOfArray(Message);

    RandomElementsOfArray(Data);

    FindAvg(Data);

    PrintAvg(Data);

    return 0;
}

ArrayData ReadSizeOfArray(const std::string &Message)
{
    ArrayData Data;

    std::cout << Message;

    std::cin >> Data.Size;

    return Data;
}

void RandomElementsOfArray(ArrayData &Data)
{
    for (int i = 0; i < Data.Size; i++)
    {
        Data.Elements[i] = rand() % 101;
    }
}

void FindAvg(ArrayData &Data)
{
    for (int i = 0; i < Data.Size; i++)
    {
        Data.Max += Data.Elements[i];
    }

    Data.Avg = static_cast<float>(Data.Max) / Data.Size;
}

void PrintAvg(const ArrayData &Data)
{
    std::cout << "Array Elements: ";

    for (int i = 0; i < Data.Size; i++)
    {
        std::cout << Data.Elements[i] << " ";
    }

    std::cout << "\n\nAverage of the array: " << Data.Avg << '\n';
}