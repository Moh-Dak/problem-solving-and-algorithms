#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <limits>

enum class Answers
{
    Wrong = 0,
    Correct = 1
};

enum class Difficulty
{
    Easy = 1,
    Medium = 2,
    Hard = 3,
    Mix = 4,
};

enum class OperationTypes
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mix = 5,
};

enum class Result
{
    Pass,
    Fail
};

struct MathGameData
{
    std::string PlayerName = "";
    std::string PlayerNoun = "";
    int PlayerChoice = 0;
    int CorrectChoice = 0;

    int Rounds = 0;
    int CorrectCount = 0;
    int WrongCount = 0;
};

const std::string MaleNoun = "Mister";
const std::string FemaleNoun = "Miss";

// ---------- Helpers ----------

std::mt19937 &Rng()
{
    static std::mt19937 gen(std::random_device{}());
    return gen;
}

int RandomNumber(int from, int to)
{
    std::uniform_int_distribution<int> dist(from, to);
    return dist(Rng());
}

int ReadInt(const std::string &message, int min, int max)
{
    int value;
    while (true)
    {
        std::cout << message;
        if (std::cin >> value && value >= min && value <= max)
        {
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter a number between " << min << " and " << max << ".\n";
    }
}

char OperationSymbol(OperationTypes op)
{
    switch (op)
    {
    case OperationTypes::Add:
        return '+';
    case OperationTypes::Sub:
        return '-';
    case OperationTypes::Mul:
        return '*';
    case OperationTypes::Div:
        return '/';
    default:
        return '?';
    }
}

// ---------- Game steps ----------

void Greetings(MathGameData &data)
{
    std::cout << "=== Math Game ===\n";
    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, data.PlayerName);

    char gender = ' ';
    while (gender != 'M' && gender != 'F')
    {
        std::cout << "Are you male or female? (M/F): ";
        std::cin >> gender;
        gender = static_cast<char>(std::toupper(static_cast<unsigned char>(gender)));
    }
    data.PlayerNoun = (gender == 'M') ? MaleNoun : FemaleNoun;

    std::cout << "\nWelcome, " << data.PlayerNoun << " " << data.PlayerName << "!\n\n";
}

int ReadNumberOfRounds()
{
    return ReadInt("How many rounds do you want to play? (1-100): ", 1, 100);
}

Difficulty ReadDifficulty()
{
    int choice = ReadInt("Difficulty [1] Easy [2] Medium [3] Hard [4] Mix: ", 1, 4);
    return static_cast<Difficulty>(choice);
}

OperationTypes ChooseOperationType()
{
    int choice = ReadInt("Operation [1] Add [2] Sub [3] Mul [4] Div [5] Mix: ", 1, 5);
    return static_cast<OperationTypes>(choice);
}

// Resolves Mix into a concrete difficulty
Difficulty CheckForDifficulty(Difficulty difficulty)
{
    if (difficulty == Difficulty::Mix)
    {
        return static_cast<Difficulty>(RandomNumber(1, 3));
    }
    return difficulty;
}

int MaxForDifficulty(Difficulty difficulty)
{
    switch (difficulty)
    {
    case Difficulty::Easy:
        return 10;
    case Difficulty::Medium:
        return 50;
    case Difficulty::Hard:
        return 100;
    default:
        return 10;
    }
}

int GenerateRandomFirstNumber(Difficulty difficulty)
{
    return RandomNumber(1, MaxForDifficulty(difficulty));
}

int GenerateRandomSecondNumber(Difficulty difficulty)
{
    return RandomNumber(1, MaxForDifficulty(difficulty));
}

OperationTypes GenerateRandomOperationType()
{
    return static_cast<OperationTypes>(RandomNumber(1, 4));
}

OperationTypes GeneratedNonrandomOperationType(OperationTypes op)
{
    return op;
}

