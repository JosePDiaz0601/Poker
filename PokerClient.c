/* PokerClient.c: TCP/IP client with timeout support for poker game
* This file has been adapted to fit the needs of the socket communication
* that is used between client and server for our poker game.
* Author: Victor Dam, Arhant Katare
* Based on code from Rainer Doemer in ClockClient.c//
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include "graphics.h"
 
int seat;
 
/* #define DEBUG */ /* be verbose */
/*** global variables ****************************************************/
const char *Program = NULL;
 
/*** global functions ****************************************************/
 
// FatalError does not need to be modified
void FatalError(        /* print error diagnostics and abort */
   const char *ErrorMsg)
{
   fputs(Program, stderr);
   fputs(": ", stderr);
   perror(ErrorMsg);
   fputs(Program, stderr);
   fputs(": Exiting!\n", stderr);
   exit(20);
} /* end of FatalError */
 
// this may not be necessary to edit
int main(int argc, char *argv[])
{
   int l, n;
   int SocketFD,   /* socket file descriptor */
   PortNo;     /* port number */
   struct sockaddr_in
   ServerAddress;  /* server address we connect with */
   struct hostent
   *Server;    /* server host */
   static char SendBuf[256];   /* message buffer for sending a message */
   static char RecvBuf[256];   /* message buffer for receiving a response */
   static char PlayerBuf[256]; // long string with names from server to client
   static char TempSendBuf[256];
   static char CardBuf[256];
   char *token;
   const char s[2] = " ";
   char ClientSeatNumChar;
   int ClientSeatNumInt;   // client seat num
//   char PlayerNameTemp[256];  // use to token on client side as strtok messes up original string
   Program = argv[0];  /* publish program name (for diagnostics) */
 
   CreateWindow(&argc, &argv);
 
#ifdef DEBUG
   printf("%s: Starting...\n", argv[0]);
#endif
   if (argc < 3)
   {   fprintf(stderr, "Usage: %s hostname port\n", Program);
   exit(10);
   }
   Server = gethostbyname(argv[1]);
   if (Server == NULL)
   {   fprintf(stderr, "%s: no such host named '%s'\n", Program, argv[1]);
       exit(10);
   }
   PortNo = atoi(argv[2]);
   if (PortNo <= 2000)
   {   fprintf(stderr, "%s: invalid port number %d, should be >2000\n",
       Program, PortNo);
       exit(10);
   }
   ServerAddress.sin_family = AF_INET;
   ServerAddress.sin_port = htons(PortNo);
   ServerAddress.sin_addr = *(struct in_addr*)Server->h_addr_list[0];
   do
   {   UpdateWindow();
       printf("%s: Enter a command to send to the poker server:\n"
       "         'ENTER (SEAT NUMBER)' to choose a seat (without parenthesis),\n"
/*        "         'F SEAT (NUMBER)' to Fold,\n"
       "         'R SEAT (NUMBER)' to Raise,\n"
       "         'C SEAT (NUMBER)' to Call,\n"
       "         'READY' to start game,\n"
*/
       "         'SHUTDOWN' to terminate the server,\n"
       "         or 'bye' to quit this client\n"
       "command: ", argv[0]);
   fgets(SendBuf, sizeof(SendBuf), stdin);
   l = strlen(SendBuf);
   if (SendBuf[l-1] == '\n')
   {   SendBuf[--l] = 0;
   }
 
   strcpy(TempSendBuf, SendBuf);   // copy string for temp Send Buffer
   token = strtok(TempSendBuf, s);     // ENTER player input
    //printf("\n\n Token is %s. \n\n", token);
   if (0 == strcmp(token, "ENTER")){
       //printf("\n\n\nENTERED THIS IF\n\n\n\n");
       ClientSeatNumChar = SendBuf[6];
       ClientSeatNumInt = (SendBuf[6] - '0');     // Set client to a int number for later comparison
       //printf("\n\nCLIENT SEAT NUMBER IS %d\n\n", ClientSeatNumInt);
   }
   else if (0 == strcmp(token, "RAISE")){
       strcpy(SendBuf, "3");                                            // sending 3 for raise
       strncat(SendBuf, ClientSeatNumChar, 256 - strlen(SendBuf) - 1);  // sending client seat number
       token = strtok(NULL, s);
       strncat(SendBuf, token, 256 - strlen(SendBuf) - 1);                // outcome would be 31150 if raise, seat 1, $150
   }
  
 
   if (0 == strcmp("bye", SendBuf))
   {   break;
   }
   else if (0 == strcmp(SendBuf, "Call")){     // call from client to server
       strcpy(SendBuf, "2");                   // setting SendBuf to '2'
       strcat(SendBuf, ClientSeatNumChar);     // setting SendBuf to '2(client seat number)'
   }

   if (l)
   {   SocketFD = socket(AF_INET, SOCK_STREAM, 0);
       if (SocketFD < 0)
       {   FatalError("socket creation failed");
       }
       printf("%s: Connecting to the server at port %d...\n",
           Program, PortNo);
       if (connect(SocketFD, (struct sockaddr*)&ServerAddress,
           sizeof(ServerAddress)) < 0)
       {   FatalError("connecting to server failed");
       }
       printf("%s: Sending message '%s'...\n", Program, SendBuf);
       n = write(SocketFD, SendBuf, l);
       if (n < 0)
       {   FatalError("writing to socket failed");
       }
#ifdef DEBUG
       printf("%s: Waiting for response...\n", Program);
#endif
       n = read(SocketFD, RecvBuf, sizeof(RecvBuf)-1);
       if (n < 0)
       {   FatalError("reading from socket failed");
       }
       RecvBuf[n] = 0;
       printf("%s: Received response: %s\n", Program, RecvBuf);
 
       // parsing string for information here (RecvBuf from server - long string)
       if (RecvBuf[0] == '1'){
           strcpy(PlayerBuf, RecvBuf);    // all the player names
       }
 
       else if (RecvBuf[0] == '0'){
           strcpy(CardBuf, RecvBuf);      // all the INFORMATION of poker game
           printf("\n%s\n", CardBuf);
           your1CardSuit = CardBuf[(11+(4*(ClientSeatNumInt-1)))];
           your1CardType = CardBuf[(12+(4*(ClientSeatNumInt-1)))];
           your2CardSuit = CardBuf[(13+(4*(ClientSeatNumInt-1)))];
           your2CardType = CardBuf[(14+(4*(ClientSeatNumInt-1)))];
           makeCards();
       }

       else if (RecvBuf[0] == "2"){    // client recieving string from server (who called?)
           int tempplayernum;
           tempplayernum = (RecvBuf[1] - '0');
           if (tempplayernum == ClientSeatNumInt){         // checking if this specific client called
               printf("Player at Seat %d, you have called.", tempplayernum);        // print for client who called
           }
           else{
               // do nothing since this client didn't call 
           }
       }

       else if (RecvBuf[0] == "3"){     // client recieving string from server (who raised?)
           int tempplayernum;
           tempplayernum = (RecvBuf[1] - '0');
           if (tempplayernum == ClientSeatNumInt){  
               printf("Player at Seat %d, you have raised.", tempplayernum);
           }
           else{
               // do nothing since this client didn't call
           }
       }

 
       else{
           // use this section to printf the server telling the client what commands they can do :)
       }

      
       //makeCards(RecvBuf); // GTK
 
#ifdef DEBUG
       printf("%s: Closing the connection...\n", Program);
#endif
       close(SocketFD);
   }
   } while(0 != strcmp("SHUTDOWN", SendBuf));
   printf("%s: Exiting...\n", Program);
   return 0;
}
 
/* EOF PokerClient.c */
 
/* Example string parsing provided by T.A. Yutong*/
/*
while(1){
       //Waiting for client to send message
       char string[50] = "@2;R;100";
       char player[10];
       char command[10];
       char amount[10];
       char * token = strtok(string";");
       // loop through the string to extract all other tokens
int i= 0;
}
 
//strcpy(command.token)
while( token != NULL ) {
   if(i == 0)  {
       strcpy(command, token);
   printf("s\n", command ); //printing each token
   }
   else if(i ==1){
       strcpy(amount, token);
       printf("s\n", amount); //printing each token
   }
   //printf(" %s\n, command); //printing each toekn
   token = strtok(NULL, ";");
   i++;
}
*/
/*
while(1){
   switch(command){
       case 'R':
           //function_for_Raise()
           break;
 
       case 'F':
           //function_for_fold()
           break;
       case '....':
           break;
   }
}
/* EOF PokerClient.c */
 
 

