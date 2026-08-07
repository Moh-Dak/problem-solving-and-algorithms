#include <iostream>
#include <cstdlib>
#include <ctime>

struct ArrayData
{
    int SizeOfArray = 0;

    int Elements[100] = {0};
};

int ReadSizeOfArray(const std::string &Message);

void FillArrayWithRandomNumbers(ArrayData &Data);

void DisplayArray(const ArrayData &Data);

int ReadNumberToCheck(const std::string &Message);

bool CheckForNumberInArray(const ArrayData &Data, int NumberToSearch);

void DisplayCheckResult(bool Found, int NumberToSearch);

int main(void)
{
    ArrayData Data;

    Data.SizeOfArray = ReadSizeOfArray("Enter the size of the array (1-100):\n");

    FillArrayWithRandomNumbers(Data);

    DisplayArray(Data);

    int NumberToCheck = ReadNumberToCheck("Enter a number to check for in the array:\n");

    bool Found = CheckForNumberInArray(Data, NumberToCheck);

    DisplayCheckResult(Found, NumberToCheck);

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

void FillArrayWithRandomNumbers(ArrayData &Data)
{
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Elements[i] = rand() % 101; // random number 0-100
    }
}

void DisplayArray(const ArrayData &Data)
{
    std::cout << "Generated array: ";
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.Elements[i] << " ";
    }
    std::cout << std::endl;
}

int ReadNumberToCheck(const std::string &Message)
{
    int NumberToCheck = 0;

    std::cout << Message;
    std::cin >> NumberToCheck;

    return NumberToCheck;
}

bool CheckForNumberInArray(const ArrayData &Data, int NumberToSearch)
{
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        if (Data.Elements[i] == NumberToSearch)
        {
            return true;
        }
    }
    return false;
}

void DisplayCheckResult(bool Found, int NumberToSearch)
{
    if (Found)
    {
        std::cout << "The number " << NumberToSearch << " was found in the array.\n";
    }
    else
    {
        std::cout << "The number " << NumberToSearch << " was NOT found in the array.\n";
    }
}