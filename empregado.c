#include "empregado.h"
#include "index.h"
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
    empregado->proxEmp = NULL;
    empregado->proxNomeEmp = NULL;
    empregado->proxIdadeEmp = NULL;
    empregado->proxSalarioEmp = NULL;
    
    return empregado;
}

void salvaEmp(int chave, Empregado *empregado, FILE *arqDadosEmp, FILE *arqEmp, FILE *arqNomeEmp, FILE *arqIdadeEmp, FILE *arqSalarioEmp) {
    Empregado *empAux;
    IndexEmp *indexEmpAux;
    IndexEmp *indexIdadeEmpAux;
    IndexEmp *indexNomeEmpAux;

    fseek(arqEmp, tamanhoIndexEmp() * chave, SEEK_SET);
    IndexEmpAux = leIndexEmp(arqEmp);
    
    //Insere no arquivo de índice de empregado
    if(indexEmpAux == NULL){
        index = criaIndexEmp(empregado, 1);
        fseek(arqEmp, tamanhoIndexEmp() * chave, SEEK_SET);
        
        fwrite(&index->quantidade, sizeof(int), arqEmp);
        fwrite(index->prox, sizeof(Empregado), arqEmp);
    
    }else{
        empAux = indexEmpAux;
        indexEmpAux->quantidade += 1;
        while(empAux->prox != NULL){

            empAux = empAux->prox;
        }
        empAux->prox = empregado;
    }
    
    //Rotina para inserir na lista encadeada de Idade;
    indexIdadeEmpAux = leIndexEmp(arqIdadeEmp);

    //Se arquivo estava vazio ele insere no inicio
    if(indexIdadeEmpAux == NULL){
        index = criaIndexEmp(empregado, 1);
        fwrite(&index->quantidade, sizeof(int), arqIdadeEmp);
        fwrite(index->prox, sizeof(Empregado), arqIdadeEmp);
    }else{
        //Se arquivo não estava vazio e a idade do primeiro é igual a do empregado ele insere na primeira lista
        if((indexIdadeEmpAux->prox)->idade == empregado->idade){
            empAux = indexIdadeEmpAux;
            indexIdadeEmpAux->quantidade += 1;
            while(empAux->prox != NULL){
                empAux = empAux->prox;
            }
            empAux->prox = empregado;
        }else{
            //Se o arquivo estava com listas e as idades não batem ele percorre até achar ou NULL ou a idade
            int i = 1;
            while(indexIdadeEmpAux != NULL && (indexIdadeEmpAux->prox)->idade != empregado->idade){

                fseek(arqIdadeEmp, tamanhoIndexEmp() * i, SEEK_SET);
                indexIdadeEmpAux = le(arqIdadeEmp);
                i++;
            }
            //Se achar NULL ele insere no final do arquivo   
            if(indexIdadeEmpAux == NULL){
                fseek(arqIdadeEmp, tamanhoIndexEmp() * i, SEEK_SET);
                index = criaIndexEmp(empregado, 1);
                fwrite(&index->quantidade, sizeof(int), arqIdadeEmp);
                fwrite(index->prox, sizeof(Empregado), arqIdadeEmp);
            }else{
                //Se achar uma lista de idade compatível ele percorre a lista e insere no final
                empAux = indexIdadeEmpAux;
                indexIdadeEmpAux->quantidade += 1;
                while(empAux->prox != NULL){
                    empAux = empAux->prox;
                }

                empAux->prox = empregado;
            }
        }
    }

    //Insere no índice de nomes
    indexNomeEmpAux = leIndexEmp(arqNomeEmp);

    //Se arquivo estava vazio ele insere no inicio
    if(indexNomeEmpAux == NULL){
        index = criaIndexEmp(empregado, 1);
        fwrite(&index->quantidade, sizeof(int), arqNomeEmp);
        fwrite(index->prox, sizeof(Empregado), arqNomeEmp);
    }else{
        //Se arquivo não estava vazio e o nome do primeiro é igual a do empregado ele insere na primeira lista
        if(strcmp((indexNomeEmpAux->prox)->nome, empregado->nome) == 0){
            empAux = indexNomeEmpAux;
            indexNomeEmpAux->quantidade += 1;
            while(empAux->prox != NULL){
                empAux = empAux->prox;
            }
            empAux->prox = empregado;
        }else{
            //Se o arquivo estava com listas e os nomes não batem ele percorre até achar ou NULL ou o nome
            int i = 1;
            while(indexNomeEmpAux != NULL && strcmp((indexNomeEmpAux->prox)->nome, empregado->nome) != 0) {

                fseek(arqNomeEmp, tamanhoIndexEmp() * i, SEEK_SET);
                indexNomeEmpAux = le(arqNomeEmp);
                i++;
            }
            //Se achar NULL ele insere no final do arquivo   
            if(indexNomeEmpAux == NULL){
                fseek(arqNomeEmp, tamanhoIndexEmp() * i, SEEK_SET);
                index = criaIndexEmp(empregado, 1);
                fwrite(&index->quantidade, sizeof(int), arqNomeEmp);
                fwrite(index->prox, sizeof(Empregado), arqNomeEmp);
            }else{
                //Se achar uma lista de nome compatível ele percorre a lista e insere no final
                empAux = indexNomeEmpAux;
                indexIdadeEmpAux->quantidade += 1;
                while(empAux->prox != NULL){
                    empAux = empAux->prox;
                }

                empAux->prox = empregado;
            }
        }
    }

    //Se arquivo estava vazio ele insere no inicio
    if(indexSalarioEmpAux == NULL){
        index = criaIndexEmp(empregado, 1);
        fwrite(&index->quantidade, sizeof(int), arqSalarioEmp);
        fwrite(index->prox, sizeof(Empregado), arqSalarioEmp);
    }else{
        //Se arquivo não estava vazio e o salario do primeiro é igual a do empregado ele insere na primeira lista
        if((indexIdadeEmpAux->prox)->salario == empregado->salario){
            empAux = indexSalarioEmpAux;
            indexIdadeEmpAux->quantidade += 1;
            while(empAux->prox != NULL){
                empAux = empAux->prox;
            }
            empAux->prox = empregado;
        }else{
            //Se o arquivo estava com listas e os salarios não batem ele percorre até achar ou NULL ou o salario
            int i = 1;
            while(indexIdadeEmpAux != NULL && (indexIdadeEmpAux->prox)->salario != empregado->salario){

                fseek(arqSalarioEmp, tamanhoIndexEmp() * i, SEEK_SET);
                indexIdadeEmpAux = le(arqSalarioEmp);
                i++;
            }
            //Se achar NULL ele insere no final do arquivo   
            if(indexSalarioEmpAux == NULL){
                fseek(arqSalarioEmp, tamanhoIndexEmp() * i, SEEK_SET);
                index = criaIndexEmp(empregado, 1);
                fwrite(&index->quantidade, sizeof(int), arqSalarioEmp);
                fwrite(index->prox, sizeof(Empregado), arqSalarioEmp);
            }else{
                //Se achar uma lista de idade compatível ele percorre a lista e insere no final
                empAux = indexSalarioEmpAux;
                indexSalarioEmpAux->quantidade += 1;
                while(empAux->prox != NULL){
                    empAux = empAux->prox;
                }

                empAux->prox = empregado;
            }
        }
    }


    //Rotina para inserir no arquivo de dados
    fwrite(&empregado->cod, sizeof(int), 1, arqDadosEmp);
    fwrite(&empregado->idade, sizeof(int), 1, arqDadosEmp);
    fwrite(&empregado->salario, sizeof(double), 1, arqDadosEmp);
    fwrite(empregado->nome, sizeof(char), sizeof(empregado->nome), arqDadosEmp);
    fwrite(empregado->proxEmp, sizeof(Empregado), 1, arqDadosEmp);
    fwrite(empregado->proxNomeEmp, sizeof(Empregado), 1, arqDadosEmp);
    fwrite(empregado->proxIdadeEmp, sizeof(Empregado), 1, arqDadosEmp);
    fwrite(empregado->proxSalarioEmp, sizeof(Empregado), 1, arqDadosEmp); 
}

Empregado *leEmp(FILE *in) {
    Empregado *empregado = (Empregado *) malloc(sizeof(Empregado));
    if (0 >= fread(&empregado->cod, sizeof(int), 1, in)) {
	free(empregado);
	return NULL;
    }
    fread(&empregado->idade, sizeof(int), 1, in);
    fread(&empregado->salario, sizeof(double), 1, in);
    fread(empregado->nome, sizeof(char), sizeof(empregado->nome), in);
    fread(empregado->proxEmp, sizeof(Empregado), in);
    fread(empregado->proxNomeEmp, sizeof(Empregado), in);
    fread(empregado->proxIdadeEmp, sizeof(Empregado), in);
    fread(empregado->proxSalarioEmp, sizeof(Empregado), in);
    return empregado;
}

int tamanhoEmp() {
    return  2 * sizeof(int) + sizeof(double) + sizeof(char) * 50 + sizeof(Empregado) * 4;
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