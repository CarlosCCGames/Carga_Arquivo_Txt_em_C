#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include<string.h>
#include <conio.h>

typedef struct
{
    char login[30];
    char senha[30];
} pessoa;
pessoa p[1];

int main()
{

    //criando uma variavel ponteiro para o arquivo
    FILE *pont_arq;

    //definindo as variaveis  a serem utilizadas
    char login[30]; // vetor para login
    char senha[30]; // vetor para senha
    char nome[200];
    char endereco[200];
    int idade;
    int dados;

    //iniciando loop
    do
    {
        setlocale(LC_ALL,"Portuguese"); //para caracteres especiais da lingua portuguesa
        printf("Aluno: Batatinha\n");
        printf("RA: XXXXXXXXX\n\n");
        printf("Projeto Integrado Multidisciplinar\n\n");

        strcpy(p[0].login, "Batatinha" );  // lê o que esta escrito no vetor login para validação
        strcpy(p[0].senha, "123Ratata" ); // lê o que esta escrito no vetor senha para validação

        printf("Digite o Login: \n");
        scanf("%s", login);
        setbuf(stdin,NULL);

        printf("Digite a senha: \n");
        scanf("%s", senha);
        setbuf(stdin,NULL); //limpa o buffer

        if((strcmp(login,p[0].login)== 0) && (strcmp(senha,p[0].senha)== 0)) // validação da senha e do login
        {
            system("cls");
            printf("Seja bem vindo!\n\n");

            printf("Digite seu nome: ");
            fgets(nome, 200, stdin);  // salva os dados digitados no vetor
            setbuf(stdin,NULL);
            //fflush(stdin);

            printf("Digite sua idade: ");
            scanf("%d", &idade);
            setbuf(stdin,NULL);
            //fflush(stdin);

            printf("Digite seu endereço: ");
            fgets(endereco, 300, stdin);
            setbuf(stdin,NULL);;
            //fflush(stdin);

            printf("Digite 1 para gerar dados ou 2 para sair: ");
            scanf("%d", &dados);
            setbuf(stdin,NULL);

            if (dados == 1) //verifica se o usuário quer salvar as informações
            {

                //abrindo o arquivo caso exista ou cria caso não exista

                pont_arq = fopen("caminho da rede/arquivo.txt","a");

                if (pont_arq == NULL) // em caso de erro na abertura
                {
                    printf("Erro na abertura do arquivo");
                    return 1;
                }
                else // salva os dados no arquivo em txt separados por "PIPE (|)" caso opção 1
                {
                    fprintf(pont_arq,"%s |", nome);
                    fprintf(pont_arq,"%d |", idade);
                    fprintf(pont_arq,"%s |\n", endereco);
                    fclose(pont_arq);
                    printf("Dados gravados com sucesso!");
                    sleep(01);
                    system("cls"); //Limpa a tela
                }

            }
            else // sai do programa e não salva os dados caso opção 2
            {
                printf("Obrigado e volte sempre!");
            }
        }
        else // caso logim e senha incorretos retorna para digitar
        {
            printf("Login e/ou senha incorretos\n");
            sleep(01); // temporizador para leitura do arquivo
            system("cls");
        }

    }
    while(dados != 2); // condição para sair do programa
    return 0;
}
