#include "dependente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimeDp(Dependente *dependente) {
    printf("\nCódigo do dependente: ");
    printf("%d", dependente->cod);
    printf("\nCódigo de dependencia: ");
    printf("%d", dependente->codDependencia);
    printf("\nNome do depentente: ");
    printf("%s", dependente->nome);
    printf("\n Idade do depentente");
    printf("%d", dependente->idade);
}

Dependente *criaDp(int cod, int codDependencia, int idade, char *nome) {
    Dependente *dependente = (Dependente*)malloc(sizeof(Dependente));

    if (dependente) memset(dependente, 0, sizeof(dependente));

    dependente->cod = cod;
    dependente->codDependencia = codDependencia;
    dependente->idade = idade;
    strcpy(dependente->nome, nome);
    dependente->prox = NULL;
    return dependente;
}

void salvaDp(int chave, Dependente *dependente,FILE *indexDp, FILE *out) {

    Dependente *dpAux;

    //Rotina para inserir na lista encadeada
    fseek(indexDp, tamanhoDp() * chave, SEEK_SET);
    dpAux = leDp(indexDp);
    
    while(dpAux->prox != NULL){
        dpAux = dpAux->prox;
    }
    if(dpAux->prox == NULL){
        dpAux->prox = dependente;
    }

    //Rotina para inserir no arquivo de dados
    fwrite(&dependente->cod, sizeof(int), 1, out);
    fwrite(&dependente->codDependencia, sizeof(int), 1, out);
    fwrite(&dependente->idade, sizeof(int), 1, out);
    fwrite(dependente->nome, sizeof(char), sizeof(dependente->nome), out);
    fwrite(&dependente->prox, sizeof(int), 1, out);
}

Dependente *leDp(FILE *in) {
    Dependente *dependente = (Dependente*) malloc(sizeof(Dependente));
    if (0 >= fread(&dependente->cod, sizeof(int), 1, in)) {
	free(dependente);
	return NULL;
    }
    fread(&dependente->codDependencia, sizeof(int), 1, in);
    fread(&dependente->idade, sizeof(int), 1, in);
    fread(dependente->nome, sizeof(char), sizeof(dependente->nome), in);
    fread(&dependente->prox, sizeof(int), 1, in);
    return dependente;
}

int tamanhoDp() {
    return (3 * sizeof(int)) + sizeof(char) * 50 + sizeof(Dependente);
}