#ifndef STRUKTURA_H
#define STRUKTURA_H
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct stos{
    int dana;           /*dana zapamiętywana w stosie*/
    struct stos *nast;     /*wskaźnik na następny element listy*/
}t_stos;


#endif