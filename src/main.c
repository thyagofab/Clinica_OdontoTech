#include "dentista.c"
#define TAM 100

int main(){
    TabelaHash *tabela = criar_TabelaHash(TAM);
    int opcao;

    do{
        menu();
        scanf(" %d", &opcao);

        switch (opcao){

        case 1:
            adicionar_dentista(tabela);
            break;
            
        case 2:
            mostrar_dentistas(tabela);  // Função criada para testes: mostrar dentistas e seus pacientes
            break;

        case 3:
            remover_dentista(); // Não implementada
            break;

        case 4:
            adicionar_paciente_dentista(tabela);
            break;

        case 5: 
            //atender_paciente(heap);
            break;

        case 6:
            buscar_paciente();
            break;

        case 7:
            printf("Saindo...\n");
            break;

        default:
            printf("opcao invalida!\n");
            system("cls");
            break;
        }
        
    }while (opcao != 7);
    
    return 0;
}