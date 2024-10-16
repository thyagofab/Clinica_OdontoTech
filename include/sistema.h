#ifndef SISTEMA_H
#define SISTEMA_H
#include "../include/dentista.h"
#include "../include/paciente.h"

/*Função que exibe o menu principal do sistema.
*/
void menu();

/*Função que exibe o menu de adição de dentista.
*/
void menu_dentista();

/*Função que exibe o menu de busca de dentista.
*/
void menu_buscar_dentista();

/*Função que exibe o menu de remoção de dentista.
*/
void menu_remover_dentista();

/*Função que exibe o menu de adição de paciente.
*/
void menu_paciente();

/*Função que exibe o menu de busca de paciente.
*/
void menu_buscar_paciente();

/*Função que exibe o menu de atendimento de paciente.
*/
void menu_atenter_paciente();

/*Função que exibe o menu de prioridade de paciente.
*/
void menu_definir_prioridade();

/*Função que exibe o menu de prioridade de paciente. Nele, o usuário escolhe a prioridade do paciente.
return: retorna a prioridade escolhida.
*/
int definir_prioridade();

/*Função que lê um nome digitado pelo usuário. Verifica se o nome contém apenas letras e espaços. 
 @param texto: texto a ser exibido antes da leitura.
 @param nome: ponteiro para o nome a ser lido.
*/
void leia_nomes(char *texto, char *nome);

/*Função que lê um número digitado pelo usuário. Verifica se o número inteiro é válido.
 @param texto: texto a ser exibido antes da leitura.
 @param numero: ponteiro para o número a ser lido.
*/
void leia_numeros(char *texto, int *numero);

/*Função que lê um telefone digitado pelo usuário. Verifica se o telefone é válido.
 @param texto: texto a ser exibido antes da leitura.
 @param telefone: ponteiro para o telefone a ser lido.
*/
void leia_telefone(char *texto, char *telefone);

/*Função que lê um CPF digitado pelo usuário. Verifica se o CPF é válido.
 @param texto: texto a ser exibido antes da leitura.
 @param cpf: ponteiro para o CPF a ser lido.
*/
void leia_cpf(char *texto, char *cpf);

/*Função que salva os dentistas e pacientes em um arquivo.
 @param tabela: ponteiro para a tabela hash que contém os dentistas.
 @param cpf: CPF do dentista.
*/
void salvar_dentistas_pacientes(TabelaHash *tabela);

/*Função que carrega os dentistas e pacientes de um arquivo.
 @param tabela: ponteiro para a tabela hash que contém os dentistas.
*/
void carregar_dentistas_pacientes(TabelaHash *tabela, NoAVL **arvorePacientes);

/*Função auxiliar que cria um dentista.
 @param nome: nome do dentista.
 @param cpf: CPF do dentista.
 @param especialidade: especialidade do dentista.
 @return: retorna um ponteiro para o dentista criado.
*/
Dentista *criar_dentista(char *nome, char *cpf, char *especialidade);

/*Função auxiliar que cria um paciente.
 @param nome: nome do paciente.
 @param telefone: telefone do paciente.
 @param prioridade: prioridade do paciente.
 @return: retorna um ponteiro para o paciente criado.
*/
Paciente *criar_paciente(char *nome, char *telefone, int prioridade); 

#endif