#pragma once

#include "struct.h"

#include <string>
#include <vector>

int menu(std::vector<User>& users, struct User account);
void printBoard(char board[9], std::string message);
void controls();
void creators();
