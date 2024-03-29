#include "dependente.h"
#include "empregado.h"
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
    printf("Idade do depentente: ");
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

void salvaDp(int chave, Dependente *dependente, FILE *indexDp, FILE *indexCodDp, FILE *indexIdadeDp, FILE *indexNomeDp, FILE *out) {

    int i = 0;
    Dependente  *aux, *dpAux, *iDpIdadeAux;
    IndexDp *idpAux, *indexIdadeDpAux, *indexNomeDpAux, *indexCodDpAux;
    //Rotina para inserir na lista encadeada
    fseek(indexDp, tamanhoIndexDp() * chave, SEEK_SET);
    idpAux = leIndexDp(indexDp);
    
    if(idpAux == NULL){
        fseek(indexDp, tamanhoIndexDp() * chave, SEEK_SET);
        printf("erro1\n");
        IndexDp *index = criaIndexDp(dependente, 1);
        fwrite(&index->quantidade, sizeof(int), 1, indexDp);
        fwrite(index->prox, sizeof(Dependente),1, indexDp);
        printf("erro1\n");
    
    }else{
        if(idpAux->prox == NULL){
            idpAux->prox == dependente;
            idpAux->quantidade += 1;
        }else{
            dpAux = idpAux->prox;
            while(dpAux->proxDp != NULL){
                dpAux = dpAux->proxDp;
            }
            if(dpAux->proxDp == NULL){
                dpAux->proxDp = dependente;
                idpAux->quantidade += 1;
            }
        } 
    }

    //Rotina para inserir na lista de Idade
    printf("erroidade\n");
    indexIdadeDpAux = leIndexDp(indexIdadeDp);
    printf("erroidade\n");
    i = 0;
    while(indexIdadeDpAux != NULL && indexIdadeDpAux->prox->idade != dependente->idade){
        i++;
        fseek(indexIdadeDp, i * tamanhoIndexDp(), SEEK_SET);
        indexIdadeDpAux = leIndexDp(indexIdadeDp);
        printf("entrou");
    }
    if(indexIdadeDpAux == NULL){
        printf("erroidade\n");
        IndexDp *index = criaIndexDp(dependente, 1);
        fwrite(&index->quantidade, sizeof(int), 1, indexIdadeDp);
        fwrite(index->prox, sizeof(Dependente),1, indexIdadeDp);
        printf("erroidade\n");
    
    }else if(indexIdadeDpAux != NULL && indexIdadeDpAux->prox->idade == dependente->idade ){
        fseek(indexIdadeDp, i * tamanhoIndexDp(), SEEK_SET);
        dpAux = indexIdadeDpAux->prox;
        if(dpAux != NULL){
            while(dpAux->proxDp != NULL){
                dpAux = dpAux->proxDp;
            }
            dpAux->proxDp = dependente;
            indexIdadeDpAux->quantidade += 1;
        }else{
            indexIdadeDpAux->prox = dependente;
            indexIdadeDpAux->quantidade += 1;
        }
    
    }

    //Rotina para inserir na lista de nomes
    printf("erroidade\n");
    indexNomeDpAux = leIndexDp(indexNomeDp);
    printf("erroidade\n");
    i = 0;
    while(indexNomeDpAux != NULL && strcmp(indexNomeDpAux->prox->nome, dependente->nome) != 0){
        i++;
        fseek(indexNomeDp, i * tamanhoIndexDp(), SEEK_SET);
        indexNomeDpAux = leIndexDp(indexNomeDp);
        printf("entrou");
    }
    if(indexNomeDpAux == NULL){
        printf("erroidade\n");
        IndexDp *index = criaIndexDp(dependente, 1);
        fwrite(&index->quantidade, sizeof(int), 1, indexNomeDp);
        fwrite(index->prox, sizeof(Dependente),1, indexNomeDp);
        printf("erroidade\n");
    
    }else if(indexNomeDpAux != NULL && strcmp(indexNomeDpAux->prox->nome, dependente->nome) == 0){
        fseek(indexNomeDp, i * tamanhoIndexDp(), SEEK_SET);
        dpAux = indexNomeDpAux->prox;
        if(dpAux != NULL){
            while(dpAux->proxDp != NULL){
                dpAux = dpAux->proxDp;
            }
            dpAux->proxDp = dependente;
            indexNomeDpAux->quantidade += 1;
        }else{
            indexNomeDpAux->prox = dependente;
            indexNomeDpAux->quantidade += 1;
        }
    
    }
    //Rotina para inserir coddependente em index
    printf("errocodDp\n");
    indexCodDpAux = leIndexDp(indexCodDp);
    printf("errocodDp\n");
    i = 0;
    while(indexCodDpAux != NULL && indexCodDpAux->prox->codDependencia != dependente->codDependencia){
        i++;
        fseek(indexCodDp, i * tamanhoIndexDp(), SEEK_SET);
        indexCodDpAux = leIndexDp(indexCodDp);
        printf("entrou");
    }
    if(indexCodDpAux == NULL){
        printf("errocodDp\n");
        IndexDp *index = criaIndexDp(dependente, 1);
        fwrite(&index->quantidade, sizeof(int), 1, indexCodDp);
        fwrite(index->prox, sizeof(Dependente),1, indexCodDp);
        printf("errocodDp\n");
    
    }else if(indexCodDpAux != NULL && indexCodDpAux->prox->codDependencia == dependente->codDependencia ){
        fseek(indexCodDp, i * tamanhoIndexDp(), SEEK_SET);
        dpAux = indexCodDpAux->prox;
        if(dpAux != NULL){
            while(dpAux->proxDp != NULL){
                dpAux = dpAux->proxDp;
            }
            dpAux->proxDp = dependente;
            indexCodDpAux->quantidade += 1;
        }else{
            indexCodDpAux->prox = dependente;
            indexCodDpAux->quantidade += 1;
        }
    
    }

    //Rotina para inserir dependente no arquivos de dados
    fwrite(&dependente->cod, sizeof(int), 1, out);
    fwrite(&dependente->codDependencia, sizeof(int), 1, out);
    fwrite(&dependente->idade, sizeof(int), 1, out);
    fwrite(dependente->nome, sizeof(char), sizeof(dependente->nome), out);
    fwrite(dependente->proxDp, sizeof(Dependente), 1, out);
    fwrite(dependente->proxCodDp, sizeof(Dependente), 1, out);
    fwrite(dependente->proxIdadeDp, sizeof(Dependente), 1, out);
    fwrite(dependente->proxNomeDp, sizeof(Dependente), 1, out);
}

