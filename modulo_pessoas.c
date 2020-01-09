
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modulo_disciplina.h"
#include "modulo_pessoas.h"
#include "modulo_estruturas.h"
#define quant_pes 60


/*######################Cadastro de Usuarios######################*/

void Dados_Do_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, int *num_matricula, struct Escola escola, int *quant_alunos, int *quant_professores)
{

    int Tamanho = 0;
    int tamanho_cpf=0;
    int tamanho_rg=0;
    int tamanho_passaporte=0;
    int tamanho_cep=0;
    int tamanho_pis=0;

    scanf("%[^;]", Pessoa[*cont_pessoas].nome);
    getchar();
    scanf("%[^;]", Pessoa[*cont_pessoas].Sobrenome);
    getchar();
    scanf("%d[^;]", &Pessoa[*cont_pessoas].Nacionalidade);
    getchar();

    if(Pessoa[*cont_pessoas].Nacionalidade == 0)
    {
        scanf("%[^;]", Pessoa[*cont_pessoas].CPF);
        getchar();

        tamanho_cpf = strlen(Pessoa[*cont_pessoas].CPF);

        if(tamanho_cpf > 11 || tamanho_cpf < 11) //comparar tamanho de string
        {
            printf("ERRO Quantidade de Numeros do CPF invalida\n");
        }
        else
        {
            scanf("%[^;]", Pessoa[*cont_pessoas].RG);
            getchar();
        }

        tamanho_rg = strlen(Pessoa[*cont_pessoas].RG );

        if(tamanho_rg > 9 || tamanho_rg < 6 )
        {
            printf("ERRO quantidade de numeros do RG invalido\n");
        }
    }

    else
    {
        scanf("%[^;]", Pessoa[*cont_pessoas].Passaporte);
        getchar();

        tamanho_passaporte = strlen(Pessoa[*cont_pessoas].Passaporte);

        if( tamanho_passaporte > 8 || tamanho_passaporte < 8)
        {
            printf("ERRO Quantidade de Numeros do Passaporte Invalido\n");
        }
        else
        {
            scanf("%[^;]", Pessoa[*cont_pessoas].Pais_de_Origem);
            getchar();
        }
    }

    scanf("%[^;]", Pessoa[*cont_pessoas].Data_de_Nascimento);
    getchar();

    scanf("%d[^;]",&Pessoa[*cont_pessoas].Portador_de_Necessidades_Especiais);
    getchar();

    if(Pessoa[*cont_pessoas].Portador_de_Necessidades_Especiais == 1)
    {
        scanf("%[^;]", Pessoa[*cont_pessoas].Laudo_Medico);
        getchar();

        Tamanho = strlen(Pessoa[*cont_pessoas].Laudo_Medico);

        if(Tamanho > 10)
        {
            printf("quantidade de Caracteres Do Laudo Invalido\n");
        }
    }

    scanf("%[^;]", Pessoa[*cont_pessoas].CEP);
    getchar();

    tamanho_cep = strlen(Pessoa[*cont_pessoas].CEP);

    if( tamanho_cep > 8 ||tamanho_cep < 8 )
    {
        printf("ERRO! Quantidade de Numeros do CEP invalido\n");
    }

    scanf("%[^;]", Pessoa[*cont_pessoas].Endereco);
    getchar();

    scanf("%d[^;]", &Pessoa[*cont_pessoas].Aluno_Professor);

    if(Pessoa[*cont_pessoas].Aluno_Professor == 0)//se for aluno
    {
        (*quant_alunos)++;

        *num_matricula = ((*num_matricula) + 1);
        Pessoa[*cont_pessoas].Numero_da_Matricula = *num_matricula;

        escola.alunos = *quant_alunos;
    }
    else//se for pessoa
    {
        (*quant_professores)++;

        getchar();
        scanf("%[^\n]s", Pessoa[*cont_pessoas].PIS);

        tamanho_pis = strlen(Pessoa[*cont_pessoas].PIS);

    if( tamanho_pis > 11 || tamanho_pis < 11 )
    {
        printf("ERRO! Quantidade de Numeros do PIS invalido\n");
    }
        escola.professores = *quant_professores;
    }
}


/*######################Exibir Dados de uma Pessoa######################*/

