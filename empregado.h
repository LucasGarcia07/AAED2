#ifndef EMPREGADO_H
#define EMPREGADO_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Empregado{
    int cod, idade;
    double salario;
    char nome[50];
    struct Empregado *proxEmp;
    // struct Empregado *proxNomeEmp;
    // struct Empregado *proxIdadeEmp;
    // struct Empregado *proxSalarioEmp;
}Empregado;

void imprimeEmp(Empregado *empregado);

Empregado *criaEmp(int cod, int idade, char *nome, double salario);

void salvaEmp(int chave, Empregado *empregado, FILE *arqDadosEmp, FILE *arqEmp, FILE *arqNomeEmp, FILE *arqIdadeEmp, FILE *arqSalarioEmp);

Empregado *leEmp(FILE *in);

int tamanhoEmp();

#endif