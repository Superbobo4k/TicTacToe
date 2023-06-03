#pragma once

#include "struct.h"

#include <fstream>
#include <string>
#include <vector>

void exportDatabase(std::vector<User> users);
void syncAccount(std::vector<User>& users, struct User account);
