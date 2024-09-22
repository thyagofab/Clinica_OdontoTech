#include "dentista.c"

int main(){

    Heap *heap = criarHeap();
    TabelaHash *tabela = criarTabelaHash(10);
    int opcao;

    do{
        menu();
        scanf(" %d", &opcao);

        switch (opcao){

        case 1:
            adicionar_dentista(tabela);
            break;
            
        case 2:
            buscar_dentista();
            mostrar_dentistas(tabela);
            break;

        case 3:
            remover_dentista();
            break;

        case 4:
            adicionar_paciente(heap);
            break;

        case 5: 
            atender_paciente(heap);
            break;

        case 6:
            buscar_paciente();
            break;

        case 7:
            printf("Saindo...\n");
            mostrar_pacientes(heap);
            break;

        default:
            printf("opcao invalida!\n");
            system("cls");
            break;
        }
        
    }while (opcao != 7);
    
    return 0;
}