/**
 *  Hay 8 filas y 8 columna
 *  Hay 15 diagonales
 * \diagonalIzquierdaExceptuada
 * /diagonalDerechaexceptuada
 * 
 */

#include <stdio.h>
#define n 8

//Busca el valor "aBuscar" en el arreglo
int buscarEn(int aBuscar, int* arreglo, int size){
    for(int i=0; i<size; i++){
        if(aBuscar==arreglo[i])return 1;
    }
    return 0;
}

//retorna 1 si esta vacia y 0 si no
int comprobarSiColumnaVacia(int fila, int tablero[][n]){
    return (tablero[fila][0] == 0);
}

//Comprueba si hay 1, si lo hay retorna 0 y si esta vacia retorna 1
int comprobarSiUnoAlRededor(int x, int y, int tablero[][n]){
    int horizontalEsVacio = (tablero[x-1][y]==0 && tablero[x+1][y]==0);
    int verticalEsVacio = (tablero[x][y-1]==0 && tablero[x][y+1]==0);
    return (horizontalEsVacio && verticalEsVacio);
}

int inicializarTablero(int tablero[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tablero[i][j] = 0;
        }
    }
}

//coloca un 2 a la reina y 1 a los espacios amenazados
int colocarReina(int x, int y, int tablero[][n]){
    tablero[x][y] = 2;
    //unos en horizontal y vertical
    for(int i=0; i<n; i++){
        tablero[x][i] = 1;
        tablero[i][y] = 1;
    }
    //Unos en la diagonal izquierda
    for(int i=0; i<n; i++){
        if(i<x && tablero[x-1][y+1]!=2 && tablero[x-1][y+1]!=2){
            tablero[x-1][y+1] = 1;
            tablero[x-1][y-1] = 1;
        }else if(i>x && tablero[x+1][y-1]!=2 && tablero[x+1][y+1]!=2){
            tablero[x+1][y-1] = 1;
            tablero[x+1][y+1] = 1;
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
    int tablero[n][n];
    int filaExceptuada[n], columnaExceptuada[n], diagonalIzquierdaExceptuada[(n*2)-1], diagonalDerechaexceptuada[(n*2)-1];
    
    //Inicializamos el tablero en cero
    inicializarTablero(tablero);
    
    for(int i=0; i<n; i++){
        if(comprobarSiColumnaVacia(i, tablero)){
            //Buscamos en la columna un lugar donde no haya unos
            for(int j=0; j<n; j++){
                if(comprobarSiUnoAlRededor(i,j,tablero) && tablero[i][j]!=0){
                    //ponemos la reina en esta coordenada
                    colocarReina(i,j,tablero);
                }
            }
        }
    }

    imprimeArreglo(tablero, n);

    return 0;
}
