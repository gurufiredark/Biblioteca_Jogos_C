#include <stdio.h>
#include <string.h>

struct informacoes
{
    char nome[20];
    char genero[20];
    char multiplayer;
    int visao_jogador;
    char maior_idade;
    int ano_lancamento;
    char desenvolvedora[20];
    float preco;
};

void adicionar_jogo(struct informacoes *jogo, int *numero_jogos)
{
    int i;
    *numero_jogos += 1;

    for(i=(*numero_jogos-1);i<*numero_jogos;i++)
    {
        printf("\n---------");
        printf("NOVO JOGO");
        printf("---------\n");
        fflush(stdin);
        printf("\nQual o nome do jogo?: ");
        fgets(jogo[i].nome,20,stdin);
        strupr(jogo[i].nome);

        fflush(stdin);
        printf("\nQual o genero desse jogo?: ");
        fgets(jogo[i].genero,20,stdin);
        strupr(jogo[i].genero);
        jogo[i].genero[strlen(jogo[i].genero)-1] = '\0';

        printf("\nO jogo possui multiplayer?[s/n]: ");
        scanf("%c",&jogo[i].multiplayer);

        printf("\nEm qual pessoa esta a visao do jogador?[1 ou 3]?: ");
        scanf("%i",&jogo[i].visao_jogador);

        fflush(stdin);
        printf("\nE para maiores de 18 anos?[s/n]: ");
        scanf("%c",&jogo[i].maior_idade);

        printf("\nQual o ano de lancamento do jogo?: ");
        scanf("%i",&jogo[i].ano_lancamento);

        fflush(stdin);
        printf("\nQual o nome da desenvolvedora desse jogo?: ");
        fgets(jogo[i].desenvolvedora,20,stdin);
        strupr(jogo[i].desenvolvedora);
        jogo[i].desenvolvedora[strlen(jogo[i].desenvolvedora)-1] = '\0';

        fflush(stdin);
        printf("\nQual o preco desse jogo?: ");
        scanf("%f",&jogo[i].preco);
        system("cls");
    }
}

void remover_jogo(struct informacoes *jogo, int *numero_jogos)
{
    int i, j;
    int fileira_excluida;

    printf("\n---------");
    printf("EXCLUIR JOGO");
    printf("---------\n");
    fflush(stdin);

    printf("Qual jogo deseja Excluir?");
    for(i=0;i<*numero_jogos;i++)
    {
        printf("\n %i - %s",i+1,jogo[i].nome);
    }
    printf("\n\b\b Digite aqui: ");
    scanf("%i",&fileira_excluida);

    if((fileira_excluida-1) < *numero_jogos)
    {
        for(i=(fileira_excluida-1);i<*numero_jogos;i++)  // -1 para a posiçao do vetor real
        {
            j = i + 1;
            strcpy(jogo[i].nome,jogo[j].nome);
            strcpy(jogo[i].genero,jogo[j].genero);
            jogo[i].multiplayer = jogo[j].multiplayer;
            jogo[i].visao_jogador = jogo[j].visao_jogador;
            jogo[i].maior_idade = jogo[j].maior_idade;
            jogo[i].ano_lancamento = jogo[j].ano_lancamento;
            strcpy(jogo[i].desenvolvedora,jogo[j].desenvolvedora);
            jogo[i].preco = jogo[j].preco;
        }
    *numero_jogos -= 1;
    system("cls");
    }
    else
    {
        printf("\n\nNENHUM JOGO EXCLUIDO");
    }

}

