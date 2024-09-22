#include "../src/paciente.c"

typedef struct{
    char nome[100];
    char cpf[12];  
    Heap *filaPacientes;  
} Dentista;

typedef struct{
    Dentista **dentistas;  
    int tamanho;
} TabelaHash;

Dentista *adicionar_dentista();

TabelaHash *criarTabelaHash(int tamanho);

int hash(char *chave, int tamanho);

void inserirDentista(TabelaHash *tabela, Dentista *dentista); 

void buscar_dentista();

void remover_dentista();

// Função criada para testes
void mostrar_dentistas(TabelaHash* tabela);