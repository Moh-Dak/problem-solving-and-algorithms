#include <iostream>
#include <cstdlib>
#include <ctime>

struct RandomArrayData
{
    int SizeOfArray = 0;

    int Elements[100] = {0};
};

int ReadSizeOfArray(const std::string &Message);

int ReadNumberToSearch(const std::string &Message);

void FillArrayWithRandomNumbers(RandomArrayData &Data);

bool SearchForNumberInArray(const RandomArrayData &Data, int NumberToSearch);

void DisplayArray(const RandomArrayData &Data);

void DisplaySearchResult(bool Found, int NumberToSearch);

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    // Step 1: get the size, build the struct
    RandomArrayData Data;

    Data.SizeOfArray = ReadSizeOfArray("Enter the size of the array (1-100):\n");

    // Step 2: fill it (this function ONLY fills, nothing else)
    FillArrayWithRandomNumbers(Data);

    // Step 3: show what got generated (only once)
    DisplayArray(Data);

    // Step 4: ask what to search for (real input, not a placeholder)
    int NumberToSearch = ReadNumberToSearch("Enter a number to search for in the array:\n");

    // Step 5: search returns the real answer instead of printing internally
    bool Found = SearchForNumberInArray(Data, NumberToSearch);

    // Step 6: exactly one function is responsible for reporting the result
    DisplaySearchResult(Found, NumberToSearch);

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

int ReadNumberToSearch(const std::string &Message)
{
    int NumberToSearch = 0;

    std::cout << Message;
    std::cin >> NumberToSearch;

    return NumberToSearch;
}

void FillArrayWithRandomNumbers(RandomArrayData &Data)
{
    // Only fills. No printing, no searching, no user prompts here.
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        Data.Elements[i] = rand() % 101; // random number 0-100
    }
}

bool SearchForNumberInArray(const RandomArrayData &Data, int NumberToSearch)
{
    // Only searches and returns the result. Doesn't print anything itself.
    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        if (Data.Elements[i] == NumberToSearch)
        {
            return true; // found it, no need to keep looping
        }
    }

    return false; // looped through everything, never matched
}

void DisplayArray(const RandomArrayData &Data)
{
    std::cout << "Array elements:\n";

    for (int i = 0; i < Data.SizeOfArray; ++i)
    {
        std::cout << Data.Elements[i] << " ";
    }

    std::cout << "\n";
}

void DisplaySearchResult(bool Found, int NumberToSearch)
{
    // The ONLY place that reports the search outcome, using the real result.
    if (Found)
    {
        std::cout << "Number " << NumberToSearch << " was found in the array.\n";
    }
    else
    {
        std::cout << "Number " << NumberToSearch << " was not found in the array.\n";
    }
}