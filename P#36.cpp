// #include <iostream>

// const int MaxSize = 100;

// struct ArrayData
// {
//     int Elements[100];
//     int Length;
// };

// ArrayData ReadNumbers();
// void PrintArray(const ArrayData &Data);

// int main()
// {
//     ArrayData Data = ReadNumbers();

//     PrintArray(Data);

//     return 0;
// }

// ArrayData ReadNumbers()
// {
//     ArrayData Data;
//     Data.Length = 0;

//     char Choice = 'y';

//     while (Choice == 'y' && Data.Length < MaxSize)
//     {
//         std::cout << "Enter a number: ";
//         std::cin >> Data.Elements[Data.Length];
//         Data.Length++;

//         std::cout << std::endl;

//         std::cout << "Do you want to add more numbers? (y/n): ";
//         std::cin >> Choice;

//         std::cout << std::endl;
//     }

//     return Data;
// }

// void PrintArray(const ArrayData &Data)
// {
//     std::cout << "array length: " << Data.Length << std::endl;
//     std::cout << "array elements: ";

//     for (int i = 0; i < Data.Length; i++)
//     {
//         std::cout << Data.Elements[i] << " ";
//     }

//     std::cout << std::endl;
// }

#include <iostream>

const int MaxSize = 100;

struct ArrayData
{
    int Elements[100];
    int Length;
};

int ReadOneNumber();

char AskToContinue();

void AddNumber(ArrayData &Data, int Number);

ArrayData ReadNumbers();

void PrintLength(const ArrayData &Data);

void PrintElements(const ArrayData &Data);

void PrintArray(const ArrayData &Data);

int main()
{
    ArrayData Data = ReadNumbers();

    PrintArray(Data);

    return 0;
}

int ReadOneNumber()
{
    int Number;

    std::cout << "Enter a number: ";

    std::cin >> Number;

    return Number;
}

char AskToContinue()
{
    char Choice;

    std::cout << std::endl;

    std::cout << "Do you want to add more numbers? (y/n): ";

    std::cin >> Choice;

    std::cout << std::endl;

    return Choice;
}

void AddNumber(ArrayData &Data, int Number)
{
    Data.Elements[Data.Length] = Number;

    Data.Length++;
}

ArrayData ReadNumbers()
{
    ArrayData Data;

    Data.Length = 0;

    char Choice = 'y';

    while (Choice == 'y' && Data.Length < MaxSize)
    {
        int Number = ReadOneNumber();

        AddNumber(Data, Number);

        Choice = AskToContinue();
    }

    return Data;
}

void PrintLength(const ArrayData &Data)
{
    std::cout << "array length: " << Data.Length << std::endl;
}

void PrintElements(const ArrayData &Data)
{
    std::cout << "array elements: ";

    for (int i = 0; i < Data.Length; i++)
    {
        std::cout << Data.Elements[i] << " ";
    }

    std::cout << std::endl;
}

void PrintArray(const ArrayData &Data)
{
    PrintLength(Data);

    PrintElements(Data);
}