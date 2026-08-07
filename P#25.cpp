#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

struct ArrayData
{
    int Elements[100] = {0};

    int Size = 0;

    int Min = 0;
};

ArrayData PrintSizeOfArray(const std::string &Message);

void RandomElementsOfArray(ArrayData &Data);

void FindMin(ArrayData &Data);

void PrintMin(ArrayData &Data);

int main(void)
{
    srand(static_cast<unsigned int>(time(0))); // call once in main, before any rand() calls

    const std::string Message = "Enter the size of the array\n";

    ArrayData Data = PrintSizeOfArray(Message);

    RandomElementsOfArray(Data);

    FindMin(Data);

    PrintMin(Data);

    return 0;
}

ArrayData PrintSizeOfArray(const std::string &Message)
{
    ArrayData Data;

    do
    {
        std::cout << Message;

        std::cin >> Data.Size;

    } while (Data.Size <= 0 || Data.Size > 100);

    return Data;
}

void RandomElementsOfArray(ArrayData &Data)
{
    std::cout << '\n';

    std::cout << "Array Elements:\n";

    for (int i = 0; i < Data.Size; i++)
    {
        Data.Elements[i] = rand() % 101;

        std::cout << Data.Elements[i] << " ";
    }

    std::cout << "\n";
}

void FindMin(ArrayData &Data)
{
    Data.Min = Data.Elements[0];

    for (int i = 1; i < Data.Size; i++)
    {
        if (Data.Elements[i] < Data.Min)
        {
            Data.Min = Data.Elements[i];
        }
    }
}

void PrintMin(ArrayData &Data)
{
    std::cout << "\nMinimum element: " << Data.Min << "\n";

    std::cout << "\n";
}