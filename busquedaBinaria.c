#include <stdio.h>

int main()
{
         // Requisito: Encuentra la ubicación del elemento 7
    int key = 20;
    int num[10] = {1,3,5,7,9,10,13,20,30,34};
    int min = 0;
    int max = sizeof(num) / sizeof(num[0]) - 1;
    int mid = min + (max - min) / 2;
    while(max >= min){
        if(num[mid] > key){
            max = mid - 1;
        }else if(num[mid] < key){
            min = mid + 1;
        }else{
                         printf ("En la posición del índice% i", mid);
            break;
        }
        mid = (min + max)/2;
    }
    return 0;
}
