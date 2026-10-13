#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cstdint>
#include <limits>
#include <cctype>
#include <algorithm>

enum class Choice : uint8_t
{
    Paper = 1,

    Rock = 2,

    Scissor = 3
};

enum class RoundResult
{
    Tie,

    PlayerWins,

    ComputerWins
};

struct GameData
{
    int RoundsNumber = 0;

    int PlayerWins = 0;

    int ComputerWins = 0;

    int Ties = 0;
};

void ClearInputLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ReadRoundsNumber(const std::string &Message, const std::string &username)
{
    int RoundsNumber = 1;

    do
    {
        std::cout << Message;

        std::cin >> RoundsNumber;

        std::cout << "\n\n";

        if (std::cin.fail())
        {
            std::cin.clear();

            ClearInputLine();

            std::cout << "Sorry, Mister " << username << " ... A Number Between (1-10)";

            std::cout << '\n';

            std::cout << "Not A Character !";

            std::cout << "\n\n";

            continue;
        }

        ClearInputLine();

        if (RoundsNumber <= 0 || RoundsNumber > 10)
        {
            std::cout << '\n';

            std::cout << "In The (1-10) Range, Please";

            std::cout << "\n\n";

            continue;
        }

    } while (RoundsNumber <= 0 || RoundsNumber > 10);

    return RoundsNumber;
}

Choice ReadPlayersPick(const std::string &username)
{
    int PlayersChoice = 0;

    std::cout << "Choose Wisely:\n(1) For Paper\n(2) For Rock\n(3) For Scissor";

    std::cout << "\n\n";

    std::cout << "Now Is Your Choice, Mister " << username << ": ";

    std::cout << "\n\n";

    int TriesNumber = 0;

    do
    {
        std::cin >> PlayersChoice;

        if (std::cin.fail())
        {

            std::cin.clear();

            ClearInputLine();

            if (TriesNumber == 3)
            {
                std::cout << "That Is Enough !!!";

                std::cout << "\n\n";

                break;
            }

            std::cout << "\n\n";

            std::cout << "I Beg Your Pardon ...";

            std::cout << "\n\n";

            std::cout << "Mister " << username << ", Do You Have An Idiot Uncle ?";

            std::cout << "\n\n";

            std::cout << "I Have Just Told Above What Inputs You Should Enter !";

            std::cout << "\n\n";

            std::cout << "Take A Small Look At Them Once Again";

            std::cout << "\n\n";

            TriesNumber++;

            continue;
        }

        ClearInputLine();

        if (PlayersChoice < 1 || PlayersChoice > 3)
        {
            if (TriesNumber == 3)
            {
                std::cout << "That Is Enough !!!";

                std::cout << "\n\n";

                break;
            }

            std::cout << "Oh God ...";

            std::cout << "\n";

            std::cout << "Mister " << username << ", Could You Please Look At The Instruction Above ?";

            std::cout << '\n';

            std::cout << "And Correct Your Mistake ...";

            std::cout << "\n\n";

            TriesNumber++;

            continue;
        }

        TriesNumber++;

    } while (PlayersChoice < 1 || PlayersChoice > 3);

    return static_cast<Choice>(PlayersChoice);
}

Choice GenerateComputerPick()
{
    std::cout << "\n\n";

    std::cout << "And The Computer Choice is: ";

    int ComputerChoice = (rand() % 3) + 1;

    std::cout << ComputerChoice;

    std::cout << "\n\n";

    return static_cast<Choice>(ComputerChoice);
}

std::string ChoicesToString(Choice PlayersChoice)
{
    switch (PlayersChoice)
    {
    case Choice::Paper:
        return "Paper";
        break;
    case Choice::Rock:
        return "Rock";
        break;
    case Choice::Scissor:
        return "Scissor";
        break;
    }

    return "Unknown";
}

bool CheckForTies(Choice &PlayersChoice, Choice &ComputerChoice)
{
    return (PlayersChoice == ComputerChoice ? true : false);
}

RoundResult DetermineRoundWinner(Choice &PlayersChoice, Choice &ComputerChoice, const std::string &username)
{
    if (CheckForTies(PlayersChoice, ComputerChoice))
    {
        return RoundResult::Tie;
    }

    bool PlayerWinsRound =
        (PlayersChoice == Choice::Paper && ComputerChoice == Choice::Rock) ||
        (PlayersChoice == Choice::Rock && ComputerChoice == Choice::Scissor) ||
        (PlayersChoice == Choice::Scissor && ComputerChoice == Choice::Paper);

    if (PlayerWinsRound)
    {
        return RoundResult::PlayerWins;
    }

    return RoundResult::ComputerWins;
}

void ShowComputerWinScreen()
{
    std::cout << '\a';

    std::cout << "\033[41m\033[97m";

    std::cout << '\n';

    std::cout << "           COMPUTER WINS THIS ROUND!           ";

    std::cout << '\n';

    std::cout << "\033[0m\n";
}

