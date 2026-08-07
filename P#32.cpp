#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time


struct ArrayData
{
    int Elements[100] = {0};

    int SizeOfArray = 0;

    int ReversedElements[100] = {0};
};

ArrayData ReadSizeOfArray(const std::string &Message);

void RandomElementsOfArray(ArrayData &Data);

void PrintArray(ArrayData &Data);

void ReverseElementsOfArray(ArrayData &Data);

void PrintReversedArray(ArrayData &Data);

int main(void) {

    srand(static_cast<unsigned int>(time(0))); // call once in main, before any rand() calls

    const std::string Message = "Enter the size of the array\n";

    ArrayData Data = ReadSizeOfArray(Message);

    RandomElementsOfArray(Data);

    PrintArray(Data);

    ReverseElementsOfArray(Data);

    PrintReversedArray(Data);

    return 0;
}

ArrayData ReadSizeOfArray(const std::string &Message)
{
    ArrayData Data;

    do{
        std::cout << Message;

        std::cin >> Data.SizeOfArray;

        if (Data.SizeOfArray < 1 || Data.SizeOfArray > 100)
        {
            std::cout << "Invalid size. Please enter a size between 1 and 100.\n";
        }
    } while (Data.SizeOfArray < 1 || Data.SizeOfArray > 100);

    return Data;
}

void RandomElementsOfArray(ArrayData &Data)
{
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Elements[i] = rand() % 101; // Random number between 0 and 100
    }
}

void PrintArray(ArrayData &Data)
{
    std::cout << "Elements of the array:\n";

    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.Elements[i] << " ";
    }
    std::cout << '\n';
}

void ReverseElementsOfArray(ArrayData &Data)
{
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.ReversedElements[i] = Data.Elements[Data.SizeOfArray - 1 - i];
    }
}

void PrintReversedArray(ArrayData &Data)
{
    std::cout << "Reversed elements of the array:\n";
    
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.ReversedElements[i] << " ";
    }
    std::cout << '\n';
}