int CalculateOperations(int a, int b, OperationTypes op)
{
    switch (op)
    {
    case OperationTypes::Add:
        return a + b;
    case OperationTypes::Sub:
        return a - b;
    case OperationTypes::Mul:
        return a * b;
    case OperationTypes::Div:
        return a / b;
    default:
        return 0;
    }
}

Answers CheckForCorrectAnswer(const MathGameData &data)
{
    return (data.PlayerChoice == data.CorrectChoice) ? Answers::Correct : Answers::Wrong;
}

void NumberOfCorrectAnswers(const MathGameData &data)
{
    std::cout << "Correct answers: " << data.CorrectCount << "\n";
}

void NumberOfWrongAnswers(const MathGameData &data)
{
    std::cout << "Wrong answers:   " << data.WrongCount << "\n";
}

void CongratsForPassing(const MathGameData &data)
{
    std::cout << "\nCongratulations, " << data.PlayerNoun << " " << data.PlayerName
              << "! You passed!\n";
}

void SadForFailing(const MathGameData &data)
{
    std::cout << "\nSorry, " << data.PlayerNoun << " " << data.PlayerName
              << ". You failed. Better luck next time.\n";
}

void LoopsForRounds(MathGameData &data, Difficulty difficulty, OperationTypes opType)
{
    for (int round = 1; round <= data.Rounds; round++)
    {
        Difficulty currentDifficulty = CheckForDifficulty(difficulty);
        OperationTypes currentOp = (opType == OperationTypes::Mix)
                                       ? GenerateRandomOperationType()
                                       : GeneratedNonrandomOperationType(opType);

        int a = GenerateRandomFirstNumber(currentDifficulty);
        int b = GenerateRandomSecondNumber(currentDifficulty);

        // Keep subtraction non-negative
        if (currentOp == OperationTypes::Sub && a < b)
        {
            std::swap(a, b);
        }
        // Keep division clean (integer result)
        if (currentOp == OperationTypes::Div)
        {
            a = b * RandomNumber(1, 10);
        }

        data.CorrectChoice = CalculateOperations(a, b, currentOp);

        std::cout << "\nRound [" << round << "/" << data.Rounds << "]\n";
        std::cout << a << " " << OperationSymbol(currentOp) << " " << b << " = ";

        while (!(std::cin >> data.PlayerChoice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter a valid integer: ";
        }

        if (CheckForCorrectAnswer(data) == Answers::Correct)
        {
            data.CorrectCount++;
            std::cout << "Correct!\n";
        }
        else
        {
            data.WrongCount++;
            std::cout << "Wrong! The right answer is " << data.CorrectChoice << "\n";
        }
    }
}

void FinalResult(const MathGameData &data)
{
    std::cout << "\n=== Final Result ===\n";
    std::cout << "Rounds played:   " << data.Rounds << "\n";
    NumberOfCorrectAnswers(data);
    NumberOfWrongAnswers(data);

    // Pass if at least 50% correct
    Result result = (data.CorrectCount * 2 >= data.Rounds) ? Result::Pass : Result::Fail;

    if (result == Result::Pass)
    {
        CongratsForPassing(data);
    }
    else
    {
        SadForFailing(data);
    }
}

bool AskPlayAgain()
{
    char answer = ' ';
    while (answer != 'Y' && answer != 'N')
    {
        std::cout << "\nPlay again? (Y/N): ";
        std::cin >> answer;
        answer = static_cast<char>(std::toupper(static_cast<unsigned char>(answer)));
    }
    return answer == 'Y';
}

int main(void)
{
    MathGameData data;

    Greetings(data);

    do
    {
        data.CorrectCount = 0;
        data.WrongCount = 0;

        data.Rounds = ReadNumberOfRounds();
        Difficulty difficulty = ReadDifficulty();
        OperationTypes opType = ChooseOperationType();

        LoopsForRounds(data, difficulty, opType);
        FinalResult(data);
    } while (AskPlayAgain());

    std::cout << "\nThanks for playing, " << data.PlayerNoun << " " << data.PlayerName << "!\n";

    return 0;
}