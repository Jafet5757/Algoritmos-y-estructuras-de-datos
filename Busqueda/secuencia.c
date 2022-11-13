#include<stdio.h>

int main(){

    int n = 6;
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int encontrado = -1;

    //Iniciamos la busqueda
    for(int i=0; i<10; i++){
        if(arr[i]==n){
            encontrado = i;
            break;
        }
    }

    printf("La posicion es: %d", encontrado);

    return 0;
}