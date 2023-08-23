
#include <stdio.h>
#include <stdlib.h>
#include "FILA.H"

int main(){

struct sfila fila;

int i;

qinit(&fila);

enqueue(&fila,'A');
enqueue(&fila,'B');
enqueue(&fila,'C');
enqueue(&fila,'D');
enqueue(&fila,'E');
enqueue(&fila,'F');
enqueue(&fila,'G');
enqueue(&fila,'H');
enqueue(&fila,'I');
enqueue(&fila,'J');

dequeue(&fila);
dequeue(&fila);

enqueue(&fila,'K');


printf("Primeiro: %c \n",first(&fila));
printf("Ultimo: %c \n",last(&fila));
printf("Total de elementos: %d \n",count(&fila)) ;


while (! qisEmpty(&fila))
{ printf("%c \n", dequeue(&fila));
}

}

