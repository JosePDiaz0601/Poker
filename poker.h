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
int main(int argc, char *argv[]);
void newRound();
char player1Name[16] = "";
char player2Name[16] = "";
char player3Name[16] = "";
char player4Name[16] = "";
char player5Name[16] = "";
char player6Name[16] = "";

struct CARD
{
    char suit;
    int type;
    char taken;
};

struct CARD dealer[52];
struct CARD river[5];
struct CARD player1[2];
struct CARD player2[2];
struct CARD player3[2];
struct CARD player4[2];
struct CARD player5[2];
struct CARD player6[2];

#endif
