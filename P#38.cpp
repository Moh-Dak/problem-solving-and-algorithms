#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

struct ArraysData
{
    int SizeOfArray = 0;

    std::array<int, 100> OriginalArray = {0};

    std::array<int, 100> OddValuesOnly = {0};
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

    Data.SizeOfArray = ReadSizeOfArray("Enter the size of the array (between 1 and 100): ");

    FillArrayWithRandomNumbers(Data);

    AddArrayElements(Data);

    PrintArray1(Data);

    PrintArray2(Data);

    return 0;
}

int ReadSizeOfArray(const std::string &Message)
{
    ArraysData Data;

    Data.SizeOfArray = 0;

    do
    {
        std::cout << Message;
        std::cin >> Data.SizeOfArray;

        if (Data.SizeOfArray < 1 || Data.SizeOfArray > 100)
        {
            std::cout << "Invalid size. Please enter a number between 1 and 100.\n";
        }
    } while (Data.SizeOfArray < 1 || Data.SizeOfArray > 100);

    return Data.SizeOfArray;
}

void FillArrayWithRandomNumbers(ArraysData &Data)
{
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.OriginalArray[i] = rand() % 100; // Fill with random numbers between 0 and 99
    }
}

void AddArrayElements(ArraysData &Data)
{
    int OddIndex = 0;

    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        if (Data.OriginalArray[i] % 2 != 0) // Check if the number is odd
        {
            Data.OddValuesOnly[OddIndex++] = Data.OriginalArray[i];
        }
    }
}

void PrintArray1(const ArraysData &Data)
{
    std::cout << "Original Array: ";
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.OriginalArray[i] << " ";
    }
    std::cout << std::endl;
}

void PrintArray2(const ArraysData &Data)
{
    std::cout << "Odd Values Only Array: ";
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        if (Data.OddValuesOnly[i] != 0) // Print only non-zero values
        {
            std::cout << Data.OddValuesOnly[i] << " ";
        }
    }
    std::cout << std::endl;
}

/*
the program asks the user to enter the size of an array (between 1 and 100), fills the array with random numbers, and then creates a second array that contains only the odd values from the first array. Finally, it prints both arrays to the console.
*/