#ifndef CUSTOMSTRING
#define CUSTOMSTRING

#include<string.h>
#include <stdio.h>
#include<stdlib.h>
//<string implementation from https://gist.github.com/water-air-flash/fb74ab18c53c485769c2a6cd1b81f082>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define STRSIZE 10

typedef struct {
    char *str;
    unsigned int size;
} string;

#endif