#include "empregado.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void imprimeEmp(Empregado *empregado) {
    printf("\nCódigo do empregado: ");
    printf("%d", empregado->cod);
    printf("\nNome do empregado: ");
    printf("%s", empregado->nome);
    printf("\n Idade do empregado");
    printf("%d", empregado->idade);
    printf("\n Salario do empregado");
    printf("%lf", empregado->salario);
}

Empregado *criaEmp(int cod, int idade, char *nome, double salario) {
    Empregado *empregado = (Empregado *) malloc(sizeof(Empregado));

    if (empregado) memset(empregado, 0, sizeof(Empregado));
    empregado->cod = cod;
    empregado->idade = idade;
    empregado->salario = salario;
    strcpy(empregado->nome, nome);
    empregado->prox = NULL;
    
    return empregado;
}

void salvaEmp(int chave, Empregado *empregado,FILE *indexEmp, FILE *out) {
    Empregado *empAux;

    //Rotina para inserir na lista encadeada
    fseek(indexEmp, tamanhoEmp() * chave, SEEK_SET);
    empAux = leEmp(indexEmp);
    while(empAux->prox != NULL){
        empAux = empAux->prox;
    }
    if(empAux->prox == NULL){
        empAux->prox = empregado;
    }
    //Rotina para inserir no arquivo de dados
    fwrite(&empregado->cod, sizeof(int), 1, out);
    fwrite(&empregado->idade, sizeof(int), 1, out);
    fwrite(&empregado->salario, sizeof(double), 1, out);
    fwrite(empregado->nome, sizeof(char), sizeof(empregado->nome), out);
    fwrite(&empregado->prox, sizeof(int), 1, out);
}

Empregado *leEmp(FILE *in) {
    Empregado *empregado = (Empregado *) malloc(sizeof(Empregado));
    if (0 >= fread(&empregado->cod, sizeof(int), 1, in)) {
	free(empregado);
	return NULL;
    }
    fread(&empregado->idade, sizeof(int), 1, in);
    fread(&empregado->prox, sizeof(int), 1, in);
    fread(&empregado->salario, sizeof(double), 1, in);
    fread(empregado->nome, sizeof(char), sizeof(empregado->nome), in);
    return empregado;
}

int tamanhoEmp() {
    return  2 * sizeof(int) + sizeof(double) + sizeof(char) * 50 + sizeof(Empregado);
}

int hash(int x, int m, int l){
    return x % (m * pow(2, l));
}

int hashl(int x, int m, int *p, int *l){
    int endereco = hash(x, m, p, l);
    if(endereco < p){
        return x % (m * pow(2, l+1));
    }
    return endereco;
}

double carga(int n, int m) return n/m;

void rotina(int m, int n, int *p, int *l){
    if(carga(n, m) > 4){
        p++;
    }
    if(p == m-1){
        p = 0;
        l++;
    }
}