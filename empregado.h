#ifndef EMPREGADO_H
#define EMPREGADO_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Empregado{
    int cod, idade;
    double salario;
    char nome[50];
    Empregado *proxEmp;
    Empregado *proxNome;
    Empregado *proxIdade;
}Empregado;

void imprimeEmp(Empregado *empregado);

Empregado *criaEmp(int cod, int idade, char *nome, double salario);

void salvaEmp(int chave, Empregado *empregado, FILE *indexEmp, FILE *out);

Empregado *leEmp(FILE *in);

int tamanhoEmp();

#endif