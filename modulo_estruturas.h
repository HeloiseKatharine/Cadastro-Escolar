/***********************************************************

Modulo: modulo_estruturas.h
Descrição: obtem todas as estruturas de dados necessárias
para o sistema.

***********************************************************/

#ifndef modulo_estruturas
#define modulo_estruturas
#define quant_pes 60

//struct disciplina (modulo_disciplina)

struct disciplina
{
    int codigo;
    char nome[30];
    int carga_horaria;
    char pis[12];
    int alunos[10];
};
struct disciplina disciplinas;

struct Escola
{
    int alunos; //50
    int professores;//10
    struct disciplina disciplinas [10];//10
};
struct Escola escola;

//struct pessoas (modulo_pessoas)

struct Cadastro //Objeto de Variaveis que Cadastrará o Usuario
{
    char nome[20];
    char Sobrenome[20];
    int Nacionalidade;
    char CPF[12];
    char RG[11]; //entre 6 e 9
    char Passaporte[9];//8
    char Pais_de_Origem[15];
    char Data_de_Nascimento[11];
    int Portador_de_Necessidades_Especiais;
    char Laudo_Medico[10];
    char CEP[9];
    char Endereco[20];
    int Aluno_Professor;
    int Numero_da_Matricula; //Começando com 19000 a Matricula dos Alunos
    char PIS[12];
};

struct Cadastro Pessoa[quant_pes];//tipo Pessoa

#endif
