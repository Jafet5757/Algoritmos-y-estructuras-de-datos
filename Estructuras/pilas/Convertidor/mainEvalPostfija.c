#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pila.h"

void manejaError(int);
void leeExpresion(char *);
void mostrarResultado(char *, float);

void main(){
	char cadena[TAM];
	float resultado;
	leeExpresion(cadena);
	resultado = evalua(cadena);
	mostrarResultado(cadena, resultado);
}

void manejaError(int e){
	char *errores[] = {"No hay memoria disponible", "La pila esta llena", "La pila esta vacia", "Division por CERO"};
	printf("\n%s\n", errores[e]);
}

void leeExpresion(char *cadena){
	int pos=0;
	printf("\tEvaluacion de expresion Postfijas\n");
	printf("Operaciones Basicas: Suma, Resta, Producto y Division\n\n");
	printf("\n\nIntroduzca la expresion en Postfija: ");
	scanf("%[^\n]", cadena);
	pos = strlen(cadena-1);
	//while((cadena[pos++] == getchar()) != '1');
	cadena[--pos] = '\0';
}

void mostrarResultado(char *cadena, float resul){
	printf("\n\n\t %s = %.2f \n\n", cadena, resul);
}