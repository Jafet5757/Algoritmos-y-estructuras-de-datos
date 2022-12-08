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

int comprobarSiEsNumero(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int main(){

    Pila p;
    inicializacion(&p);

    //Iniciamos con la lógica del traductor
    char text[] = "(1+2-3)";
    int size = sizeof(text)/sizeof(text[0]);
    char newExpression [size];
    int contadorNuevaExpresion = 0;

    /*Reglas
    operador = procedencia -> se cambiasize
    operador > procedencia -> se agrega a la pila
    operador < procedencia -> saca operadpres
    parentesis derecho -> vacia pila 
    Se omiten los parentesis*/

    for(int i=0; i<size; i++){
        if(comprobarSiEsNumero(text[i])){
            newExpression[contadorNuevaExpresion] = text[i];
            contadorNuevaExpresion++;
        }else{
            //comprobamos reglas
            if(p.tamano==0 && text[i]!='(' && text[i]!=')'){
                Elemento e = {text[i]};
                push(&p, e);
            }else{
                Elemento *anterior = p.inicio;
                Elemento actual = {text[i], NULL};
                if(actual.dato=='(' || actual.dato==')'){
                    //No hace nada
                }else if((anterior->dato=='+' || anterior->dato=='-') && (actual.dato=='+' || actual.dato=='-')){
                    //metemos el anterior a la nueva expresion y dejamos al anterior
                    newExpression[contadorNuevaExpresion] = anterior->dato;
                    contadorNuevaExpresion++;
                    pop(&p);
                    push(&p, actual);
                }else if((anterior->dato=='*' || anterior->dato=='/') && (actual.dato=='*' || actual.dato=='/')){
                    //metemos el anterior a la nueva expresion y dejamos al anterior, lo mismo que el anterior
                    newExpression[contadorNuevaExpresion] = anterior->dato;
                    contadorNuevaExpresion++;
                    pop(&p);
                    push(&p, actual);
                }else if((anterior->dato=='+' || anterior->dato=='-') && (actual.dato=='*' || actual.dato=='/')){
                    //los operadores anteriores tienen menor jerarquía, solo se agrega a la pila
                    push(&p, actual);
                }else if((anterior->dato=='*' || anterior->dato=='/') && (actual.dato=='+' || actual.dato=='-')){
                    //los operadores anteriores tienen mayor jerarquía, se sacan y se agregan a la nueva expresión
                    int aux = 0;
                    do{
                        newExpression[contadorNuevaExpresion] = anterior->dato;
                        contadorNuevaExpresion++;
                        pop(&p);
                        Elemento *temp = anterior->sig;
                        aux = (temp->dato=='*' || temp->dato=='/') ? 1 : 0;
                    }while(aux);
                    push(&p, actual);
                }
            }
        }
    }
    
    //si el tamano de la pila no es cero vaciamos todo
    while(p.tamano>0){
        Elemento temp = pop(&p);
        if(temp.dato!='e'){
            newExpression[contadorNuevaExpresion] = temp.dato;
            contadorNuevaExpresion++;
        }else//subdesbordamiento
            break;
    }

    //Imprimimos el arreglo postfijo
    for(int i=0; i<contadorNuevaExpresion; i++){
        printf("%c", newExpression[i]);
    }

    return 0;
}