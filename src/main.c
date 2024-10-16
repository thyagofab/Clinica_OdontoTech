#include "../include/dentista.h"
#include "../include/sistema.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(){
    TabelaHash *tabela = criar_TabelaHash(TAM);
    carregar_dentistas_pacientes(tabela);
    int opcao;

    do{
        menu();
        leia_numeros("Digite uma opcao: ", &opcao);

        switch (opcao){

        case 1:
            adicionar_dentista(tabela);
            break;
            
        case 2:
            buscar_dentista(tabela, "");
            break;

        case 3:
            remover_dentista(tabela);
            break;

        case 4:
            adicionar_paciente_dentista(tabela);
            break;

        case 5: 
            atender_paciente_dentista(tabela);
            break;

        case 6:
            buscar_paciente();  // Não implementada
            break;

        case 7:
            printf("Saindo...\n");
            break;
            
        case 8:
            mostrar_dentistas(tabela);  // Função criada para testes: mostrar dentistas e seus pacientes
            break;

        default:
            printf("opcao invalida!\n");
            system("cls");
            break;
        }
        
    }while (opcao != 7);
    
    salvar_dentistas_pacientes(tabela);

    return 0;
}