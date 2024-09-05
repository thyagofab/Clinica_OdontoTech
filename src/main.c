#include "dentista.c"

int main(){

    int opcao;

    do{
        menu();
        scanf(" %d", &opcao);

        switch (opcao){

        case 1:
            adicionar_dentista();
            break;
            
        case 2:
            buscar_dentista();
            break;

        case 3:
            remover_dentista();
            break;

        case 4:
            printf("opcao 4\n");
            break;

        case 5: 
            printf("opcao 5\n");
            break;

        case 6:
            printf("opcao 6\n");
            break;

        case 7:
            printf("Saindo...\n");
            break;

        default:
            printf("opcao invalida!\n");
            break;
        }
    }while (opcao != 7);
    
    return 0;
}