
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modulo_disciplina.h"
#include "modulo_pessoas.h"
#include "modulo_estruturas.h"
#define quant_pes 60

/*######################Cadastrar disciplina######################*/

int cadastrar(int *cont_cadastro, int *cont_pessoas, struct Escola *escola)
{
    int verifica=0;
    int i;

    if((*cont_cadastro) < 10)
    {
        char aux_pis[12];
        char aux_nome[30];
        int aux_disciplina;
        int aux_carga;
        int existe_pis = 0;
        int existe_disc = 0;
        int Pis_Igual = 0;


        printf("Informe os dados da disciplina(%d): \n",(*cont_cadastro));
        scanf("%d[^;]", &aux_disciplina);//codigo da disciplina
        getchar();
        scanf("%[^;]",aux_nome);//nome da disciplina
        getchar();
        scanf("%d[^;]",&aux_carga);//carga horaria da disciplina
        getchar();
        scanf("%[^\n]", aux_pis);//PIS do professor da disciplina
        getchar();

        for(i=0; i < *cont_cadastro; i++)
        {
            if (aux_disciplina == (*escola).disciplinas[i].codigo)
            {
                existe_disc = 1;
                break;
            }
        }

        if (existe_disc == 1)
        {
            printf("A disciplina ja existe e/ou o codigo foi digitado incorretamente.\n");
        }

        else //Se o codigo nao existe continua com o cadastro
        {

            for( i=0; i < *cont_pessoas; i++)
            {
                //compara strings

                Pis_Igual = strcmp(aux_pis,Pessoa[i].PIS);

                if(Pis_Igual == 0)
                {
                    existe_pis = 1;
                    break;
                }

            }

            if (existe_pis == 1)
            {

                (*escola).disciplinas[*cont_cadastro].codigo = aux_disciplina;
                strcpy( (*escola).disciplinas[*cont_cadastro].nome,aux_nome);
                (*escola).disciplinas[*cont_cadastro].carga_horaria = aux_carga;
                strcpy( (*escola).disciplinas[*cont_cadastro].pis,aux_pis);

                verifica = 1;
            }

            else
            {
                printf("O professor nao existe e/ou o PIS foi digitado incorretamente.\n");
            }

        }
    }

    else
    {
        printf("Nao pode ser realizado mais de 10 cadastros de disciplina.\n");

    }
    return verifica;
}

/*######################Alterar professor de uma disciplina######################*/

void alterar(int *cont_cadastro, struct Escola *escola)
{
    int codigo_digitado;
    int verifica=0;
    int pos;

    printf("Informe o codigo da disciplina: ");
    scanf("%d", &codigo_digitado);

    for(int i=0; i< *cont_cadastro; i++)
    {

        if(codigo_digitado == (*escola).disciplinas[i].codigo)
        {

            verifica =1;
            pos=i;
        }
    }

    if (verifica == 1)
    {
        printf("Informe o novo PIS: ");
        scanf("%s",(*escola).disciplinas[pos].pis);//PIS do novo professor
        getchar();
    }
    else
    {
        printf("A disciplina nao existe e/ou o codigo foi digitado incorretamente.\n");
    }
}

/*######################Adicionar um aluno a uma disciplina######################*/

void adicionar(int *cont_cadastro, struct Cadastro Pessoa[quant_pes],int *cont_pessoas, struct Escola *escola, int *quant_alunos_disc)
{

    int codigo_digitado;
    int matricula_digitada;
    int j=0,i;
    int verifica_cod = 0;
    int verifica_disc = 0;
    int verifica_aluno = 0;
    int pos;

    printf("Informe o codigo da disciplina: ");
    scanf("%d",&codigo_digitado);

    for(i=0; i<(*cont_cadastro); i++)//verifica se a disciplina existe
    {
        if(codigo_digitado == (*escola).disciplinas[i].codigo)
        {

            verifica_cod = 1;
            pos = i;
            break;
        }
    }

    if (verifica_cod == 1)//se a disciplina existe
    {
        printf("Informe a matricula do aluno: ");
        scanf("%d", &matricula_digitada);

        for(i=0; i<*cont_pessoas; i++)//verifica se o aluno já tem cadastro
        {
            if(matricula_digitada == Pessoa[i].Numero_da_Matricula )
            {

                verifica_disc=1;
                break;
            }
        }

        if (verifica_disc == 1)//se o aluno já tem cadastro
        {
            for (j=0; j<10; j++)
            {
                if(matricula_digitada == (*escola).disciplinas[pos].alunos[j])//verifca se o aluno tem cadastro em alguma disciplina
                {
                    verifica_aluno=1;
                    break;
                }
            }

            if(verifica_aluno == 1) //o aluno NAO pode ser matriculado na disciplina
            {
                printf("O aluno ja esta matriculado.\n");
            }

            else //o aluno pode ser matriculado na disciplina
            {
                (*escola).disciplinas[pos].alunos[*quant_alunos_disc] = matricula_digitada;
                (*quant_alunos_disc)++;
            }
        }

        else
        {
            printf("O aluno nao existe e/ou a matricula foi digitada incorretamente.\n");
        }
    }

    else
    {
        printf("A disciplina nao existe e/ou o codigo foi digitado incorretamente.\n");
    }


    //Corrigir quando realiza o cadastro da pessoa, cadastro da disciplina e adiciona da certo
    // porem quando realiza o cadastro da pessoa, cadastro da disciplina, adiciona o aluno e depois volta
    // para cadastrar um novo aluno, ele apaga todos as disciplinas cadastradas e tem q fazer tudo de novo

}

