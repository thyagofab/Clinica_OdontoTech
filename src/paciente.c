#include "../include/paciente.h"
#include "../include/sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void *adicionar_paciente(Heap *heap, NoAVL **arvorePacientes){
    char nome[100];
    char telefone[15];
    int prioridadeEscolhida;

    menu_paciente();
    leia_nomes("Informe o nome: ", nome);
    leia_telefone("Informe o telefone: ", telefone);

    prioridadeEscolhida = definir_prioridade();

    Paciente *novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    strcpy(novoPaciente->nome, nome);
    strcpy(novoPaciente->telefone, telefone);
    novoPaciente->prioridade = prioridadeEscolhida;

    inserir_Heap(heap, novoPaciente);

    *arvorePacientes = inserir_paciente_AVL(*arvorePacientes, novoPaciente);
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

Paciente *remover_paciente(Heap *heap, NoAVL **arvorePacientes){
    if (heap->tamanhoAtual == 0){
        printf("Não há pacientes para remover.\n");
        return NULL;
    }

    Paciente *pacienteRemovido = heap->pacientes[0];

    heap->pacientes[0] = heap->pacientes[--heap->tamanhoAtual];

    heapify_Abaixo(heap, 0);

    printf("Paciente %s foi atendido!\n", pacienteRemovido->nome);

    *arvorePacientes = remover_paciente_AVL(*arvorePacientes, pacienteRemovido->nome);

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

    if (esquerda < heap->tamanhoAtual && heap->pacientes[esquerda]->prioridade > heap->pacientes[maiorFilho]->prioridade){
        maiorFilho = esquerda;
    }

    if (direita < heap->tamanhoAtual && heap->pacientes[direita]->prioridade > heap->pacientes[maiorFilho]->prioridade){
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

NoAVL *inserir_paciente_AVL(NoAVL *no, Paciente *paciente){
    if (no == NULL) {
        return criar_NoAVL(paciente);  
    }

    if (strcmp(paciente->nome, no->paciente->nome) < 0){
        no->esq = inserir_paciente_AVL(no->esq, paciente);
    } else if (strcmp(paciente->nome, no->paciente->nome) > 0){
        no->dir = inserir_paciente_AVL(no->dir, paciente);
    } else {
        return no;  
    }

    no->alt = 1 + fmax(altura_No(no->esq), altura_No(no->dir));

    int bal = balanceamento(no);

    if (bal > 1 && strcmp(paciente->nome, no->esq->paciente->nome) < 0){
        return rotacao_direita(no);
    }

    if (bal < -1 && strcmp(paciente->nome, no->dir->paciente->nome) > 0){
        return rotacao_esquerda(no);
    }

    if (bal > 1 && strcmp(paciente->nome, no->esq->paciente->nome) > 0){
        no->esq = rotacao_esquerda(no->esq);
        return rotacao_direita(no);
    }

    if (bal < -1 && strcmp(paciente->nome, no->dir->paciente->nome) < 0){
        no->dir = rotacao_direita(no->dir);
        return rotacao_esquerda(no);
    }

    return no;
}

void buscar_paciente(NoAVL *arvorePacientes){
    char nome[100];
    menu_buscar_paciente();

    leia_nomes("Informe o nome do paciente: ", nome);

    NoAVL *resultado = buscar_paciente_AVL(arvorePacientes, nome);

    if (resultado != NULL) {
        printf("Paciente encontrado!\n");
        printf("Nome: %s, Telefone: %s, Prioridade: %d\n", resultado->paciente->nome, resultado->paciente->telefone, resultado->paciente->prioridade);
    } else {
        printf("Paciente não encontrado.\n");
    }
}

NoAVL *buscar_paciente_AVL(NoAVL *no, char *nome){

    if (no == NULL || strcmp(no->paciente->nome, nome) == 0){
        return no;  
    }

    if (strcmp(nome, no->paciente->nome) < 0){
        return buscar_paciente_AVL(no->esq, nome);
    }

    return buscar_paciente_AVL(no->dir, nome);
}

NoAVL *remover_paciente_AVL(NoAVL *raiz, char *nome){
    if (raiz == NULL){
        return raiz;  
    }

    if (strcmp(nome, raiz->paciente->nome) < 0){
        raiz->esq = remover_paciente_AVL(raiz->esq, nome);
    } else if (strcmp(nome, raiz->paciente->nome) > 0){
        raiz->dir = remover_paciente_AVL(raiz->dir, nome);
    } else {
        if (raiz->esq == NULL || raiz->dir == NULL){
            NoAVL *temp = raiz->esq ? raiz->esq : raiz->dir;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;  
            }

            free(temp->paciente);  
            free(temp); 
        } else {
            NoAVL *temp = minValorNo(raiz->dir);

            raiz->paciente = temp->paciente;

            raiz->dir = remover_paciente_AVL(raiz->dir, temp->paciente->nome);
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->alt = 1 + fmax(altura_No(raiz->esq), altura_No(raiz->dir));

    int bal = balanceamento(raiz);

    if (bal > 1 && balanceamento(raiz->esq) >= 0){
        return rotacao_direita(raiz);
    }

    if (bal < -1 && balanceamento(raiz->dir) <= 0){
        return rotacao_esquerda(raiz);
    }

    if (bal > 1 && balanceamento(raiz->esq) < 0){
        raiz->esq = rotacao_esquerda(raiz->esq);
        return rotacao_direita(raiz);
    }

    if (bal < -1 && balanceamento(raiz->dir) > 0){
        raiz->dir = rotacao_direita(raiz->dir);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

void listar_InOrder(NoAVL *raiz){
    if (raiz != NULL){
        listar_InOrder(raiz->esq);
        printf("Nome: %s, Telefone: %s, Prioridade: %d\n", raiz->paciente->nome, raiz->paciente->telefone, raiz->paciente->prioridade);
        listar_InOrder(raiz->dir);
    }
}

void inicializar_AVL(NoAVL **arvorePacientes){
    *arvorePacientes = NULL;
}

NoAVL *criar_NoAVL(Paciente *paciente){
    NoAVL *novo = (NoAVL *)malloc(sizeof(NoAVL));
    novo->paciente = paciente;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->alt = 1;  
    return novo;
}

NoAVL *rotacao_direita(NoAVL *y){
    NoAVL *x = y->esq;
    NoAVL *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->alt = 1 + fmax(altura_No(y->esq), altura_No(y->dir));
    x->alt = 1 + fmax(altura_No(x->esq), altura_No(x->dir));

    return x;
}

NoAVL *rotacao_esquerda(NoAVL *x){
    NoAVL *y = x->dir;
    NoAVL *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->alt = 1 + fmax(altura_No(x->esq), altura_No(x->dir));
    y->alt = 1 + fmax(altura_No(y->esq), altura_No(y->dir));

    return y;
}

int altura_No(NoAVL *no){
    if (no == NULL){
        return 0;
    }
    return no->alt;
}

int balanceamento(NoAVL *no){
    if (no == NULL){
        return 0;
    }
    return altura_No(no->esq) - altura_No(no->dir);
}

NoAVL *minValorNo(NoAVL *no) {
    NoAVL *atual = no;

    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}
