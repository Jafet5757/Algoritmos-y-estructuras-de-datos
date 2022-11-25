#include <stdio.h>
#define n = 4;

int factorial(int number){
    return number*(number!=1?factorial(number-1):1);
}

int main(){


    int vertices[4*4] = {0,3,4,13,0,2,8,4,2,0,5,0};


    return 0;
}