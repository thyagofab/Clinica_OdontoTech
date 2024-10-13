#include "../include/sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

void menu(){
    printf("=========== MENU =============\n");
    printf("[1] adicionar dentista\n");
    printf("[2] buscar dentista\n");
    printf("[3] remover dentista\n");
    printf("[4] adicionar paciente\n");
    printf("[5] atender paciente\n");
    printf("[6] buscar pacientes\n");
    printf("[7] sair\n");
    printf("==============================\n");
}

void menu_dentista(){
    system("cls");
    printf("==========================\n");
    printf("|   ADICIONAR DENTISTA   |\n");
    printf("==========================\n");
    printf("|   NOME: xxxxxxxxx      |\n");
    printf("|   CPF:  xxxxxxxxx      |\n");
    printf("|   ESPECIALIADE: xxxxxx |\n");
    printf("==========================\n");
    system("pause");
}

void menu_buscar_dentista(){
    system("cls");
    printf("=========================\n");
    printf("|    BUSCAR DENTISTA    |\n");
    printf("=========================\n");
    printf("|    CPF:  xxxxxxxxx    |\n");
    printf("=========================\n");
    system("pause");
}

void menu_remover_dentista(){
    system("cls");
    printf("=========================\n");
    printf("|    REMOVER DENTISTA   |\n");
    printf("=========================\n");
    printf("|    CPF:  xxxxxxxxx    |\n");
    printf("=========================\n");
    system("pause");
}

void menu_paciente(){
    system("cls");
    printf("==========================\n");
    printf("|   ADICIONAR PACIENTE   |\n");
    printf("==========================\n");
    printf("|   NOME:  xxxxxxxxx     |\n");
    printf("|   TELEFONE: 9xxxx-YYYY |\n");
    printf("==========================\n");
    system("pause");
}

void menu_buscar_paciente(){
    system("cls");
    printf("=========================\n");
    printf("|    BUSCAR PACIENTE    |\n");
    printf("=========================\n");
    printf("|    NOME:  xxxxxxxxx   |\n");
    printf("=========================\n");
    system("pause");
    system("cls");
}

void menu_atenter_paciente(){
    system("cls");
    printf("=========================\n");
    printf("|    ATENDER PACIENTE   |\n");
    printf("=========================\n");
    printf("|    CPF:  xxxxxxxxx    |\n");
    printf("=========================\n");
    system("pause");
}

void menu_definir_prioridade(){
    
    printf("===========================\n");
    printf("|    DEFINIR PRIORIDADE   |\n");
    printf("===========================\n");
    printf("|    [1] - Normal         |\n");
    printf("|    [2] - Preferencial   |\n");
    printf("|    [3] - Emergencial    |\n");
    printf("===========================\n");
}

int definir_prioridade(){
    int opcao;

    menu_definir_prioridade();
    leia_numeros("", &opcao);

    while (opcao < 1 || opcao > 3){
        printf("Opcao invalida!\n");
        sleep(1);
        menu_definir_prioridade();
        leia_numeros("", &opcao);
    }

    switch (opcao){
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
    }
}

void leia_nomes(char *texto, char *nome){
    int indice, teste = 0; 

    while (!teste){ 
        printf("%s", texto);
        scanf(" %[^\n]", nome);

        teste = 1;  

        for (indice = 0; nome[indice] != '\0'; indice++){
            if (!isalpha(nome[indice]) && nome[indice] != ' '){
                printf("Esse campo deve conter apenas letras e espaços.\n");
                teste = 0; 
                break;  
            }
        }
    }
}

void leia_numeros(char *texto, int *numero){
    int indice, teste = 0;
    char entrada[10];

    while (!teste){  
        printf("%s", texto);
        scanf(" %[^\n]", entrada);

        teste = 1; 

        for (indice = 0; entrada[indice] != '\0'; indice++){
            if (!isdigit(entrada[indice])){ 
                printf("Esse campo deve conter apenas números.\n");
                teste = 0;  
                break;  
            }
        }

        if (teste){
            *numero = atoi(entrada);  
        }
    }
}

