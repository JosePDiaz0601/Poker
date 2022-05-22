// Header file for poker.c
#ifndef POKERHEADER
#define POKERHEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void startGame(int players);
void main();
void newRound();

struct CARD
{
    char suit;
    int type;
    char taken;
};

#endif