/*######################Remover aluno de uma disciplina######################*/

void remover(int *cont_cadastro,struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Escola *escola,int *quant_alunos_disc)
{
    int matricula_digitada;
    int verifica_mat = 0;
    int codigo_digitado;
    int verifica_cod = 0;
    int pos;

    printf("Informe o codigo da disciplina: ");
    scanf("%d", &codigo_digitado);

    for(int i=0; i<*cont_cadastro; i++)
    {
        if(codigo_digitado == (*escola).disciplinas[i].codigo)
        {
            verifica_cod =1;
            pos = i;
            break;
        }
    }

    if (verifica_cod == 1)
    {
        printf("Informe a matricula do aluno: ");
        scanf("%d", &matricula_digitada);

        for(int i=0; i<*cont_pessoas; i++)
        {
            if(matricula_digitada == Pessoa[i].Numero_da_Matricula )
            {
                verifica_mat=1;
                break;
            }
        }

        if (verifica_mat == 1)
        {
            for (int j=0; j<*quant_alunos_disc; j++)
            {
                if(matricula_digitada == (*escola).disciplinas[pos].alunos[j])
                {

                    for(int i=j; i < *quant_alunos_disc-1; i++)
                    {
                        (*escola).disciplinas[pos].alunos[j] = (*escola).disciplinas[pos].alunos[j+1];
                    }

                    (*quant_alunos_disc)--;

                    printf("Aluno removido.\n");

                }
            }

        }



    else
    {
        printf("O aluno nao existe e/ou a matricula foi digitada incorretamente.\n");
    }
}

else
{
    printf("A disciplina nao existe e/ou o codigo foi digitado incorretamente.\n");
}

}



//Receber o número de matrícula do aluno a ser removido da disciplina.


/*######################Exibir dados de uma disciplina######################*/

void exibir(int *cont_cadastro,struct Cadastro Pessoa[quant_pes],int *cont_pessoas, struct Escola *escola, int *quant_alunos_disc)
{
    int codigo_digitado;
    int pos;
    int i,j;
    int verifica_pis=0;
    char aux_pis[12];

    printf("Informe o codigo da disciplina: ");
    scanf("%d", &codigo_digitado);

    for( i=0; i<*cont_cadastro; i++)
    {
        if ((*escola).disciplinas[i].codigo == codigo_digitado)
        {
            printf("\nDADOS DA DISCIPLINA(%i):\n ",i);
            printf("\nCodigo da disciplina: %d", (*escola).disciplinas[i].codigo);
            printf("\nNome da disciplina: %s",(*escola).disciplinas[i].nome);
            pos=i;
            strcpy(aux_pis,(*escola).disciplinas[pos].pis);
        }
    }

    for (i=0; i<*cont_pessoas; i++)
    {
        verifica_pis = strcmp(aux_pis, Pessoa[i].PIS);

        if(verifica_pis == 0)//o pis é igual
        {
            printf("\nNome do Professor(a): %s %s",Pessoa[i].nome, Pessoa[i].Sobrenome);
            break;
        }
    }

    printf("\nMatricula e nome dos alunos:");
    for(i=0; i<*cont_pessoas; i++)
    {
        for(j=0; j<  *quant_alunos_disc ; j++)
        {
            if((*escola).disciplinas[pos].alunos[j] == Pessoa[i].Numero_da_Matricula)
            {
                printf("\n%d - %s",Pessoa[i].Numero_da_Matricula,Pessoa[i].nome);
            }
        }
    }
    printf("\n");
}


/*######################main######################*/

void main_disciplina(int *cont_pessoas, int *cont_cadastro)
{
    int opcao,verifica;
    int quant_alunos_disc=0;


    do
    {
        printf("-----------------------MENU-----------------------\n");
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Alterar professor de uma disciplina\n");
        printf("3 - Adicionar um aluno a uma disciplina\n");
        printf("4 - Remover aluno de uma disciplina\n");
        printf("5 - Exibir dados de uma disciplina\n");
        printf("6 - Voltar ao menu principal\n");
        printf("--------------------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d",&opcao);
        printf("--------------------------------------------------\n");

        switch(opcao)
        {
        case 1:

            verifica = cadastrar(cont_cadastro,cont_pessoas, &escola);

            if (verifica == 1)
            {
                printf("Cadastro Realizado com Sucesso!\n");
                (*cont_cadastro)++;

            }
            else
            {
                printf("Cadastro Nao Realizado!\n");
            }
            break;

        case 2:
            alterar(cont_cadastro, &escola);
            break;

        case 3:

            adicionar(cont_cadastro,Pessoa,cont_pessoas, &escola, &quant_alunos_disc);
            break;

        case 4:
            remover(cont_cadastro,Pessoa,cont_pessoas, &escola, &quant_alunos_disc);
            break;

        case 5:
            exibir(cont_cadastro,Pessoa,cont_pessoas, &escola, &quant_alunos_disc);
            break;

        case 6:
            break;

        default:
            printf("Opcao nao existente!\n\n");
            break;
        }
    }
    while(opcao!=6);
}