void consulta_jogos(struct informacoes *jogo, int numero_jogos)
{
    int i, j, MultiSingle, visao, idade, ano;
    int palavra_chave;
    char genero_chave[20];
    char desenvol[20];
    float preco_chave;

    do
    {
        palavra_chave = menu_palavra_chave();
        switch(palavra_chave)
        {
            case 1:
            j = 1;
                printf("Voce deseja jogos de qual genero?:\n ");
                printf("--GENEROS--\nMOBA\nFPS\nRPG\nCORRIDA\nRTS\nBATTLE ROYALE\nLUTA\n");
                printf("\b\b Digite aqui: ");
                scanf("%s",&genero_chave);
                strupr(genero_chave);
                printf("\nJogos do genero %s\n",genero_chave);

                for(i=0;i<numero_jogos;i++)
                {
                    if(strcmp(genero_chave,jogo[i].genero) == 0)
                    {
                        printf("\n %i - %s",j,jogo[i].nome);
                        j++;
                    }
                }
                if(j == 1)
                {
                    printf("Nenhum jogo encontrado");
                }
                break;
            case 2:
            j = 1;
                printf("Voce deseja jogos:\n\n");
                printf("1 - SinglePlayer\n");
                printf("2 - MultiPlayer\n");
                printf("\b\b Digite aqui: ");
                scanf("%i",&MultiSingle);

                if(MultiSingle == 1)
                {
                    printf("\nJogos SINGLEPLAYER\n");
                    for(i=0;i<numero_jogos;i++)
                    {
                        if(jogo[i].multiplayer == 'n')
                        {
                            printf("\n %i - %s",j,jogo[i].nome);
                            j++;
                        }
                    }
                }

                else if(MultiSingle == 2)
                {
                    printf("\nJogos MULTIPLAYER\n");
                    for(i=0;i<numero_jogos;i++)
                    {
                        if(jogo[i].multiplayer == 's')
                        {
                            printf("\n %i - %s",j,jogo[i].nome);
                            j++;
                        }
                    }
                }

                else
                {
                    printf("Comando Inválido");
                }

                break;
            case 3:
                j = 1;
                printf("Voce deseja jogos:\n\n");
                printf("1 - 1.a pessoa\n");
                printf("2 - 3.a pessoa\n");
                printf("\b\b Digite aqui: ");
                scanf("%i",&visao);

                if(visao == 1)
                {
                    printf("\nJogos em 1.a pessoa\n");
                    for(i=0;i<numero_jogos;i++)
                    {
                        if(jogo[i].visao_jogador == 1)
                        {
                            printf("\n %i - %s",j,jogo[i].nome);
                            j++;
                        }
                    }
                }

                else if(visao == 2)
                {
                    printf("\nJogos em 3.a pessoa\n");
                    for(i=0;i<numero_jogos;i++)
                    {
                        if(jogo[i].visao_jogador == 3)
                        {
                            printf("\n %i - %s",j,jogo[i].nome);
                            j++;
                        }
                    }
                }

                else
                {
                    printf("Comando Invalido");
                }

                break;
            case 4:
                j = 1;
                printf("Voce deseja jogos:\n\n");
                printf("1 - -18\n");
                printf("2 - +18\n");
                printf("\b\b Digite aqui: ");
                scanf("%i",&idade);

                if(idade == 1)
                {
                    printf("\nJogos para menores de idade \n");
                    for(i=0;i<numero_jogos;i++)
                    {
                        if(jogo[i].maior_idade == 'n')
                        {
                            printf("\n %i - %s",j,jogo[i].nome);
                            j++;
                        }
                    }
                }

                else if(idade == 2)
                {
                    printf("\nJogos para maiores de idade \n");
                    for(i=0;i<numero_jogos;i++)
                    {
                        if(jogo[i].maior_idade == 's')
                        {
                            printf("\n %i - %s",j,jogo[i].nome);
                            j++;
                        }
                    }
                }

                else
                {
                    printf("Comando Invalido");
                }

                break;
            case 5:
                j = 1;
                printf("Voce deseja jogos de qual ano?:\n");
                printf("\b\b Digite aqui: ");
                scanf("%i",&ano);
                printf("\nJogos do ano %i",ano);

                for(i=0;i<numero_jogos;i++)
                {
                    if(ano == jogo[i].ano_lancamento)
                    {
                        printf("\n %i - %s",j,jogo[i].nome);
                        j++;
                    }
                }
                break;
            case 6:
                j = 1;
                printf("Digite o nome da desenvolvedora dos jogos:\n ");
                printf("\b\b Digite aqui: ");
                fflush(stdin);
                fgets(desenvol,20,stdin);
                fflush(stdin);
                strupr(desenvol);
                printf("\nJogos da desenvolvedora: %s\n",desenvol);
                desenvol[strlen(desenvol)-1] = '\0';

                for(i=0;i<numero_jogos;i++)
                {
                    if(strcmp(desenvol,jogo[i].desenvolvedora) == 0)
                    {
                        printf("\n %i - %s",j,jogo[i].nome);
                        j++;
                    }
                }
                break;
            case 7:
                j = 1;
                printf("Digite o preco dos jogos desejados:\n ");
                printf("\b\b Digite aqui: ");
                scanf("%f",&preco_chave);

                for(i=0;i<numero_jogos;i++)
                {
                    if(preco_chave == jogo[i].preco)
                    {
                        printf("\n %i - %s",j,jogo[i].nome);
                        j++;
                    }
                }
                break;
            case 8:
                printf("Voltando...");
                break;
            default:
                printf("Comando invalido");
                break;
        }
    } while (palavra_chave != 8);

}

