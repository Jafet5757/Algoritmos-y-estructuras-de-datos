#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    struct *elemento previo;
} elemento;

typedef struct{
    elemento tope;
    int tamaño;
} pila;

void initialize(pila *p){
    p->tamaño = 0;
    p->elemento = NULL;
}

void push(elemento e, pila *p){
    elemento *nuevo= malloc((elemento*) sizeof(elemento));
    nuevo->previo = p->tope;
    nuevo ->value = e.value;
    p->tope = nuevo;
    p->tamaño++;
}