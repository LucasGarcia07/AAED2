#include "empregado.h"
#include "dependente.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "index.h"



//funções auxiliares IndexEmp
IndexEmp *leIndexEmp(FILE *in){
    IndexEmp *index = (IndexEmp*) malloc(sizeof(IndexEmp));
    if (0 >= fread(&index->quantidade, sizeof(int), 1, in)) {
	free(index);
	return NULL;
    }
    fread(index->prox, sizeof(Empregado), 1, in);
    return index;
}

IndexEmp *criaIndexEmp(Empregado *emp, int quantidade){
    IndexEmp *index = (IndexEmp*) malloc(sizeof(IndexEmp));
        
    if (index) memset(index, 0, sizeof(IndexEmp));
    index->prox = emp;
    index->quantidade = 0;
    return index;
}

IndexDp *leIndexDp(FILE *in){
    IndexDp *index = (IndexDp*) malloc(sizeof(IndexDp));
    if (0 >= fread(&index->quantidade, sizeof(int), 1, in)) {
	free(index);
	return NULL;
    }
    fread(&index->prox, sizeof(Dependente*), 1, in);
    return index;
}

IndexDp *criaIndexDp(Dependente *dp, int quantidade){
    IndexDp *index = (IndexDp*) malloc(sizeof(IndexDp));
        
    if (index) memset(index, 0, sizeof(IndexDp));
    index->prox = dp;
    index->quantidade = quantidade;
    return index;
}

void imprimeIndexDp(IndexDp *dp){
    printf("\nQuantidade: %d\n", dp->quantidade);
}

int tamanhoIndexEmp(){
    return sizeof(Empregado*) + sizeof(int);
}
int tamanhoIndexDp(){
    return sizeof(Dependente*) + sizeof(int);
}