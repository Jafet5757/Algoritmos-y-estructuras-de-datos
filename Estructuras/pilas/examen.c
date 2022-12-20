/**
 * @file examen.c
 * @author Kevin Jafet Moran Orozco
 * @brief Verifica si una frase es un palindromo
 * @version 0.1
 * @date 2022-12-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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

/**
 * @brief Comprueba si es un palindromo
 * 
 * @param p Pila donde se guardan los caracteres
 * @param frase Frase a evaluar
 * @return int Booleano
 */
int comprobarSiEsPalindromo(Pila p, char *frase){
    int i = 0;
    while(frase[i] != '\0'){
        Elemento e;
        e.dato = frase[i];
        if(e.dato != ' '){
            push(&p,e);
        }
        i++;
    }
    i = 0;
    while(frase[i] != '\0'){
        Elemento e = pop(&p);
        if(frase[i] == ' ')i++;//elimina espacios

        if(e.dato != frase[i]){
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * @brief Convierte una cadena de caracteres a minusculas
 * 
 * @param frase Frase a transformar
 */
void stringAMinusculas(char *frase){
    int i = 0;
    while(frase[i] != '\0'){
        if(frase[i] >= 'A' && frase[i] <= 'Z'){
            frase[i] = frase[i] + 32;
        }
        i++;
    }
}

void eliminaTildesAscii(char *frase){
    int i = 0;
    while(frase[i] != '\0'){
        if(frase[i] == 160){
            frase[i] = 'a';
        }else if(frase[i] == 130){
            frase[i] = 'e';
        }else if(frase[i] == 161){
            frase[i] = 'i';
        }else if(frase[i] == 162){
            frase[i] = 'o';
        }else if(frase[i] == 163){
            frase[i] = 'u';
        }
        i++;
    }
}

//Elimina tildes con hexadecimal
void eliminaTildesHexadecimal(char *frase){
    int i = 0;
    while(frase[i] != '\0'){
        if(frase[i] == 0xA0){
            frase[i] = 'a';
        }else if(frase[i] == 0x82){
            frase[i] = 'e';
        }else if(frase[i] == 0xA1){
            frase[i] = 'i';
        }else if(frase[i] == 0xA2){
            frase[i] = 'o';
        }else if(frase[i] == 0xA3){
            frase[i] = 'u';
        }
        i++;
    }
}


int main(){

    Pila p;
    inicializacion(&p);

    char frase[] = "anita lava la tIna";

    eliminaTildesHexadecimal(frase);
    stringAMinusculas(frase);

    printf("\n%s\n", frase);

    comprobarSiEsPalindromo(p,frase) ? printf("Si es palindromo") : printf("No es palindromo");

    return 0;
}