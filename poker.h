// Header file for poker.c
//test
#ifndef POKERHEADER
#define POKERHEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void printDecks();
void startGame(int players);
int main(void);
void newRound();

struct CARD
{
    char suit;
    int type;
    char taken;
};

#endif
