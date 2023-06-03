#pragma once

#include <iostream>
#include <string>

void printMenu(
        std::string menuItems[], size_t menuItemCount, size_t menuItemIndex);
std::string menuItem(std::string menuItem, int menuWidth);
std::string menuItem(
        std::string menuItem,
        int menuWidth,
        std::string pointerLeft,
        std::string pointerRight);
int iterateMenu(char key, int menuItemCount, int menuItemIndex);
