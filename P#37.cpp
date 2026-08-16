#include <iostream>
#include <cstdlib>
#include <ctime>

struct ArraysData
{
    int SizeOfArray = 0;

    int Array1[100] = {0};

    int Array2[100] = {0};
};

int ReadSizeOfArray(const std::string &Message);

void FillArrayWithRandomNumbers(ArraysData &Data);

void AddArrayElements(ArraysData &Data);

void PrintArray1(const ArraysData &Data);

void PrintArray2(const ArraysData &Data);

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    ArraysData Data;

    Data.SizeOfArray = ReadSizeOfArray("Enter the size of the array (1-100):\n");

    FillArrayWithRandomNumbers(Data);

    AddArrayElements(Data);

    PrintArray1(Data);

    PrintArray2(Data);

    return 0;
}

int ReadSizeOfArray(const std::string &Message)
{
    int SizeOfArray = 0;

    do
    {
        std::cout << Message;
        std::cin >> SizeOfArray;

        if (SizeOfArray < 1 || SizeOfArray > 100)
        {
            std::cout << "Invalid size. Please enter a number between 1 and 100.\n";
        }
    } while (SizeOfArray < 1 || SizeOfArray > 100);

    return SizeOfArray;
}

void FillArrayWithRandomNumbers(ArraysData &Data)
{
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Array1[i] = rand() % 100 + 1; // random numbers between 1 and 100
    }
}

void AddArrayElements(ArraysData &Data)
{
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Array2[i] = Data.Array1[i];
    }
}

void PrintArray1(const ArraysData &Data)
{
    std::cout << "Array 1 elements:\n";

    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.Array1[i] << " ";
    }

    std::cout << "\n\n";
}

void PrintArray2(const ArraysData &Data)
{
    std::cout << "Array 2 elements:\n";

    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.Array2[i] << " ";
    }

    std::cout << "\n";
}