#pragma once

#include <iostream>
#include <string>

using namespace std;

string game(char board[9]);
void printBoard(char board[9], int playerTurn);
void printBoard(char board[9], int playerTurn, string message);
void turn(char board[9], int playerTurn);
bool isFull(char board[9]);
bool isVictory(char board[9]);
