#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct data
    {
        int dia;
        int mes;
        int ano;

    };

    int dbissexto(int ano)
    {
        return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
    }

    struct data nova_data(int dia, int mes, int ano)
    {
        int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                           {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
        struct data nova;
        int bissexto = dbissexto(ano);
        int i;
        bool k = true;

        for(i = mes; k; i++){
            if(i>12){
                bissexto = dbissexto(ano++);
                i = 1;
            }
            if(dia > dias_mes[bissexto][i]){
                dia -= dias_mes[bissexto][i];
                k = true;
            }
            else if(dia <= dias_mes[bissexto][i]){
                k = false;
                nova.dia = dia;
                nova.mes = mes;
                nova.ano = ano;
            }
        }
        printf("dia = %d // mes = %d // ano = %d\n\n", nova.dia, nova.mes, nova.ano);
        return nova;
    }

int main()
{
    struct data d;
    int qnt = 0;

    printf("Utilize o formato DD/MM/AAAA\n\n");
    printf("Informe a data.\n");
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
    printf("Informe a quantidade de dias.\n");
    scanf("%d", &qnt);

    int i;
    d.dia += qnt;

    nova_data(d.dia, d.mes, d.ano);

    return 0;
}
