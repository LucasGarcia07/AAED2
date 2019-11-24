#ifndef DEPENDENTE_H
#define DEPENDENTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dependente{
    int cod, codDependencia, idade;
    char nome[50];
    struct Dependente *proxDp;
    struct Dependente *proxCodDp;
    struct Dependente *proxIdadeDp;
    struct Dependente *proxNomeDp;
}Dependente;

void imprimeDp(Dependente *dependente);

Dependente *criaDp(int cod, int codDependencia, int idade, char *nome, Dependente *aux);

void salvaDp(int chave, Dependente *dependente,FILE *indexDp,  FILE *out);

Dependente *leDp(FILE *in);

int tamanhoDp();
#endif