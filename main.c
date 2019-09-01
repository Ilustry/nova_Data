#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Instanciando o struct contendo as vari�veis que comp�em a data//
struct data
{
    int dia;
    int mes;
    int ano;

};

/*Vari�vel global contendo os dias de cada m�s
  linha 1 = bissexto e linha 0 = n-bissexto*/
int dias_mes[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*Vari�vel global para manipular as linha da matriz dias_mes
  com o retorno do valor da fun��o dbissexto*/
int bissexto;

//Fun��o que verifica se o ano � bissexto, retorna 1 quando bissexto e 0 quando n�o//
int dbissexto(int ano)
{
    return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

//Fun��o que calcula a nova data ap�s o tempo (em dias transcorridos) informado//
struct data nova_data(int dia, int mes, int ano)
{
    struct data nova;
    bissexto = dbissexto(ano);
    int i;
    bool k = true;

    for(i = mes; k; i++){
        if(i>12){
            ano++;
            bissexto = dbissexto(ano);
            i = 1;
        }
        if(dia > dias_mes[bissexto][i]){
            dia -= dias_mes[bissexto][i];
            k = true;
        }
        else if(dia <= dias_mes[bissexto][i]){
            k = false;
            nova.dia = dia;
            nova.mes = i;
            nova.ano = ano;
        }
    }
    return nova;
}

int main()
{
    struct data d;
    int qnt = 0;


    printf("////////////////////////////////////////\n");
    printf("///// Utilize o formato DD/MM/AAAA /////\n");
    printf("////////////////////////////////////////\n\n");
    printf("Informe a data.\n");
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
    bissexto = dbissexto(d.ano);

    //Verificando validez do valor digitado pelo usu�rio//
    while(d.dia > dias_mes[bissexto][d.mes] || d.dia < 1 || d.mes < 1 || d.mes > 12 || d.ano < 1){
        fflush(stdin);
        printf("\nData inexistente.\n");
        printf("Informe a data novamente.\n");
        scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
        bissexto = dbissexto(d.ano);
    }
    printf("Informe a quantidade de dias.\n");
    scanf("%d",&qnt);

    while(qnt < 1){
        fflush(stdin);
        printf("Valor invalido.\n");
        printf("Informe outro valor.\n");
        scanf("%d", &qnt);
    }

    d.dia += qnt;

    //Chamando a fun��o que efetua o c�lculo//
    d = nova_data(d.dia, d.mes, d.ano);
    printf("\n\nA data sera %d/%d/%d em %d dias.\n\n", d.dia, d.mes, d.ano, qnt);

    return 0;
}
