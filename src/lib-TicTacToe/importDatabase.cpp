#include "importDatabase.h"
#include "getch.h"

#include <iostream>

void importDatabase(std::vector<User>& users)
{
    std::ifstream file("data", std::ios::out | std::ios::binary);
    if (file) {
        char* buffer;

        int usernameSize = 0;
        int passwordSize = 0;

        char ch;
        file.read(&ch, sizeof(size_t));
        int len = (int)ch;

        for (int i = 0; i < len; i++) {
            struct User t;

            file.read(reinterpret_cast<char*>(&usernameSize), sizeof(int));
            buffer = new char[usernameSize];
            file.read(buffer, usernameSize);
            std::string username = "";
            username.append(buffer, usernameSize);
            t.username = username;

            file.read(reinterpret_cast<char*>(&passwordSize), sizeof(int));
            buffer = new char[passwordSize];
            file.read(buffer, passwordSize);
            std::string password = "";
            password.append(buffer, passwordSize);
            t.password = password;

            char timesPlayedCh;
            file.read(&timesPlayedCh, sizeof(size_t));
            int timesPlayed = (int)timesPlayedCh;
            t.timesPlayed = timesPlayed;

            users.push_back(t);
        }
        file.close();
    }
}
