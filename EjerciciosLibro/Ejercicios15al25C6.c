#include <stdio.h>
#include <math.h>
//Ejercicio 6.15
/*
int main(){
	float r, a, v, pi = 3.141592;
	do
	{
		printf("Valor del radio > 0\n");
		fflush(stdin);
		scanf("%f",&r);
	}while( r <= 0);
	
	a = 4 * pi * r * r;
	v = 4.0/3 * pi * r * r * r;
	
	printf("El area y el volumen de la esfera de radio r =%f es: \n",r);
	printf("Area = %f\nVolumen = %f \n",a,v);
	return 0;
}*/

//Ejercicio 6.16
/*
#define M 10
#define f(x) sin(2 * x)- x
int main(){
	double x;
	for(x = 0.0; x <= M; x+= 0.5){
		printf("%f = %f\n",x, f(x));
	}
	return 0;
}*/

//Ejercicio 6.17
/*
int main(){
	int i, n;
	float M, m, media, num;
	do
	{
		puts("Valor de n > 0");
		fflush(stdin);
		scanf("%d",&n);
	} while( n <= 0);
	
	printf("Introduzca %d numeros: \n",n);
	fflush(stdin);
	scanf("%f",&num);
	M = num;
	m = num;
	media = num;
	for(i = 2; i<= n; i++){
		fflush(stdin);
		scanf("%f",&num);
		if(M < num){
			M = num;
		}
		if( m > num){
			m = num;	
		}
		media = media + num;
	}
	media = media / n;
	printf("media = %f\n", media);
	printf("menor = %f\n",m);
	printf("mayor = %f\n",M);
	return 0;
}
*/

//Ejerciio 6.18
/*
int main(){
	int i, n, resto, acu;
	do
	{
		puts("Valor de n > 0");
		fflush(stdin);
		scanf("%d",&n);
	}
	while( n <= 0);
	acu = 0; //acu contendra en todo momento la suma de todos los divisores
			//conocidos de n menores que i
	for(i=1; i<n; i++)
	{
		resto = n % i;
		if(resto == 0) acu += i;
	}
	if(n == acu){
		printf("El numero %d es perfecto\n",n);
	}
	else{
		printf("El numero %d no es perfecto\n",n);
	}
	return 0;
}*/

//Ejercicio 6.19
/*
int main(){
	int i;
	float x, t, e;
	printf("Valor de x: \n");
	fflush(stdin);
	scanf("%f",&x);
	e = 1;
	t = 1;	//Se ha inicializado el valor de e y el termino t
	
	puts("Distintos valores");
	for(i = 1; i <= 100; i++){
		t *= x / i; //Se recalculo el nuevo termino
		e += t;     //Se recalculo la nueva suma
		printf("i = %d, e = %f\n",i,e);
	}
	return 0;
}*/

//Ejercicio 6.20
/*
int main(){
	int n, i, f1, f2, aux, np;
	do
	{
		puts("Valor de n: ");
		fflush(stdin);
		scanf("%d",&n);
	} while( n < 0);
	f1 = 1;
	f2 = 1;
			//Se calculan los sucesivos terminos de la sucesion de fibonacci
	for(i = 2; i <= n; i++)
	{
		aux = f1 + f2;
		f1 = f2;
		f2 = aux;
	}
	printf("Valor de fibonacci para n = %d, es %d \n",n,f2);
	//Comienza la mejora
	puts("Numero de parejas necesarias: ");
	fflush(stdin);
	scanf("%d",&np); //Se supone que np es positivo
	f1 = 1;
	f2 = 1;
	i = 1;
	while(f2 < np)
	{
		aux = f1 + f2;
		f1 = f2;
		f2 = aux;
		i++;
	}
	printf("Numero de meses: %d\n",i);
	return 0;
}*/

//Ejercicio 6.21
/*
int main(){
	int primo, i, n;
	do
	{
		puts("Valor de n > 0");
		fflush(stdin);
		scanf("%d", &n);
	} while(n <= 0);
	primo = 1;
	//Inicialmente el numero es primo
	for(i = 2; (i*i<n)&primo; i++){//Mientras sea primo y queden posibles divisores menores
								   //o iguales que la raiz de n hacer
	primo = (n % i) != 0;
		
	}
	if(primo){
		printf("El numero %d es primo\n",n);
	}
	else {
		printf("El numero %d no es primo\n",n);
	}
	return 0;
}*/

//Ejercicio 6.22
/*
int main(){
	int i,n;
	float t, s;
	do
	{
		printf("Valor en  n \n");
		fflush(stdin);
		scanf("%d",&n);
	}while(n <= 0);
	s = 1;
	for(i = 1; i <= n; i++)
	{
		t = 1.0/i;
		s += t;
	}
	printf("Valor de la suma = %f\n",s);
	return 0;
}*/

//Ejercicio 6.23
/*
int main(){
	int i,n;
	float t, s;
	do
	{
		puts("Valor de n: ");
		fflush(stdin);
		scanf("%d",&n);
	}while(n <= 0);
	s = 1;
	for(i=1; i <= n; i++)
	{
		t = float(i) / pow(2,i);//Se obliga a que el cociente sea real
		s += t;
	}
	printf("Valor de la suma = %f\n",s);
	return 0;
}*/

//Ejercicio 6.24
/*
int main(){
	int n;
	float s, maximo;
	do
	{
		puts("Valor maximo n: ");
		fflush(stdin);
		scanf("%d",&maximo);
	}while(maximo <= 0);
	s = 0;
	for (n = 0; s<maximo; n++){
		s += n;
	}
	printf("Valor de la suma = %6.2f\n",s);
	printf("Valor del numero de terminos = %d\n",n);
	return 0;
}*/

//Ejercicio 6.25
/*int main(){
	int n1, i, fact;
	do
	{
		puts("Dame un numero entero: ");
		fflush(stdin);
		scanf("%d",&n1);
	}while(n1 <= 0);
	for(fact = 1, i = 1; i<= n1; i++){
		fact *= i;
	}
	printf("Con bucle for: %d\n", fact);
	fact = 1;
	i = 1;
	while(i < n1){
		i++;
		fact *= i;
	}
	printf("Con bucle while: %d\n",fact);
	
	fact = 1;
	i = 0;
	do
	{
		i++;
		fact *= i;
	}while(i < n1);
	printf("Con bucle do-while: %d\n",fact);
	return 0;
}*/

//Ejercicio 6.14
/*int main(){
	int n, m, mcm;

	do{
		printf("Valor de n>0 \n");
		scanf("%d", &n);
	} while (n <= 0);

	do
	{
		printf("valor de m > 0\n");
		scanf("%d", &m);
	} while (m <= 0);
	

	if(n<m){
		mcm = n;
	}else{
		mcm = n;
	}

	while((mcm % m != 0)||(mcm % n != 0))
		mcm++;
	printf(" el minimo comun multiplo es %3d\n", mcm);

	return 0;
}*/

//Ejercicio 6.12
/*int main(){
	int i, n, n1;
	do
	{
		printf("valor de n >0\n");
		scanf("%d", &n);
	} while (n <= 0);
	
	while(n <= 0);
	n1 = 0;

	while( n != 0){
		i = n % 10;
		n = n / 10;
		n1 = n1 * 10 + i;
	}

	printf(" número invertido %d", n1);  
	
	return 0;
}*/