void leia_telefone(char *texto, char *telefone){
    int indice, teste = 0;

    while (!teste){
        printf("%s", texto);
        scanf(" %[^\n]", telefone);

        teste = 1;

        if (strlen(telefone) != 9){
            printf("O telefone deve conter exatamente 9 dígitos.\n");
            teste = 0;
            continue;
        }

        for (indice = 0; telefone[indice] != '\0'; indice++){
            if (!isdigit(telefone[indice])){
                printf("Esse campo deve conter apenas números.\n");
                teste = 0;
                break;
            }
        }
    } 
}

void leia_cpf(char *texto, char *cpf){
    int indice, teste = 0;

    while (!teste){
        printf("%s", texto);
        scanf(" %[^\n]", cpf);

        teste = 1;

        if (strlen(cpf) != 11){
            printf("O CPF deve conter exatamente 11 dígitos.\n");
            teste = 0;
            continue;
        }

        for (indice = 0; cpf[indice] != '\0'; indice++){
            if (!isdigit(cpf[indice])){
                printf("Esse campo deve conter apenas números.\n");
                teste = 0;
                break;
            }
        }
    }
}

void salvar_dentistas_pacientes(TabelaHash *tabela) {
    FILE *arquivo;
    int i, j;

    arquivo = fopen("dentistas_pacientes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (i = 0; i < tabela->tamanho; i++) {
        if (tabela->dentistas[i] != NULL) {
            fprintf(arquivo, "%s %s %s\n", tabela->dentistas[i]->nome, tabela->dentistas[i]->cpf, tabela->dentistas[i]->especialidade);

            fprintf(arquivo, "%d\n", tabela->dentistas[i]->filaPacientes->tamanhoAtual);

            for (j = 0; j < tabela->dentistas[i]->filaPacientes->tamanhoAtual; j++) {
                fprintf(arquivo, "%s %s %d\n", tabela->dentistas[i]->filaPacientes->pacientes[j]->nome, 
                    tabela->dentistas[i]->filaPacientes->pacientes[j]->telefone, 
                    tabela->dentistas[i]->filaPacientes->pacientes[j]->prioridade);
            }
        }
    }

    fclose(arquivo);
}

void carregar_dentistas_pacientes(TabelaHash *tabela) {
    FILE *arquivo;
    char nome[100], cpf[12], especialidade[100], telefone[10];
    int i, j, prioridade, tamanhoFila;

    arquivo = fopen("dentistas_pacientes.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

     while (fscanf(arquivo, "%s %s %s", nome, cpf, especialidade) == 3) {
        Dentista *dentista = criar_dentista(nome, cpf, especialidade);
        inserir_dentista(tabela, dentista);

        fscanf(arquivo, "%d", &tamanhoFila);

        for (i = 0; i < tamanhoFila; i++) {
            fscanf(arquivo, "%s %s %d", nome, telefone, &prioridade);
            Paciente *paciente = criar_paciente(nome, telefone, prioridade);
            inserir_Heap(dentista->filaPacientes, paciente); 
        }
    }

    fclose(arquivo);
}

Dentista *criar_dentista(char *nome, char *cpf, char *especialidade) {
        Dentista *novoDentista = (Dentista *)malloc(sizeof(Dentista));
        strcpy(novoDentista->nome, nome);
        strcpy(novoDentista->cpf, cpf);
        strcpy(novoDentista->especialidade, especialidade);
        novoDentista->filaPacientes = criar_Heap();  
        return novoDentista;
}

 Paciente *criar_paciente(char *nome, char *telefone, int prioridade) {
        Paciente *novoPaciente = (Paciente *)malloc(sizeof(Paciente));
        strcpy(novoPaciente->nome, nome);
        strcpy(novoPaciente->telefone, telefone);
        novoPaciente->prioridade = prioridade;
        return novoPaciente;
}