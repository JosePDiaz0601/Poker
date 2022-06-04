/* ClockServer.c: simple TCP/IP server example with timeout support
 * Author: Rainer Doemer, 2/17/15
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <assert.h>
#include "poker.h"


// do we need to include graphics.h?

/* #define DEBUG */	/* be verbose */

/*** type definitions ****************************************************/

typedef void (*ClientHandler)(int DataSocketFD);
typedef void (*TimeoutHandler)(void);

/*** global variables ****************************************************/

const char *Program	/* program name for descriptive diagnostics */
	= NULL;
int Shutdown		/* keep running until Shutdown == 1 */
	= 0;
char ClockBuffer[26]	/* current time in printable format */
	= "";

/*** global functions ****************************************************/

void FatalError(		/* print error diagnostics and abort */
	const char *ErrorMsg)
{
    fputs(Program, stderr);
    fputs(": ", stderr);
    perror(ErrorMsg);
    fputs(Program, stderr);
    fputs(": Exiting!\n", stderr);
    exit(20);
} /* end of FatalError */

// dont edit this fucntion
int MakeServerSocket(		/* create a socket on this server */ 
	uint16_t PortNo)
{
    int ServSocketFD;
    struct sockaddr_in ServSocketName;

    startGame(7);                             // THIS STARTS THE GAME!! REMEMBER!! NOT DOEMER CODE
    /* create the socket */
    ServSocketFD = socket(PF_INET, SOCK_STREAM, 0);
    if (ServSocketFD < 0)
    {   FatalError("service socket creation failed");
    }
    /* bind the socket to this server */
    ServSocketName.sin_family = AF_INET;
    ServSocketName.sin_port = htons(PortNo);
    ServSocketName.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(ServSocketFD, (struct sockaddr*)&ServSocketName,
		sizeof(ServSocketName)) < 0)
    {   FatalError("binding the server to a socket failed");
    }
    /* start listening to this socket */
    if (listen(ServSocketFD, 7) < 0)	/* max 5 clients in backlog */
    {   FatalError("listening on socket failed");
    }
    return ServSocketFD;
} /* end of MakeServerSocket */

// pretty sure you dont need this function (unless we want the time)
void PrintCurrentTime(void)	/*  print/update the current real time */
{
    time_t CurrentTime; /* seconds since 1970 (see 'man 2 time') */
    char   *TimeString;	/* printable time string (see 'man ctime') */
    char   Wheel,
	   *WheelChars = "|/-\\";
    static int WheelIndex = 0;

    CurrentTime = time(NULL);	/* get current real time (in seconds) */
    TimeString = ctime(&CurrentTime);	/* convert to printable format */
    strncpy(ClockBuffer, TimeString, 25);
    ClockBuffer[24] = 0;	/* remove unwanted '/n' at the end */
    WheelIndex = (WheelIndex+1) % 4;
    Wheel = WheelChars[WheelIndex];
    printf("\rClock: %s %c",	/* print from beginning of current line */
	ClockBuffer, Wheel);	/* print time plus a rotating wheel */
    fflush(stdout);
} /* end of PrintCurrentTime */

