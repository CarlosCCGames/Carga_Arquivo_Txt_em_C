#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include<string.h>
#include <conio.h>

typedef struct{
    char login[30];
    char senha[30];
} pessoa; pessoa p[1];

struct dma2 {
int dia;
int mes;
int ano;
};

struct dma2 data2;

int validacao (int dia, int mes, int ano){
    int y, m;
    if( mes > 0 && mes <= 12 && dia <=31)
    {
        m = validacao_fev (dia, mes, ano);
        if ( m == 0)
        {
            y = 0;
        }
        else
        {
            y = 1;
        }
    }
    else
    {
        printf("\n Digite a data corretamente! ");
        y = 1;
    }
    return y;
}

int validacao_fev (int dia, int mes, int ano){
    int fev, conf_ano;

    conf_ano = ano%4;

    if(conf_ano == 0)
    {
        if(mes == 2 && dia <=29)
        {
            fev = 0;
        }
    }
    else
    {
        if(mes == 2 && dia <=28)
        {
            fev = 0;
        }
    }
    return fev;
}

void main()
{
    setlocale(LC_ALL,"Portuguese"); //para caracteres especiais da lingua portuguesa

    //criando uma variavel ponteiro para o arquivo1
    FILE *pont_arq;

    //definindo as variaveis  a serem utilizadas
    char login[30]; // vetor para login
    char senha[30]; // vetor para senha
    char nome[200];
    char endereco[200];
    char telefone[30],email[30], cpf[30] ;
    int dados, dia, mes, ano, x, idade = 0;
    char diab[30] = "Diabetes";
    char obes[30] = "Obesidade";
    char hiper[30] = "Hipertensao";
    char tub[30] = "Tuberculose";
    int d, o, h, t = 0;
    char outros[100];

    //iniciando loop
    do
    {

        printf("Aluno: Batatinha\n");
        printf("RA: XXXXXXXXX\n\n");
        printf("Projeto Integrado Multidisciplinar\n\n");

        strcpy(p[0].login, "1" );  // lê o que esta escrito no vetor login para validação
        strcpy(p[0].senha, "1" ); // lê o que esta escrito no vetor senha para validação

        printf("Digite o Login: ");
        scanf("%s", login);
        setbuf(stdin,NULL); //limpa o buffer

        printf("Digite a senha: ");
        scanf("%s", senha);
        setbuf(stdin,NULL); //limpa o buffer

        if((strcmp(login,p[0].login)== 0) && (strcmp(senha,p[0].senha)== 0)) // validação da senha e do login
        {
            system("cls");
            printf("Seja bem vindo!\n\n");

            printf("Digite seu nome: ");
            fgets(nome, 200, stdin);  // salva os dados digitados no vetor
            setbuf(stdin,NULL);

            printf("Digite seu CPF: ");
            fgets(cpf, 30, stdin);  // salva os dados digitados no vetor
            setbuf(stdin,NULL);

            printf("Digite seu endereço completo: ");
            fgets(endereco, 300, stdin);
            setbuf(stdin,NULL);

            printf("Digite seu e-mail: ");
            fgets(email, 30, stdin);
            setbuf(stdin,NULL);

            printf("Digite seu telefone: ");
            fgets(telefone, 30, stdin);
            setbuf(stdin,NULL);

            do
            {
                printf("\nDigite sua data de nascimento\n");

                printf("Digite o dia de seu nascimento: ");
                scanf("%d", &data2.dia);
                setbuf(stdin,NULL);

                printf("Digite o mês de seu nascimento: ");
                scanf("%d", &data2.mes);
                setbuf(stdin,NULL);

                printf("Digite o ano de seu nascimento: ");
                scanf("%d", &data2.ano);
                setbuf(stdin,NULL);

                dia = data2.dia;
                mes = data2.mes;
                ano = data2.ano;

                x = validacao(dia, mes, ano);
                setbuf(stdin,NULL);

            }while( x != 1);


            idade = 2023 - ano;

            if(idade > 65)
            {
                printf("Favor verificar se tem as seguintes comorbidades:\n");
                printf("\nDigite 1 para sim ou 2 para não:\n");

                printf("Tem diabetes: ");
                scanf("%s", &diab);
                setbuf(stdin,NULL);

                printf("Tem obesidade: ");
                scanf("%s", &obes);
                setbuf(stdin,NULL);

                printf("Tem Hipertenção: ");
                scanf("%s", &hiper);
                setbuf(stdin,NULL);

                printf("Tem tuberculose: ");
                scanf("%s", &tub);
                setbuf(stdin,NULL);

                printf("Descreve caso tenha outras comorbidades: ");
                fgets(outros, 100, stdin);
                setbuf(stdin,NULL);

            }

            printf("Digite 1 para gerar dados ou 2 para sair: ");
            scanf("%d", &dados);
            setbuf(stdin,NULL);

            if (dados == 1) //verifica se o usuário quer salvar as informações
            {

                //abrindo o arquivo caso exista ou cria caso não exista

                pont_arq = fopen("C:/Users/carlo/OneDrive/Área de Trabalho/Aulas Power BI/05 - Aulas C/Exercício 12/arquivo.txt","a");

                if (pont_arq == NULL) // em caso de erro na abertura
                {
                    printf("Erro na abertura do arquivo");
                    return 1;
                }
                else // salva os dados no arquivo em txt separados por "PIPE (|)" caso opção 1
                {
                    fprintf(pont_arq,"Nome: %s \n", nome);
                    fprintf(pont_arq,"CPF: %s \n", cpf);
                    fprintf(pont_arq,"Telefone: %s \n", telefone);
                    fprintf(pont_arq," Endereço: %s \n", endereco);
                    fprintf(pont_arq,"Data de nascimento: %d/%d/%d \n", dia, mes, ano);
                    fprintf(pont_arq,"E-mail: %s \n", email);

                    if(diab == '1')
                    {
                       fprintf(pont_arq,"Diabetes: Positivo \n", diab);

                    }else
                    {
                        fprintf(pont_arq,"Diabetes: Negativo \n", hiper);
                    }

                    if(obes == '1')
                    {
                       fprintf(pont_arq,"Obsidade: Positivo \n", obes);

                    }else
                    {
                        fprintf(pont_arq,"Obsidade: Negativo \n", hiper);
                    }

                    if(hiper == '1')
                    {
                       fprintf(pont_arq,"Hipertenção: Positivo \n", hiper);

                    }else
                    {
                        fprintf(pont_arq,"Hipertenção: Negativo \n", hiper);
                    }

                    if(tub == '1')
                    {
                       fprintf(pont_arq,"Tuberculose: Positivo \n", tub );

                    }else
                    {
                        fprintf(pont_arq,"Tuberculose: Negativo \n", hiper);
                    }



                    //fprintf(pont_arq,"%d |", diab);
                    //fprintf(pont_arq,"%d |", obes);
                    ///fprintf(pont_arq,"%d |", hiper);
                    //fprintf(pont_arq,"%d |", tub);
                    fprintf(pont_arq,"%s |", outros);

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
