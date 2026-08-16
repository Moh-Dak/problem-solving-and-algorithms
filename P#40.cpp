/*
    write a program to fill array with numbers from user input, and then print the distinct numbers to another array.

    output:
    Original Array Elements:
    10 10 10 50 50 70 70 70 70 90

    Distinct Elements Array:
    10 50 70 90
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct DynamicArray
{
    int *Data;
    int Count;
    int Capacity;
};

DynamicArray CreateArray(int InitialCapacity);

void AddElement(DynamicArray &Arr, int Value);

DynamicArray FillArray();

void PrintArray(const DynamicArray &Arr, std::string Label);

DynamicArray GetDistinctElements(const DynamicArray &Arr);
int GetAndUpdateRunCount();

int main()
{

    int RunCount = GetAndUpdateRunCount();

    std::cout << "This program has been run " << RunCount << " time(s)." << std::endl;

    DynamicArray OriginalArray = FillArray();

    PrintArray(OriginalArray, "Original Array Elements:");

    DynamicArray DistinctArray = GetDistinctElements(OriginalArray);

    PrintArray(DistinctArray, "Distinct Elements Array:");

    delete[] OriginalArray.Data;

    delete[] DistinctArray.Data;

    return 0;
}

DynamicArray CreateArray(int InitialCapacity)
{
    DynamicArray Arr;
    Arr.Data = new int[InitialCapacity];
    Arr.Count = 0;
    Arr.Capacity = InitialCapacity;

    return Arr;
}

void AddElement(DynamicArray &Arr, int Value)
{
    if (Arr.Count == Arr.Capacity)
    {
        int NewCapacity = Arr.Capacity * 2;
        int *NewData = new int[NewCapacity];

        for (int i = 0; i < Arr.Count; i++)
        {
            NewData[i] = Arr.Data[i];
        }

        delete[] Arr.Data;

        Arr.Data = NewData;
        Arr.Capacity = NewCapacity;
    }

    Arr.Data[Arr.Count] = Value;
    Arr.Count++;
}

DynamicArray FillArray()
{
    DynamicArray Arr = CreateArray(4);

    std::cout << "Enter numbers (press Enter on an empty line to stop):" << std::endl;

    std::string Line;

    while (true)
    {
        std::getline(std::cin, Line);

        if (Line.empty())
        {
            break;
        }

        std::stringstream LineStream(Line);

        int Value;

        while (LineStream >> Value)
        {
            AddElement(Arr, Value);
        }
    }

    return Arr;
}

void PrintArray(const DynamicArray &Arr, std::string Label)
{
    std::cout << Label << std::endl;

    for (int i = 0; i < Arr.Count; i++)
    {
        std::cout << Arr.Data[i] << " ";
    }

    std::cout << std::endl;
}

DynamicArray GetDistinctElements(const DynamicArray &Arr)
{
    DynamicArray Result = CreateArray(4);

    for (int i = 0; i < Arr.Count; i++)
    {
        bool Found = false;

        for (int j = 0; j < Result.Count; j++)
        {
            if (Arr.Data[i] == Result.Data[j])
            {
                Found = true;
                break;
            }
        }

        if (!Found)
        {
            AddElement(Result, Arr.Data[i]);
        }
    }

    return Result;
}

int GetAndUpdateRunCount()
{
    int Count = 0;

    std::ifstream InputFile("run_count.txt");

    if (InputFile.is_open())
    {
        InputFile >> Count;
    }

    InputFile.close();

    Count++;

    std::ofstream OutputFile("run_count.txt");

    OutputFile << Count;

    OutputFile.close();

    return Count;
}