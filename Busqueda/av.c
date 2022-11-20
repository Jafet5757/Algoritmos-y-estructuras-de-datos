#include<stdio.h>
int orden[3] = { 1, 2, 3 };
int permutations [6][3]; //el tamaño es factorial de n y tamaño de orden

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

int main(){

    int vertices[4][4] = {{0,2,3,4},{5,0,6,7},{3,2,0,4},{1,2,1,0}};

    heapPermutation(orden, 3, 3);

    //imprimimos las permutaciones
    for(int i=0; i<6; i++){
        printf("\n");
        for(int j=0; j<3; j++){
            printf("%d ", permutations[i][j]);
        }
    }
    printf("\n================\n");
    //Ahora según la permutación solo sumamos
    int sumas[6];
    
    for(int i=0; i<6; i++){
        int suma = 0;
        printf("%d. ", i);
        for(int j=0; j<3; j++){
            //1=a 2=b 3=c 
            switch(permutations[i][j]){
                    case 1: 
                        suma += vertices[j][1];
                        break;
                    case 2:
                        suma += vertices[j][2];
                        break;
                    case 3:
                        suma += vertices[j][3];
                        break;
            }
            printf(" %d ", permutations[i][j]);
        }
        sumas[i] = suma;
        printf(" = %d \n", suma);
    }

    int menor = sumas[0];
    int indice = -1;
    for(int i=0; i<6; i++){
        if(sumas[i]<menor){
            menor = sumas[i];
            indice = i;
        }
    }
    printf("\nMejor ruta: %d. %d\n", indice, menor);

    return 0;
}