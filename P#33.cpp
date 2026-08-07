#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

struct KeysData
{
    std::string Keys[100];

    int NumberOfKeys = 0;
};

KeysData ReadNumberOfKeys(const std::string &Message);

void FillArrayWithKeys(KeysData &Data);

std::string GenerateOneKey();

char RandomUppercaseLetter();

void PrintArrayOfKeys(KeysData &Data);

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    const std::string Message = "Enter how many keys to generate:\n";

    KeysData Data = ReadNumberOfKeys(Message);

    FillArrayWithKeys(Data);

    PrintArrayOfKeys(Data);

    return 0;
}

KeysData ReadNumberOfKeys(const std::string &Message)
{
    KeysData Data;

    do
    {
        std::cout << Message;

        std::cin >> Data.NumberOfKeys;

        if (Data.NumberOfKeys < 1 || Data.NumberOfKeys > 100)
        {
            std::cout << "Invalid number. Please enter a number between 1 and 100.\n";
        }

    } while (Data.NumberOfKeys < 1 || Data.NumberOfKeys > 100);

    return Data;
}

char RandomUppercaseLetter()
{
    return 'A' + (rand() % 26);
}

std::string GenerateOneKey()
{
    std::string Key = "";

    for (int Group = 0; Group < 4; Group++)
    {
        for (int Letter = 0; Letter < 4; Letter++)
        {
            Key += RandomUppercaseLetter();
        }

        if (Group != 3)
        {
            Key += '-';
        }
    }

    return Key;
}

void FillArrayWithKeys(KeysData &Data)
{
    for (int i = 0; i < Data.NumberOfKeys; i++)
    {
        Data.Keys[i] = GenerateOneKey();
    }
}

void PrintArrayOfKeys(KeysData &Data)
{
    std::cout << "\nArray elements:\n\n";

    for (int i = 0; i < Data.NumberOfKeys; i++)
    {
        std::cout << "Array[" << i + 1 << "]: " << Data.Keys[i] << '\n';
    }
}