#include "../lib-TicTacToe/authorise.h"
#include "../lib-TicTacToe/importDatabase.h"
#include "../lib-TicTacToe/menu.h"
int main()
{
    struct User account;
    int loggedOut;
    do {
        loggedOut = 0;
        std::vector<User> users(0);
        importDatabase(users);
        if (authorise(users, account)) {
            loggedOut = menu(users, account);
        }

    } while (loggedOut);

    return 0;
}