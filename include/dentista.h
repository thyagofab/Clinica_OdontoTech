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

TabelaHash *criar_TabelaHash(int tamanho);

int hash(char *chave, int tamanho);

void inserir_dentista(TabelaHash *tabela, Dentista *dentista); 

void adicionar_paciente_dentista(TabelaHash *tabela);

void *buscar_dentista(TabelaHash* tabela);

void remover_dentista();

// Função criada para testes
void mostrar_dentistas(TabelaHash* tabela);