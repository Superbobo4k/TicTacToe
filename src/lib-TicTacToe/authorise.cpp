#include "authorise.h"
#include "exportDatabase.h"
#include "getch.h"
#include "printMenu.h"

int authorise(std::vector<User>& users, struct User& account)
{
    size_t menuItemCount = 3;
    std::string menuItems[menuItemCount] = {"Login", "Register", "Quit"};
    size_t menuItemIndex = 0;
    do {
        printMenu(menuItems, menuItemCount, menuItemIndex);
        char key = getch();
        if (key == '\n') {
            if (menuItemIndex == 0) {
                if (loginUser(users, account))
                    return 1;
            }
            if (menuItemIndex == 1) {
                registerUser(users);
            }
            if (menuItemIndex == 2) {
                return 0;
            }
        }
        if (key == '\033')
            menuItemIndex = iterateMenu(key, menuItemCount, menuItemIndex);
    } while (1);
    return 0;
}

int loginUser(std::vector<User> users, struct User& account)
{
    std::string username;
    std::string password;
    int userIndex;
    do {
        username = "";
        password = "";
        do {
            system("clear");
            std::cout << "Username: " << username;
            char key = getch();
            if (key == '\n')
                break;
            if (key == 27)
                return 0;
            if (key == 127 || key == 8) {
                if (username.size() > 0)
                    username.pop_back();
            } else
                username += key;
        } while (true);

        std::cout << std::endl << "Password: ";
        do {
            char key = getch();
            if (key == '\n')
                break;
            if (key == 27)
                return 0;
            if (key == 127 || key == 8) {
                if (password.size() > 0)
                    password.pop_back();
            } else
                password += key;
        } while (true);

        userIndex = usernameMatch(users, username);
        if (userIndex > -1)
            if (users[userIndex].password == password)
                break;
    } while (true);

    account.username = users[userIndex].username;
    account.password = users[userIndex].password;
    account.timesPlayed = users[userIndex].timesPlayed;

    return 1;
}

int registerUser(std::vector<User>& users)
{
    std::string username;
    std::string password;
    int userIndex;
    do {
        username = "";
        password = "";
        do {
            system("clear");
            std::cout << "Username: " << username;
            char key = getch();
            if (key == '\n')
                break;
            if (key == 27)
                return 0;
            if (key == 127 || key == 8) {
                if (username.size() > 0)
                    username.pop_back();
            } else
                username += key;
        } while (true);

        std::cout << std::endl << "Password: ";
        do {
            char key = getch();
            if (key == '\n')
                break;
            if (key == 27)
                return 0;
            if (key == 127 || key == 8) {
                if (password.size() > 0)
                    password.pop_back();
            } else
                password += key;
        } while (true);

        userIndex = usernameMatch(users, username);
    } while (userIndex > -1);

    struct User t;
    t.username = username;
    t.password = password;

    users.push_back(t);

    exportDatabase(users);

    return 1;
}

int usernameMatch(std::vector<User> users, std::string username)
{
    for (size_t i = 0; i < users.size(); i++)
        if (users[i].username == username)
            return i;
    return -1;
}