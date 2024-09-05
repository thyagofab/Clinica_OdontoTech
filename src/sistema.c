#include <stdio.h>
#include <stdlib.h>
#include "../include/sistema.h"

void menu(){
    printf("[1] - adicionar dentista\n");
    printf("[2] - buscar dentista\n");
    printf("[3] - remover dentista\n");
    printf("[4] - adicionar paciente\n");
    printf("[5] - remover paciente\n");
    printf("[6] - listar pacientes\n");
    printf("[7] - sair\n");
    printf("------------------------------\n");
}

void menu_dentista(){
    system("cls");
    printf("==========================\n");
    printf("|   ADICIONAR DENTISTA   |\n");
    printf("==========================\n");
    printf("|   NOME:  xxxxxxxxx     |\n");
    printf("|   ESPECIALIADE: xxxxxx |\n");
    printf("==========================\n");
    system("pause");
    system("cls");
}

void menu_buscar_dentista(){
    system("cls");
    printf("=========================\n");
    printf("|    BUSCAR DENTISTA    |\n");
    printf("=========================\n");
    printf("|    NOME:  xxxxxxxxx   |\n");
    printf("=========================\n");
    system("pause");
    system("cls");
}

void menu_remover_dentista(){
    system("cls");
    printf("=========================\n");
    printf("|    REMOVER DENTISTA   |\n");
    printf("=========================\n");
    printf("|    NOME:  xxxxxxxxx   |\n");
    printf("=========================\n");
    system("pause");
    system("cls");
}

