#ifndef _pila_
#define _pila_
#define TAM 100
#define TRUE 1
#define FALSE 0

typedef struct{
	float pila[TAM];
	int tope;
}Pila;

typedef Pila *PILA;

PILA crearPila();
int es_vaciaPila(PILA);
void apilar(PILA, float);
float desapilar(PILA);
float elemTope(PILA);
float evalua(char *);
#endif