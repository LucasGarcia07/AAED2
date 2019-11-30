#include "empregado.h"
#include "index.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void imprimeEmp(Empregado *empregado) {
    printf("\nCódigo do empregado: ");
    printf("%d\n", empregado->cod);
    printf("Nome do empregado: ");
    printf("%s\n", empregado->nome);
    printf("Idade do empregado: ");
    printf("%d\n", empregado->idade);
    printf("Salario do empregado: ");
    printf("%lf\n", empregado->salario);
    printf("flag: %d", empregado->flag);
}

Empregado *criaEmp(int cod, int idade, double salario, char *nome, Empregado *aux) {
    Empregado *empregado = (Empregado *) malloc(sizeof(Empregado));
    if (empregado) memset(empregado, 0, sizeof(Empregado));
    empregado->cod = cod;
    empregado->idade = idade;
    empregado->salario = salario;
    strcpy(empregado->nome, nome);
    empregado->flag = 1;
    empregado->proxEmp = aux;
    empregado->proxNomeEmp = aux;
    empregado->proxIdadeEmp = aux;
    empregado->proxSalarioEmp = aux;
    
    return empregado;
}

void salvaEmp(int chave, Empregado *empregado, FILE *arqDadosEmp, FILE *arqEmp, FILE *arqNomeEmp, FILE *arqIdadeEmp, FILE *arqSalarioEmp) {
    Empregado *empAux;
    IndexEmp *indexEmpAux;
    IndexEmp *indexIdadeEmpAux;
    IndexEmp *indexNomeEmpAux;
    IndexEmp *indexSalarioEmpAux;
    int i = 0;

    fseek(arqEmp, tamanhoIndexEmp() * chave, SEEK_SET);
    indexEmpAux = leIndexEmp(arqEmp);
    
    //Insere no arquivo de índice de empregado
    if(indexEmpAux == NULL || indexEmpAux->quantidade == 0){
        fseek(arqEmp, tamanhoIndexEmp() * chave, SEEK_SET);
        IndexEmp *index;
        index = criaIndexEmp(empregado);
        fseek(arqEmp, tamanhoIndexEmp() * chave, SEEK_SET);
        fwrite(&index->quantidade, sizeof(int),1, arqEmp);
        fwrite(index->prox, sizeof(Empregado),1, arqEmp);
    }else{
        empAux = indexEmpAux->prox;
        while(empAux->proxEmp->cod != -1){
            empAux = empAux->proxEmp;
            printf("passei aqui");
        }
        if(empAux->proxEmp->cod == -1){
            empAux->proxEmp = empregado;
            indexEmpAux->quantidade += 1;
            fseek(arqEmp, tamanhoIndexEmp() * chave, SEEK_SET);
            fwrite(&indexEmpAux->quantidade, sizeof(int),1, arqEmp);
            fwrite(indexEmpAux->prox, sizeof(Empregado),1, arqEmp);
        }
    }
    //Insere no arquivo de índice de Nome de empregado
    fseek(arqNomeEmp, 0, SEEK_SET);
    indexNomeEmpAux = leIndexEmp(arqNomeEmp);
    
    if(indexNomeEmpAux == NULL || indexNomeEmpAux->quantidade == 0){
        fseek(arqNomeEmp, 0, SEEK_SET);
        IndexEmp *index;
        index = criaIndexEmp(empregado);
        fseek(arqEmp, tamanhoIndexEmp() * chave, SEEK_SET);
        fwrite(&index->quantidade, sizeof(int),1, arqEmp);
        fwrite(index->prox, sizeof(Empregado),1, arqEmp);
    }else{
        i = 0;
        while(indexNomeEmpAux != NULL && strcmp(indexNomeEmpAux->prox->nome, empregado->nome) != 0){
            i++;
            fseek(arqNomeEmp, i * tamanhoIndexEmp(),SEEK_SET);
            indexNomeEmpAux = leIndexEmp(arqNomeEmp);
        }
        if(indexNomeEmpAux != NULL && strcmp(indexNomeEmpAux->prox->nome, empregado->nome) == 0){
            empAux = indexNomeEmpAux->prox;
            while(empAux->proxEmp->cod != -1){
                empAux = empAux->proxEmp;
                printf("passei aqui");
            }
            if(empAux->proxEmp->cod == -1){
                empAux->proxEmp = empregado;
                printf("teste emp");
                imprimeEmp(indexNomeEmpAux->prox->proxEmp);
                indexEmpAux->quantidade += 1;
                fseek(arqEmp, tamanhoIndexEmp() * i, SEEK_SET);
                fwrite(&indexEmpAux->quantidade, sizeof(int),1, arqEmp);
                fwrite(indexEmpAux->prox, sizeof(Empregado),1, arqEmp);
            }
        }else{
            fseek(arqNomeEmp, 0, SEEK_SET);
            IndexEmp *index;
            index = criaIndexEmp(empregado);
            fseek(arqEmp, tamanhoIndexEmp() * i, SEEK_SET);
            fwrite(&index->quantidade, sizeof(int),1, arqEmp);
            fwrite(index->prox, sizeof(Empregado),1, arqEmp);
        }
        


    }

    
    // printf("entrou\n");
    // //Rotina para inserir na lista encadeada de Idade;
    // indexIdadeEmpAux = leIndexEmp(arqIdadeEmp);

    // i = 0;
    // while(indexIdadeEmpAux != NULL && (indexIdadeEmpAux->prox)->idade != empregado->idade){
    //     i++;
    //     fseek(arqIdadeEmp, tamanhoIndexEmp() * i, SEEK_SET);
    //     indexIdadeEmpAux = leIndexEmp(arqIdadeEmp);
    // }
    // printf("entrou\n");
    // if(indexIdadeEmpAux == NULL){

    //     IndexEmp *index = criaIndexEmp(empregado, 1);
    //     fwrite(&index->quantidade, sizeof(int),1, arqIdadeEmp);
    //     fwrite(index->prox, sizeof(Empregado),1, arqIdadeEmp);
    // }else if(indexIdadeEmpAux != NULL && indexIdadeEmpAux->prox->idade == empregado->idade){
    //         fseek(arqIdadeEmp, i * tamanhoIndexEmp(), SEEK_SET);
    //         empAux = indexIdadeEmpAux->prox;
    //         if(empAux != NULL){
    //             while(empAux->proxEmp != NULL){
    //                 empAux = empAux->proxEmp;
    //             }
    //         }
    //         empAux->proxEmp = empregado;
    //         indexIdadeEmpAux->quantidade += 1;
    //     }else{
    //         indexIdadeEmpAux->prox = empregado;
    //         indexIdadeEmpAux->quantidade += 1;
    //     }
    
    // printf("entrou\n");
    // //Rotina para inserir na lista encadeada de nomes
    // indexNomeEmpAux = leIndexEmp(arqNomeEmp);

    // i = 0;
    // while(indexNomeEmpAux != NULL && strcmp(indexNomeEmpAux->prox->nome, empregado->nome) != 0){
    //     i++;
    //     fseek(arqNomeEmp, tamanhoIndexEmp() * i, SEEK_SET);
    //     indexNomeEmpAux = leIndexEmp(arqNomeEmp);
    // }

    // if(indexNomeEmpAux == NULL){

    //     IndexEmp *index = criaIndexEmp(empregado, 1);
    //     fwrite(&index->quantidade, sizeof(int),1, arqNomeEmp);
    //     fwrite(index->prox, sizeof(Empregado),1, arqNomeEmp);
    // }else if(indexNomeEmpAux != NULL && strcmp(indexNomeEmpAux->prox->nome, empregado->nome) == 0){
    //         fseek(arqNomeEmp, i * tamanhoIndexEmp(), SEEK_SET);
    //         empAux = indexNomeEmpAux->prox;
    //         if(empAux != NULL){
    //             while(empAux->proxEmp != NULL){
    //                 empAux = empAux->proxEmp;
    //             }
    //         }
    //         empAux->proxEmp = empregado;
    //         indexNomeEmpAux->quantidade += 1;
    //     }else{
    //         indexNomeEmpAux->prox = empregado;
    //         indexNomeEmpAux->quantidade += 1;
    //     }
    
    // printf("entrou\n");
    // //Rotina para inserir na lista encadeada de Salario;
    // indexSalarioEmpAux = leIndexEmp(arqSalarioEmp);

    // i = 0;
    // while(indexSalarioEmpAux != NULL && (indexSalarioEmpAux->prox)->salario != empregado->salario){
    //     i++;
    //     fseek(arqSalarioEmp, tamanhoIndexEmp() * i, SEEK_SET);
    //     indexSalarioEmpAux = leIndexEmp(arqSalarioEmp);
    // }

    // if(indexSalarioEmpAux == NULL){

    //     IndexEmp *index = criaIndexEmp(empregado, 1);
    //     fwrite(&index->quantidade, sizeof(int),1, arqSalarioEmp);
    //     fwrite(index->prox, sizeof(Empregado),1, arqSalarioEmp);
    // }else if(indexSalarioEmpAux != NULL && indexSalarioEmpAux->prox->salario == empregado->salario){
    //         fseek(arqSalarioEmp, i * tamanhoIndexEmp(), SEEK_SET);
    //         empAux = indexSalarioEmpAux->prox;
    //         if(empAux != NULL){
    //             while(empAux->proxEmp != NULL){
    //                 empAux = empAux->proxEmp;
    //             }
    //         }
    //         empAux->proxEmp = empregado;
    //         indexSalarioEmpAux->quantidade += 1;
    //     }else{
    //         indexSalarioEmpAux->prox = empregado;
    //         indexSalarioEmpAux->quantidade += 1;
    //     }
    
    // printf("entrou\n");
    // //Rotina para inserir no arquivo de dados
    
    i = 0;
    fseek(arqDadosEmp, 0, SEEK_SET);
    Empregado *percorreDados = leEmp(arqDadosEmp);
    
    if(percorreDados == NULL){
        fseek(arqDadosEmp, i * tamanhoEmp(), SEEK_SET);
        fwrite(&empregado->cod, sizeof(int), 1, arqDadosEmp);
        fwrite(&empregado->idade, sizeof(int), 1, arqDadosEmp);
        fwrite(&empregado->salario, sizeof(double), 1, arqDadosEmp);
        fwrite(&empregado->flag, sizeof(int), 1, arqDadosEmp);
        fwrite(empregado->nome, sizeof(char), sizeof(empregado->nome), arqDadosEmp);
        fwrite(empregado->proxEmp, sizeof(Empregado), 1, arqDadosEmp);
        fwrite(empregado->proxNomeEmp, sizeof(Empregado), 1, arqDadosEmp);
    }else{
        while(percorreDados != NULL && percorreDados->flag != 0){
            i++;
            fseek(arqDadosEmp, i * tamanhoEmp(), SEEK_SET);
            percorreDados = leEmp(arqDadosEmp);
        }
        fseek(arqDadosEmp, i * tamanhoEmp(), SEEK_SET);
        fwrite(&empregado->cod, sizeof(int), 1, arqDadosEmp);
        fwrite(&empregado->idade, sizeof(int), 1, arqDadosEmp);
        fwrite(&empregado->salario, sizeof(double), 1, arqDadosEmp);
        fwrite(&empregado->flag, sizeof(int), 1, arqDadosEmp);
        fwrite(empregado->nome, sizeof(char), sizeof(empregado->nome), arqDadosEmp);
        fwrite(empregado->proxEmp, sizeof(Empregado), 1, arqDadosEmp);
        fwrite(empregado->proxNomeEmp, sizeof(Empregado), 1, arqDadosEmp);
        // fwrite(empregado->proxIdadeEmp, sizeof(Empregado), 1, arqDadosEmp);
        // fwrite(empregado->proxSalarioEmp, sizeof(Empregado), 1, arqDadosEmp);
    }
}

