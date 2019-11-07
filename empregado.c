#include "empregado.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprime(Empregado *empregado) {
    printf("\nCódigo do empregado: ");
    printf("%d", empregado->cod);
    printf("\nNome do empregado: ");
    printf("%s", empregado->nome);
    printf("\n Idade do empregado");
    printf("%d", empregado->idade);
    printf("\n Salario do empregado");
    printf("%lf", empregado->salario);
}

Empregado *criaEmpregado(int cod, int idade, char *nome, double salario) {
    Empregado *empregado = (Empregado *) malloc(sizeof(Empregado));

    if (Empregado) memset(empregado, 0, sizeof(Empregado));

    empregado->cod = cod;
    empregado->idade = idade;
    empregado->status = 1;
    empregado->prox = -1;
    empregado->salario = salario;
    strcpy(empregado->nome, nome);
    
    return empregado;
}

void salva(int chave, Empregado *empregado, FILE *out) {
    Empregado *empAtual, *empAnt;

    fseek(out, tamanho() * chave, SEEK_SET);
    empAtual = le(out);
    while(empAtual != NULL && empAtual->prox != -1){
        empAnt = empAtual;
        fseek(out, tamanho() * (empAtual->prox), SEEK_SET);
        empAtual = le(out);
    }
    if(empAtual == NULL){
        fwrite(&empregado->cod, sizeof(int), 1, out);
        fwrite(&empregado->idade, sizeof(int), 1, out);
        fwrite(&empregado->status, sizeof(int), 1, out);
        fwrite(&empregado->prox, sizeof(int), 1, out);
        fwrite(&empregado->salario, sizeof(double), 1, out);
        fwrite(empregado->nome, sizeof(char), sizeof(empregado->nome), out);
    }else if(empAtual != NULL && empAtual->prox == -1){

    }
    
    
}

Empregado *le(FILE *in) {
    Empregado *empregado = (Empregado *) malloc(sizeof(Empregado));
    if (0 >= fread(&empregado->cod, sizeof(int), 1, in)) {
	free(empregado);
	return NULL;
    }
    fread(&empregado->idade, sizeof(int), 1, in));
    fread(&empregado->status, sizeof(int), 1, in));
    fread(&empregado->prox, sizeof(int), 1, in));
    fread(&empregado->salario, sizeof(double), 1, in));
    fread(empregado->nome, sizeof(char), sizeof(empregado->nome), in);
    return empregado;
}

int tamanho() {
    return sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int) + sizeof(double) + sizeof(char) * 50;
}

int hash(x, m) return (x % 43)% m; 
int hashl(int x, int end, int p, int l){
    
    end = 
}