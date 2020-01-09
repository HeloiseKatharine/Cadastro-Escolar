/***********************************************************

Modulo: modulo_disciplina.h
Descrição: obtem funções que manipulam as disciplinas da escola.

***********************************************************/

#ifndef modulo_disciplina
#define modulo_disciplina

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modulo_estruturas.h"
#include "modulo_pessoas.h"


//int cadastrar(struct disciplina disciplinas[10],int *cont_cadastro, int *cont_pessoas); //Cadastrar disciplina
int cadastrar(int *cont_cadastro, int *cont_pessoas, struct Escola *escola);

//void alterar(struct disciplina disciplinas[10],int *cont_cadastro); //Alterar professor de uma disciplina
void alterar(int *cont_cadastro, struct Escola *escola);

//void adicionar(struct disciplina disciplinas[10],int *cont_cadastro, struct Cadastro Pessoa[quant_pes],int *cont_pessoas);
void adicionar(int *cont_cadastro, struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Escola *escola, int *quant_alunos_disc);

//void remover(struct disciplina disciplinas[10],int *cont_cadastro,struct Cadastro Pessoa[quant_pes],int *cont_pessoas );//Remover aluno de uma disciplina
void remover(int *cont_cadastro,struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Escola *escola, int *quant_alunos_disc);

//void exibir(struct disciplina disciplinas[10],int *cont_cadastro,struct Cadastro Pessoa[quant_pes], int *cont_pessoas);//Exibir dados de uma disciplina
void exibir(int *cont_cadastro,struct Cadastro Pessoa[quant_pes],int *cont_pessoas, struct Escola *escola, int *quant_alunos_disc);


void main_disciplina(int *cont_pessoas, int *cont_cadastro);

 #endif
