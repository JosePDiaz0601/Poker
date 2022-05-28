// Header file for poker.c
// test
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
char player1Name[16];
char player2Name[16];
char player3Name[16];
char player4Name[16];
char player5Name[16];
char player6Name[16];
struct CARD
{
    char suit;
    int type;
    char taken;
};

#endif
