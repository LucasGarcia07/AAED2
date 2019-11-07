#ifndef DEPENDENTE_H
#define DEPENDENTE_H

typedef struct Dependente{
    int cod, codDependencia, idade, status, prox;
    char nome[50];
}Dependente;

typedef struct ListaDep{
    Dependente dependente;
    ListaDep* prox;
}ListaDep;

void imprime(Depentente *depentente);

Depentente *criadepentente(int codDependencia, int idade, char *nome, double salario);

void salva(Depentente *depentente, FILE *out);

Depentente *le(FILE *in);

int tamanho();
#endif