Empregado *leEmp(FILE *in) {
    Empregado *empregado = (Empregado*) malloc(sizeof(Empregado));
    if (0 >= fread(&empregado->cod, sizeof(int), 1, in)) {
	    free(empregado);
	    return NULL;
    }
    fread(&empregado->idade, sizeof(int), 1, in);
    fread(&empregado->salario, sizeof(double), 1, in);
    fread(&empregado->flag, sizeof(int), 1, in);
    fread(empregado->nome, sizeof(char), sizeof(empregado->nome), in);
    empregado->proxEmp = malloc(sizeof(Empregado));
    fread(empregado->proxEmp, sizeof(Empregado),1, in);
    empregado->proxNomeEmp = malloc(sizeof(Empregado));
    fread(empregado->proxNomeEmp, sizeof(Empregado),1, in);
    empregado->proxIdadeEmp = malloc(sizeof(Empregado));
    fread(empregado->proxIdadeEmp, sizeof(Empregado),1, in);
    empregado->proxSalarioEmp = malloc(sizeof(Empregado));
    fread(empregado->proxSalarioEmp, sizeof(Empregado),1, in);
    return empregado;
}

Empregado *buscaNomeEmp(char *nome, FILE *arqNome){
    Empregado *empregado;
    IndexEmp *nomeEmp;
    fseek(arqNome, 0, SEEK_SET);
    nomeEmp = leIndexEmp(arqNome);
    int i = 0;
    while(nomeEmp != NULL && strcmp(nomeEmp->prox->nome, nome) != 0){
        i++;
        fseek(arqNome, i * tamanhoIndexEmp(), SEEK_SET);
        nomeEmp = leIndexEmp(arqNome);
    }
    if(nomeEmp != NULL && strcmp(nomeEmp->prox->nome, nome) == 0){
        return nomeEmp->prox;
        
    }else{
        printf("Nossos registros não possuem um empregado com esse nome");
    }
}
Empregado *buscaIdadeEmp(int idade, FILE *arqIdade){
    Empregado *empregado;
    IndexEmp *idadeEmp;
    fseek(arqIdade, 0, SEEK_SET);
    idadeEmp = leIndexEmp(arqIdade);
    int i = 0;
    while(idadeEmp != NULL && idadeEmp->prox->idade < idade){
        i++;
        fseek(arqIdade, i* tamanhoIndexEmp(), SEEK_SET);
        idadeEmp = leIndexEmp(arqIdade);
    }
    if(idadeEmp != NULL && idadeEmp->prox->idade >= idade){
        return idadeEmp->prox;      
    }
}
//dado um salario retorna o empregado de maior idade
Empregado *buscaSalarioEmp(double salario, FILE *arqSalarioEmp){
    IndexEmp *empaux;
    Empregado *empregado;
    int i = 0;
    int maiorIdade = 0;
    Empregado *empIdade;
    
    fseek(arqSalarioEmp,0, SEEK_SET);
    empaux = leIndexEmp(arqSalarioEmp);
    while(empaux != NULL && empaux->prox->salario != salario){
        i++;
        fseek(arqSalarioEmp, i * tamanhoIndexEmp(), SEEK_SET);
        empaux = leIndexEmp(arqSalarioEmp);
    }
    if(empaux != NULL && empaux->prox->salario == salario){
        empregado = empaux->prox;
        empIdade = empaux->prox;
        while(empregado->proxEmp != NULL){
            if(empregado->idade < empregado->proxEmp->idade){
                empIdade = empaux->prox;
            }
            empregado = empregado->proxEmp;
        }
        return empIdade;
    }else{
        printf("esse nome não consta nos nossos registros");
    }
}
//Retorna lista de nomes de empregados que possuem o mesmo salário
Empregado *buscaNomeSalarioEmp(double salario, FILE *arqSalarioEmp){
    IndexEmp *empaux;
    Empregado *empregado;
    int i = 0;

    fseek(arqSalarioEmp,0, SEEK_SET);
    empaux = leIndexEmp(arqSalarioEmp);
    while(empaux != NULL && empaux->prox->salario != salario){
        i++;
        fseek(arqSalarioEmp, i * tamanhoIndexEmp(), SEEK_SET);
        empaux = leIndexEmp(arqSalarioEmp);
    }
    if(empaux != NULL && empaux->prox->salario == salario){
        imprimeEmp(empaux->prox);
        empregado = empaux->prox;
        while(empregado->proxEmp != NULL){
            imprimeEmp(empregado->proxEmp);
            empregado = empregado->proxEmp;
        }
    }else{
        printf("esse nome não consta nos nossos registros");
    }
}

