#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char dato;
    struct elemento *sig;
}Elemento;

typedef struct{
    Elemento *inicio;
    int tamano;
}Pila;

void inicializacion(Pila *p){
    p -> inicio = NULL;
    p -> tamano = 0;
}

void push(Pila *p, Elemento e){
    Elemento *nuevo = calloc(1,sizeof(Elemento));
    nuevo -> dato = e.dato;
    nuevo -> sig = p -> inicio;
    p -> inicio = nuevo;
    p -> tamano++;
}

void empty(Pila *p) {
    Elemento *aux = p -> inicio;
    while(aux != NULL){
        Elemento *temp = aux;
        aux = aux -> sig;
        free(temp);
    }
    p -> inicio = NULL;
    p -> tamano = 0;
}

Elemento pop(Pila *p){
    Elemento e;
    if(p -> inicio == NULL){
        e.dato = 'e';//error
        return e;
    }
    Elemento *aux = p -> inicio;
    e.dato = aux -> dato;
    p -> inicio = aux -> sig;
    free(aux);
    p -> tamano--;
    return e;
}

float evalua(char *cadena){
	Pila S;
	inicializacion(&S);
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
}

int main(){

    Pila p;
    inicializacion(&p);

    //solo sumas y multiplicaciones, sin paréntesis
    char text[] = "15+2*1-";
    int size = sizeof(text)/sizeof(text[0]);
    char newExpression [size];



    return 0;
}