#ifndef INDEX_H
#define INDEX_H
#include "empregado.h"
#include "dependente.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct IndexDp{
    Dependente *prox;
    int quantidade;
}IndexDp;


//índice de empregados 
typedef struct IndexEmp{
    int quantidade;
    Empregado *prox;
}IndexEmp;

IndexEmp *criaIndexEmp(Empregado *emp, int quantidade);

IndexEmp *leIndexEmp(FILE *in);

int tamanhoIndexEmp();




#endif