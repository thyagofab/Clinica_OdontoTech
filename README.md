<img align="right" width="80" height="80" src="https://assecom.ufersa.edu.br/wp-content/uploads/sites/24/2014/09/PNG-bras%C3%A3o-Ufersa.png">

<h1 align="center">Clínica Odontológica-OdontoTech</h1>

<br> 

## Navegação do Projeto:

- [Proposta do Projeto](#proposta-do-projeto)
- [Funcionalidades do Projeto](#funcionalidades-do-projeto)
- [Estrutura de Diretórios](#estrutura-de-diretórios-do-projeto)
- [Compilar o Código](#compilar-o-código)
- [Implementação](#implementacao)
- [Colaboradores](#colaboradores)


# Proposta do Projeto

<p> O objetivo deste projeto é desenvolver um sistema de gerenciamento para clínicas odontológicas, facilitando a organização e o controle de dentistas e pacientes. A plataforma permitirá o cadastro e a gestão dos profissionais da clínica, além de fornecer uma interface eficiente para atender pacientes de forma organizada. Com isso, busca-se otimizar o processo de agendamento, atendimento e gestão de informações, oferecendo uma solução integrada para melhorar a eficiência operacional e a qualidade do serviço prestado.
</p>


# Compilar o código

### Gerar Arquivo Objeto

```
gcc -c src/sistema.c -o sistema.o
gcc -c src/paciente.c -o paciente.o
gcc -c src/dentista.c -o dentista.o
gcc -c src/main.c -o main.o

```

### Linkar Objetos e Gerar o Executável

``` 

gcc sistema.o paciente.o dentista.o main.o -o Nome-do-executavel

```

# Funcionalidades do Projeto


```
✅ Adicionar dentista
✅ Buscar dentista
✅ Remover dentista
✅ Adicionar paciente
✅ Atender paciente
✅ Buscar paciente
```

# Estrutura de Diretórios do Projeto

### A organização dos diretórios e arquivos do projeto é a seguinte:

```
Clínica_OdontoTech/
│
├── 📁 include/                   
│   ├── 🦷 dentista.h             
│   ├── 👨‍⚕️ paciente.h           
│   └── ⚙️ sistema.h             
│
├── 📁 src/                       
│   ├── 🦷 dentista.c             
│   ├── 👨‍⚕️ paciente.c            
│   ├── ⚙️ sistema.c              
│   └── 💻 main.c                 
│
├── 📁 output/                    
│   └── 🛠 main.exe               
│
├── 🚫 .gitignore
└── 📄 README.md                 
```

# Implementação


### Heap
<p>A estrutura Dentista é usada para representar um dentista no sistema. Ela contém informações como o nome, CPF, especialidade do dentista e um ponteiro para uma fila de pacientes, que é implementada como um Heap. A fila de pacientes organiza os pacientes de acordo com algum critério de prioridade</p>

```
typedef struct{
    char nome[100];
    char cpf[12];  
    char especialidade[100];
    Heap *filaPacientes;  
} Dentista;

```

### Hash
<p>A estrutura TabelaHash é usada para armazenar uma coleção de dentistas dentro de uma tabela hash. O objetivo de usar uma tabela hash é permitir um acesso eficiente aos dentistas com base em algum valor de hash, como o CPF ou outro identificador único.</p>


```
typedef struct{
    Dentista **dentistas;  
    int tamanho;
} TabelaHash;

```

### Criar Heap
A função criar_Heap tem a responsabilidade principal de alocar e inicializar uma nova estrutura de dados do tipo Heap, que será utilizada para gerenciar a fila de pacientes. A heap é uma estrutura que armazena dados de forma organizada, permitindo o acesso eficiente a elementos prioritários (por exemplo, o paciente com maior urgência). Nesta implementação, a heap começa com uma capacidade inicial para armazenar até 10 pacientes. A função também reserva espaço na memória para um array de ponteiros do tipo Paciente, que será usado para referenciar as estruturas individuais de pacientes. O array serve como o "container" onde os pacientes serão mantidos e organizados dentro da heap. Inicialmente, a heap estará vazia (nenhum paciente registrado), e o campo tamanhoAtual é configurado como zero para refletir esse estado. Essa função facilita a criação de uma heap que pode ser expandida posteriormente se mais pacientes precisarem ser inseridos, mantendo a organização e a prioridade da fila

```
Heap *criar_Heap(){

    Heap *heap = (Heap*)malloc(sizeof(Heap));
    
    heap->capacidade = 10;
    
    heap->pacientes = (Paciente**)malloc(sizeof(Paciente*) *heap->capacidade);
    
    heap->tamanhoAtual = 0;
    
    return heap;
}


```

### Inserir na Heap:

<p>A função inserir_Heap é responsável por inserir um novo paciente na heap, garantindo que a estrutura de prioridade seja mantida. Se a heap já tiver atingido sua capacidade máxima, a função redimensiona automaticamente o array de pacientes, dobrando sua capacidade com realloc. Após a inserção do paciente na próxima posição disponível, a função reorganiza a heap utilizando o algoritmo heapify_Acima para garantir que o paciente seja posicionado corretamente de acordo com sua prioridade. Por fim, o tamanho atual da heap é atualizado.
</p>

```
void inserir_Heap(Heap *heap, Paciente *paciente){
    
    if (heap->tamanhoAtual == heap->capacidade) {
        heap->capacidade *= 2;
        heap->pacientes = (Paciente**)realloc(heap->pacientes, heap->capacidade * sizeof(Paciente*));
    }

    heap->pacientes[heap->tamanhoAtual] = paciente;

    heapify_Acima(heap, heap->tamanhoAtual);

    heap->tamanhoAtual++;
}

```

### Ordenação da heap:
<p>A função heapify_Acima é usada para garantir que a propriedade da heap seja mantida após a inserção de um novo paciente. Ela é chamada sempre que um novo paciente é adicionado à heap, começando pela última posição (index) e comparando a prioridade do paciente inserido com a de seu pai. Se a prioridade do paciente for maior que a do pai, ocorre uma troca de posições entre eles. O processo é recursivamente repetido até que o paciente esteja na posição correta ou alcance a raiz da heap (índice 0). Isso garante que a heap continue sendo uma estrutura organizada por prioridade. O algoritmo é eficiente para reordenar a estrutura, subindo o elemento até sua posição correta na árvore.</p>

```
void heapify_Acima(Heap *heap, int index){
    if (index == 0){
        return;
    } 
    
    int pai = (index - 1) / 2;  
    
    if (heap->pacientes[index]->prioridade > heap->pacientes[pai]->prioridade){    
        trocar_Pacientes(&heap->pacientes[index], &heap->pacientes[pai]);
        heapify_Acima(heap, pai);
    }
}

```
### Trocar pacientes
<p>
  A função utiliza uma variável temporária (temp) para armazenar temporariamente o valor do primeiro ponteiro de paciente (a). Em seguida, atribui o valor do segundo ponteiro (b) ao primeiro, e então coloca o valor armazenado em temp no segundo ponteiro. Isso efetua a troca das posições entre os dois pacientes na heap.
</p>

```
void trocar_Pacientes(Paciente **a, Paciente **b){
    Paciente* temp = *a;
    *a = *b;
    *b = temp;
}

```





  # Colaboradores
  Um agradecimento especial a todas as pessoas que contribuíram para este projeto.
  <table>
    <tr>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/143232809?v=4" width="100px;" alt="foto de Thyago"/><br>
          <sub>
            <a href="https://github.com/thyagofab"><b>Thyago Fabricio</b></a>
          </sub>
        </a>
      </td>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/146228058?v=4" width="100px;" alt="Foto de Vinícius"/><br>
          <sub>
            <a href="https://github.com/ViniciusOliver13"><b>Antonio Vinícius</b></a>
          </sub>
        </a>
      </td>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/140117398?v=4" width="100px;" alt="Foto de Marcelo"/><br>
          <sub>
            <a href="https://github.com/marceloDev0"><b>Marcelo Augusto</b></a>
          </sub>
        </a>
      </td>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/146675089?v=4" width="100px;" alt="Foto de Dinarte"/><br>
            <sub>
              <a href="https://github.com/dinarteefilho"><b>Dinarte Filho</b></a>
            </sub>
        </a>
      </td>
    </tr>
  </table>
</div>
