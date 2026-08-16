// // Paper-Rock-Scissor

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <string>

// enum class Choice
// {
//     Rock = 1,
//     Paper = 2,
//     Scissors = 3
// };

// enum class RoundResult
// {
//     Tie,
//     PlayerWins,
//     ComputerWins
// };

// struct GameData
// {
//     int NumberOfRounds = 0;

//     int PlayerWins = 0;

//     int ComputerWins = 0;

//     int Ties = 0;
// };

// int ReadNumberOfRounds(const std::string &Message);

// Choice ReadPlayerChoice();

// Choice GenerateComputerChoice();

// std::string ChoiceToString(Choice PlayerChoice);

// RoundResult DetermineRoundWinner(Choice PlayerChoice, Choice ComputerChoice);

// void PlayRound(GameData &Data);

// void ShowComputerWinScreen();

// void ShowPlayerWinScreen();

// void ShowTieMessage();

// void PlayAllRounds(GameData &Data);

// void PrintGameResults(const GameData &Data);

// bool AskPlayAgain();

// int main(void)
// {
//     srand(static_cast<unsigned int>(time(0)));

//     bool KeepPlaying = true;

//     while (KeepPlaying)
//     {
//         GameData Data;

//         Data.NumberOfRounds = ReadNumberOfRounds("Enter how many rounds to play:\n");

//         PlayAllRounds(Data);

//         std::cout << "\n===== GAME OVER =====\n";

//         PrintGameResults(Data);

//         KeepPlaying = AskPlayAgain();
//     }

//     std::cout << "Thanks for playing!\n";

//     return 0;
// }

// int ReadNumberOfRounds(const std::string &Message)
// {
//     int NumberOfRounds = 0;

//     do
//     {
//         std::cout << Message;

//         std::cin >> NumberOfRounds;

//         if (NumberOfRounds < 1)
//         {
//             std::cout << "Invalid Input. Please enter a number greater than 0.\n";
//         }
//     } while (NumberOfRounds < 1);

//     return NumberOfRounds;
// }

// Choice ReadPlayerChoice()
// {
//     int Input = 0;

//     do
//     {
//         std::cout << "Choose (1) Rock, (2) Paper, (3) Scissors:\n";

//         std::cin >> Input;

//         if (Input < 1 || Input > 3)
//         {
//             std::cout << "Invalid Input. Please enter 1, 2, or 3.\n";
//         }
//     } while (Input < 1 || Input > 3);

//     return static_cast<Choice>(Input);
// }

// Choice GenerateComputerChoice()
// {
//     int Random = (rand() % 3) + 1;

//     return static_cast<Choice>(Random);
// }

// std::string ChoiceToString(Choice PlayerChoice)
// {
//     switch (PlayerChoice)
//     {
//         case Choice::Rock:
//             return "Rock";

//         case Choice::Paper:
//             return "Paper";

//         case Choice::Scissors:
//             return "Scissors";
//     }

//     return "Unknown";
// }

// RoundResult DetermineRoundWinner(Choice PlayerChoice, Choice ComputerChoice)
// {
//     if (PlayerChoice == ComputerChoice)
//     {
//         return RoundResult::Tie;
//     }

//     bool PlayerWinsRound =
//         (PlayerChoice == Choice::Rock && ComputerChoice == Choice::Scissors) ||
//         (PlayerChoice == Choice::Paper && ComputerChoice == Choice::Rock) ||
//         (PlayerChoice == Choice::Scissors && ComputerChoice == Choice::Paper);

//     if (PlayerWinsRound)
//     {
//         return RoundResult::PlayerWins;
//     }

//     return RoundResult::ComputerWins;
// }

// void ShowComputerWinScreen()
// {
//     std::cout << "\a";

//     std::cout << "\033[41m\033[97m";

//     std::cout << "\n           COMPUTER WINS THIS ROUND!           \n";

//     std::cout << "\033[0m\n";
// }

// void ShowPlayerWinScreen()
// {
//     std::cout << "\033[42m\033[97m";

//     std::cout << "\n             YOU WIN THIS ROUND!               \n";

//     std::cout << "\033[0m\n";
// }

// void ShowTieMessage()
// {
//     std::cout << "\nIt's a tie this round!\n\n";
// }

// void PlayRound(GameData &Data)
// {
//     Choice PlayerChoice = ReadPlayerChoice();

//     Choice ComputerChoice = GenerateComputerChoice();

//     std::cout << "\nYou chose: " << ChoiceToString(PlayerChoice) << '\n';

//     std::cout << "Computer chose: " << ChoiceToString(ComputerChoice) << '\n';

//     RoundResult Result = DetermineRoundWinner(PlayerChoice, ComputerChoice);

//     switch (Result)
//     {
//         case RoundResult::Tie:
//             ShowTieMessage();
//             Data.Ties++;
//             break;

//         case RoundResult::PlayerWins:
//             ShowPlayerWinScreen();
//             Data.PlayerWins++;
//             break;

//         case RoundResult::ComputerWins:
//             ShowComputerWinScreen();
//             Data.ComputerWins++;
//             break;
//     }
// }

// void PlayAllRounds(GameData &Data)
// {
//     for (int Round = 1; Round <= Data.NumberOfRounds; Round++)
//     {
//         std::cout << "\n----- Round " << Round << " of " << Data.NumberOfRounds << " -----\n";

//         PlayRound(Data);
//     }
// }

// void PrintGameResults(const GameData &Data)
// {
//     std::cout << "\nFinal Results:\n";

//     std::cout << "Rounds Played: " << Data.NumberOfRounds << '\n';

//     std::cout << "Player Wins:   " << Data.PlayerWins << '\n';

//     std::cout << "Computer Wins: " << Data.ComputerWins << '\n';

//     std::cout << "Ties:          " << Data.Ties << '\n';

//     if (Data.PlayerWins > Data.ComputerWins)
//     {
//         std::cout << "\nOverall Result: YOU WON THE GAME!\n";
//     }
//     else if (Data.ComputerWins > Data.PlayerWins)
//     {
//         std::cout << "\nOverall Result: COMPUTER WON THE GAME!\n";
//     }
//     else
//     {
//         std::cout << "\nOverall Result: IT'S AN OVERALL TIE!\n";
//     }
// }

// bool AskPlayAgain()
// {
//     char Answer = 'n';

//     std::cout << "\nDo you want to play again? (y/n):\n";

//     std::cin >> Answer;

//     return (Answer == 'y' || Answer == 'Y');
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>

enum Choice
{
    Paper = 1,
    Rock = 2,
    Scissor = 3
};

enum ChancesOfWin
{
    Tie,
    PlayerWins,
    ComputerWins
};

struct GameData
{
};

/*

*/