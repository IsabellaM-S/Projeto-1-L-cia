#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define v1 0
#define v2 1
#define v3 5
#define v4 7
#define v5 9


// posições para a senha correta: 6, 15, 19, 14
// senha correta: 6 4 3 7 4 


int main()
{
    int barra [20] = {v1,v3,v2,v3,v5,v4,v2,v2,v1,v3,v5,v5,v2,v4,v4,v1,v1,v4,v5,v2};
    int senhaCorreta [5] = {6, 4, 3, 7, 4};
    int tentativaSenha [5];
    int numeroDaTentativa, somaV1, somaV2, somaV3, somaV4, somaV5, posicaoInicio, posicaoFim, qtdDeslizamentos, deslizamento, acertos;
    
    setlocale(LC_ALL, "portuguese");
    
    printf("\n\t\t\t\t*** SEGREDO PARA COFRES ***\n");
    printf("\n\tTente descobrir o segredo do cofre indicando as posições para deslizamento da barra de dígitos!\n");
    printf("\n\t\t >>> Atenção: a barra com os dígitos possui vinte posições. Escolha apenas valores entre 1 e 20.");
    printf("\n\t\t >>> Você terá no máximo 4 deslizamentos para adivinhar a senha, mas fique a vontade para tentar com menos!");
    printf("\n\t\t >>> Caso você não acerte a senha de primeira, terá mais duas tentativas!\n");
    printf("\n\t\t\t\t\t BOA SORTE!!!\n");
    fflush(stdout);
    
    for(numeroDaTentativa = 1; numeroDaTentativa <= 3; numeroDaTentativa ++)
    {
        
        if(acertos != 5)
        {
            qtdDeslizamentos = 0;    
            while (qtdDeslizamentos < 1 || qtdDeslizamentos > 4)
            {
                printf("\n\nCom quantos deslizamentos você deseja tentar? ");
                fflush(stdout);
                scanf("%u", &qtdDeslizamentos);
                fflush(stdin);
                
                if (qtdDeslizamentos < 1 || qtdDeslizamentos > 4)
                {
                    printf("\n\t> ATENÇÃO: Você só pode escolher valores entre 1 e 4.");
                }
            }
            
            posicaoFim = 0;
            while (posicaoFim < 1 || posicaoFim > 20)
            {
                if(qtdDeslizamentos == 1)
                {
                    printf("\nDigite a posição desejada: ");
                    fflush(stdout);
                    scanf("%i", &posicaoFim);
                    fflush(stdin);
                }
                else
                {
                    printf("\nDigite a primeira posição desejada: ");
                    fflush(stdout);
                    scanf("%i", &posicaoFim);
                    fflush(stdin);
                }
                
                if(posicaoFim < 1 || posicaoFim > 20)
                {
                    printf("\n\t> ATENÇÃO: A posição %i não existe, escolha outra.\n", posicaoFim);
                    fflush(stdout);
                }
            }
            
            somaV1 = 0;
            somaV2 = 0;
            somaV3 = 0;
            somaV4 = 0;
            somaV5 = 0;
            
            //primeiro deslizamento:
            deslizamento = 1;
            for(posicaoInicio = 0; posicaoInicio < posicaoFim; posicaoInicio ++)
            {
                switch (barra[posicaoInicio])
                {
                    case v1:
                        somaV1 += 1;
                        break;
                    case v2:
                        somaV2 += 1;
                        break;
                    case v3:
                        somaV3 += 1;
                        break;
                    case v4:
                        somaV4 += 1;
                        break;
                    case v5:
                        somaV5 += 1;
                        break;
                }
            }
            
            for(deslizamento = 2; deslizamento <= qtdDeslizamentos; deslizamento++)
            {
                posicaoInicio = posicaoFim;
                posicaoFim = 0;
                while (posicaoFim < 1 || posicaoFim > 20)
                {
                    printf("\nDigite a posição para o %iº deslizamento: ", deslizamento);
                    fflush(stdout);
                    scanf("%u", &posicaoFim);
                    fflush(stdin);
                    
                    if(posicaoFim < 1 || posicaoFim > 20)
                    {
                        printf("\n\t> ATENÇÃO: A posição %i não existe, escolha outra.\n", posicaoFim);
                        fflush(stdout);
                    }
                }
            
                if(posicaoFim < posicaoInicio)
                {
                    for(posicaoFim-=1; posicaoFim < posicaoInicio-1; posicaoFim ++)
                    {
                        switch (barra[posicaoFim])
                        {
                            case v1:
                                somaV1 += 1;
                                break;
                            case v2:
                                somaV2 += 1;
                                break;
                            case v3:
                                somaV3 += 1;
                                break;
                            case v4:
                                somaV4 += 1;
                                break;
                            case v5:
                                somaV5 += 1;
                                break;
                        }
                    }
                }
                else
                {
                    for(posicaoInicio; posicaoInicio < posicaoFim; posicaoInicio ++)
                    {
                        switch (barra[posicaoInicio])
                        {
                            case v1:
                                somaV1 += 1;
                                break;
                            case v2:
                                somaV2 += 1;
                                break;
                            case v3:
                                somaV3 += 1;
                                break;
                            case v4:
                                somaV4 += 1;
                                break;
                            case v5:
                                somaV5 += 1;
                                break;
                        }
                    }
                }
            }
    
            tentativaSenha[0] = somaV1;
            tentativaSenha[1] = somaV2;
            tentativaSenha[2] = somaV3;
            tentativaSenha[3] = somaV4;
            tentativaSenha[4] = somaV5;
            
            printf("\n> A senha que você tentou é: ");
            for(deslizamento=0; deslizamento<=4; deslizamento++)
            {
                printf("%i ", tentativaSenha[deslizamento]);
            }
        
            acertos = 0;
            for(deslizamento=0; deslizamento<=4; deslizamento++)
            {
                if(tentativaSenha[deslizamento] == senhaCorreta[deslizamento])
                    acertos += 1;
            }

            if(acertos != 5)
            {
                printf("\n\n\tOhh no... Não foi dessa vez.\n");
                
                if (numeroDaTentativa <= 2)
                    printf("\n\tVocê ainda tem %i tentativas!\n", 3 - numeroDaTentativa);
                else
                    printf("\n\tSinto muito, suas tentativas acabaram...");
            }
            else
                printf("\n\n\tPARABÉNS!!! Você acertou a senha do cofre!\n");
        }
    }
    
    system("pause");
    return 0;
}
