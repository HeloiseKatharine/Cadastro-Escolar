/***********************************************************

Modulo: modulo_pessoas.h
Descrição: obtem funções que manipulam os cadastros de professores
e alunos da escola.

***********************************************************/

#ifndef modulo_disciplina
#define modulo_disciplina

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modulo_estruturas.h"
#include "modulo_pessoas.h"


//void Dados_Do_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, int *num_matricula);
void Dados_Do_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, int *num_matricula, struct Escola escola, int *quant_alunos, int *quant_professores);

//void exibe( struct Cadastro Pessoa[quant_pes], int *cont_pessoas);// Fun��o exibir dados de todas as pessoas
void exibe( struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Escola escola);

//void Altera_Dados_De_Uma_Pessoa(struct Cadastro Pessoa[quant_pes],int *cont_pessoas);
void Altera_Dados_De_Uma_Pessoa(struct Cadastro Pessoa[quant_pes],int *cont_pessoas, struct Escola escola);

//void excluir(struct Cadastro Pessoa[quant_pes], int *cont_pessoas)
void excluir(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Escola escola);

void main_pessoas(int *cont_pessoas, int *cont_cadastro);


 #endif
