#ifndef STOS_H
#define STOS_H
#include"struktura.h"
void inicjuj(t_stos** );
void print(t_stos** );
void print1(t_stos** );
int empty(t_stos** );
void push(t_stos** , int *);
int pop(t_stos**, int *);

#endif