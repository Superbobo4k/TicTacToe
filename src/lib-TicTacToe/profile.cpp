#include "profile.h"
#include "getch.h"

void profile(struct User account)
{
    system("clear");
    std::cout << "--------------- Profile ---------------" << std::endl;
    std::cout << "Username: " << account.username << std::endl;
    std::cout << "Times played: " << account.timesPlayed << std::endl;
    getch();
}
