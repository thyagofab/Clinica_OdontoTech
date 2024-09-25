#include "../include/sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int definir_prioridade(){
    int opcao;
    printf("Selecione a prioridade do paciente:\n");
    printf("[1] - Normal\n");
    printf("[2] - Preferencial\n");
    printf("[3] - Emergencial\n");
    scanf(" %d", &opcao);

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
        default:
            printf("Opcao invalida!\n");
            break;
    }
    
    return -1;
}