void listagem_jogos(struct informacoes *jogo, int numero_jogos)
{
    int i;

    printf("\n\n-------------------\n");
    printf("JOGOS CADASTRADOS:");
    printf("\n-------------------");

    for(i=0;i<numero_jogos;i++)
    {
        printf("\n%i.o jogo",i+1);
        printf("\nNome: %s",jogo[i].nome);
        printf("\nGenero: %s",jogo[i].genero);
        printf("\nMultiplayer ou Singleplayer?: ");
        if (jogo[i].multiplayer == 's')
        {
            printf("MULTIPLAYER");
        }
        else if (jogo[i].multiplayer == 'n')
        {
            printf("SINGLEPLAYER");
        }
        else
        {
            printf("Comando invalido");
        }

        printf("\nVisao do jogador: ");
        if(jogo[i].visao_jogador == 1)
        {
            printf("1.a PESSOA");
        }
        else if (jogo[i].visao_jogador == 3)
        {
            printf("3.a PESSOA");
        }
        else
        {
            printf("Comando invalido");
        }

        printf("\nE para maiores de 18 anos?: ");
        if (jogo[i].maior_idade == 's')
        {
            printf("JOGO PARA MAIORES DE 18 ANOS");
        }
        else if (jogo[i].maior_idade == 'n')
        {
            printf("JOGO LIVRE PARA TODOS OS PUBLICOS");
        }
        else
        {
            printf("Comando invalido");
        }

        printf("\nAno de lancamento: %i",jogo[i].ano_lancamento);
        printf("\nDesenvolvedora do jogo: %s",jogo[i].desenvolvedora);
        printf("\nValor: %.2f",jogo[i].preco);
        printf("\n----------------------\n\n");
    }
}

void atualizacao_preco(struct informacoes *jogo, int numero_jogos)
{
    int i, numero_escolhido;
    float novo_preco;

    printf("\n-------------------\n");
    printf("ATUALIZACAO DE PRECO");
    printf("\n-------------------\n");
    printf("\nQual jogo deseja atualizar o valor?:\n ");

    for(i=0;i<numero_jogos;i++)
    {
        printf("\n %i - %s",i+1, jogo[i].nome);
    }
    printf("\n\b\b Digite aqui: ");
    scanf("%i",&numero_escolhido);

    numero_escolhido -= 1;
    printf("\nJogo escolhido: %s",jogo[numero_escolhido].nome);
    printf("\nPreco atual: %.2f",jogo[numero_escolhido].preco);
    printf("\n\nQual o novo preco desse jogo?: ");
    printf("\n\b\bDigite aqui: ");
    scanf("%f",&novo_preco);

    jogo[numero_escolhido].preco = novo_preco;
}

void leitura(struct informacoes *jogo, int *numero_jogos)
{
    int i;
    FILE *arquivo;

    if((arquivo = fopen("Jogos_Cadastrados.txt","r+b")) != NULL)
    {
        fscanf(arquivo,"%i\n",&*numero_jogos);

        for(i=0;i<*numero_jogos;i++)
        {
            fread(&jogo[i],sizeof(struct informacoes),1,arquivo);
        }
    }
    fclose(arquivo);
}

void gravacao(struct informacoes *jogo, int numero_jogos)
{
    int i;
    FILE *arquivo;
    arquivo = fopen("Jogos_Cadastrados.txt","w+b");

    fprintf(arquivo,"%i\n",numero_jogos);
    for(i=0;i<numero_jogos;i++)
    {
        fwrite(&jogo[i],sizeof(struct informacoes),1,arquivo);
    }
    fclose(arquivo);
}

int menu()
{
    int resposta;
    printf("\n------ MENU ------\n");
    printf("1 - Adicionar novo jogo no cadastro\n");
    printf("2 - Remover jogo do cadastro\n");
    printf("3 - Consultar por palavra chave\n");
    printf("4 - Listagem de todos os jogos do cadastro\n");
    printf("5 - Alteracao no preco de um jogo\n");
    printf("6 - Sair do programa\n\n");
    printf("\b\b Digite aqui: ");
    scanf("%i",&resposta);

    system("cls");
    return(resposta);
}

int menu_palavra_chave()
{
    int resposta_chave;
    printf("\n------ MENU ------\n");
    printf("Consultar por:\n ");
    printf("\b1 - Genero\n");
    printf("\b2 - Multiplayer\n");
    printf("\b3 - Visao do jogador\n");
    printf("\b4 - Jogos +18\n");
    printf("\b5 - Ano de lancamento\n");
    printf("\b6 - Desenvolvedora\n");
    printf("\b7 - Preco\n");
    printf("\b8 - Voltar\n\n");
    printf("\b\b Digite aqui: ");
    scanf("%i",&resposta_chave);

    system("cls");
    return(resposta_chave);
}

void main()
{
   struct informacoes jogos;
   int num_jog=0, resposta;
   system("color 9");
   leitura(&jogos,&num_jog);

   do
   {
       resposta = menu();
        switch(resposta)
        {
            case 1:
                adicionar_jogo(&jogos,&num_jog);
                break;
            case 2:
                remover_jogo(&jogos,&num_jog);
                break;
            case 3:
                consulta_jogos(&jogos,num_jog);
                break;
            case 4:
                listagem_jogos(&jogos,num_jog);
                break;
            case 5:
                atualizacao_preco(&jogos,num_jog);
                break;
            case 6:
                printf("SAINDO DO PROGRAMA...");
                gravacao(&jogos,num_jog);
                break;
            default:
                printf("Resposta invalida");
                break;
        }
   }while(resposta != 6);
}
