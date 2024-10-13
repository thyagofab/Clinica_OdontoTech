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

/*Função que aciona um paciente a fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
*/ 
void *adicionar_paciente(Heap *heap);

/*Função que insere um paciente na fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
 @param paciente: paciente a ser inserido.
*/
void inserir_Heap(Heap* heap, Paciente *paciente); 

/*Função que busca um paciente na fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
*/
void buscar_paciente();

/*Função que remove um paciente da fila de espera de um dentista.
 @param heap: fila de espera do dentista escolhido.
 @return: retorna um ponteiro para o paciente removido.
*/
Paciente *remover_paciente(Heap* heap); 

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

// Função criada para testes
void mostrar_pacientes(Heap* heap);

#endif