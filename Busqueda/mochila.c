#include<stdio.h>
#define N 5
#define factorial 120
#define pesoMax 5
int permutations[factorial][N];//el tamaño es factorial de n y tamaño de orden

 void swap(int *a, int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
 }

int c = 0;
void heapPermutation(int a[], int size, int n){

    if (size == 1) {
        for(int i=0; i<n; i++){
            permutations[c][i]=a[i];
        }
        c++;
        return;
    }
 
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n);
 
        if (size % 2 == 1)
            swap(&a[0], &(a[size - 1]));

        else
            swap(&a[i], &(a[size - 1]));
    }
}

void imprimeArreglo(int arr[][N], int length, int n){
    printf("\n");
    for(int i=0; i<length; i++){
        for(int j=0; j<n; j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeArreglo2(int arr[][4], int length, int n){
    printf("\nPeso | valor  | i | j\n");
    for(int i=0; i<length; i++){
        for(int j=0; j<n; j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){

    int peso[] = {2,4,1,3,5};
    int valor[] = {1,1,2,3,5};
    int orden[] = {0,1,2,3,4};

    heapPermutation(orden, N, N);

    imprimeArreglo(permutations, factorial, N);

    //Segpun las mermutaciones buscamos cual es mejor
    //peso | valor | i | j
    int pesosValores[factorial][4];

    for(int i=0; i<factorial; i++){
        int pesoTemp = 0;
        int valorTemp = 0;
        int j=0;
        while(pesoTemp<pesoMax && j<N){
            pesoTemp += peso[permutations[i][j]];
            valorTemp += valor[permutations[i][j]];
            if(pesoTemp>pesoMax){
                pesoTemp -= peso[permutations[i][j]];
                valorTemp -= valor[permutations[i][j]];
                break;
            }
            j++;
        }
        pesosValores[i][0] = pesoTemp;
        pesosValores[i][1] = valorTemp;
        pesosValores[i][2] = i;
        pesosValores[i][3] = j;
    }

    imprimeArreglo2(pesosValores, factorial, 4);

    //Buscamos el menor de forma secuencial
    int valorMax = pesosValores[0][1];
    int pesoMochila = pesosValores[0][0];
    int xPermutation = pesosValores[0][2];
    int yPermutation = pesosValores[0][3];
    for(int i=0; i<factorial; i++){
        if(pesosValores[i][1]>valorMax){
            valorMax = pesosValores[i][1];
            pesoMochila = pesosValores[i][0];
            xPermutation = pesosValores[i][2];
            yPermutation = pesosValores[i][3];
        }
    }

    //Imprimimos el menor valor con los elementos de la mochila
    printf("\nPeso: %d\nValor: %d\nPeso por elemento | Valor por elemento ", pesoMochila, valorMax);
    int pesoTemp = 0;
    int j = 0;
    while(pesoTemp<pesoMax && j<N){
        pesoTemp += peso[permutations[0][j]];
        printf("\n %d | %d", peso[permutations[xPermutation][j]], valor[permutations[xPermutation][j]]);
        j++;
    }
    

    return 0;
}