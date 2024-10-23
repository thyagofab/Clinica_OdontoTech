#ifndef PACIENTE_H
#define PACIENTE_H

typedef enum prioridade { Normal = 1, Preferencial, Emergencial} Prioridade;

// Estrutura de um paciente
typedef struct paciente{
    char nome[100];
    char telefone[15];
    Prioridade prioridade;  
} Paciente;

// Estrutura de uma fila de espera de pacientes
typedef struct heap{
    Paciente **pacientes;  
    int capacidade;        
    int tamanhoAtual;     
} Heap;

// Estrutura de um nó da árvore AVL
typedef struct NoAVL {
    Paciente *paciente;        
    struct NoAVL *esq;         
    struct NoAVL *dir;         
    int alt;                   
} NoAVL;

/*Função que aciona um paciente a fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
*/ 
void *adicionar_paciente(Heap *heap, NoAVL **arvorePacientes);

/*Função que insere um paciente na fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
 @param paciente: paciente a ser inserido.
*/
void inserir_Heap(Heap* heap, Paciente *paciente); 

/*Função que busca um paciente na fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
*/
void buscar_paciente(NoAVL *arvorePacientes);

/*Função que remove um paciente da fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
 @return: retorna um ponteiro para o paciente removido.
*/

Paciente *remover_paciente(Heap* heap, NoAVL **arvorePacientes);
 
// Função criada para testes
void mostrar_pacientes(Heap* heap);

/*Função que organiza a fila de espera de pacientes de acordo com a prioridade.
Utilizada quando um paciente é adicionado à fila.
 @param heap: fila de espera do dentista escolhido.
 @param index: índice do paciente a ser organizado.
*/
void heapify_Acima(Heap *heap, int index);

/*Função que organiza a fila de espera de pacientes de acordo com a prioridade.
Utilizada quando um paciente é removido da fila.
 @param heap: fila de espera do dentista escolhido.
 @param index: índice do paciente a ser organizado.
*/
void heapify_Abaixo(Heap *heap, int index); 

/*Função que troca a posição de dois pacientes. Auxiliar para a função heapify_Acima.
 @param a: ponteiro para o primeiro paciente.
 @param b: ponteiro para o segundo paciente.
*/
void trocar_Pacientes(Paciente **a, Paciente **b);

/*Função que cria uma fila de espera de pacientes para um dentista.
 @return: retorna um ponteiro para a fila de espera.
*/
Heap *criar_Heap(); 

NoAVL *inserir_paciente_AVL(NoAVL *no, Paciente *paciente);

/*Busca um paciente na árvore AVL pelo nome. 
 @param no: Raiz da árvore AVL.
 @param nome: Nome do paciente a ser buscado.
 @return: nó da árvore que contém o paciente buscado.
*/
NoAVL *buscar_paciente_AVL(NoAVL *no, char *nome);

/* Remove um paciente da árvore AVL pelo nome.
 @param raiz: Raiz da árvore AVL.
 @param nome: Nome do paciente a ser removido.
 @return: a nova raiz da árvore AVL após a remoção.
*/
NoAVL *remover_paciente_AVL(NoAVL *raiz, char *nome);

/* Lista os pacientes da árvore AVL em ordem alfabética.
 @param nome: Nome do paciente a ser removido. 
 @param raiz: Raiz da árvore AVL.
*/
void listar_InOrder(NoAVL *raiz);

/* Inicializa uma árvore AVL vazia.
 @param arvorePacientes: Ponteiro para a árvore AVL de pacientes.
*/
void inicializar_AVL(NoAVL **arvorePacientes);

/* Cria um novo nó AVL para um paciente.
 @param paciente: Paciente a ser inserido no nó.
 @return: Um ponteiro para o novo nó AVL.
*/
NoAVL *criar_NoAVL(Paciente *paciente);

/* Realiza uma rotação à direita em um nó AVL.
 @param y: Nó desbalanceado que será rotacionado.
 @return: A nova raiz após a rotação.
*/
NoAVL *rotacao_direita(NoAVL *y);

/* Realiza uma rotação à esquerda em um nó AVL.
 @param x: Nó desbalanceado que será rotacionado.
 @return: A nova raiz após a rotação.
*/
NoAVL *rotacao_esquerda(NoAVL *x);

/* Calcula a altura de um nó AVL.
 @param no: O nó AVL.
 @return: A altura do nó.
*/
int altura_No(NoAVL *no);

/* Calcula o fator de balanceamento de um nó AVL. 
 @param no: O nó AVL.
 @return: O fator de balanceamento do nó.
*/
int balanceamento(NoAVL *no);

/* Retorna o nó com o menor valor (mais à esquerda) na árvore AVL.
 @param no Raiz da subárvore AVL.
 @return O nó com o menor valor.
*/
NoAVL *minValorNo(NoAVL *no);

#endif