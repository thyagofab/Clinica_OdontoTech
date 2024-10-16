#ifndef DENTISTA_H
#define DENTISTA_H
#include "../include/paciente.h"

typedef struct{
    char nome[100];
    char cpf[12];  
    char especialidade[100];
    Heap *filaPacientes;  
} Dentista;

typedef struct{
    Dentista **dentistas;  
    int tamanho;
} TabelaHash;

/* Função que aciona um dentista a tabela hash.
* @param tabela: tabela hash que contém os dentistas.
* @return: retorna um ponteiro para o dentista.
*/
void *adicionar_dentista(TabelaHash *tabela);

/* Função que adiciona um paciente a um dentista.
* @param tabela: tabela hash que contém os dentistas.
*/
void adicionar_paciente_dentista(TabelaHash *tabela);

/* Função que atende um paciente de um dentista.
* @param tabela: tabela hash que contém os dentistas.
*/
void atender_paciente_dentista(TabelaHash *tabela);

/* Função que cria uma tabela hash de acordo com o tamanho definido.
* @param tamanho: tamanho da tabela hash.
*/

/* Função que busca um dentista na tabela hash.
* @param tabela: tabela hash que contém os dentistas.
* @param cpf: CPF do dentista a ser buscado.
*/
void *buscar_dentista(TabelaHash* tabela, char *cpf);

/* Função que insere um dentista na tabela hash.
* @param tabela: tabela hash que contém os dentistas.
* @param dentista: dentista a ser inserido.
*/
int inserir_dentista(TabelaHash *tabela, Dentista *dentista); 

/* Função que remove um dentista da tabela hash.
* @param tabela: tabela hash que contém os dentistas.
*/
void remover_dentista(TabelaHash *tabela);

/* Função que inicializa uma tabela hash.
*/
TabelaHash *criar_TabelaHash(int tamanho);

/* Função que calcula o hash de uma chave (CPF).
* @param chave: chave a ser calculada.
* @param tamanho: tamanho da tabela hash.
*/
int hash(char *chave, int tamanho);

// Função criada para testes
void mostrar_dentistas(TabelaHash* tabela);

#endif