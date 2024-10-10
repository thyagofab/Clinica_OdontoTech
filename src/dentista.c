#include "../include/dentista.h"
#include "../include/sistema.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *adicionar_dentista(TabelaHash *tabela){
    char nome[100];
    char cpf[12];
    char especialidade[100];

    menu_dentista();
    
    printf("Digite o nome do dentista: ");
    scanf(" %[^\n]", nome);
    printf("Digite o CPF do dentista: ");
    scanf(" %[^\n]", cpf);
    printf("Digite a especialidade do dentista: ");
    scanf(" %[^\n]", especialidade);

    Dentista *novoDentista = (Dentista*)malloc(sizeof(Dentista));

    strcpy(novoDentista->nome, nome);
    strcpy(novoDentista->cpf, cpf);
    strcpy(novoDentista->especialidade, especialidade);
    novoDentista->filaPacientes = criar_Heap();

    inserir_dentista(tabela, novoDentista);  
    printf("Dentista %s adicionado com sucesso!\n", nome);
}

void atender_paciente_dentista(TabelaHash *tabela){
    char cpf[12];
    int indice;

    menu_atenter_paciente();
    printf("Digite o CPF do dentista: ");
    scanf(" %[^\n]", cpf);

    indice = hash(cpf, tabela->tamanho);

    if(tabela->dentistas[indice] == NULL){
        printf("Dentista não encontrado!\n");

    }else{
        printf("Denstista encontrado!\n");
        system("pause");
        remover_paciente(tabela->dentistas[indice]->filaPacientes);
    }
} 

void adicionar_paciente_dentista(TabelaHash *tabela){ 
    char cpf[12];
    int indice;

    printf("Digite o CPF do dentista: ");
    scanf(" %[^\n]", cpf);

    indice = hash(cpf, tabela->tamanho);

    if(tabela->dentistas[indice] == NULL){
        printf("Dentista não encontrado!\n");

    }else{
        adicionar_paciente(tabela->dentistas[indice]->filaPacientes);
    }
}

void *buscar_dentista(TabelaHash *tabela){
    char cpf[12];
    int indice;

    menu_buscar_dentista();
    printf("Digite o CPF do dentista: ");
    scanf(" %[^\n]", cpf);

    indice = hash(cpf, tabela->tamanho);

    if(tabela->dentistas[indice] == NULL){
        printf("Dentista não encontrado!\n");
        return NULL;

    }else{
        printf("Dentista encontrado!\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("========== DENTISTA  ==========\n");
        printf("Nome: %s\n", tabela->dentistas[indice]->nome);
        printf("CPF: %s\n", tabela->dentistas[indice]->cpf);
        printf("Especialidade: %s\n", tabela->dentistas[indice]->especialidade);
        printf("===============================\n");
    }
}

void inserir_dentista(TabelaHash *tabela, Dentista *dentista){
    int indice = hash(dentista->cpf, tabela->tamanho);
    tabela->dentistas[indice] = dentista;
}

void remover_dentista(TabelaHash *tabela){
    char cpf[12];

    menu_remover_dentista();
    printf("Digite o CPF do dentista: ");
    scanf(" %[^\n]", cpf);

    int indice = hash(cpf, tabela->tamanho);

    if(tabela->dentistas[indice] == NULL){
        printf("Dentista não encontrado!\n");

    }else{

        if(tabela->dentistas[indice]->filaPacientes->tamanhoAtual > 0){
            printf("O dentista ainda possui pacientes na fila de espera!\n");
            return;
        }

        free(tabela->dentistas[indice]);
        tabela->dentistas[indice] = NULL;
        printf("Dentista %s removido com sucesso!\n", tabela->dentistas[indice]->nome);
    }
}

TabelaHash *criar_TabelaHash(int tamanho){
    TabelaHash *tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    tabela->dentistas = (Dentista**)calloc(tamanho, sizeof(Dentista*));  
    tabela->tamanho = tamanho;
    return tabela;
}

int hash(char *chave, int tamanho){
    int soma = 0;

    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i]; 
    }

    return soma % tamanho; 
}

void mostrar_dentistas(TabelaHash *tabela){
    for (int i = 0; i < tabela->tamanho; i++){
        if (tabela->dentistas[i] != NULL){
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("========== DENTISTA  ==========\n");
            printf("Nome: %s\n", tabela->dentistas[i]->nome);
            printf("CPF: %s\n", tabela->dentistas[i]->cpf);
            printf("Especialidade: %s\n", tabela->dentistas[i]->especialidade);
            printf("===============================\n");
            mostrar_pacientes(tabela->dentistas[i]->filaPacientes);
        }
    }
}
