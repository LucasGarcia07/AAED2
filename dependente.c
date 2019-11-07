#include "dependente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprime(Depentente *depentente) {
    printf("\nCódigo do depentente: ");
    printf("%d", depentente->codDependencia);
    printf("\nNome do depentente: ");
    printf("%s", depentente->nome);
    printf("\n Idade do depentente");
    printf("%d", depentente->idade);
    printf("\n Salario do depentente");
    printf("%lf", depentente->salario);
}

Depentente *criadepentente(int codDependencia, int idade, char *nome, double salario) {
    Depentente *depentente = (depentente *) malloc(sizeof(depentente));

    if (depentente) memset(depentente, 0, sizeof(depentente));

    depentente->codDependencia = codDependencia;
    depentente->idade = idade;
    depentente->salario = solario;
    strcpy(depentente->nome, nome);
    return depentente;
}

void salva(Depentente *depentente, FILE *out) {
    fwrite(&depentente->codDependencia, sizeof(int), 1, out);
    fwrite(&depentente->idade, sizeof(int), 1, out);
    fwrite(&depentente->salario, sizeof(double), 1, out);
    fwrite(depentente->nome, sizeof(char), sizeof(depentente->nome), out);
}

Depentente *le(FILE *in) {
    Depentente *depentente = (depentente *) malloc(sizeof(depentente));
    if (0 >= fread(&depentente->codDependencia, sizeof(int), 1, in)) {
	free(depentente);
	return NULL;
    }
    fread(&depentente->idade, sizeof(int), 1, in));
    fread(&depentente->salario, sizeof(double), 1, in));
    fread(depentente->nome, sizeof(char), sizeof(depentente->nome), in);
    return depentente;
}

int tamanho() {
    return sizeof(int) + sizeof(int) + sizeof(double) + sizeof(char) * 50;
}