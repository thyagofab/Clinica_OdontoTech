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
    novoDentista->filaPacientes = criar_Heap();

    inserir_dentista(tabela, novoDentista);  
    printf("Dentista %s adicionado com sucesso!\n", nome);
}

void adicionar_paciente_dentista(TabelaHash *tabela){ 
    char cpf[12];
    int indice;

    printf("Digite o CPF do dentista: ");
    scanf("%s", cpf);

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
    scanf("%s", cpf);

    indice = hash(cpf, tabela->tamanho);

    if(tabela->dentistas[indice] == NULL){
        printf("Dentista não encontrado!\n");
        return NULL;

    }else{
        printf("Nome: %s\n", tabela->dentistas[indice]->nome);
        printf("CPF: %s\n", tabela->dentistas[indice]->cpf);
    }
}

void remover_dentista(){
    menu_remover_dentista();
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

void inserir_dentista(TabelaHash *tabela, Dentista *dentista){
    int indice = hash(dentista->cpf, tabela->tamanho);
    tabela->dentistas[indice] = dentista;
}

void mostrar_dentistas(TabelaHash *tabela){
    printf("\nDentistas cadastrados:\n");

    for (int i = 0; i < tabela->tamanho; i++){
        if (tabela->dentistas[i] != NULL){
            printf("Nome: %s\n", tabela->dentistas[i]->nome);
            printf("CPF: %s\n", tabela->dentistas[i]->cpf);
            printf("\n");
            mostrar_pacientes(tabela->dentistas[i]->filaPacientes);
        }
    }
}
