#ifndef EMPREGADO_H
#define EMPREGADO_H
#include"dependente.h"

typedef struct Empregado{
    int cod, idade, status, prox;
    double salario;
    char nome[50];
}Empregado;

void imprime(Empregado *empregado);

Empregado *criaEmpregado(int cod, int idade, char *nome, double salario);

void salva(Empregado *empregado, FILE *out);

Empregado *le(FILE *in);

int tamanho();

#endif