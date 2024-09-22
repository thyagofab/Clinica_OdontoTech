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

void adicionar_paciente(Heap *heap);

void buscar_paciente();

void atender_paciente(Heap *heap);

Heap *criarHeap();

void trocarPacientes(Paciente** a, Paciente** b); 

void heapifyAcima(Heap* heap, int index);

void heapifyAbaixo(Heap* heap, int index); 

void inserirHeap(Heap* heap, Paciente* paciente); 

// Função criada para testes
void mostrar_pacientes(Heap* heap);

Paciente* removerPaciente(Heap* heap); 