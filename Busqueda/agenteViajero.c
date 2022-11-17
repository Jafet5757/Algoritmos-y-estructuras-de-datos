#include<stdio.h>

int menor;

int * extraerArregloDeOtro(int *arr, int inicio, int fin, int * nuevoArreglo){
    int c=0;
    for(int i=inicio; i<=fin; i++){
        nuevoArreglo[c] = arr[i];
    }
    return nuevoArreglo;
}

//Dado que la matriz es reflexiva es lo mismo fila y columna
int obtenerMenor(int *fila, int n, int * columnaExcluida){
    menor = fila[0];
    int pos = 0;

    //primero aignamos cualquier valor a menor y pos que no haya sido excluido
    for(int i=0; i<n; i++){
        if(!columnaExcluida[i] && fila[i]!=0){
            menor = fila[i];
            pos = i;
        }
    }


    for(int i=0; i<n; i++){
        if(fila[i]<=menor && !columnaExcluida[i] && fila[i]!=0){
            menor = fila[i];
            pos = i;
        }
    }
    
    return pos;
}

int main(){

    int vertice[16] = {0,3,4,1,3,0,2,8,4,2,0,5,1,8,5,0};// matriz 4x4
    int filaExcluida[4] = {0,0,0,0};// se pone un uno según corresponda a,b,c,d...
    int n = 4;
    int resultado = 0;

    //Iniciando en (0,0) buscamos el caminos más corto que concete con la fila 0
    for(int i=0; i<n*n; i+=n){
        //buscamos la coordenanda del más corto
        int nuevoArreglo[i-i+n-1];//inicio-fin
        int *fila = extraerArregloDeOtro(vertice, i, i+n-1, nuevoArreglo);
        int posicion = obtenerMenor(fila, n, filaExcluida);
        filaExcluida[posicion] = 1;
        resultado += menor;
    }

    printf("La suma menor es: %d", resultado);

    return 0;
}