#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void gerarMenu()
{
    printf("------------MENU------------\n\nPor favor, digite uma das opções abaixo: \n\n");
    printf("[1] - Listar carros\n");
    printf("[2] - Liberar carros\n");
    printf("[3] - Registrar carro\n");
    printf("[4] - SAIR\n");
    return;
}

void exibirCarros(struct sfila *guarus, struct sfila *centro)
{
    struct sfila fila_aux;
    int contador = 1;
    system("clear");
    printf("---------Carros em Guarus---------\n\n\n\n");

    while (!qisEmpty(guarus))
    {
        enqueue(&fila_aux, (dequeue(guarus)));
        printf("[%d] - %s\n", contador, last(&fila_aux).placa);
        contador++;
    }

    while (!qisEmpty(&fila_aux))
    {
        enqueue(guarus, dequeue(&fila_aux));
    }

    contador = 1;
    printf("---------Carros no Centro---------\n\n\n\n");
    while (!qisEmpty(centro))
    {
        enqueue(&fila_aux, (dequeue(centro)));
        printf("[%d] - %s\n", contador, last(&fila_aux).placa);
        contador++;
    }

    while (!qisEmpty(&fila_aux))
    {
        enqueue(centro, dequeue(&fila_aux));
    }
}

void liberarCarros(struct sfila *fila_guarus, struct sfila *fila_centro)
{
    dequeue(fila_guarus);
    dequeue(fila_centro);
}

void registrarCarro(struct sfila *f)
{
    if (qisFull(f))
    {
        printf("Esta fila está cheia, pressione ENTER para continuar.");
        scanf("%*c");
        getchar();
        return;
    }
    struct carro carro_a_adicionar;
    printf("Digite a placa / identificação do carro: ");
    scanf("%9s", carro_a_adicionar.placa);
    enqueue(f, carro_a_adicionar);
}

int main()
{

    int entrada;
    struct sfila fila_guarus;
    struct sfila fila_centro;

    qinit(&fila_guarus);
    qinit(&fila_centro);

    do
    {
        system("clear");
        gerarMenu();
        scanf("%d", &entrada);
        switch (entrada)
        {
        case 1:
            system("clear");
            exibirCarros(&fila_guarus, &fila_centro);
            scanf("%*c");
            getchar();
            break;

        case 2:
            liberarCarros(&fila_guarus, &fila_centro);
            break;

        case 3:
            system("clear");
            int fila_a_adicionar;
            scanf("%*[^\n]s");
            printf("1- Guarus\n2-Campos Centro\n");
            scanf("%d", &fila_a_adicionar);

            if (fila_a_adicionar == 1)
            {
                registrarCarro(&fila_guarus);
            }
            else if (fila_a_adicionar == 2)
            {
                registrarCarro(&fila_centro);
            }
            break;

        default:
            break;
        }
    } while (entrada != 4);

    return 0;
}