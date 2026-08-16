#include <iostream>
#include <cstdlib>
#include <ctime>

struct ArraysData
{
    int SizeOfArray = 0;

    int Array1[100] = {0};

    int PrimeNumbers[100] = {0};

    int PrimeCount = 0;
};

int ReadSizeOfArray(const std::string &Message);

void FillArrayWithRandomNumbers(ArraysData &Data);

void AddArrayPrimeElements(ArraysData &Data);

void PrintArray1(const ArraysData &Data);

void PrintArray2(const ArraysData &Data);

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    ArraysData Data;

    Data.SizeOfArray = ReadSizeOfArray("Enter the size of the array (1-100):\n");

    FillArrayWithRandomNumbers(Data);

    AddArrayPrimeElements(Data);

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
        Data.Array1[i] = rand() % 100 + 1; // Random numbers between 1 and 100
    }
}

void AddArrayPrimeElements(ArraysData &Data)
{
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        if (Data.Array1[i] > 1)
        {
            bool IsPrime = true;

            for (int j = 2; j * j <= Data.Array1[i]; ++j)
            {
                if (Data.Array1[i] % j == 0)
                {
                    IsPrime = false;
                    break;
                }
            }

            if (IsPrime)
            {
                Data.PrimeNumbers[Data.PrimeCount] = Data.Array1[i];

                Data.PrimeCount++;
            }
        }
    }
}

void PrintArray1(const ArraysData &Data)
{
    std::cout << "Array 1: ";

    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.Array1[i] << " ";
    }

    std::cout << std::endl;
}

void PrintArray2(const ArraysData &Data)
{
    std::cout << "Prime Numbers Array: ";

    for (int i = 0; i < Data.PrimeCount; ++i)
    {
        std::cout << Data.PrimeNumbers[i] << " ";
    }

    std::cout << std::endl;
}