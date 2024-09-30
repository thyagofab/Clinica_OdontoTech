#ifndef SISTEMA_H
#define SISTEMA_H

/* Função que exibe o menu principal do sistema.
*/
void menu();

/* Função que exibe o menu de adição de dentista.
*/
void menu_dentista();

/* Função que exibe o menu de busca de dentista.
*/
void menu_buscar_dentista();

/* Função que exibe o menu de remoção de dentista.
*/
void menu_remover_dentista();

/* Função que exibe o menu de adição de paciente.
*/
void menu_paciente();

/* Função que exibe o menu de busca de paciente.
*/
void menu_buscar_paciente();

/* Função que exibe o menu de atendimento de paciente.
*/
void menu_atenter_paciente();

/* Função que exibe o menu de prioridade de paciente. Nele, o usuário escolhe a prioridade do paciente.
return: retorna a prioridade escolhida.
*/
int definir_prioridade();

#endif