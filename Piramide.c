#include <stdio.h>

int main(){

    int n = 0;
    int level = 0;

    printf("Ingrese el tamano de la piramide: ");
    fflush(stdin);
    scanf("%i",&n);

    for(int i=n; i>0; i--){
        for(int j=0; j<level; j++){
            printf(" ");
        }
        for(int j=0;j<(n-(level*2));j++){
            printf("*");
        }
        for(int j=0; j<level; j++){
            printf(" ");
        }
        printf("\n");
        level++;
    }

    return 0;
}