#include "printMenu.h"
#include "getch.h"

void printMenu(
        std::string menuItems[], size_t menuItemCount, size_t menuItemIndex)
{
    int menuWidth = 30;

    std::string gameName = "Tic Tac Toe";

    std::string pointerLeft = "-->";
    std::string pointerRight = "<--";

    system("clear");
    std::cout << std::string(menuWidth, '-') << std::endl
              << menuItem(gameName, menuWidth) << std::endl
              << std::string(menuWidth, '-') << std::endl;
    size_t i = 0;
    for (i = i; i < menuItemIndex; i++) {
        std::cout << menuItem(menuItems[i], menuWidth) << std::endl;
    }
    std::cout << menuItem(menuItems[i], menuWidth, pointerLeft, pointerRight)
              << std::endl;
    i++;
    for (i = i; i < menuItemCount; i++) {
        std::cout << menuItem(menuItems[i], menuWidth) << std::endl;
    }
}

std::string menuItem(std::string menuItem, int menuWidth)
{
    std::string space = std::string((menuWidth - menuItem.length()) / 2, ' ');
    return space + menuItem + space;
}

std::string menuItem(
        std::string menuItem,
        int menuWidth,
        std::string pointerLeft,
        std::string pointerRight)
{
    std::string spaceLeft = std::string(
            (menuWidth - menuItem.length()) / 2 - pointerLeft.length(), ' ');
    std::string spaceRight = std::string(
            (menuWidth - menuItem.length()) / 2 - pointerRight.length(), ' ');
    return spaceLeft + pointerLeft + menuItem + pointerRight + spaceRight;
}

int iterateMenu(char key, int menuItemCount, int menuItemIndex)
{
    getch();
    key = getch();
    if (key == 'A') {
        if (menuItemIndex == 0)
            menuItemIndex = menuItemCount - 1;
        else
            menuItemIndex--;
    }
    if (key == 'B') {
        if (menuItemIndex == menuItemCount - 1)
            menuItemIndex = 0;
        else
            menuItemIndex++;
    }
    return menuItemIndex;
}
