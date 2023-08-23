#include <stdio.h>
#include <stdlib.h>
#include "FILA.H"

void gerarMenu() {
    return;
}

void registrarCarro(struct sfila *f, char carro_a_adicionar) {
    char carro_a_adicionar;
    
    enqueue(&f, carro_a_adicionar);
}

void exibirFilas(struct sfila *fila_guarus, struct sfila *fila_centro) {
    struct sfila fila_aux;
    while (!qisEmpty(&fila_guarus)) {
        printf("%s", last(&fila_guarus));
        enqueue(&fila_aux,(dequeue(fila_guarus)));
    }

    while (!qisEmpty(&fila_aux)) {
        enqueue( &fila_guarus, dequeue(&fila_aux));
    }

    while (!qisEmpty(&fila_centro)) {
        printf("%s", last(&fila_guarus));
        enqueue(&fila_aux,(dequeue(fila_centro)));
    }

    while (!qisEmpty(&fila_aux)) {
        enqueue( &fila_centro, dequeue(&fila_aux));
    }
}

void liberarCarros(struct sfila *fila_guarus, struct sfila *fila_centro) {
    dequeue(&fila_guarus);
    dequeue(&fila_centro);
}

int main() {
    int entrada;
    struct sfila fila_guarus;
    struct sfila fila_camposcentro;

    qinit(&fila_guarus);
    qinit(&fila_camposcentro);



    do {
        system("clear");
        gerarMenu();
        scanf("%d", &entrada);
        switch (entrada) {
            case 1:
                system("clear");
                exibirFilas(&fila_guarus, &fila_camposcentro);
                break;
            

            case 2:
                system("clear");
                int fila_a_adicionar;
                char carro_a_adicionar[10];
                scanf("%*[^\n]s");
                printf("1- Guarus\n2-Campos Centro\n");
                scanf("%d", &fila_a_adicionar);
                printf("Digite a placa / identificação do carro: ");
                scanf("%9s", carro_a_adicionar);
                if (fila_a_adicionar == 1) {
                    registrarCarro(&fila_guarus, carro_a_adicionar);
                } else if (fila_a_adicionar == 2) {
                    registrarCarro(&fila_camposcentro, carro_a_adicionar);
                }
                break;
            
            

            case 3:
                system("clear");
                liberarCarros(&fila_guarus, &fila_camposcentro);
                break;

            default:
                break;
        }
    } while (entrada != 4);
    return 0;
}