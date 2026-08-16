#include <iostream>
#include <sstream>
#include <string>

struct ArrayData
{
    int Elements[100] = {0};

    int SizeOfArray = 0;
};

ArrayData ReadArrayFromLine();

bool IsPalindrome(const ArrayData &Data);

void PrintArray(const ArrayData &Data);

void PrintPalindromeResult(bool Result);

int main(void)
{
    ArrayData Data = ReadArrayFromLine();

    PrintArray(Data);

    bool Result = IsPalindrome(Data);

    PrintPalindromeResult(Result);

    return 0;
}

ArrayData ReadArrayFromLine()
{
    ArrayData Data;

    std::string Line;

    std::getline(std::cin, Line);

    std::stringstream Stream(Line);

    int Value = 0;

    while (Stream >> Value && Data.SizeOfArray < 100)
    {
        Data.Elements[Data.SizeOfArray] = Value;

        Data.SizeOfArray++;
    }

    return Data;
}

bool IsPalindrome(const ArrayData &Data)
{
    int Left = 0;

    int Right = Data.SizeOfArray - 1;

    while (Left < Right)
    {
        if (Data.Elements[Left] != Data.Elements[Right])
        {
            return false;
        }

        Left++;

        Right--;
    }

    return true;
}

void PrintArray(const ArrayData &Data)
{
    for (int i = 0; i < Data.SizeOfArray; i++)
    {
        std::cout << Data.Elements[i];

        if (i != Data.SizeOfArray - 1)
        {
            std::cout << ' ';
        }
    }

    std::cout << '\n';
}

void PrintPalindromeResult(bool Result)
{
    if (Result)
    {
        std::cout << "Yes, That Array Is Palindrome.\n";
    }
    else
    {
        std::cout << "No, That Array Is Not Palindrome.\n";
    }
}