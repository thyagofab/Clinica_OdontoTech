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
    leia_nomes("Informe o nome: ", nome);
    leia_cpf("Digite o CPF do dentista: ", cpf);
    leia_nomes("Especialidade do dentista: ", especialidade);

    Dentista *novoDentista = (Dentista*)malloc(sizeof(Dentista));

    strcpy(novoDentista->nome, nome);
    strcpy(novoDentista->cpf, cpf);
    strcpy(novoDentista->especialidade, especialidade);
    novoDentista->filaPacientes = criar_Heap();

    if (inserir_dentista(tabela, novoDentista) == 0){
        printf("Dentista adicionado com sucesso!\n");
    } else if (inserir_dentista(tabela, novoDentista) == 1){
        printf("Dentista com CPF %s já cadastrado!\n", cpf);
    }else{
        printf("Não foi possível adicionar o dentista!\n");
    }
}

int inserir_dentista(TabelaHash *tabela, Dentista *dentista){
    int indice = hash(dentista->cpf, tabela->tamanho);
    int indice_inicial = indice;  
    
    while (tabela->dentistas[indice] != NULL){
        if (strcmp(tabela->dentistas[indice]->cpf, dentista->cpf) == 0){
            return 1;
        }

        indice = (indice + 1) % tabela->tamanho;

        if (indice == indice_inicial){
            printf("Tabela hash está cheia.\n");
            return 2;
        }
    }

    tabela->dentistas[indice] = dentista;
    return 0;
}

void *buscar_dentista(TabelaHash *tabela, char *cpf){
    int retorno, indice, indice_inicial;
    char entrada[12];

    if (strcmp(cpf, "") == 0){
        menu_buscar_dentista();
        leia_cpf("Digite o CPF do dentista: ", entrada);
        retorno = 0;

    } else{
        retorno = 1;
        strcpy(entrada, cpf);  
    }

    indice = hash(entrada, tabela->tamanho);
    indice_inicial = indice;

    while (tabela->dentistas[indice] != NULL){
        if (strcmp(tabela->dentistas[indice]->cpf, entrada) == 0){
            printf("Dentista encontrado!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("========== DENTISTA  ==========\n");
            printf("Nome: %s\n", tabela->dentistas[indice]->nome);
            printf("CPF: %s\n", tabela->dentistas[indice]->cpf);
            printf("Especialidade: %s\n", tabela->dentistas[indice]->especialidade);
            printf("===============================\n");

            if (retorno == 1){
                return tabela->dentistas[indice];
            } else{
                return NULL;
            }

        }
        indice = (indice + 1) % tabela->tamanho;
    }

    if (indice == indice_inicial){
        printf("Dentista não encontrado!\n");
        return NULL;
    }
    
    printf("Dentista não encontrado!\n");
    return NULL;
}

void adicionar_paciente_dentista(TabelaHash *tabela, NoAVL **arvorePacientes){
    char cpf[12];

    leia_cpf("Digite o CPF do dentista: ", cpf);

    Dentista *dentista = buscar_dentista(tabela, cpf);

    if (dentista == NULL){
        printf("Dentista não encontrado!\n");
    } else{
        adicionar_paciente(dentista->filaPacientes, arvorePacientes);
    }
}

void atender_paciente_dentista(TabelaHash *tabela, NoAVL **arvorePacientes){
    char cpf[12];
    int indice;

    menu_atenter_paciente();
    leia_cpf("Digite o CPF do dentista: ", cpf);

    indice = hash(cpf, tabela->tamanho);

    while (tabela->dentistas[indice] != NULL){
        if (strcmp(tabela->dentistas[indice]->cpf, cpf) == 0){
            remover_paciente(tabela->dentistas[indice]->filaPacientes, arvorePacientes);
            remover_paciente_AVL(*arvorePacientes, cpf);
            return;
        }

        indice = (indice + 1) % tabela->tamanho;
    }
    printf("Dentista não encontrado!\n");
}

void remover_dentista(TabelaHash *tabela){
    char cpf[12];

    menu_remover_dentista();
    leia_cpf("Digite o CPF do dentista: ", cpf);

    Dentista *dentista = buscar_dentista(tabela, cpf);

    if (dentista == NULL){
        printf("Dentista não encontrado!\n");
        return;
    }

    if (dentista->filaPacientes->tamanhoAtual > 0){
        printf("O dentista ainda possui pacientes na fila de espera!\n");
        return;
    }

    free(dentista->filaPacientes); 
    dentista->filaPacientes = NULL;

    int indice = hash(cpf, tabela->tamanho);
    int indice_inicial = indice;

    while (tabela->dentistas[indice] != NULL){
        if (strcmp(tabela->dentistas[indice]->cpf, cpf) == 0){
            free(tabela->dentistas[indice]); 
            tabela->dentistas[indice] = NULL;  
            printf("Dentista removido com sucesso!\n");
            return;
        }

        indice = (indice + 1) % tabela->tamanho;

        if (indice == indice_inicial){
            break;
        }
    }

    printf("Erro ao remover o dentista.\n");
}

TabelaHash *criar_TabelaHash(int tamanho){
    TabelaHash *tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    tabela->dentistas = (Dentista**)calloc(tamanho, sizeof(Dentista*));  
    tabela->tamanho = tamanho;
    return tabela;
}

int hash(char *chave, int tamanho){
    int soma = 0;

    for (int i = 0; chave[i] != '\0'; i++){
        soma += chave[i]; 
    }

    return soma % tamanho; 
}

void mostrar_dentistas(TabelaHash *tabela){
    for (int i = 0; i < tabela->tamanho; i++){
        if (tabela->dentistas[i] != NULL) {
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
