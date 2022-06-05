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
int currentPotAmount = 0;
int currentBetAmount = 0;
/*
char player1Name[16] = "\0";
char player2Name[16] = "\0";
char player3Name[16] = "\0";
char player4Name[16] = "\0";
char player5Name[16] = "\0";
char player6Name[16] = "\0";
*/

struct CARD
{
    char suit;
    int type;
    char taken;
};

struct PLAYERDATA
{
    char playerName[16];
    int points;
    bool hasFolded;
    bool connected;
};

struct CARD dealer[52];
struct CARD river[5];
struct CARD player1[2];
struct CARD player2[2];
struct CARD player3[2];
struct CARD player4[2];
struct CARD player5[2];
struct CARD player6[2];
struct PLAYERDATA player1data = {NULL, 1000, '0', '0'};
struct PLAYERDATA player2data = {NULL, 1000, '0', '0'};
struct PLAYERDATA player3data = {NULL, 1000, '0', '0'};
struct PLAYERDATA player4data = {NULL, 1000, '0', '0'};
struct PLAYERDATA player5data = {NULL, 1000, '0', '0'};
struct PLAYERDATA player6data = {NULL, 1000, '0', '0'};

// player1data.playerName = "Test";

const char *riverStringCat(int i, char *SendBuf);
#endif
