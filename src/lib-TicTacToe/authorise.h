#pragma once

#include "struct.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int authorise(std::vector<User>& users, struct User& account);
int loginUser(std::vector<User> users, struct User& account);
int registerUser(std::vector<User>& users);
int usernameMatch(std::vector<User> users, std::string username);
