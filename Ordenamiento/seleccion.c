/**
 * @file seleccion.c
 * @author Kevin Jafet Moran Orozco
 * @brief Recorre todo el arreglo buscando el numero más pequeño, lo pasa al inicio y vulevea recorrer el arreglo
 * empezando en i + 1
 * @version 0.1
 * @date 2022-11-12
 * 
 * mejor y peor de los casos O(n) = n^2
 * inestable
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

void intercambio(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void imprimeArreglo(int *arr, int length){
    printf("\n");
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[10] = {5, 2, 4, 6, 1, 3, 2, 6, 7, 2};
    int menorPosition = 0;

    for(int i = 0; i < 10-1 ; i++){
      int menorPosition = i;
      for(int j = i + 1 ; j < 10 ; j++){
            if(arr[j] < arr[menorPosition]){
                  menorPosition = j;
            }
      }
      intercambio(&arr[menorPosition], &arr[i]);
    }

    imprimeArreglo(arr, 10);

    return 0;
}