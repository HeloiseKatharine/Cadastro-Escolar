#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modulo_disciplina.h"
#include "modulo_pessoas.h"
#include "modulo_estruturas.h"

int main()
{
    int opc = 0;
    int cont_pessoas=0;
    int cont_cadastro=0;

    while(opc != 3)
    {
        printf("1 - Sistema de Pessoas\n2 - Sistema de Disciplinas\n3 - Sair do Sistema\n");
        scanf("%d", &opc);

        switch(opc)
        {

        case 1://Sistema de Pessoas
            main_pessoas(&cont_pessoas,&cont_cadastro);
            break;

        case 2://Sistema de Disciplinas
            main_disciplina(&cont_pessoas,&cont_cadastro);
            break;

        case 3://Sair do Sistema

            break;

        default: // Colocou um Numero que n�o est� nas Op��es
            printf("\nERRO Insira uma op��o Valida!\n");
            printf("\n");
        }
    }
    return 0;
}
