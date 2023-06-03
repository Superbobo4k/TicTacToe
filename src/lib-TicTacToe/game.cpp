#include "game.h"
#include "getch.h"

void printBoard(char board[9], int playerTurn)
{
    system("clear");
    cout << "      ##########################################" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ## This is the standard pattern. Please ##" << endl;
    cout << "      ## enter the number of place where you  ##" << endl;
    cout << "      ##      want to place your symbol       ##" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | 7 | 8 | 9 |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | 4 | 5 | 6 |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | 1 | 2 | 3 |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##########################################" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##           Player " << playerTurn
         << " turn:             ##" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | " << board[6] << " | " << board[7] << " | "
         << board[8] << " |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | " << board[3] << " | " << board[4] << " | "
         << board[5] << " |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | " << board[0] << " | " << board[1] << " | "
         << board[2] << " |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##########################################" << endl;
}

void printBoard(char board[9], string message)
{
    string line;
    if (message == "Draw")
        line = "      ##                 Draw                 ##";
    else
        line = "      ##        " + message + "        ##";
    system("clear");
    cout << "      ##########################################" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ## This is the standard pattern. Please ##" << endl;
    cout << "      ## enter the number of place where you  ##" << endl;
    cout << "      ##      want to place your symbol       ##" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | 7 | 8 | 9 |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | 4 | 5 | 6 |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | 1 | 2 | 3 |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##########################################" << endl;
    cout << "      ##                                      ##" << endl;
    cout << line << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | " << board[6] << " | " << board[7] << " | "
         << board[8] << " |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | " << board[3] << " | " << board[4] << " | "
         << board[5] << " |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##            | " << board[0] << " | " << board[1] << " | "
         << board[2] << " |             ##" << endl;
    cout << "      ##            +---+---+---+             ##" << endl;
    cout << "      ##                                      ##" << endl;
    cout << "      ##########################################" << endl;
}

string game(char board[9])
{
    int playerTurn;
    do {
        playerTurn = 1;
        turn(board, playerTurn);
        if (isVictory(board) || isFull(board))
            break;
        playerTurn = 2;
        turn(board, playerTurn);
        if (isVictory(board) || isFull(board))
            break;
    } while (true);
    if (isVictory(board)) {
        string s = to_string(playerTurn);
        return "Victory! Player " + s + " won!";
    } else
        return "Draw";
}

void turn(char board[9], int playerTurn)
{
    printBoard(board, playerTurn);
    char symbols[2] = {'X', 'O'};
    char ch;
    do {
        ch = getch();
    } while (board[((int)ch - 48) - 1] != ' ');
    board[((int)ch - 48) - 1] = symbols[playerTurn - 1];
}

bool isFull(char board[9])
{
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool isVictory(char board[9])
{
    for (int i = 0; i < 9; i += 3)
        if (((board[i]) == (board[i + 1])) && ((board[i + 1]) == (board[i + 2]))
            && ((board[i + 2]) != (' ')))
            return true;
    for (int i = 0; i < 3; i++)
        if (((board[i] == board[i + 3])) && ((board[i + 3] == board[i + 6]))
            && ((board[i + 6]) != (' ')))
            return true;
    if (((board[0]) == (board[4])) && ((board[4] == board[8]))
        && ((board[8]) != (' ')))
        return true;
    if (((board[2]) == (board[4])) && ((board[4]) == (board[6]))
        && ((board[6]) != (' ')))
        return true;
    return false;
}
