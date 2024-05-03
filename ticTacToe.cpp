#include <iostream>
#include <string>
using namespace std;

int gameGrid(string array[9], string player1, string player2)
{
    cout << "\n________________________________________\n\n" + player1 + ": O    " + player2 + ": X\n       |       |       \n   " + array[0] + "   |   " + array[1] + "   |   " + array[2] + "    \n       |       |        \n-------|-------|-------\n       |       |       \n   " + array[3] + "   |   " + array[4] + "   |   " + array[5] + "    \n       |       |        \n-------|-------|-------\n       |       |       \n   " + array[6] + "   |   " + array[7] + "   |   " + array[8] + "    \n       |       |        \n";
    return 0;
}

string whichPlayer(bool isPlayer1, string player1, string player2)
{
    if (isPlayer1 == true)
    {
        return player1;
    }
    else
    {
        return player2;
    }
}

int playerChoice(bool isPlayer1, string player1, string player2)
{
    int choice;
    cout << whichPlayer(isPlayer1, player1, player2) + ": Choose a grid number to play - ";
    cin >> choice;
    return choice;
}

string updateGameGrid(string currentGame[9], bool isPlayer1, string player1, string player2)
{
    string naughtOrCross;
    bool isValidChoice = false;
    if (isPlayer1 == true)
    {
        naughtOrCross = "O";
    }
    else
    {
        naughtOrCross = "X";
    }
    int gridNumber = playerChoice(isPlayer1, player1,player2) - 1;
    while (isValidChoice == false)
    {
        if (currentGame[gridNumber] == "O" || currentGame[gridNumber] == "X")
        {
            cout << "This grid number has already been chosen. Please choose another\n";
            gridNumber = playerChoice(isPlayer1, player1, player2) - 1;
        }
        else
        {
            currentGame[gridNumber] = naughtOrCross;
            isValidChoice = true;
        }
    }
    return currentGame[9];
}

bool gameStatus(string currentGame[9])
{
    bool isThereAWinner = false;
    if ((currentGame[0] == currentGame[1] && currentGame[1] == currentGame[2]) || (currentGame[3] == currentGame[4] && currentGame[4] == currentGame[5]) || (currentGame[6] == currentGame[7] && currentGame[7] == currentGame[8]))
    {
        isThereAWinner = true;
    }
    else if ((currentGame[0] == currentGame[3] && currentGame[3] == currentGame[6]) || (currentGame[1] == currentGame[4] && currentGame[4] == currentGame[7]) || (currentGame[2] == currentGame[5] && currentGame[5] == currentGame[8]))
    {
        isThereAWinner = true;
    }
    else if ((currentGame[0] == currentGame[4] && currentGame[4] == currentGame[8]) || (currentGame[2] == currentGame[4] && currentGame[4] == currentGame[6]))
    {
        isThereAWinner = true;
    }
    return isThereAWinner;
}

int main()
{
    bool gameFinished = false;
    bool isPlayer1 = true;
    string player1, player2, currentPlayer;
    string currentGame[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    cout << "\nPlayer 1: O    Player 2: X\n\n";
    cout << "Enter your name player 1: \n";
    cin >> player1;
    cout << "Enter your name player 2: \n";
    cin >> player2;

    gameGrid(currentGame, player1, player2);
    for (int i = 0; i < 9; i++)
    {
        updateGameGrid(currentGame, isPlayer1, player1, player2);
        gameFinished = gameStatus(currentGame);
        gameGrid(currentGame, player1, player2);
        if (gameFinished == true)
        {
            cout << "🎊🎊 ❌🔵Congratulations " + whichPlayer(isPlayer1, player1, player2) + " you have won the game 🎊🎊🎊\n";
            return 0;
        }
        isPlayer1 = !isPlayer1;
    }
    cout << "It's a DRAW!!!\n";
    return 0;
}
