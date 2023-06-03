#include <../src/lib-TicTacToe/struct.h>

#include <../src/lib-TicTacToe/authorise.h>
#include <../src/lib-TicTacToe/exportDatabase.h>
#include <../src/lib-TicTacToe/game.h>
#include <../src/lib-TicTacToe/menu.h>
#include <../src/lib-TicTacToe/printMenu.h>

#include <../thirdparty/ctest.h>

CTEST(parsing_suite, centerMenuItem)
{
    // Given
    string s = "Start Game";
    int menuWidth = 30;

    // When
    string result = menuItem(s, menuWidth);

    // Then
    string expected = string(10, ' ') + "Start Game" + string(10, ' ');

    ASSERT_STR(expected.c_str(), result.c_str());
}

CTEST(parsing_suite, centerMenuItemSelected)
{
    // Given
    string s = "Instructions";
    int menuWidth = 30;
    string pointerLeft = "->";
    string pointerRight = "<-";

    // When
    string result = menuItem(s, menuWidth, pointerLeft, pointerRight);

    // Then
    string expected
            = string(7, ' ') + "->" + "Instructions" + "<-" + string(7, ' ');

    ASSERT_STR(expected.c_str(), result.c_str());
}

CTEST(arithmetic_suite, isFullTrue)
{
    // Given
    char board[9] = {'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X'};

    // When
    int result = isFull(board);

    // Then
    int expected = true;

    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, isFullFalse)
{
    // Given
    char board[9] = {' ', 'X', ' ', 'X', 'O', ' ', 'O', ' ', 'X'};

    // When
    int result = isFull(board);

    // Then
    int expected = false;

    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, isVictoryTrue)
{
    // Given
    char board[9] = {'X', 'O', ' ', ' ', 'X', ' ', 'O', ' ', 'X'};

    // When
    int result = isVictory(board);

    // Then
    int expected = true;

    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, isVictoryFalse)
{
    // Given
    char board[9] = {'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X'};

    // When
    int result = isVictory(board);

    // Then
    int expected = false;

    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, usernameMatchFalse)
{
    // Given
    std::vector<User> users(0);

    struct User t1;
    t1.username = "username-1";
    t1.password = "password-1";
    users.push_back(t1);

    struct User t2;
    t2.username = "username-2";
    t2.password = "password-2";
    users.push_back(t2);

    struct User t3;
    t3.username = "username-3";
    t3.password = "password-3";
    users.push_back(t3);

    std::string username = "username-2";

    // When
    int result = usernameMatch(users, username);

    // Then
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, usernameMatchTrue)
{
    // Given
    std::vector<User> users(0);
    std::string username = "username-2";

    // When
    int result = usernameMatch(users, username);

    // Then
    int expected = -1;

    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, syncAccount)
{
    // Given
    std::vector<User> users(0);

    struct User t1;
    t1.username = "username-1";
    t1.password = "password-1";
    t1.timesPlayed = 1;
    users.push_back(t1);

    struct User t2;
    t2.username = "username-2";
    t2.password = "password-2";
    t2.timesPlayed = 2;
    users.push_back(t2);

    struct User t3;
    t3.username = "username-3";
    t3.password = "password-3";
    t3.timesPlayed = 3;
    users.push_back(t3);

    struct User x;
    x.username = "username-3";
    x.password = "password-3";
    x.timesPlayed = 4;

    // When
    syncAccount(users, x);

    // Then
    int expected1 = t3.timesPlayed + 1;
    int expected2 = x.timesPlayed;

    ASSERT_EQUAL(expected1, expected2);
}
