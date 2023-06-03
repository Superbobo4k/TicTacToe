#pragma once

#include <string>

struct User {
    std::string username;
    std::string password;
    int timesPlayed = 0;
};