void ShowPlayerWinScreen(std::string username)
{
    for (size_t Letter = 0; Letter < username.length(); Letter++)
    {
        username[Letter] = std::toupper(username[Letter]);
    }

    std::cout << "\033[42m\033[97m";

    std::cout << '\n';

    std::cout << "           MISTER " << username << " WINS THIS ROUND!           ";

    std::cout << '\n';

    std::cout << "\033[0m\n";
}

void ShowTieMessage()
{
    std::cout << "\nIt's a tie this round!\n\n";
}

void GamePlay(GameData &Data, const std::string &username)
{
    Choice PlayerChoice = ReadPlayersPick(username);

    Choice ComputerChoice = GenerateComputerPick();

    std::cout << '\n';

    std::cout << "Mister " << username << ", ";

    std::cout << "You Chose: ";

    std::cout << ChoicesToString(PlayerChoice) << '\n';

    std::cout << "\nComputer Chose: ";

    std::cout << ChoicesToString(ComputerChoice) << '\n';

    RoundResult Result = DetermineRoundWinner(PlayerChoice, ComputerChoice, username);

    switch (Result)
    {
    case RoundResult::Tie:
        ShowTieMessage();
        Data.Ties++;
        break;
    case RoundResult::PlayerWins:
        ShowPlayerWinScreen(username);
        Data.PlayerWins++;
        break;
    case RoundResult::ComputerWins:
        ShowComputerWinScreen();
        Data.ComputerWins++;
        break;
    }
}

void RoundsLoop(GameData &Data, const std::string &username)
{
    for (int Round = 1; Round <= Data.RoundsNumber; Round++)
    {
        std::cout << "\n----- Round " << Round << " of " << Data.RoundsNumber << " -----\n";

        GamePlay(Data, username);
    }
}

void PrintGameResults(GameData &Data)
{
    std::cout << "\nFinal Result:";

    std::cout << '\n';

    std::cout << "Rounds Played:    " << Data.RoundsNumber;

    std::cout << '\n';

    std::cout << "Player Wins:      " << Data.PlayerWins;

    std::cout << '\n';

    std::cout << "Computer Wins:    " << Data.ComputerWins;

    std::cout << '\n';

    std::cout << "Ties:             " << Data.Ties;

    std::cout << '\n';

    if (Data.PlayerWins > Data.ComputerWins)
    {
        std::cout << '\n';

        std::cout << "Overall Result: YOU WON THE GAME !";

        std::cout << '\n';
    }

    else if (Data.ComputerWins > Data.PlayerWins)
    {
        std::cout << '\n';

        std::cout << "Overall Result: COMPUTER WON THE GAME !";

        std::cout << '\n';
    }

    else
    {
        std::cout << '\n';

        std::cout << "Overall Result: IT IS AN OVERALL TIE !";

        std::cout << '\n';
    }
}

bool AskPlayAgain()
{
    char Answer = ' ';
    do
    {
        std::cout << '\n';

        std::cout << "Do You Want To Play Again ?";

        std::cout << " (y/n):";

        std::cout << '\n';

        std::cin >> Answer;

        if (std::cin.fail())
        {
            std::cin.clear();

            std::cout << "";

            continue;
        }

        ClearInputLine();

    } while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');

    return (Answer == 'y' || Answer == 'Y');
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);

    srand(static_cast<unsigned int>(time(0)));

    std::cout << "\nWELCOME FOR PAPER ROCK SCISSOR GAME CHALLENGE !!!" << "\n\n";

    std::cout << "Are You Ready To Beat Our Advanced AI That Reads Your Mind In Seconds !" << "\n\n";

    std::cout << "And Learn From Its Mistakes Immediately !" << "\n\n";

    std::cout << "Let Us See Then How Good You Are, Mister ...";

    std::cout << "\n\n";

    std::cout << "*Whispering* Mister what please? \n";

    std::string username;

    std::cout << "\n\n";

    std::cin >> username;

    ClearInputLine();

    std::cout << "\n\n";

    std::cout << "Yes, Mister " << username << " !";

    std::cout << "\n\n";

    std::cout << "AND FOR NOW ... HERE WE START IN OUR JOURNEY !!!";

    std::cout << "\n\n\n";

    bool KeepPlaying = true;

    const std::string Message = "Enter the number of the rounds: ";

    while (KeepPlaying)
    {
        GameData Data;

        Data.RoundsNumber = ReadRoundsNumber(Message, username);

        RoundsLoop(Data, username);

        std::cout << "\n\n";

        std::cout << "===== GAME OVER =====";

        std::cout << "\n\n";

        PrintGameResults(Data);

        KeepPlaying = AskPlayAgain();
    }

    std::cout << "\n\n";

    std::cout << "Thanks For Playing, Mister ";

    std::cout << username << '\n';

    return 0;
}
