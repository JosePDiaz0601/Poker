// Header file for poker.c
#ifndef POKERHEADER
#define POKERHEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void startGame(int players);

struct DECK
{
    struct CARD *first = NULL;
    struct CARD *last = NULL;
    int length;
};
struct CARD
{
    char suit;
    char type;
    struct CARD *next = NULL;
    struct CARD *prev = NULL;
    struct DECK *deck = NULL;
};

#endif
