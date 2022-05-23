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
	gcc $(CLFAGS) -g -DDEBUG $< -o $@
	
slow: poker.c graphics.c poker.h graphics.h
	gcc $(CFLAGS) $^ -o $@
	
poker.o: poker.c poker.h ClockClient.h ClockServer.h
	gcc $(CFLAGS) $^ -c -o $@

graphics.o: graphics.c graphics.h
	gcc $(CFLAGS) $^ -c -o $@
	
print:
	@echo $(Mymessage)

poker: poker.c poker.h ClockServer.c ClockClient.c graphics.c graphics.h
	gcc $(CFLAGS) $^ -o $@

clean: 
	rm -f poker
