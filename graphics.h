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


//Certain constants we want to define (window size etc.) should go here.
GtkWidget *CreateWindow(int *argc, char **argv[]);

void UpdateWindow(void);

#endif
