
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef char elemento;

// Define a estrutura Pilha
struct sfila{
 int total, inicio, fim;
 elemento vetor[MAX];
};   

void qinit(struct sfila *f);
int qisEmpty(struct sfila *f);
int qisFull(struct sfila *f);
void enqueue(struct sfila *f, elemento v);
elemento dequeue(struct sfila *f);
elemento first(struct sfila *f);
elemento last(struct sfila *f);
int count(struct sfila *f);

//inicializa a fila
void qinit(struct sfila *f)
{ f->total = 0; 
  f->inicio = 0;
  f->fim = 0;
}

//verifica se a fila esta vazia
int qisEmpty(struct sfila *f)
{ return (f->total == 0);
}

//verifica se a fila esta cheia
int qisFull(struct sfila *f)
{ return (f->total == MAX); /* capacidade esgotada */
}

//insere um elemento na fila
void enqueue(struct sfila *f, elemento v)
{
  if (qisFull(f)) {
   printf("Fila cheia.\n");
   exit(1); /* aborta programa */
  }

  /* insere elemento na pr�xima posi��o livre */
  f->vetor[f->fim] = v;
  f->total++;

  f->fim++; // simula a circularidade
  if (f->fim >= MAX)
  { f->fim = 0; }
}

//retira um elemento da fila
elemento dequeue(struct sfila *f)
{
elemento v;

if (qisEmpty(f))
{printf("Fila vazia.\n");
 exit(1); // aborta programa
}

v = f->vetor[f->inicio];
f->total--;

f->inicio++; //simula a circularidade
if (f->inicio >= MAX)
{ f->inicio = 0; }
return v;

}


elemento first(struct sfila *f)
{
  elemento v;

  if (qisEmpty(f))
  { printf("Fila vazia.\n");
    exit(1); // aborta programa
  }

  v = f->vetor[f->inicio];

  return v;

}

elemento last(struct sfila *f)
{
  elemento v;

  if (qisEmpty(f))
  { printf("Fila vazia.\n");
    exit(1); // aborta programa
  }

  if (f->fim == 0)
     v = f->vetor[MAX-1]; 
  else
     v = f->vetor[f->fim-1];

  return v;

}

int count(struct sfila *f)
{ return f->total;  }


