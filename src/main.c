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
            adicionar_paciente();
            break;

        case 5: 
            atender_paciente();
            break;

        case 6:
            buscar_paciente();
            break;

        case 7:
            printf("Saindo...\n");
            break;

        default:
            printf("opcao invalida!\n");
            sleep(1);
            system("cls");
            break;
        }
    }while (opcao != 7);
    
    return 0;
}