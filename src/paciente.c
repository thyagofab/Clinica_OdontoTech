#include "../include/paciente.h"
#include "sistema.c"

void adicionar_paciente(Heap *heap){
    char nome[100];
    char telefone[15];
    int prioridadeEscolhida;
    Prioridade prioridade;

    menu_paciente();

    printf("Nome do paciente: ");
    scanf("%s", nome);
    printf("Telefone do paciente: ");
    scanf("%s", telefone);

    prioridadeEscolhida = definir_prioridade();

    Paciente *novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    strcpy(novoPaciente->nome, nome);
    strcpy(novoPaciente->telefone, telefone);
    novoPaciente->prioridade = prioridadeEscolhida;

    inserirHeap(heap, novoPaciente);
    printf("Paciente %s adicionado com sucesso!\n", nome);

}

void buscar_paciente(){
    menu_buscar_paciente();
}

void atender_paciente(Heap *heap){
    menu_atenter_paciente();
    removerPaciente(heap);
}

Heap *criarHeap(){

    Heap *heap = (Heap*)malloc(sizeof(Heap));
    
    heap->capacidade = 10;
    
    heap->pacientes = (Paciente**)malloc(sizeof(Paciente*) *heap->capacidade);
    
    heap->tamanhoAtual = 0;
    
    return heap;
}

void trocarPacientes(Paciente **a, Paciente **b){
    Paciente* temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyAcima(Heap *heap, int index){
    if (index == 0){
        return;
    } 
    
    int pai = (index - 1) / 2;  
    
    if (heap->pacientes[index]->prioridade > heap->pacientes[pai]->prioridade){    
        trocarPacientes(&heap->pacientes[index], &heap->pacientes[pai]);
        heapifyAcima(heap, pai);
    }
}

void heapifyAbaixo(Heap *heap, int index){
    int maiorFilho = index;
    int esquerda = 2 * index + 1;  
    int direita = 2 * index + 2;   

    if (esquerda < heap->tamanhoAtual && heap->pacientes[esquerda]->prioridade > heap->pacientes[maiorFilho]->prioridade) {
        maiorFilho = esquerda;
    }

    if (direita < heap->tamanhoAtual && heap->pacientes[direita]->prioridade > heap->pacientes[maiorFilho]->prioridade) {
        maiorFilho = direita;
    }

    if (maiorFilho != index) {
        trocarPacientes(&heap->pacientes[index], &heap->pacientes[maiorFilho]);
        heapifyAbaixo(heap, maiorFilho);  
    }
}

void inserirHeap(Heap *heap, Paciente *paciente){
    
    if (heap->tamanhoAtual == heap->capacidade) {
        heap->capacidade *= 2;
        heap->pacientes = (Paciente**)realloc(heap->pacientes, heap->capacidade * sizeof(Paciente*));
    }

    heap->pacientes[heap->tamanhoAtual] = paciente;

    heapifyAcima(heap, heap->tamanhoAtual);

    heap->tamanhoAtual++;
}

void mostrar_pacientes(Heap *heap){
    printf("Pacientes na fila de espera:\n");

    for (int i = 0; i < heap->tamanhoAtual; i++) {
        printf("Nome: %s, Telefone: %s, Prioridade: %d\n", heap->pacientes[i]->nome, heap->pacientes[i]->telefone, heap->pacientes[i]->prioridade);
    }
    system("pause");
}

Paciente* removerPaciente(Heap* heap) {
    if (heap->tamanhoAtual == 0) {
        printf("Erro: Heap vazia. Não há pacientes para remover.\n");
        return NULL;
    }

    Paciente* pacienteRemovido = heap->pacientes[0];

    heap->pacientes[0] = heap->pacientes[--heap->tamanhoAtual];

    heapifyAbaixo(heap, 0);

    return pacienteRemovido;
}
