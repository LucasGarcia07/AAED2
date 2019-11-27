#include "empregado.h"
#include "dependente.h"
#include "index.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char comandos[50], nome[50], nomeEmp[50];
    int cod, codDependencia, idade, mEmp = 10, nEmp = 0, mDp = 10, nDp = 0;
    double salario;
    Empregado *empregado;
    FILE *arqDadosEmp, *arqIndexEmp, *arqNomeEmp, *arqIdadeEmp, *arqSalarioEmp, *arqDep, *arqIndexDep, *arqCodDp, *arqIdadeDp, *arqNomeDp;
    
    arqDadosEmp = fopen("empregado.bin", "w+b");
    arqIndexEmp = fopen("indexEmp.bin", "w+b");
    arqNomeEmp = fopen("indexNomeEmp.bin", "w+b");
    arqIdadeEmp = fopen("indexIdadeEmp.bin", "w+b");
    arqSalarioEmp = fopen("indexSalarioEmp.bin", "w+b");
    
    arqDep = fopen("dependente.bin", "w+b");
    arqIndexDep = fopen("indexDp.bin", "w+b");
    arqCodDp = fopen("indexCodDp.bin", "w+b");
    arqIdadeDp = fopen("indexIdadeDp.bin", "w+b");
    arqNomeDp = fopen("indexNomeDp.bin", "w+b");
    Dependente *depentende;

    Dependente *aux = (Dependente*)malloc(sizeof(Dependente));
    aux->cod = -1;

    printf("\n*-----SISTEMA DE CONTROLE DE EMPREGADOS E DEPENDENTES-----*\n");
    printf("\n\n*--LISTA DE COMANDOS--*\n");
    printf("\n novoempregado - Cadastrar funcionário");
    printf("\n novodependente - Cadastrar dependente de funcionário");
    printf("\n nome=JOANA - Encontrar um empregado pelo nome");
    printf("\n idade>20 - Encontrar empregados maiores de uma certa idade");
    printf("\n dependentes>3 - Encontrar empregados com mais de 3 dependentes");
    printf("\n nomedp=JOAQUIN - Encontrar dependente pelo nome");
    printf("\n idade<10 - Encontrar dependente com menos de uma certa idade ");
    printf("\n empregadodps - Lista de nomes de dependentes do empregado");
    printf("\n sair - Fechar o programa\n\n");
    
    //cria, salva e imprime o dependente
    Dependente *dependente = criaDp(1, 1, 1, "1", aux);
    IndexDp *indexDpAux;
    salvaDp(1, dependente,arqIndexDep, arqCodDp, arqIdadeDp, arqNomeDp, arqDep);
    fseek(arqDep, 0, SEEK_SET);
    Dependente *auxx = leDp(arqDep);
    imprimeDp(auxx);
    
    //imprime indexDp
    fseek(arqIndexDep, tamanhoIndexDp(), SEEK_SET);
    indexDpAux = leIndexDp(arqIndexDep);
    if(indexDpAux != NULL){
        imprimeIndexDp(indexDpAux);
    }
    //imprime indexIdade
    fseek(arqIdadeDp, 0, SEEK_SET);
    IndexDp *idadeaux = leIndexDp(arqIdadeDp);
    if(idadeaux != NULL){
        imprimeIndexDp(idadeaux);
    }
    //imprime indexNome
    fseek(arqNomeDp, 0, SEEK_SET);
    IndexDp *nomeaux = leIndexDp(arqNomeDp);
    if(nomeaux != NULL){
        imprimeIndexDp(nomeaux);
    }
    //imprime indexCodDp
    fseek(arqCodDp, 0, SEEK_SET);
    IndexDp *codAux = leIndexDp(arqCodDp);
    if(codAux != NULL){
        imprimeIndexDp(codAux);
    }
    // scanf("%s", comandos);
    // while(strcmp(comandos, "sair") != 0){        
        
    //     if(strcmp(comandos, "novoempregado") == 0){
    //         //Cadastrar empregado
    //         printf("\nDigite o nome: ");
    //         scanf("%s", nome);
    //         printf("\nDigite o codigo: ");
    //         scanf("%d", &cod);
    //         printf("\nDigite a idade: ");
    //         scanf("%d", &idade);
    //         printf("\nDigite o salario: ");
    //         scanf("%lf", &salario);
            
    //         empregado = criaEmp(cod, idade, nome, salario);
            
    //         salvaEmp(10, empregado, arqDadosEmp, arqIndexEmp, arqNomeEmp, arqIdadeEmp, arqSalarioEmp);

    //         Empregado *teste;
    //         // teste = leEmp(arqDadosEmp);
    //         // printf("%d\n", teste->idade);
    //         // imprimeEmp(teste);

    //     }else if(strcmp(comandos, "novodependente")== 0){
    //         //Cadastrar dependente
    //         printf("\nDigite o nome do empregado: ");
    //         scanf("%s", nomeEmp);
    //         printf("\nDigite o nome: ");
    //         scanf("%s", nome);
    //         printf("\nDigite o codigo: ");
    //         scanf("%d", &cod);
    //         printf("\nDigite a idade: ");
    //         scanf("%d", &idade);
    //         printf("Em breve");
    //         strcpy(comandos, "sair");

            
    //     }else if(strcmp(comandos, "empregadodps")== 0){
    //         //Retornar lista de nome dos dependentes do empregado
    //         printf("Digite o nome do empregado: ");
    //         scanf("%s", nome);
    //     }else if(strncmp(comandos,"nome=",5) == 0){
    //         //achar empregado por nome
    //         printf("Em breve");
    //     }else if(strncmp(comandos, "idade>", 6) == 0){
    //         //achar empregado com uma idade maior
    //         printf("Em breve");
    //     }else if(strncmp(comandos, "dependentes>", 12) == 0){
    //         //achar empregado por numero de dependentes
    //         printf("Em breve");
    //     }else if(strncmp(comandos, "nomedp=", 7) == 0){
    //         //encontrar dependente pelo nome
    //         printf("Em breve");
    //     }else if(strncmp(comandos, "idade<", 6) == 0){
    //         //achar empregado com uma idade maior
    //         printf("Em breve");        
    //     }
    // }

    return 0;
}


