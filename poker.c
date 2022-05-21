// This file shall contain the main function for our poker game
#include "poker.h"
#include <time.h>

int players = 6;

void main()
{
    print("Welcome to poker, go fuck yourself");
    // Change this later so that player count isnt hardcoded
    startGame(players);
}

void startGame(int players)
{
    srand(time(0));
    int dealer = rand() % players;
}