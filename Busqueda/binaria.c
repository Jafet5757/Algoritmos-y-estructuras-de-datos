/**
 * @file binaria.c
 * @author your name (you@domain.com)
 * @brief Se utiliza cuando el vector en el que queremos determinar la existencia de un elemento 
 * está previamente ordenado. Este algoritmo reduce el tiempo de búsqueda considerablemente, ya 
 * que disminuye exponencialmente el número de iteraciones necesarias. En el peor de los casos el 
 * número máximo de comparaciones es log2 n + 1, donde n es el número de los elementos en el vector. 
 * Por ejemplo, en uno conteniendo 50.000.000 elementos, el algoritmo realiza como máximo 26 comparaciones.
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

int busquedaBinaria(int  vector[], int n, int dato) {
   int centro,inf=0,sup=n-1;
   while(inf<=sup){
      centro=((sup+inf)/2);
      if(vector[centro]==dato)       return centro;
      else if(dato < vector[centro]) sup=centro-1;
      else                           inf=centro+1;
   }
   return -1;
}

int main(){
    int n = 6;
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    printf("La posicion es: %d ",busquedaBinaria(arr, 10, n));
}