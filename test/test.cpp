#include <../src/lib-tic-tac-toe/game.h>
#include <../src/lib-tic-tac-toe/menu.h>
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
