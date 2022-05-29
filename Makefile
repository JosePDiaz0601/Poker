#Initial Makefile to create
#Make sure to include trick showed by T.A. for object files and simplifying dependencies
#Example Makefile for EECS22L


GTKINC	= `pkg-config --cflags gtk+-2.0` #GTK FLAGS
GTKLIBS	= `pkg-config --libs gtk+-2.0`

CFLAGS = -Wall -ansi -std=c99 $(GTKINC) #commented out until compilation with GUI is tested.

Mymessage = success
	
test:
	@echo 'This is the alpha version of our program'
	make poker
	./bin/poker

help:
	@echo 'This is how you use the Makefile!!!'
	@echo 'Type make all '
# $< is the first file in your dependency
# S@ is your target on the left of :
# S^ is all the dependency

poker: ./src/poker.c ./src/poker.h
	gcc $(CFLAGS) -g ./src/poker.c -o ./bin/poker

#debug: poker.c poker.h
#	gcc $(CFLAGS) -g -DDEBUG $< -o $@

#poker: Poker.o Clock.o
#	$(CC) $(CFLAGS) ./bin/Poker.o ./bin/Graphics.o
	
#Poker.o: ./src/poker.c ./src/poker.h ./src/grahics.h ./src/ClockClient.c ./src/ClockServer.c ./src/ClockClient.h ./src/ClockServer.h
#	$(CC) $(CFLAGS) -c ./src/chess.c -o ./bin/Chess.o
	
#Graphics.o: ./src/graphics.c ./src/graphics.h ./src/ClockServer.h ./src/ClockClient.h
#	$(CC) $(CFLAGS) -c ./src/graphics.c -o ./bin/Graphics.o
	
print:
	@echo $(Mymessage)

#poker: poker.c poker.h ClockServer.c ClockClient.c graphics.c graphics.h
#	gcc $(CFLAGS) $^ -o $@

clean: 
	rm ./bin/poker
	#rm ./bin/*.o


/*

GTKINC	= `pkg-config --cflags gtk+-2.0`
GTKLIBS	= `pkg-config --libs gtk+-2.0`


DEBUG	= -g -DDEBUG
DEBUG	= -O2
CFLAGS	= -Wall -std=c11 $(DEBUG) $(GTKINC) -c
LFLAGS	= -Wall -std=c11 $(DEBUG) $(GTKLIBS) -lm


all: GTK_ClockClient GTK_ClockServer

clean:
	rm -f *.o
	rm -f Poker_Client Poker_Server

test:
	@echo "To run the examples, first start the server in one terminal,"
	@echo "then start one (or multiple) client(s) in another."
	@echo
	@echo "For example:"
	@echo "crystalcove% ./GTK_ClockServer 10000"
	@echo "crystalcove% ./GTK_ClockClient crystalcove 10000"

GTK_ClockClient.o: GTK_ClockClient.c
	gcc GTK_ClockClient.c $(CFLAGS) -o GTK_ClockClient.o

GTK_ClockClient: GTK_ClockClient.o
	gcc GTK_ClockClient.o $(LFLAGS) -o Poker_Client

GTK_ClockServer.o: GTK_ClockServer.c
	gcc GTK_ClockServer.c $(CFLAGS) -o GTK_ClockServer.o

GTK_ClockServer: GTK_ClockServer.o
	gcc GTK_ClockServer.o $(LFLAGS) -o Poker_Server

*/
