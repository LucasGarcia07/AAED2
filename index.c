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
    fread(index->prox, sizeof(Empregado), in);
    return index;
}

IndexEmp *criaIndexEmp(Empregado *emp, int quantidade){
    IndexEmp *index = (IndexEmp*) malloc(sizeof(IndexEmp));
        
    if (index) memset(index, 0, sizeof(IndexEmp));
    index->prox = emp;
    index->quantidade = 0;

    return index;
}

int tamanhoIndexEmp(){
    return sizeof(Empregado) + sizeof(int);
}

IndexEmp *buscaSecEmp(){
    
}