void removeEmp(int codigo, FILE *arqDadosEmp, FILE *arqEmp, FILE *arqNomeEmp, FILE *arqIdadeEmp, FILE *arqSalarioEmp){
    Empregado *empregado;
    Empregado *empAux;
    IndexEmp *emp;
    //muda a flag para 0, permitindo que seja inserido um novo empregado nesse espaço
    fseek(arqDadosEmp, 0, SEEK_SET);
    int i = 0;
    empregado = leEmp(arqDadosEmp);
    while(empregado != NULL && empregado->flag != 1 && empregado->cod != codigo){
        i++;
        fseek(arqDadosEmp, i * tamanhoEmp(), SEEK_SET);
        empregado = leEmp(arqDadosEmp);
    }
    if(empregado != NULL && empregado->flag == 1 && empregado->cod == codigo){
        empregado->flag = 0;
    }else if(empregado != NULL && empregado->flag != 1 && empregado->cod == codigo){
        printf("empregado já excluido");
    }else{
        printf("erro ao excluir empregado não está nos nossos registros");
    }
    //exclui da lista encadeada indexEmp
    fseek(arqEmp, 0, SEEK_SET);
    i = 0;
    emp = leIndexEmp(arqEmp);
}

int tamanhoEmp() {
    return  3 * sizeof(int) + sizeof(double) + sizeof(char) * 50 + sizeof(Empregado) * 2;
}

int hash(int x, int m, int *l){
    return x % (m * (int)pow(2, *l));
}

int hashl(int x, int m, int *p, int *l){
    int endereco = hash(x, m, l);
    if(endereco < *p){
        return x % (m * (int)pow(2, *l+1));
    }
    return endereco;
}

double carga(int n, int m){
    return (double)n/m;
}    

void rotina(int m, int n, int *p, int *l){
    if(carga(n, m) > 4){
        *p+= 1;
    }
    if(*p == m-1){
        *p = 0;
        *l+= 1;
    }
}