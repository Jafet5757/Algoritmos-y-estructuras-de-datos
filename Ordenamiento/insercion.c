/**
 * @file insercion.c
 * @author Kevin Jafet Moran Orozco (moran.orozco.kevingmail.com)
 * @brief  Compara si el numero en la pos i es mayor que i+1, si es así los intercambia 
 * y ahora compara los de la pos i e i-1, va hacia abajo para comprobar que ya esta bien acomodado
 * una vez que encuentra uno mal a comodado lo lleva hacia atras todo los posible
 * @version 0.1
 * @date 2022-11-12
 * 
 * mejor O(n) = n
 * medio O(n) = n^2
 * peor O(n) = n^2
 * estable
 * 
 * @copyright Copyright (c) 2022
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

    int arr[10] = {5, 2, 4, 6, 20, 3, 2, 6, 7, 2};
    int j = 0;

    for(int i=0; i<10-1; i++){
        j = i;
        while(arr[j]>arr[j+1]){
            intercambio(&arr[j], &arr[j+1]);
            if(j==0)
                break;
            j--;
        }
    }

    imprimeArreglo(arr, 10);

    return 0;
}