Empregado *buscaNumDp(int quant, FILE *arqCodDp, FILE *arqindexEmp){
    Dependente *dependente;
    IndexDp *codDp;
    Empregado *empregado;
    IndexEmp *empaux;
    int codaux;
    fseek(arqCodDp, 0,SEEK_SET);
    codDp = leIndexDp(arqCodDp);
    int i = 0;
    while(codDp != NULL && codDp->quantidade < quant){
        i++;
        fseek(arqCodDp, i * tamanhoIndexDp(), SEEK_SET);
        codDp = leIndexDp(arqCodDp);
    }
    if(codDp != NULL && codDp->quantidade >= quant){
        int codaux = codDp->prox->codDependencia; 
    }else{
        printf("não existe nenhum empregado com esse número de dependentes");
    }
    
    fseek(arqindexEmp, 0, SEEK_SET);
    empaux = leIndexEmp(arqindexEmp);
    i = 0;
    while(empaux != NULL && empaux->prox->cod != codaux){
        i++;
        fseek(arqindexEmp, i * tamanhoIndexEmp(), SEEK_SET);
        empaux = leIndexEmp(arqindexEmp);
    }
    if(empaux != NULL && empaux->prox->cod == codaux){
        return empaux->prox;
    }else{
        printf("houve um erro ao buscar o empregado");
    }
}

Dependente *buscaNomeDp(char *nome, FILE *arqNome){
    Dependente *empregado;
    
    
    fseek(arqNome, 0, SEEK_SET);
    IndexDp *nomeEmp = leIndexDp(arqNome);
    
    int i = 0;
    while(nomeEmp != NULL && strcmp(nomeEmp->prox->nome, nome) != 0){
        i++;
        fseek(arqNome, i * tamanhoIndexDp(), SEEK_SET);
        nomeEmp = leIndexDp(arqNome);
    }
    if(nomeEmp != NULL && strcmp(nomeEmp->prox->nome, nome) == 0){
        return nomeEmp->prox;
        
    }else{
        printf("Nossos registros não possuem um empregado com esse nome");
    }
}

Dependente *buscaIdadeDp(int idade, FILE *arqIdadeDp){
    Dependente *dependente;
    IndexDp *idadeDp;
    fseek(arqIdadeDp, 0, SEEK_SET);
    idadeDp = leIndexDp(arqIdadeDp);
    int i = 0;
    while(idadeDp != NULL && idadeDp->prox->idade > idade){
        i++;
        fseek(arqIdadeDp, i * tamanhoIndexDp(), SEEK_SET);
        idadeDp = leIndexDp(arqIdadeDp);
    }
    if(idadeDp != NULL && idadeDp->prox->idade <= idade){
        return idadeDp->prox;
    
    }else{
        printf("não há nenhum dependente com idade menor que %d nos nossos registros", idade);
    }
}

void buscaNomeDeps(int codEmp, FILE *arqCodDp){
    Dependente *dependente;
    IndexDp *indexDp;
    fseek(arqCodDp, 0, SEEK_SET);
    indexDp = leIndexDp(arqCodDp);
    int i = 0;
    while(indexDp != NULL && indexDp->prox->codDependencia != codEmp){
        i++;
        fseek(arqCodDp, i * tamanhoIndexDp(), SEEK_SET);
        indexDp = leIndexDp(arqCodDp);
    }
    if(indexDp != NULL && indexDp->prox->codDependencia == codEmp){
        imprimeDp(indexDp->prox);
        dependente = indexDp->prox;
        while(dependente->proxDp != NULL){
            imprimeDp(dependente->proxDp);
            dependente = dependente->proxDp;
        }
    }
}

Dependente *leDp(FILE *in){
    Dependente *dependente = (Dependente*) malloc(sizeof(Dependente));
    if (0 >= fread(&dependente->cod, sizeof(int), 1, in)) {
	free(dependente);
	return NULL;
    }
    fread(&dependente->codDependencia, sizeof(int), 1, in);
    fread(&dependente->idade, sizeof(int), 1, in);
    fread(dependente->nome, sizeof(char), sizeof(dependente->nome), in);
    dependente->proxDp = malloc(sizeof(Dependente));
    fread(dependente->proxDp, sizeof(Dependente), 1, in);
    dependente->proxCodDp = malloc(sizeof(Dependente));
    fread(dependente->proxCodDp, sizeof(Dependente), 1, in);
    dependente->proxIdadeDp = malloc(sizeof(Dependente));
    fread(dependente->proxIdadeDp, sizeof(Dependente), 1, in);
    dependente->proxNomeDp = malloc(sizeof(Dependente));
    fread(dependente->proxNomeDp, sizeof(Dependente), 1, in);
    return dependente;
}

int tamanhoDp() {
    return 3 * sizeof(int) + sizeof(char) * 50 + sizeof(Dependente) * 4;
}
