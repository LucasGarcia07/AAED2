#ifndef EMPREGADO_H
#define EMPREGADO_H
#include "empregado.h"
#include "dependente.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct IndexDadosEmp{
    Empregado *emp;
    Empregado *proxEmpNome;
    Empregado *proxIdade;
    IndexDadosEmp *prox;
}

typedef struct IndexEmp{
    Empregado *emp;
    IndexEmp *prox;
    int quantidade;
}IndexEmp;

typedef struct IndexDp{
    Dependente *dp;
    IndexDp *prox;
    int quantidade;
}IndexDp;

typedef struct IndexNomeEmp{
    char nomeEmp[50];
    IndexNomeEmp *prox;
    int quantidade;
}IndexNomeEmp;

typedef struct IndexIdadeEmp{
    int idade;
    IndexIdadeEmp *prox;
    int quantidade;
}IndexIdadeEmp;

typedef struct IndexCodDp{
    int codDp;
    IndexCodDp *prox;
    int quantidade;
}


typedef struct IndexIdadeDp{
    int idade;
    IndexIdadeDp *prox;
    int quantidade;
}

#endif