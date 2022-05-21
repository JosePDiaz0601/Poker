#Initial Makefile to create
#Make sure to include trick showed by T.A. for object files and simplifying dependencies
#Example Makefile for EECS22L

CFLAGS = -Wall -O2
Mymessage = success

help:
	@echo 'This is how you use the Makefile!!!'
	@echo 'Type make all '
	
test:
	@echo 'This is an example Makefile message'
	make poker
	./poker

# $< is the first file in your dependency
# S@ is your target on the left of :
# S^ is all the dependency

debug: simplecfile.c simpleheader.h
	gcc $(CLFAGS) -g -DDEBUG $< -o $@
	
slow: simplecfile.c simplecfile2.c simpleheader.h simpleheader2.h
	gcc $(CFLAGS) $^ -o $@
	
simple.o: simplecfile.c simpleheader.h simpleheader2.h
	gcc $(CFLAGS) $^ -c -o $@

simple2.o: simplecfile2.c simpleheader2.h
	gcc $(CFLAGS) $^ -c -o $@
	
print:
	@echo $(Mymessage)

poker: simplefile.c simpleheader.h
	gcc $(CFLAGS) $^ -o $@

clean: 
	rm -f results
