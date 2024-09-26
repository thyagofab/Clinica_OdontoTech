#ifndef PACIENTE_H
#define PACIENTE_H

typedef enum prioridade { Normal = 1, Preferencial, Emergencial} Prioridade;

typedef struct paciente{
    char nome[100];
    char telefone[15];
    Prioridade prioridade;  
} Paciente;

typedef struct heap{
    Paciente **pacientes;  
    int capacidade;        
    int tamanhoAtual;     
} Heap;

void *adicionar_paciente(Heap *heap);

void buscar_paciente();

void atender_paciente(Heap *heap);

Heap *criar_Heap();

void trocar_Pacientes(Paciente **a, Paciente **b); 

void heapify_Acima(Heap *heap, int index);

void heapify_Abaixo(Heap *heap, int index); 

void inserir_Heap(Heap* heap, Paciente *paciente); 

// Função criada para testes
void mostrar_pacientes(Heap* heap);

Paciente *remover_paciente(Heap* heap); 

#endif