#Initial Makefile to create
#Make sure to include trick showed by T.A. for object files and simplifying dependencies
#Example Makefile for EECS22L

CFLAGS = -Wall -O2
Mymessage = success
	
test:
	@echo 'This is an example Makefile message'
	make poker
	./poker

help:
	@echo 'This is how you use the Makefile!!!'
	@echo 'Type make all '
# $< is the first file in your dependency
# S@ is your target on the left of :
# S^ is all the dependency

debug: poker.c poker.h
	gcc $(CFLAGS) -g -DDEBUG $< -o $@

poker: Poker.o Clock.o
	$(CC) $(CFLAGS) ./bin/Poker.o ./bin/Graphics.o
	
Poker.o: ./src/poker.c ./src/poker.h ./src/grahics.h ./src/ClockClient.c ./src/ClockServer.c ./src/ClockClient.h ./src/ClockServer.h
	$(CC) $(CFLAGS) -c ./src/chess.c -o ./bin/Chess.o
	
Graphics.o: ./src/graphics.c ./src/graphics.h ./src/ClockServer.h ./src/ClockClient.h
	$(CC) $(CFLAGS) -c ./src/graphics.c -o ./bin/Graphics.o
	
print:
	@echo $(Mymessage)

#poker: poker.c poker.h ClockServer.c ClockClient.c graphics.c graphics.h
#	gcc $(CFLAGS) $^ -o $@

clean: 
	rm ./bin/poker
	rm ./bin/*.o
