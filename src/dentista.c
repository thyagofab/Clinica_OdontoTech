#include "../include/dentista.h"

Dentista *adicionar_dentista(TabelaHash *tabela){
    char nome[100];
    char cpf[12];
    
    menu_dentista();
    
    printf("Digite o nome do dentista: ");
    scanf("%s", nome);
    printf("Digite o CPF do dentista: ");
    scanf("%s", cpf);
    
    Dentista *novoDentista = (Dentista*)malloc(sizeof(Dentista));

    strcpy(novoDentista->nome, nome);
    strcpy(novoDentista->cpf, cpf);
    novoDentista->filaPacientes = criarHeap();

    inserirDentista(tabela, novoDentista);  
    printf("Dentista %s adicionado com sucesso!\n", nome);
}

void adicionarPacienteDentista(Dentista *dentista, Paciente *paciente){
    inserirHeap(dentista->filaPacientes, paciente); 
}


void buscar_dentista(){
    menu_buscar_dentista();
}

void remover_dentista(){
    menu_remover_dentista();
}

TabelaHash* criarTabelaHash(int tamanho){
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
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

void inserirDentista(TabelaHash* tabela, Dentista* dentista){
    int indice = hash(dentista->cpf, tabela->tamanho);
    tabela->dentistas[indice] = dentista;
}

void mostrar_dentistas(TabelaHash* tabela){
    printf("Dentistas cadastrados:\n");

    for (int i = 0; i < tabela->tamanho; i++){
        if (tabela->dentistas[i] != NULL){
            printf("Nome: %s\n", tabela->dentistas[i]->nome);
            printf("CPF: %s\n", tabela->dentistas[i]->cpf);
            printf("\n");
        }
    }
}