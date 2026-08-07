#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

struct ArrayData
{
    int Elements[100] = {0};

    int Size = 0;
};

ArrayData PrintSizeOfArray(const std::string &Message);

void RandomElementsOfArray(ArrayData &Data);

void PrintRandomArrayElements(ArrayData &Data);

int main(void)
{
    srand(static_cast<unsigned int>(time(0))); // call once in main, before any rand() calls

    const std::string Message = "Enter the size of the array\n";

    ArrayData Data = PrintSizeOfArray(Message);

    RandomElementsOfArray(Data);

    PrintRandomArrayElements(Data);

    return 0;
}

ArrayData PrintSizeOfArray(const std::string &Message)
{
    ArrayData Data;

    std::cout << Message;

    std::cin >> Data.Size;

    return Data;
}

void RandomElementsOfArray(ArrayData &Data)
{
    std::cout<<'\n';

    std::cout << "Array Elements:\n";

    for (int i = 0; i < Data.Size; i++)
    {
        Data.Elements[i] = rand() % 101;
    }
}

void PrintRandomArrayElements(ArrayData &Data) {

    for (int i = 0; i < Data.Size; i++)
    {
        std::cout << Data.Elements[i] << " ";
    }

    std::cout << "\n\n";
}