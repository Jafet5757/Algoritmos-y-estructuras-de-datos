/**
 *  Hay 8 filas y 8 columna
 *  Hay 15 diagonales
 * \diagonalIzquierdaExceptuada
 * /diagonalDerechaexceptuada
 * 
 */

#include <stdio.h>
#define n 8

int tablero[n][n];
int xTemp;
int yTemp;

//retorna 1 si esta vacia y 0 si no
int comprobarSiColumnaVacia(int fila){
    for(int i=0; i<n; i++){
        if(tablero[fila][i] == 0){
            xTemp = fila;
            yTemp = i;
            return 1;
        }
    }
    return 0;
}

//Comprueba si hay 1, si lo hay retorna 0 y si esta vacia retorna 1
int comprobarSiUnoAlRededor(int x, int y){
    int horizontalEsVacio = (tablero[x-1][y]==0 && tablero[x+1][y]==0);
    int verticalEsVacio = (tablero[x][y-1]==0 && tablero[x][y+1]==0);
    return (horizontalEsVacio && verticalEsVacio);
}

int inicializarTablero(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tablero[i][j] = 0;
        }
    }
}

//coloca un 2 a la reina y 1 a los espacios amenazados
int colocarReina(int x, int y){
    //unos en horizontal y vertical
    for(int i=0; i<n; i++){
        tablero[x][i] = 1;
        tablero[i][y] = 1;
    }
    //Colocamos reina
    tablero[x][y] = 2;

    //Unos en la diagonal izquierda
    for(int i=0; i<n; i++){
        /*if(i<x && tablero[x-i][y+i]!=2 && tablero[x-i][y+i]!=2){
            tablero[x-i][y+i] = (x-i>=0 && y+i<n) ? 1 : tablero[x-i][y+i];
            tablero[x-i][y-i] = (x-i>=0 && y-i>=0) ? 1 : tablero[x-i][y-i];
        }else*/ if(i>x && tablero[x+i][y-i]!=2 && tablero[x+i][y+i]!=2){
            tablero[x+i][y-i] = (x+i<n && y-i>=0)?1:tablero[x+i][y-i];
            tablero[x+i][y+i] = (x+i<n && y+i<n)?1:tablero[x+i][y+i];
        }
    }
    
}

void imprimeArreglo (int arr[][n], int length){
    for(int i=0; i<length; i++){
        for(int j=0; j<n; j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    
    int filaExceptuada[n], columnaExceptuada[n], diagonalIzquierdaExceptuada[(n*2)-1], diagonalDerechaexceptuada[(n*2)-1];
    int reinas = 0;
    int
    //Inicializamos el tablero en cero
    inicializarTablero();
    
    //Colocamos las reinas
    for(int i=0; i<n; i++){
        if(comprobarSiColumnaVacia(i)){
            reinas++;
            colocarReina(xTemp,yTemp);
        }
    }

    imprimeArreglo(tablero, n);
    printf("Reinas: %d", reinas);

    return 0;
}