void exibe( struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Escola escola)
{

    int Verifica;
    char PIS_Prof[12];
    int PIS_Igual=0;
    int Verf_Matricula;
    int i;
    int erro =0;

    printf("Insira 0-Aluno e 1-Professor\n");
    scanf("%d", &Verifica);

    if(Verifica == 0) //Será Aluno
    {
        printf("Digite a matricula:\n");
        scanf("%d", &Verf_Matricula);

        for(i=0; i<*cont_pessoas; i++)
        {
            if(Verf_Matricula == Pessoa[i].Numero_da_Matricula)//verifica se a matricula existe
            {
                if(Pessoa[i].Nacionalidade == 0)//se for brasileiro
                {
                    //Imprimindo os Dados do Aluno
                    printf("\n");
                    printf("------------------------------------------------\n");
                    printf("     Nome:                 %s                            \n",Pessoa[i].nome);
                    printf("     Sobrenome:            %s                            \n",Pessoa[i].Sobrenome);
                    printf("     Nacionalidade:        %d                            \n",Pessoa[i].Nacionalidade);
                    printf("     CPF:                  %s                            \n",Pessoa[i].CPF);
                    printf("     RG:                   %s                            \n",Pessoa[i].RG);
                    printf("     Data:                 %s                            \n",Pessoa[i].Data_de_Nascimento);

                    if(Pessoa[i].Portador_de_Necessidades_Especiais == 0 )
                    {
                        printf("     PNE:                  %d                         \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                    }
                    else
                    {
                        printf("     PNE:                %d                         \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                        printf("     Laudo Medico:       %s                           \n",Pessoa[i].Laudo_Medico);
                    }

                    printf("     CEP:                  %s                            \n",Pessoa[i].CEP);
                    printf("     Endereco:             %s                            \n",Pessoa[i].Endereco);
                    printf("     Numero da Matricula:  %d                            \n",Pessoa[i].Numero_da_Matricula);
                    printf("------------------------------------------------\n");

                }

                else //estrangeiro
                {
                    printf("\n");
                    printf("------------------------------------------------\n");
                    printf("     Nome:               %s                           \n",Pessoa[i].nome);
                    printf("     Sobrenome:          %s                           \n",Pessoa[i].Sobrenome);
                    printf("     Nacionalidade:      %d                           \n",Pessoa[i].Nacionalidade);
                    printf("     Passaporte:         %s                           \n",Pessoa[i].Passaporte);
                    printf("     Páis de Origem:     %s                           \n",Pessoa[i].Pais_de_Origem);
                    printf("     Data:               %s                     \n",Pessoa[i].Data_de_Nascimento);

                    if(Pessoa[i].Portador_de_Necessidades_Especiais == 0 )
                    {
                        printf("     PNE:                %d                         \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                    }
                    else
                    {
                        printf("     PNE:                %d                         \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                        printf("     Laudo_Medico:       %s                           \n",Pessoa[i].Laudo_Medico);
                    }

                    printf("     CEP:                %s                           \n",Pessoa[i].CEP);
                    printf("     Endereço:           %s                           \n",Pessoa[i].Endereco);
                    printf("     Numero da Matricula:%d                           \n",Pessoa[i].Numero_da_Matricula);
                    printf("------------------------------------------------\n");
                }
                erro = 1;
            }
        }
        if(erro != 1)
        {
            printf("Erro! Cadastro nao encontrado.\n");
            erro =0;
        }
    }
    else    //Sera professor
    {
        printf("Insira o PIS do Professor:\n");//Imprimindo os Dados do Professor
        getchar();
        scanf("%s", PIS_Prof);

        for(i=0; i< *cont_pessoas; i++)
        {
            PIS_Igual = strcmp(PIS_Prof,Pessoa[i].PIS);//verifica se o PIS existe

            if(PIS_Igual == 0)
            {
                if(Pessoa[i].Nacionalidade == 0)//se for brasileiro
                {
                    printf("\n");
                    printf("------------------------------------------------\n");
                    printf("     Nome:               %s                           \n",Pessoa[i].nome);
                    printf("     Sobrenome:          %s                           \n",Pessoa[i].Sobrenome);
                    printf("     Nacionalidade:      %d                           \n",Pessoa[i].Nacionalidade);
                    printf("     CPF:                %s                           \n",Pessoa[i].CPF);
                    printf("     RG:                 %s                           \n",Pessoa[i].RG);
                    printf("     Data:               %s                     \n",Pessoa[i].Data_de_Nascimento);

                    if(Pessoa[i].Portador_de_Necessidades_Especiais == 0 )
                    {
                        printf("     PNE:                %d                    \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                    }
                    else
                    {
                        printf("     PNE:                %d                         \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                        printf("     Laudo Medico:       %s                           \n",Pessoa[i].Laudo_Medico);
                        printf("     PIS:                %s                           \n",Pessoa[i].PIS);
                    }
                    printf("     CEP:                %s                           \n",Pessoa[i].CEP);
                    printf("     Endereco:           %s                           \n",Pessoa[i].Endereco);
                    printf("     PIS:                %s                           \n",Pessoa[i].PIS);
                    printf("------------------------------------------------\n");
                }

                else //se for estrangeiro
                {
                    printf("\n");
                    printf("------------------------------------------------\n");
                    printf("     Nome:               %s                           \n",Pessoa[i].nome);
                    printf("     Sobrenome:          %s                           \n",Pessoa[i].Sobrenome);
                    printf("     Nacionalidade:      %d                           \n",Pessoa[i].Nacionalidade);
                    printf("     Passaporte:         %s                           \n",Pessoa[i].Passaporte);
                    printf("     Pais de Origem:     %s                           \n",Pessoa[i].Pais_de_Origem);
                    printf("     Data:               %s                     \n",Pessoa[i].Data_de_Nascimento);

                    if(Pessoa[i].Portador_de_Necessidades_Especiais == 0 )
                    {
                        printf("     PNE:                %d\n                    \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                    }
                    else
                    {
                        printf("     PNE:                %d\n                         \n",Pessoa[i].Portador_de_Necessidades_Especiais);
                        printf("     Laudo Medico:       %s                           \n",Pessoa[i].Laudo_Medico);
                        printf("     PIS:                %s                           \n",Pessoa[i].PIS);
                    }
                    printf("     CEP:                %s                           \n",Pessoa[i].CEP);
                    printf("     Endereco:           %s                           \n",Pessoa[i].Endereco);
                    printf("     PIS:                %s                           \n",Pessoa[i].PIS);
                    printf("------------------------------------------------\n");
                }
                erro = 1;
            }
        }
        if(erro != 1)
        {
            printf("Erro! Cadastro nao encontrado.\n");
            erro =0;
        }
    }
}

/*######################Alterar dados de Pessoa######################*/

void Altera_Dados_De_Uma_Pessoa(struct Cadastro Pessoa[quant_pes],int *cont_pessoas, struct Escola escola)
{
    int Verifica_Alt=0;
    int Matricula_Verf;
    char PIS_Verf[12];
    int PIS_Igual=0;
    int Opcao_Alt=0;

    printf("Insira 0-Aluno e 1-Professor\n");//Verificando se � Aluno ou Professor
    scanf("%d", &Verifica_Alt);

    if(Verifica_Alt == 0)//Se for Aluno fará as buscas de Matricula
    {
        printf("Insira a Matricula do Aluno:\n");
        scanf("%d", &Matricula_Verf);

        for(int i=0; i < *cont_pessoas; i++) //Verificando se o Aluno Existe
        {
            if( Matricula_Verf == Pessoa[i].Numero_da_Matricula)
            {
                printf("\n");
                printf("1.Portador de Necessidades especiais\n");
                printf("2.Codigo do laudo medico\n");
                printf("3.CEP\n");
                printf("4.Endereco\n");

                scanf("%d", &Opcao_Alt);
                getchar();

                switch(Opcao_Alt)
                {
                case 1:
                    scanf("%d", &Pessoa[i].Portador_de_Necessidades_Especiais);
                    getchar();
                    break;

                case 2:
                    scanf("%s", Pessoa[i].Laudo_Medico);
                    getchar();
                    break;

                case 3:
                    scanf("%s", Pessoa[i].CEP);
                    getchar();
                    break;

                case 4:
                    scanf("%s", Pessoa[i].Endereco);
                    getchar();
                    break;

                default:
                    printf("Opcao Invalida\n");
                    break;
                }
            }

        }
    }
    else
    {
        printf("Insira o PIS do Professor:");
        scanf("%[^\n]s", PIS_Verf);
        getchar();

        for(int i=0; i < *cont_pessoas; i++)
        {
            PIS_Igual = strcmp(PIS_Verf,Pessoa[i].PIS); //compara strings

            if(PIS_Igual == 0)
            {
                printf("1.Portador de Necessidades especiais\n");
                printf("2.Codigo do laudo médico\n");
                printf("3.CEP\n");
                printf("4.Endere�o\n");

                scanf("%d", &Opcao_Alt);
                getchar();

                switch(Opcao_Alt)
                {

                case 1:
                    scanf("%d", &Pessoa[i].Portador_de_Necessidades_Especiais);
                    getchar();
                    break;

                case 2:
                    scanf("%s", Pessoa[i].Laudo_Medico);
                    getchar();
                    break;

                case 3:
                    scanf("%s", Pessoa[i].CEP);
                    getchar();
                    break;

                case 4:
                    scanf("%s", Pessoa[i].Endereco);
                    getchar();
                    break;

                default:
                    printf("Opção Invalida");
                }
            }
            break;
        }
    }
}

/*######################Remover Pessoa######################*/

void excluir(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Escola escola)
{
    char Idenficacao[15];
    int Tamanho_String;
    int igual_pis=0;
    int Idenficacao_int=0;
    int i,j;

    printf("Insira pis ou matricula:\n");//Verificando se o aluno ou Professor
    scanf("%s", Idenficacao);
    getchar();

    Tamanho_String = strlen(Idenficacao);

    if(Tamanho_String == 5)//aluno
    {
        Idenficacao_int = atoi(Idenficacao);

        for(i=0; i < *cont_pessoas; i++)
        {
            if( Idenficacao_int == Pessoa[i].Numero_da_Matricula)
            {
                for(j=i; j < *cont_pessoas-1; j++)
                {
                    Pessoa[j] = Pessoa[j+1];
                }

                (*cont_pessoas)--;

                printf("Aluno removido.\n");
            }
            else
            {
                printf("Aluno não Encontrado\n");
            }
        }
    }
    else//professor
    {
        for(i=0; i < *cont_pessoas; i++)
        {
            igual_pis = strcmp(Idenficacao, Pessoa[i].PIS);

            if( igual_pis == 0) // se for igual
            {
                for(j=i; j < *cont_pessoas-1; j++)
                {
                    Pessoa[j] = Pessoa[j+1];
                }

                (*cont_pessoas)--;

                printf("Professor removido.\n");
            }

            else
            {
                printf("Professor não encontrado\n");
            }
        }
    }

}
/*######################main######################*/

void main_pessoas(int *cont_pessoas, int *cont_cadastro)
{
    int Opcao;
    int num_matricula = 18999;
    int quant_alunos=0;
    int quant_professores = 0;

    while(Opcao != 5)
    {
        printf("-----------------------Menu---------------------\n");
        printf("   1 - Cadastrar Pessoa                         \n");
        printf("                                                \n");
        printf("   2 - Exibir Dados de uma Pessoa               \n");
        printf("                                                \n");
        printf("   3 - Alterar Dados de Uma Pessoa              \n");
        printf("                                                \n");
        printf("   4 - Remover Pessoa                           \n");
        printf("                                                \n");
        printf("   5 - Voltar ao Menu Anterior                  \n");
        printf("                                                \n");
        printf("------------------------------------------------\n");

        scanf("%d", &Opcao);
        getchar();

        switch(Opcao)
        {

        case 1://Cadastrar pessoa
            Dados_Do_Usuario(Pessoa, cont_pessoas, &num_matricula, escola, &quant_alunos, &quant_professores);//
            getchar();
            (*cont_pessoas)++;
            break;

        case 2://Exibir dados de todas as pessoas
            exibe(Pessoa, cont_pessoas, escola);
            break;

        case 3://Altera os Dados de Algum Usuario
            Altera_Dados_De_Uma_Pessoa(Pessoa, cont_pessoas, escola);
            break;

        case 4://Excluir um usuario
            excluir(Pessoa, cont_pessoas, escola);
            break;

        case 5: //Sair do Programa
            break;

        default: // Colocou um Numero que nao esta nas Opcoes
            printf("ERRO Insira uma opção Valida!\n");
            printf("\n");
        }
    }
}
