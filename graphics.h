#ifndef GRAPHICS
#define GRAPHICS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <gtk/gtk.h>
#include <assert.h>
#include <math.h>

const char *Program;
char your1CardSuit;
char your1CardType;
char your2CardSuit;
char your2CardType;

   GtkWidget *Window, *layout;
  
   GtkWidget *background; //poker table background image
 
   GtkWidget *NewLabel;
 
GtkWidget *foldButton, *callButton, *raiseButton;
   GtkWidget *table;
   GtkWidget *pCard1, *pCard2;
   GtkWidget *o1Card1, *o1Card2, *o2Card1, *o2Card2, *o3Card1, *o3Card2, *o4Card1, *o4Card2, *o5Card1, *o5Card2; //opponents cards
   GtkWidget *tCard1, *tCard2, *tCard3, *tCard4, *tCard5;
 
   GtkWidget *tLabel, *pLabel; //just player and table label
   GtkWidget *white;

   GtkWidget *player1Score, *player2Score, *player3Score, *player4Score, *player5Score, *player6Score;

//Certain constants we want to define (window size etc.) should go here.
GtkWidget *CreateWindow(int *argc, char **argv[]);

void makeCards(char cardSuit, char cardType, GtkWidget *Card);
void UpdateWindow(void);
void clientFold();
#endif
