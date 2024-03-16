#include"stos.h"

void inicjuj(t_stos** gora){
    (*gora)=NULL;               /*inicjacja listy NULLem*/
    }

void print(t_stos** gora){
    t_stos* tmp = (*gora);
    while(tmp!=NULL){           /*wypisywanie wartości w stosie*/
    printf("%d", tmp->dana);
    tmp=tmp->nast;
    printf("\n");
    }
}

void print1(t_stos** gora){
    t_stos* tmp = (*gora);
    if(tmp!=NULL){          /*wypisywanie ostatniej wartości na stosie*/
    printf("%d", tmp->dana);
    tmp=tmp->nast;
    printf("\n");
    }
}

int empty(t_stos** gora){
    if((*gora)==NULL)           /*sprawdzanie czy stos jest pusty*/
    return 1;
    else 
    return 0;
}

void push(t_stos** gora, int *dana){          /*zapisywanie wartości do stosu*/
    t_stos* nowy_elem = (t_stos*) malloc(sizeof(t_stos)); 
    nowy_elem->dana = *dana;            
    nowy_elem->nast = *gora;
    *gora = nowy_elem;
}

int pop(t_stos**gora, int *dana){       /*usuwanie wartości ze stosu*/
    if(*gora == NULL){
        return -1;
    }
    t_stos *pop_dana;
    pop_dana=*gora;
    *dana=pop_dana->dana;
    *gora=(*gora)->nast;
    free(pop_dana);

    return *dana;
}

