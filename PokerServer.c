/* PokerServer.c: simple TCP/IP server example with timeout support
 * This file has been adapted to fit the needs of the socket communication
 * that is used between client and server for our poker game.
 * Author: Victor Dam, Arhant Katare
 * Based on code from Rainer Doemer in ClockClient.c
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
int hasGameStarted = 0;
char ClockBuffer[26]	/* current time in printable format */
	= "";
players = 0;
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

    //Updated from Doemer's outline, Delimiter for changes from skeleton code
                                 // THIS STARTS THE GAME!! REMEMBER!!
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
    static char RecvBuf[256];	/* message buffer for receiving a message */
    static char TempRecvBuf[256]; // temperary RecvBuf for comparison (for ENTER, NAME comparisons)
    static char Temp2RecvBuf[256];  // another temp RecvBuf for comparison (for RAISE)
    static char SendBuf[256];	/* message buffer for sending a response */
    static char PlayerBuf[256]; /* message buffer for sending all player names */
    char *tokenName;
    const char s[2] = " "; // stuff for token (victor)
    char *token;
    char *tokenSeatNum;
    char playerseatchar;    // for call, raise, and fold
    int playerseatint;      // for call, raise, and fold
    int pointsraised;       // amount of points raised
    int tokenSeatNumInt;
    int tokenSeatNumClient; // this is the seat number that is saved in client side 
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
    if (0 == strcmp(RecvBuf, "READY")){
        if(hasGameStarted == 0){
        startGame(players);
        hasGameStarted++;
        }
        //strncpy(SendBuf, "Success", sizeof(SendBuf)-1);
        
        strncpy(SendBuf, "", sizeof(SendBuf)-1);
        //cardNum = ((int)river[0].type + '0');               // river card 1
        printf("\n FIRST CARD IS %c%d\n", river[0].suit, river[0].type);
        strcat(SendBuf, "0");
        for(int i = 0; i <= 4; i++){
        
        if(river[i].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(river[i].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(river[i].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(river[i].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        if(river[i].type == 2)
        {
            strcat(SendBuf, "2"); 
        }
        if(river[i].type == 3)
        {
            strcat(SendBuf, "3"); 
        }
        if(river[i].type == 4)
        {
            strcat(SendBuf, "4"); 
        }
        if(river[i].type == 5)
        {
            strcat(SendBuf, "5"); 
        }
        if(river[i].type == 6)
        {
            strcat(SendBuf, "6"); 
        }
        if(river[i].type == 7)
        {
            strcat(SendBuf, "7"); 
        }
        if(river[i].type == 8)
        {
            strcat(SendBuf, "8"); 
        }
        if(river[i].type == 9)
        {
            strcat(SendBuf, "9"); 
        }
        if(river[i].type == 10)
        {
            strcat(SendBuf, "T"); 
        }
        if(river[i].type == 11)
        {
            strcat(SendBuf, "J"); 
        }
        if(river[i].type == 12)
        {
            strcat(SendBuf, "Q"); 
        }
        if(river[i].type == 13)
        {
            strcat(SendBuf, "K"); 
        }
        if(river[i].type == 14)
        {
            strcat(SendBuf, "A"); 
        }
        }
        printf("passed river statement\n");
        for(int i = 0; i <= 1; i++){
        if(player1[i].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player1[i].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player1[i].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player1[i].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        if(player1[i].type == 2)
        {
            strcat(SendBuf, "2"); 
        }
        if(player1[i].type == 3)
        {
            strcat(SendBuf, "3"); 
        }
        if(player1[i].type == 4)
        {
            strcat(SendBuf, "4"); 
        }
        if(player1[i].type == 5)
        {
            strcat(SendBuf, "5"); 
        }
        if(player1[i].type == 6)
        {
            strcat(SendBuf, "6"); 
        }
        if(player1[i].type == 7)
        {
            strcat(SendBuf, "7"); 
        }
        if(player1[i].type == 8)
        {
            strcat(SendBuf, "8"); 
        }
        if(player1[i].type == 9)
        {
            strcat(SendBuf, "9"); 
        }
        if(player1[i].type == 10)
        {
            strcat(SendBuf, "T"); 
        }
        if(player1[i].type == 11)
        {
            strcat(SendBuf, "J"); 
        }
        if(player1[i].type == 12)
        {
            strcat(SendBuf, "Q"); 
        }
        if(player1[i].type == 13)
        {
            strcat(SendBuf, "K"); 
        }
        if(player1[i].type == 14)
        {
            strcat(SendBuf, "A"); 
        }
        }
        printf("passed p1 statement\n");
        for(int i = 0; i <= 1; i++){
        if(player2[i].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player2[i].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player2[i].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player2[i].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        if(player2[i].type == 2)
        {
            strcat(SendBuf, "2"); 
        }
        if(player2[i].type == 3)
        {
            strcat(SendBuf, "3"); 
        }
        if(player2[i].type == 4)
        {
            strcat(SendBuf, "4"); 
        }
        if(player2[i].type == 5)
        {
            strcat(SendBuf, "5"); 
        }
        if(player2[i].type == 6)
        {
            strcat(SendBuf, "6"); 
        }
        if(player2[i].type == 7)
        {
            strcat(SendBuf, "7"); 
        }
        if(player2[i].type == 8)
        {
            strcat(SendBuf, "8"); 
        }
        if(player2[i].type == 9)
        {
            strcat(SendBuf, "9"); 
        }
        if(player2[i].type == 10)
        {
            strcat(SendBuf, "T"); 
        }
        if(player2[i].type == 11)
        {
            strcat(SendBuf, "J"); 
        }
        if(player2[i].type == 12)
        {
            strcat(SendBuf, "Q"); 
        }
        if(player2[i].type == 13)
        {
            strcat(SendBuf, "K"); 
        }
        if(player2[i].type == 14)
        {
            strcat(SendBuf, "A"); 
        }
        }
printf("passed p2 statement\n");
        for(int i = 0; i <= 1; i++){
        if(player3[i].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player3[i].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player3[i].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player3[i].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        if(player3[i].type == 2)
        {
            strcat(SendBuf, "2"); 
        }
        if(player3[i].type == 3)
        {
            strcat(SendBuf, "3"); 
        }
        if(player3[i].type == 4)
        {
            strcat(SendBuf, "4"); 
        }
        if(player3[i].type == 5)
        {
            strcat(SendBuf, "5"); 
        }
        if(player3[i].type == 6)
        {
            strcat(SendBuf, "6"); 
        }
        if(player3[i].type == 7)
        {
            strcat(SendBuf, "7"); 
        }
        if(player3[i].type == 8)
        {
            strcat(SendBuf, "8"); 
        }
        if(player3[i].type == 9)
        {
            strcat(SendBuf, "9"); 
        }
        if(player3[i].type == 10)
        {
            strcat(SendBuf, "T"); 
        }
        if(player3[i].type == 11)
        {
            strcat(SendBuf, "J"); 
        }
        if(player3[i].type == 12)
        {
            strcat(SendBuf, "Q"); 
        }
        if(player3[i].type == 13)
        {
            strcat(SendBuf, "K"); 
        }
        if(player3[i].type == 14)
        {
            strcat(SendBuf, "A"); 
        }
        }
        printf("passed p3 statement\n");

                for(int i = 0; i <= 1; i++){
        if(player4[i].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player4[i].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player4[i].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player4[i].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        if(player4[i].type == 2)
        {
            strcat(SendBuf, "2"); 
        }
        if(player4[i].type == 3)
        {
            strcat(SendBuf, "3"); 
        }
        if(player4[i].type == 4)
        {
            strcat(SendBuf, "4"); 
        }
        if(player4[i].type == 5)
        {
            strcat(SendBuf, "5"); 
        }
        if(player4[i].type == 6)
        {
            strcat(SendBuf, "6"); 
        }
        if(player4[i].type == 7)
        {
            strcat(SendBuf, "7"); 
        }
        if(player4[i].type == 8)
        {
            strcat(SendBuf, "8"); 
        }
        if(player4[i].type == 9)
        {
            strcat(SendBuf, "9"); 
        }
        if(player4[i].type == 10) 
        {
            strcat(SendBuf, "T"); 
        }
        if(player4[i].type == 11)
        {
            strcat(SendBuf, "J"); 
        }
        if(player4[i].type == 12)
        {
            strcat(SendBuf, "Q"); 
        }
        if(player4[i].type == 13)
        {
            strcat(SendBuf, "K"); 
        }
        if(player4[i].type == 14)
        {
            strcat(SendBuf, "A"); 
        }
        }
        printf("passed p4 statement\n");

                for(int i = 0; i <= 1; i++){
        if(player5[i].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player5[i].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player5[i].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player5[i].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        if(player5[i].type == 2)
        {
            strcat(SendBuf, "2"); 
        }
        if(player5[i].type == 3)
        {
            strcat(SendBuf, "3"); 
        }
        if(player5[i].type == 4)
        {
            strcat(SendBuf, "4"); 
        }
        if(player5[i].type == 5)
        {
            strcat(SendBuf, "5"); 
        }
        if(player5[i].type == 6)
        {
            strcat(SendBuf, "6"); 
        }
        if(player5[i].type == 7)
        {
            strcat(SendBuf, "7"); 
        }
        if(player5[i].type == 8)
        {
            strcat(SendBuf, "8"); 
        }
        if(player5[i].type == 9)
        {
            strcat(SendBuf, "9"); 
        }
        if(player5[i].type == 10)
        {
            strcat(SendBuf, "T"); 
        }
        if(player5[i].type == 11)
        {
            strcat(SendBuf, "J"); 
        }
        if(player5[i].type == 12)
        {
            strcat(SendBuf, "Q"); 
        }
        if(player5[i].type == 13)
        {
            strcat(SendBuf, "K"); 
        }
        if(player5[i].type == 14)
        {
            strcat(SendBuf, "A"); 
        }
        }
        printf("passed p5 statement\n");

        for(int i = 0; i <= 1; i++){
        if(player6[i].suit == 'H')
        {
            strcat(SendBuf, "H"); 
        }
        if(player6[i].suit == 'D')
        {
            strcat(SendBuf, "D"); 
        }
        if(player6[i].suit == 'S')
        {
            strcat(SendBuf, "S"); 
        }
        if(player6[i].suit == 'C')
        {
            strcat(SendBuf, "C"); 
        }
        if(player6[i].type == 2)
        {
            strcat(SendBuf, "2"); 
        }
        if(player6[i].type == 3)
        {
            strcat(SendBuf, "3"); 
        }
        if(player6[i].type == 4)
        {
            strcat(SendBuf, "4"); 
        }
        if(player6[i].type == 5)
        {
            strcat(SendBuf, "5"); 
        }
        if(player6[i].type == 6)
        {
            strcat(SendBuf, "6"); 
        }
        if(player6[i].type == 7)
        {
            strcat(SendBuf, "7"); 
        }
        if(player6[i].type == 8)
        {
            strcat(SendBuf, "8"); 
        }
        if(player6[i].type == 9)
        {
            strcat(SendBuf, "9"); 
        }
        if(player6[i].type == 10)
        {
            strcat(SendBuf, "T"); 
        }
        if(player6[i].type == 11)
        {
            strcat(SendBuf, "J"); 
        }
        if(player6[i].type == 12)
        {
            strcat(SendBuf, "Q"); 
        }
        if(player6[i].type == 13)
        {
            strcat(SendBuf, "K"); 
        }
        if(player6[i].type == 14)
        {
            strcat(SendBuf, "A"); 
        }
        }
        SendBuf[sizeof(SendBuf)-1] = 0;
        
    }
printf("%s\n", SendBuf);
    // parsing RecvBuf string for string inputs
if(strlen(RecvBuf) >= 1){
    strcpy(TempRecvBuf, RecvBuf);
    strcpy(Temp2RecvBuf, RecvBuf);
    token = strtok(TempRecvBuf, s); 
    // setting seat number of client
    if (0 == strcmp(token, "ENTER")){
        tokenSeatNum = strtok(NULL, s);
        tokenSeatNumClient = (int)((char)(tokenSeatNum[0])) - 48;
        if (tokenSeatNumClient == 1){
            if (player1data.playerSeat == 0){
                player1data.playerSeat = tokenSeatNumClient;
                strcpy(SendBuf, "You are now assigned to Seat 1, use command NAME (PLAYER NAME) to enter name (wihtout parenthesis)");
                players++;
                }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
                }
        }
        else if(tokenSeatNumClient == 2){
            if (player2data.playerSeat == 0){
                player2data.playerSeat = tokenSeatNumClient;
                strcpy(SendBuf, "You are now assigned to Seat 2, use command NAME (PLAYER NAME) to enter name (wihtout parenthesis)");
                players++;
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 3){
            if (player3data.playerSeat == 0){
                player3data.playerSeat = tokenSeatNumClient;
                strcpy(SendBuf, "You are now assigned to Seat 3, use command NAME (PLAYER NAME) to enter name (wihtout parenthesis)");
                players++;
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 4){
            if (player4data.playerSeat == 0){
                player4data.playerSeat = tokenSeatNumClient;
                strcpy(SendBuf, "You are now assigned to Seat 4, use command NAME (PLAYER NAME) to enter name (wihtout parenthesis)");
                players++;
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 5){
            if (player5data.playerSeat == 0){
                 player5data.playerSeat = tokenSeatNumClient;
                 strcpy(SendBuf, "You are now assigned to Seat 5, use command NAME (PLAYER NAME) to enter name (wihtout parenthesis)");
                 players++;
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 6){
            if (player6data.playerSeat == 0){
                 player6data.playerSeat = tokenSeatNumClient;
                 strcpy(SendBuf, "You are now assigned to Seat 6, use command NAME (PLAYER NAME) to enter name (wihtout parenthesis)");
                 players++;
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
    }

    // this is for setting name of client
    else if (0 == strcmp(token, "NAME")){
        tokenName = strtok(NULL, s);
        if (tokenSeatNumClient == 1){
            if (player1data.playerName == ""){
                size_t token_destination_size = sizeof(tokenName);                              
                strncpy(player1data.playerName, tokenName, token_destination_size);             // copying data into data structure
                player1data.playerName[token_destination_size] = '0';                           // setting name VICTOR with 0 at end = VICTOR0
                strncat(PlayerBuf, player1data.playerName, 256 - strlen(PlayerBuf) - 1);        // 3 parameter (- 1) because of terminating character 
                }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
                }
        }
        else if(tokenSeatNumClient == 2){
            if (player2data.playerName == ""){
                size_t token_destination_size = sizeof(tokenName);
                strncpy(player2data.playerName, tokenName, token_destination_size);
                player2data.playerName[token_destination_size] = '0';
                strncat(PlayerBuf, player2data.playerName, 256 - strlen(PlayerBuf) - 1);
                }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 3){
            if (player3data.playerName == ""){
                size_t token_destination_size = sizeof(tokenName);
                strncpy(player3data.playerName, tokenName, token_destination_size);
                player3data.playerName[token_destination_size] = '0';
                strncat(PlayerBuf, player3data.playerName, 256 - strlen(PlayerBuf) - 1);
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 4){
            if (player4data.playerName == ""){
                size_t token_destination_size = sizeof(tokenName);
                strncpy(player4data.playerName, tokenName, token_destination_size);
                player4data.playerName[token_destination_size] = '0';
                strncat(PlayerBuf, player4data.playerName, 256 - strlen(PlayerBuf) - 1);
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 5){
            if (player5data.playerName == ""){
                size_t token_destination_size = sizeof(tokenName);
                strncpy(player5data.playerName, tokenName, token_destination_size);
                player5data.playerName[token_destination_size] = '0';
                strncat(PlayerBuf, player5data.playerName, 256 - strlen(PlayerBuf) - 1);
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
        else if(tokenSeatNumClient == 6){
            if (player6data.playerName == ""){
                size_t token_destination_size = sizeof(tokenName);
                strncpy(player6data.playerName, tokenName, token_destination_size);
                player6data.playerName[token_destination_size] = '0';
                strncat(PlayerBuf, player6data.playerName, 256 - strlen(PlayerBuf) - 1);
            }
            else{
                strncpy(SendBuf, "Seat already occupied. Please enter a different seat number with proper format.", sizeof(SendBuf)-1);
            }
        }
    }

    if (RecvBuf[0] == '2'){   // RecvBuf should be like 21; 2 for call; 1 for seat number
        playerseatchar = RecvBuf[1];     
        playerseatint = (RecvBuf[1] - '0'); // char to int
        if (playerseatint == 1){            // conditional to send parameter for call
            player1data.playerSeat = 1;
            call(player1data);
        }
        else if (playerseatint == 2){
            player2data.playerSeat = 2;
            call(player2data);
        }
        else if (playerseatint == 3){
            player3data.playerSeat = 3;
            call(player3data);
        }
        else if (playerseatint == 4){
            player4data.playerSeat = 4;
            call(player4data);
        }
        else if (playerseatint == 5){
            player5data.playerSeat = 5;
            call(player5data);
        }
        else if (playerseatint == 6){
            player6data.playerSeat = 6;
            call(player6data);
        }
        if (winner != 0){
            strcpy(SendBuf, "");
            SendBuf[0] = "5";
            char winnerchar;
            winnerchar = (winner + '0');
            SendBuf[1] = winnerchar;
        }
        strcpy(SendBuf, RecvBuf);       // sending back to client 
        char currentplayerturnchar = (currentplayerturn + '0');
        SendBuf[strlen(SendBuf) -1] = currentplayerturnchar;     // adding player turn
    } 

    else if (RecvBuf[0] == '3'){     // RecvBuf and Temp2RecvBuf = 31150; 3 = raise; 1 = seat number; 150 = raise amount
        Temp2RecvBuf[0] = 'a';                       // "a1150"
        playerseatchar = RecvBuf[1];            
        playerseatint = (RecvBuf[1] - '0');
        Temp2RecvBuf[1] = " ";                       // "a 150"
        token = strtok(Temp2RecvBuf, s);
        if (token == "a"){
            token = strtok(NULL, s);                // token = "150"
            pointsraised = atoi(token);             // pointsraised = 150    
        }
        if (playerseatint == 1){                    // conditional to send parameter for call
            player1data.playerSeat = 1;
            raise(player1data, pointsraised);
        }
        else if (playerseatint == 2){
            player2data.playerSeat = 2;
            raise(player2data, pointsraised);
        }
        else if (playerseatint == 3){
            player3data.playerSeat = 3;
            raise(player3data, pointsraised);
        }
        else if (playerseatint == 4){
            player4data.playerSeat = 4;
            raise(player4data, pointsraised);
        }
        else if (playerseatint == 5){
            player5data.playerSeat = 5;
            raise(player5data, pointsraised);
        }
        else if (playerseatint == 6){
            player6data.playerSeat = 6;
            raise(player6data, pointsraised);
        }
        if (winner != 0){
            strcpy(SendBuf, "");
            SendBuf[0] = "5";
            char winnerchar;
            winnerchar = (winner + '0');
            SendBuf[1] = winnerchar;
        }
        strcpy(SendBuf, RecvBuf);   // sending back to client 
        char currentplayerturnchar = (currentplayerturn + '0');
        SendBuf[strlen(SendBuf) -1] = currentplayerturnchar;     // adding player turn
    }

    else if (RecvBuf[0] == '4'){   // RecvBuf should be like 41, 4 fold; 1 for seat number
        playerseatchar = RecvBuf[1];     
        playerseatint = (RecvBuf[1] - '0'); // char to int
        if (playerseatint == 1){            // conditional to send parameter for call
            player1data.playerSeat = 1;
            fold(player1data);
        }
        else if (playerseatint == 2){
            player2data.playerSeat = 2;
            fold(player2data);
        }
        else if (playerseatint == 3){
            player3data.playerSeat = 3;
            fold(player3data);
        }
        else if (playerseatint == 4){
            player4data.playerSeat = 4;
            fold(player4data);
        }
        else if (playerseatint == 5){
            player5data.playerSeat = 5;
            fold(player5data);
        }
        else if (playerseatint == 6){
            player6data.playerSeat = 6;
            fold(player6data);
        }
        if (winner != 0){
            strcpy(SendBuf, "");
            SendBuf[0] = "5";
            char winnerchar;
            winnerchar = (winner + '0');
            SendBuf[1] = winnerchar;
        }
        strcpy(SendBuf, RecvBuf);       // sending back to client 
        char currentplayerturnchar = (currentplayerturn + '0');
        SendBuf[strlen(SendBuf) -1] = currentplayerturnchar;       // adding player turn
    }
} 

    // WE DONT NEED THIS WHILE LOOP
   /* while(1){
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
        
    }*/

 /*   if (0 == strcmp(RecvBuf, "READY")){
        strcat(SendBuf, PlayerBuf);
    }
    printf("\nMade it to End\n");
    */

//Debug messages for Server response, in case it fails
#ifdef DEBUG
    printf("%s: Responding with reply: %s.\n", Program, SendBuf);
#endif
    l = strlen(SendBuf);
    n = write(DataSocketFD, SendBuf, l);
    if (n < 0)
    {   FatalError("Writing to data socket did not execute");
    }
} /* end of ProcessRequest */

// this function does not need to be modified
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
// this function may not need to be edited

const char* riverStringCat(int i, char* SendBuf){

    return SendBuf;
}

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


//rearrange following lines after
//line that checks if 0 is returned from strcmp(RecvBuf, "READY")
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

/* EOF PokerServer.c */
