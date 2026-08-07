#include <iostream>
#include <string>

struct ArrayData
{
    int Elements[100] = {0};

    int Size = 0;
};

ArrayData ReadArrayElements(const std::string &Message);

void PrintArray(const ArrayData &Data);

int GetNumberToCheck();

int CountOccurrences(const ArrayData &Data, int Number);

void PrintOccurrences(int Number, int Count);

int main(void)
{
    const std::string Message = "ممكن النمبر يا عنبر؟\n";

    ArrayData Data = ReadArrayElements(Message);

    PrintArray(Data);

    int Number = GetNumberToCheck();

    int Count = CountOccurrences(Data, Number);

    PrintOccurrences(Number, Count);

    return 0;
}

ArrayData ReadArrayElements(const std::string &Message)
{
    ArrayData Data;

    std::cout << Message;

    std::cin >> Data.Size;

    std::cout << "Enter Array Elements:\n";

    for (int i = 0; i < Data.Size; i++)
    {
        std::cout << "Element [" << std::to_string(i + 1) << "]: ";

        std::cin >> Data.Elements[i];
    }

    return Data;
}

void PrintArray(const ArrayData &Data)
{
    std::cout << "The Original Array:\n";

    for (int i = 0; i < Data.Size; i++)
    {
        std::cout << Data.Elements[i] << " ";
    }
}

int GetNumberToCheck()
{

    int Number = 0;

    std::cout << "\nEnter the number you want to check: ";

    std::cin >> Number;

    return Number;
}

int CountOccurrences(const ArrayData &Data, int Number)
{

    int Count = 0;

    for (int i = 0; i < Data.Size; i++)
    {
        if (Number == Data.Elements[i])
        {
            Count++;
        }
    }

    return Count;
}

void PrintOccurrences(int Number, int Count)
{
    std::cout << std::to_string(Number) << " is found " << std::to_string(Count) << " Time(s)\n";
}