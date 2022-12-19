#include<stdlib.h>
#include "pila.h"

void manejaError(int);

PILA crearPila(){
	PILA S;
	S = (PILA) malloc(sizeof(Pila));
	if(S == NULL){
		manejaError(0);
		exit(0);
	}
	S->tope = -1;
	return S;
}

int es_vaciaPila(PILA S){
	if(S->tope < 0)return TRUE;
	else return FALSE;
}

void apilar(PILA S, float x){
	if(S->tope == TAM-1){
		manejaError(1);
		exit(0);
	}
	S->tope++;
	S->pila[S->tope] = x;
}

float desapilar(PILA S){
	float x;
	if(es_vaciaPila(S)){
		manejaError(2);
		exit(0);
	}
	x = S->pila[S->tope];
	S->tope--;
	return x;
}

float elemTope(PILA S){
	float x;
	if(es_vaciaPila(S)){
		manejaError(2);
		exit(0);
	}
	x = desapilar(S);
	apilar(S, x);
	return x;
}

float evalua(char *cadena){
	PILA S;
	S = crearPila();
	float a, b;
	int pos=0, i;
	char op[1];
	double conv;
	
	while(cadena[pos] != '\0'){
		*op = cadena[pos++];
		switch(*op){
			case '+':
				b = desapilar(S);
				a = desapilar(S);
				apilar(S, a+b);
			break;
			case '-':
				b = desapilar(S);
				a = desapilar(S);
				apilar(S, a-b);
			break;
			case '*':
				b = desapilar(S);
				a = desapilar(S);
				apilar(S, a*b);
			break;
			case '/':
				b = desapilar(S);
				a = desapilar(S);
				if(b == 0){
					manejaError(3);
					return 0;
					break;
				}
				apilar(S, a/b);
			break;
			case '^':
				b = desapilar(S);
				a = desapilar(S);
				while(b > 1){
					a = a*a;
					b--;
				}
				apilar(S, a);
			break;
			default: 
				conv = atof(op); //Convierte un caractr a decimal
				apilar(S, conv); //Almacena el valor (numero) en la pila
		}
	}
	return (desapilar(S));
}