// edit this for your own program
void ProcessRequest(		/* process a time request by a client */
	int DataSocketFD)
{
    int  l, n;
    char RecvBuf[256];	/* message buffer for receiving a message */
    char SendBuf[256];	/* message buffer for sending a response */
    char PlayerBuf[256]; /* message buffer for sending all player names */
    char *tokenName;
    const char s[2] = " "; // stuff for token (victor)
    char *token;
    char *tokenSeatNum;
    int tokenSeatNumInt;
    char equal[3] = " = ";
    char clientname[16]; 
    char cardNum;

    n = read(DataSocketFD, RecvBuf, sizeof(RecvBuf)-1);
    if (n < 0) 
    {   FatalError("reading from data socket failed");
    }
    RecvBuf[n] = 0;
#ifdef DEBUG
    printf("%s: Received message: %s\n", Program, RecvBuf);
#endif
    // get cards each cilent has
    if (0 == strcmp(RecvBuf, "GET CARDS SEAT 1")){
        
        //strncpy(SendBuf, "Success", sizeof(SendBuf)-1);
        
        
        
        
        strncpy(SendBuf, "", sizeof(SendBuf)-1);
        //cardNum = ((int)river[0].type + '0');               // river card 1
        printf("\n RIVER FIRST CARD IS %c\n", river[0].suit);
        if(river[0].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(river[0].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(river[0].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(river[0].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        //strcat(SendBuf, cardNum);
        strcat(SendBuf, "1");
        if(river[1].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(river[1].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(river[1].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(river[1].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        //strcat(SendBuf, cardNum);
        strcat(SendBuf, "2");
        
        if(river[2].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(river[2].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(river[2].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(river[2].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        //strcat(SendBuf, cardNum);
        strcat(SendBuf, "3");
        if(river[3].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(river[3].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(river[3].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(river[3].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        //strcat(SendBuf, cardNum);
        strcat(SendBuf, "4");
        if(river[4].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(river[4].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(river[4].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(river[4].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        //strcat(SendBuf, cardNum);
        strcat(SendBuf, "5");
        if(player1[0].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player1[0].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player1[0].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player1[0].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        //strcat(SendBuf, cardNum);
        strcat(SendBuf, "6");
        if(player1[1].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player1[1].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player1[1].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player1[1].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        //strcat(SendBuf, cardNum);
        strcat(SendBuf, "7");
        
        SendBuf[sizeof(SendBuf)-1] = 0;

        
        
        //fixed code for river 
        cardNum = (int)river[0].type + '0';               // river card 1
        strncat(SendBuf, river[0].suit, sizeof(SendBuf)-1-strlen(SendBuf));  // card suit
        strncat(SendBuf, &cardNum, sizeof(SendBuf)-1-strlen(SendBuf));    // card type
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[1].type + '0';               // river card 2
        strncat(SendBuf, river[1].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[2].type + '0';               // river card 3
	    strncat(SendBuf, river[2].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '3', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[3].type + '0';               // player card 4
        strncat(SendBuf, river[3].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '4', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[4].type + '0';               // player card 5
        strncat(SendBuf, river[4].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '5', sizeof(SendBuf)-1-strlen(SendBuf));
	    
        cardNum = (int)player1[1].type + '0';               // player card 1
	    strncat(SendBuf, player1[1].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)player1[2].type + '0';               // player card 2
        strncat(SendBuf, player1[2].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));


        //SendBuf[sizeof(SendBuf)-1] = 0;
    }

    else if (0 == strcmp(RecvBuf, "GET CARDS SEAT 2")){
        strncpy(SendBuf, "OK SEAT 2 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;

        cardNum = (int)river[0].type + '0';               // river card 1
	    strncat(SendBuf, river[0].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[1].type + '0';               // river card 2
        strncat(SendBuf, river[1].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[2].type + '0';               // river card 3
	    strncat(SendBuf, river[2].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '3', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[3].type + '0';               // player card 4
        strncat(SendBuf, river[3].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '4', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[4].type + '0';               // player card 5
        strncat(SendBuf, river[4].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '5', sizeof(SendBuf)-1-strlen(SendBuf));
	    
        cardNum = (int)player2[1].type + '0';               // player card 1
	    strncat(SendBuf, player2[1].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)player2[2].type + '0';               // player card 2
        strncat(SendBuf, player2[2].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET CARDS SEAT 3")){
        strncpy(SendBuf, "OK SEAT 3 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
        
        cardNum = (int)river[0].type + '0';               // river card 1
	    strncat(SendBuf, river[0].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[1].type + '0';               // river card 2
        strncat(SendBuf, river[1].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[2].type + '0';               // river card 3
	    strncat(SendBuf, river[2].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '3', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[3].type + '0';               // player card 4
        strncat(SendBuf, river[3].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '4', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[4].type + '0';               // player card 5
        strncat(SendBuf, river[4].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '5', sizeof(SendBuf)-1-strlen(SendBuf));
	    
        cardNum = (int)player3[1].type + '0';               // player card 1
	    strncat(SendBuf, player3[1].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)player3[2].type + '0';               // player card 2
        strncat(SendBuf, player3[2].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET CARDS SEAT 4")){
        strncpy(SendBuf, "OK SEAT 4 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
        
        cardNum = (int)river[0].type + '0';               // river card 1
	    strncat(SendBuf, river[0].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[1].type + '0';               // river card 2
        strncat(SendBuf, river[1].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[2].type + '0';               // river card 3
	    strncat(SendBuf, river[2].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '3', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[3].type + '0';               // player card 4
        strncat(SendBuf, river[3].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '4', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[4].type + '0';               // player card 5
        strncat(SendBuf, river[4].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '5', sizeof(SendBuf)-1-strlen(SendBuf));
	    
        cardNum = (int)player4[1].type + '0';               // player card 1
	    strncat(SendBuf, player4[1].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)player4[2].type + '0';               // player card 2
        strncat(SendBuf, player4[2].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET CARDS SEAT 5")){
        strncpy(SendBuf, "OK SEAT 5 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
        
        cardNum = (int)river[0].type + '0';               // river card 1
	    strncat(SendBuf, river[0].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[1].type + '0';               // river card 2
        strncat(SendBuf, river[1].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[2].type + '0';               // river card 3
	    strncat(SendBuf, river[2].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '3', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[3].type + '0';               // player card 4
        strncat(SendBuf, river[3].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '4', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[4].type + '0';               // player card 5
        strncat(SendBuf, river[4].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '5', sizeof(SendBuf)-1-strlen(SendBuf));
	    
        cardNum = (int)player5[1].type + '0';               // player card 1
	    strncat(SendBuf, player5[1].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)player5[2].type + '0';               // player card 2
        strncat(SendBuf, player5[2].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET CARDS SEAT 6")){
        strncpy(SendBuf, "OK SEAT 6 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
        
        cardNum = (int)river[0].type + '0';               // river card 1
	    strncat(SendBuf, river[0].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[1].type + '0';               // river card 2
        strncat(SendBuf, river[1].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[2].type + '0';               // river card 3
	    strncat(SendBuf, river[2].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '3', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[3].type + '0';               // player card 4
        strncat(SendBuf, river[3].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '4', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)river[4].type + '0';               // player card 5
        strncat(SendBuf, river[4].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '5', sizeof(SendBuf)-1-strlen(SendBuf));
        
        cardNum = (int)player6[1].type + '0';               // player card 1
	    strncat(SendBuf, player6[1].suit, sizeof(SendBuf)-1-strlen(SendBuf)); 
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '1', sizeof(SendBuf)-1-strlen(SendBuf));
        cardNum = (int)player6[2].type + '0';               // player card 2
        strncat(SendBuf, player6[2].suit, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, cardNum, sizeof(SendBuf)-1-strlen(SendBuf));
        strncat(SendBuf, '2', sizeof(SendBuf)-1-strlen(SendBuf));
    }
/*
    // get value of points a cilent has
    if (0 == strcmp(RecvBuf, "GET POINTS SEAT 1")){
        strncpy(SendBuf, "OK SEAT 1 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    strncat(SendBuf, /* need function to get buffer for points , sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET POINTS SEAT 2")){
        strncpy(SendBuf, "OK SEAT 2 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    strncat(SendBuf, /* need function to get buffer for points , sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET POINTS SEAT 3")){
        strncpy(SendBuf, "OK SEAT 3 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    strncat(SendBuf, /* need function to get buffer for points , sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET POINTS SEAT 4")){
        strncpy(SendBuf, "OK SEAT 4 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    strncat(SendBuf, /* need function to get buffer for points , sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET POINTS SEAT 5")){
        strncpy(SendBuf, "OK SEAT 5 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    strncat(SendBuf, /* need function to get buffer for points , sizeof(SendBuf)-1-strlen(SendBuf)); 
    }

    else if (0 == strcmp(RecvBuf, "GET POINTS SEAT 6")){
        strncpy(SendBuf, "OK SEAT 6 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    strncat(SendBuf, /* need function to gezbuffer for points , sizeof(SendBuf)-1-strlen(SendBuf)); 
    }
*/

/*   WE DONT NEED TO DO GET SEAT 1 ANYMORE
    // This is for getting information for each client seat
    if (0 == strcmp(RecvBuf, "GET SEAT 1")){
        strncpy(SendBuf, "OK SEAT 1 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    //strncat(SendBuf, player1Name, sizeof(SendBuf)-1-strlen(SendBuf));   // NOW I NEED TO GET THE VALUE OF PLAYER CARDS 
        }

    else if (0 == strcmp(RecvBuf, "GET SEAT 2")){
        strncpy(SendBuf, "OK SEAT 2 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    //strncat(SendBuf, player2Name, sizeof(SendBuf)-1-strlen(SendBuf)); 
        }

    else if (0 == strcmp(RecvBuf, "GET SEAT 3")){
        strncpy(SendBuf, "OK SEAT 3 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    //strncat(SendBuf, player3Name, sizeof(SendBuf)-1-strlen(SendBuf)); 
        }

    else if (0 == strcmp(RecvBuf, "GET SEAT 4")){
        strncpy(SendBuf, "OK SEAT 4 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    //strncat(SendBuf, player4Name, sizeof(SendBuf)-1-strlen(SendBuf)); 
        }

    else if (0 == strcmp(RecvBuf, "GET SEAT 5")){
        strncpy(SendBuf, "OK SEAT 5 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    //strncat(SendBuf, player5Name, sizeof(SendBuf)-1-strlen(SendBuf)); 
        }

    else if (0 == strcmp(RecvBuf, "GET SEAT 6")){
        strncpy(SendBuf, "OK SEAT 6 =", sizeof(SendBuf)-1);
    	SendBuf[sizeof(SendBuf)-1] = 0;
	    //strncat(SendBuf, player6Name, sizeof(SendBuf)-1-strlen(SendBuf)); 
        }
*/

    // parsing RecvBuf string for non hardcodeable string inputs
    token = strtok(RecvBuf, s); 
    if (0 == strcmp(token, "ENTER")){
        tokenName = strtok(NULL, s);    // name of the cilent
        token = strtok(NULL, s);    // seat
            if (0 == strcmp(token, "SEAT")){
                token = strtok(NULL, s);    // seat number
                int tokenNum = 0;
                tokenNum = (int)((char)(token[0])) - 48;         // making token into a int, store in new var tokenNum
                //convert ASCII char whose value is a number to an int
                    for (int i=1; i<7; i++){
                        if(tokenNum == i){
                            strncpy(SendBuf, "OK SEAT", sizeof(SendBuf)-1);
	                        SendBuf[sizeof(SendBuf)-1] = 0;
                            if(i == 1){                      // assigning the player name to a global char varaible in poker.h
//                                *player1Name = tokenName;       // can we assign a pointer *tokenname to the global char player1Name[16]?
                                size_t token_destination_size = sizeof(tokenName);
                                strncpy(player1Name, tokenName, token_destination_size);
                                player1Name[token_destination_size - 1] = '0';
                                strcat(PlayerBuf, player1Name); 
                            }
                            else if(i == 2){
//                                *player2Name = tokenName;
                                size_t token_destination_size = sizeof(tokenName);
                                strncpy(player2Name, tokenName, token_destination_size);
                                player2Name[token_destination_size - 1] = '0';
                                strcat(PlayerBuf, player1Name);
                            }
                            else if(i == 3){
//                                *player3Name = tokenName;
                                size_t token_destination_size = sizeof(tokenName);
                                strncpy(player3Name, tokenName, token_destination_size);
                                player3Name[token_destination_size - 1] = '0';
                                strcat(PlayerBuf, player1Name);
                            }
                            else if(i == 4){
//                                *player4Name = tokenName;
                                size_t token_destination_size = sizeof(tokenName);
                                strncpy(player4Name, tokenName, token_destination_size);
                                player4Name[token_destination_size - 1] = '0';
                                strcat(PlayerBuf, player1Name);
                            }
                            else if(i == 5){
//                                *player5Name = tokenName;
                                size_t token_destination_size = sizeof(tokenName);
                                strncpy(player5Name, tokenName, token_destination_size);
                                player5Name[token_destination_size - 1] = '0';
                                strcat(PlayerBuf, player1Name);
                            }
                            else if(i == 6){
//                                *player6Name = tokenName;
                                size_t token_destination_size = sizeof(tokenName);
                                strncpy(player6Name, tokenName, token_destination_size);
                                player6Name[token_destination_size - 1] = '0';
                                strcat(PlayerBuf, player1Name);
                            };

                            // WE DONT NEED TO DO THIS CAT
                    //        strncat(SendBuf, token[0], sizeof(SendBuf)-1-strlen(SendBuf));
                    //        strncat(SendBuf, , sizeof(SendBuf)-1-strlen(SendBuf));
                    //        strncat(SendBuf, tokenName, sizeof(SendBuf)-1-strlen(SendBuf));
                            // the message send would be OK SEAT (number) = (cilentname) 
                        }
                        else{
                            continue;
                        }
                    }
            }
        while(1){
            switch(token[0]){
            case 'R':
                token = strtok(NULL, s);
                tokenSeatNum = strtok(NULL, s);
                tokenSeatNumInt = (int)((char)(tokenSeatNum[0])) - 48;
                //  function_for_Raise()
               break;
            case 'F':
                token = strtok(NULL, s);
                tokenSeatNum = strtok(NULL, s);
                tokenSeatNumInt = (int)((char)(tokenSeatNum[0])) - 48;
                //  function_for_fold()
                break;
            case 'C':
                token = strtok(NULL, s);
                tokenSeatNum = strtok(NULL, s);
                tokenSeatNumInt = (int)((char)(tokenSeatNum[0])) - 48;
                call(tokenSeatNumInt);
                break;
            }
        }
    }

    if (0 == strcmp(RecvBuf, "READY")){
        strcat(SendBuf, PlayerBuf);
    }

/*
    if (0 == strcmp(RecvBuf, "TIME"))
    {   strncpy(SendBuf, "OK TIME: ", sizeof(SendBuf)-1);
	SendBuf[sizeof(SendBuf)-1] = 0;
	strncat(SendBuf, ClockBuffer, sizeof(SendBuf)-1-strlen(SendBuf));
    }
    else if (0 == strcmp(RecvBuf, "SHUTDOWN"))
    {   Shutdown = 1;
	strncpy(SendBuf, "OK SHUTDOWN", sizeof(SendBuf)-1);
	SendBuf[sizeof(SendBuf)-1] = 0;
    }
    else
    {   strncpy(SendBuf, "ERROR unknown command ", sizeof(SendBuf)-1);
	SendBuf[sizeof(SendBuf)-1] = 0;
	strncat(SendBuf, RecvBuf, sizeof(SendBuf)-1-strlen(SendBuf));
    }
    l = strlen(SendBuf);
    */
#ifdef DEBUG
    printf("%s: Sending response: %s.\n", Program, SendBuf);
#endif
    l = strlen(SendBuf);
    n = write(DataSocketFD, SendBuf, l);
    if (n < 0)
    {   FatalError("writing to data socket failed");
    }
} /* end of ProcessRequest */

// dont need to edit this function
void ServerMainLoop(		/* simple server main loop */
	int ServSocketFD,		/* server socket to wait on */
	ClientHandler HandleClient,	/* client handler to call */
	TimeoutHandler HandleTimeout,	/* timeout handler to call */
	int Timeout)			/* timeout in micro seconds */
{
    int DataSocketFD;	/* socket for a new client */
    socklen_t ClientLen;
    struct sockaddr_in
	ClientAddress;	/* client address we connect with */
    fd_set ActiveFDs;	/* socket file descriptors to select from */
    fd_set ReadFDs;	/* socket file descriptors ready to read from */
    struct timeval TimeVal;
    int res, i;

    FD_ZERO(&ActiveFDs);		/* set of active sockets */
    FD_SET(ServSocketFD, &ActiveFDs);	/* server socket is active */
    while(!Shutdown)
    {   ReadFDs = ActiveFDs;
	TimeVal.tv_sec  = Timeout / 1000000;	/* seconds */
	TimeVal.tv_usec = Timeout % 1000000;	/* microseconds */
	/* block until input arrives on active sockets or until timeout */
	res = select(FD_SETSIZE, &ReadFDs, NULL, NULL, &TimeVal);
	if (res < 0)
	{   FatalError("wait for input or timeout (select) failed");
	}
	if (res == 0)	/* timeout occurred */
	{
#ifdef DEBUG
	    printf("%s: Handling timeout...\n", Program);
#endif
	    HandleTimeout();
	}
	else		/* some FDs have data ready to read */
	{   for(i=0; i<FD_SETSIZE; i++)
	    {   if (FD_ISSET(i, &ReadFDs))
		{   if (i == ServSocketFD)
		    {	/* connection request on server socket */
#ifdef DEBUG
			printf("%s: Accepting new client %d...\n", Program, i);
#endif
			ClientLen = sizeof(ClientAddress);
			DataSocketFD = accept(ServSocketFD,
				(struct sockaddr*)&ClientAddress, &ClientLen);
			if (DataSocketFD < 0)
			{   FatalError("data socket creation (accept) failed");
			}
#ifdef DEBUG
			printf("%s: Client %d connected from %s:%hu.\n",
				Program, i,
				inet_ntoa(ClientAddress.sin_addr),
				ntohs(ClientAddress.sin_port));
#endif
			FD_SET(DataSocketFD, &ActiveFDs);
		    }
		    else
		    {   /* active communication with a client */
#ifdef DEBUG
			printf("%s: Dealing with client %d...\n", Program, i);
#endif
			HandleClient(i);
#ifdef DEBUG
			printf("%s: Closing client %d connection.\n", Program, i);
#endif
			close(i);
			FD_CLR(i, &ActiveFDs);
		    }
		}
	    }
	}
    }
} /* end of ServerMainLoop */

/*** main function *******************************************************/


// dont know if we need to edit or not
int main(int argc, char *argv[])
{
    int ServSocketFD;	/* socket file descriptor for service */
    int PortNo;		/* port number */

    Program = argv[0];	/* publish program name (for diagnostics) */
#ifdef DEBUG
    printf("%s: Starting...\n", Program);
#endif
    if (argc < 2)
    {   fprintf(stderr, "Usage: %s port\n", Program);
	exit(10);
    }
    PortNo = atoi(argv[1]);	/* get the port number */
    if (PortNo <= 2000)
    {   fprintf(stderr, "%s: invalid port number %d, should be >2000\n",
		Program, PortNo);
        exit(10);
    }
#ifdef DEBUG
    printf("%s: Creating the server socket...\n", Program);
#endif
    ServSocketFD = MakeServerSocket(PortNo);
    printf("%s: Providing current time at port %d...\n", Program, PortNo);
    ServerMainLoop(ServSocketFD, ProcessRequest,
			PrintCurrentTime, 250000);
    printf("\n%s: Shutting down.\n", Program);
    close(ServSocketFD);
    return 0;
}

/* EOF ClockServer.c */
