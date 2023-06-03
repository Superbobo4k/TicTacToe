#include "exportDatabase.h"
#include "getch.h"

#include <iostream>

void exportDatabase(std::vector<User> users)
{
    remove("data");
    std::ofstream file("data", std::ios::out | std::ios::binary);
    if (file) {
        std::string username;
        int usernameSize;
        std::string password;
        int passwordSize;
        int timesPlayed;

        size_t len = users.size();
        file.write((const char*)&len, sizeof(len));

        for (size_t i = 0; i < len; i++) {
            username = users[i].username;
            usernameSize = (username.size());
            file.write(reinterpret_cast<char*>(&usernameSize), sizeof(int));
            file.write(username.c_str(), usernameSize);

            password = users[i].password;
            passwordSize = (password.size());
            file.write(reinterpret_cast<char*>(&passwordSize), sizeof(int));
            file.write(password.c_str(), passwordSize);

            timesPlayed = users[i].timesPlayed;
            file.write((const char*)&timesPlayed, sizeof(timesPlayed));
        }

        file.close();
    }
}

void syncAccount(std::vector<User>& users, struct User account)
{
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].username == account.username) {
            users[i].timesPlayed = account.timesPlayed;
            break;
        }
    }
}
