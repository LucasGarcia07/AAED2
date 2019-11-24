#include "dependente.h"
#include "index.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimeDp(Dependente *dependente) {
    printf("\nCódigo do dependente: ");
    printf("%d", dependente->cod);
    printf("\nCódigo de dependencia: ");
    printf("%d", dependente->codDependencia);
    printf("\nNome do depentente: ");
    printf("%s\n", dependente->nome);
    printf("\n Idade do depentente");
    printf("%d\n", dependente->idade);
}

Dependente *criaDp(int cod, int codDependencia, int idade, char *nome, Dependente *aux) {
    Dependente *dependente = (Dependente*)malloc(sizeof(Dependente));
    
    if (dependente) memset(dependente, 0, sizeof(Dependente));

    dependente->cod = cod;
    dependente->codDependencia = codDependencia;
    dependente->idade = idade;
    strcpy(dependente->nome, nome);
    dependente->proxDp = aux;
    dependente->proxCodDp = aux;
    dependente->proxIdadeDp = aux;
    dependente->proxNomeDp = aux;
    return dependente;
}

void salvaDp(int chave, Dependente *dependente,FILE *indexDp, FILE *out) {

    Dependente *idpAux, *aux;

    //Rotina para inserir na lista encadeada
    fseek(indexDp, tamanhoIndexDp() * chave, SEEK_SET);
    idpAux = leDp(indexDp);
    
    if(idpAux == NULL){
        fseek(indexDp, tamanhoIndexDp() * chave, SEEK_SET);
        printf("erro1\n");
        IndexDp *index = criaIndexDp(dependente, 1);
        fwrite(&index->quantidade, sizeof(int), 1, indexDp);
        fwrite(index->prox, sizeof(Dependente *),1, indexDp);
        printf("erro1\n");
    }


    // while(dpAux->proxDp != NULL){
    //     dpAux = dpAux->proxDp;
    // }
    // if(dpAux->proxDp == NULL){
    //     dpAux->proxDp = dependente;
    // }
    //Rotina para inserir no arquivo de dados
    // int i = 0;
    // fseek(out, i, SEEK_SET)
    // while((aux = le(out)) != NULL){
    //     i++
    // }
    fwrite(&dependente->cod, sizeof(int), 1, out);
    fwrite(&dependente->codDependencia, sizeof(int), 1, out);
    fwrite(&dependente->idade, sizeof(int), 1, out);
    fwrite(dependente->nome, sizeof(char), sizeof(dependente->nome), out);
    fwrite(dependente->proxDp, sizeof(Dependente*), 1, out);
    fwrite(dependente->proxCodDp, sizeof(Dependente*), 1, out);
    fwrite(dependente->proxIdadeDp, sizeof(Dependente*), 1, out);
    fwrite(dependente->proxNomeDp, sizeof(Dependente*), 1, out);
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
    fread(&dependente->proxDp, sizeof(Dependente*), 1, in);
    fread(&dependente->proxCodDp, sizeof(Dependente*), 1, in);
    fread(&dependente->proxIdadeDp, sizeof(Dependente*), 1, in);
    fread(&dependente->proxNomeDp, sizeof(Dependente*), 1, in);
    return dependente;
}

int tamanhoDp() {
    return 3 * sizeof(int) + sizeof(char) * 50 + sizeof(Dependente*) * 4;
}
