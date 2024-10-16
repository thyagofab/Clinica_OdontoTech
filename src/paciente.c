#include "../include/paciente.h"
#include "../include/sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *adicionar_paciente(Heap *heap){
    char nome[100];
    char telefone[15];
    int prioridadeEscolhida;
    Prioridade prioridade;

    menu_paciente();
    leia_nomes("Informe o nome: ", nome);
    leia_telefone("Informe o telefone: ", telefone);

    prioridadeEscolhida = definir_prioridade();

    Paciente *novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    strcpy(novoPaciente->nome, nome);
    strcpy(novoPaciente->telefone, telefone);
    novoPaciente->prioridade = prioridadeEscolhida;

    inserir_Heap(heap, novoPaciente);
    printf("Paciente %s adicionado com sucesso!\n", nome);
}

void inserir_Heap(Heap *heap, Paciente *paciente){
    
    if (heap->tamanhoAtual == heap->capacidade) {
        heap->capacidade *= 2;
        heap->pacientes = (Paciente**)realloc(heap->pacientes, heap->capacidade * sizeof(Paciente*));
    }

    heap->pacientes[heap->tamanhoAtual] = paciente;

    heapify_Acima(heap, heap->tamanhoAtual);

    heap->tamanhoAtual++;
}

void buscar_paciente(){
    menu_buscar_paciente();
}

Paciente *remover_paciente(Heap *heap){
    if (heap->tamanhoAtual == 0){
        printf("Não há pacientes para remover.\n");
        return NULL;
    }

    Paciente *pacienteRemovido = heap->pacientes[0];

    heap->pacientes[0] = heap->pacientes[--heap->tamanhoAtual];

    heapify_Abaixo(heap, 0);

    printf("Paciente %s foi atendido!\n", pacienteRemovido->nome);
    return pacienteRemovido;
}

void heapify_Acima(Heap *heap, int indice){
    if (indice == 0){
        return;
    } 
    
    int pai = (indice - 1) / 2;  
    
    if (heap->pacientes[indice]->prioridade > heap->pacientes[pai]->prioridade){    
        trocar_Pacientes(&heap->pacientes[indice], &heap->pacientes[pai]);
        heapify_Acima(heap, pai);
    }
}

void heapify_Abaixo(Heap *heap, int indice){
    int maiorFilho = indice;
    int esquerda = 2 * indice + 1;  
    int direita = 2 * indice + 2;   

    if (esquerda < heap->tamanhoAtual && heap->pacientes[esquerda]->prioridade > heap->pacientes[maiorFilho]->prioridade) {
        maiorFilho = esquerda;
    }

    if (direita < heap->tamanhoAtual && heap->pacientes[direita]->prioridade > heap->pacientes[maiorFilho]->prioridade) {
        maiorFilho = direita;
    }

    if (maiorFilho != indice) {
        trocar_Pacientes(&heap->pacientes[indice], &heap->pacientes[maiorFilho]);
        heapify_Abaixo(heap, maiorFilho);  
    }
}

void trocar_Pacientes(Paciente **a, Paciente **b){
    Paciente* temp = *a;
    *a = *b;
    *b = temp;
}

Heap *criar_Heap(){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    
    heap->capacidade = 10;
    heap->pacientes = (Paciente**)malloc(sizeof(Paciente*) *heap->capacidade);    
    heap->tamanhoAtual = 0;

    return heap;
}

void mostrar_pacientes(Heap *heap){
    int i;

    if (heap->tamanhoAtual == 0){
        printf("Nenhum paciente na fila de espera.\n");
        system("pause");
        return;
    }
    
    printf("Pacientes na fila de espera: %d\n", heap->tamanhoAtual);
    printf("=-=-=-=-=-PACIENTES-=-=-=-=-=-\n");
    for (i = 0; i < heap->tamanhoAtual; i++){
        printf("Nome: %s, Telefone: %s, Prioridade: %d\n", heap->pacientes[i]->nome, heap->pacientes[i]->telefone, heap->pacientes[i]->prioridade);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
    system("pause");
    printf("\n");
}
