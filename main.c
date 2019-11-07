#include "empregado.h"
#include "dependente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char comandos[50], nome[50], nomeEmp[50];
    int cod, codDependencia, idade;
    double salario;

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
    printf("\n sair - Fechar o programa");
    
    while(strcmp(comandos, "sair") != 0){        
        
        if(strcmp(comandos, "novoempregado") == 0){
            //Cadastrar empregado
            printf("\nDigite o nome: ");
            scanf("%s", nome);
            printf("\nDigite o codigo: ");
            scanf("%d", &cod);
            printf("\nDigite a idade: ");
            scanf("%d", &idade);
            printf("\nDigite o salario: ");
            scanf("%lf", &salario);
            
            Empregado *emp = criaEmpregado(cod, idade, nome, salario);
            salva(emp, out);

        }else if(strcmp(comandos, "novodependente")== 0){
            //Cadastrar dependente
            printf("\nDigite o nome do empregado: ");
            scanf("%s", nomeEmp);
            printf("\nDigite o nome: ");
            scanf("%s", nome);
            printf("\nDigite o codigo: ");
            scanf("%d", &cod);
            printf("\nDigite a idade: ");
            scanf("%d", &idade);

            
        }else if(strcmp(comandos, "empregadodps")== 0){
            //Retornar lista de nome dos dependentes do empregado
            printf("Digite o nome do empregado: ");
            scanf("%s", nome);
        }else if(strncmp(comandos,"nome=",5) == 0){
            //achar empregado por nome
            printf("Em breve");
        }else if(strncmp(comandos, "idade>", 6) == 0){
            //achar empregado com uma idade maior
            printf("Em breve");
        }else if(strncmp(comandos, "dependentes>", 12) == 0){
            //achar empregado por numero de dependentes
            printf("Em breve");
        }else if(strncmp(comandos, "nomedp=", 7) == 0){
            //encontrar dependente pelo nome
            printf("Em breve");
        }else if(strncmp(comandos, "idade<", 6) == 0){
            //achar empregado com uma idade maior
            printf("Em breve");        
    }


}


