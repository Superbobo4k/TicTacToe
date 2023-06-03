#include "menu.h"
#include "exportDatabase.h"
#include "game.h"
#include "getch.h"
#include "printMenu.h"
#include "profile.h"

int menu(std::vector<User>& users, struct User account)
{
    size_t menuItemCount = 6;
    std::string menuItems[menuItemCount]
            = {"Play", "Profile", "Controls", "Creators", "Log out", "Quit"};
    size_t menuItemIndex = 0;
    do {
        printMenu(menuItems, menuItemCount, menuItemIndex);
        char key = getch();
        if (key == '\n') {
            if (menuItemIndex == 0) {
                char board[9];
                for (int i = 0; i < 9; i++)
                    board[i] = ' ';
                printBoard(board, game(board));
                account.timesPlayed++;
                syncAccount(users, account);
                exportDatabase(users);
            }
            if (menuItemIndex == 1) {
                profile(account);
            }
            if (menuItemIndex == 2) {
                controls();
            }
            if (menuItemIndex == 3) {
                creators();
            }
            if (menuItemIndex == 4) {
                return 1;
            }
            if (menuItemIndex == 5) {
                return 0;
            }
        }
        if (key == '\033')
            menuItemIndex = iterateMenu(key, menuItemCount, menuItemIndex);
    } while (true);
    return 0;
}

void controls()
{
    system("clear");
    std::cout << "--------------- Menu ---------------" << std::endl;
    std::cout << "ArrowUp - move up in menu" << std::endl;
    std::cout << "ArrowDown - move down in menu" << std::endl;
    std::cout << "Enter - submit" << std::endl;
    std::cout << "Esc - cancel" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------- Game ---------------" << std::endl;
    std::cout << "1-9 - put marker in corresponding field" << std::endl;
    getch();
}

void creators()
{
    system("clear");
    std::cout << "The amazing creators of this masterpiece:" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Andreas Vaybert IP211: " << std::endl;
    std::cout << "Pavel Tashlykov IP211: " << std::endl;
    std::cout << "Egor Shukin IP211: " << std::endl;
    getch();
}
