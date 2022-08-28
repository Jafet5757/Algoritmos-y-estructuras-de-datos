#include <stdio.h>
#include <math.h>
#include <string.h>

//Ejercicio 7.1
/*
float factorial(int x);
void main(void){
	float x,y,i;
	puts("Dame dos numeros: ");
	fflush(stdin);
	scanf("%f %f",&x,&y);
	for(i = x; i <= y; i++){
		printf("%8.0f %s %8.0f",i,"factorial",factorial(i));
	}
}
float factorial (int x){
	float i,f;
	f = 1.0;
	for(i = 1; i<= x; i++){
		f = f * i;
	}
	return (f);
}*/

//Ejercicio 7.2
/*
void inter1(int *a, int *b);
void main(void){
	int x,y;
	puts("Dame dos enteros: ");
	fflush(stdin);
	scanf("%d %d",&x,&y);
	printf("Forma normal x = %d y = %d\n",x,y);
	inter1(&x,&y);
	printf("Cambiados x = %d  y = %d\n",x,y);
}
void inter1(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}*/

//Ejercicio 7.3
/*
const float Pi = 4.141592;
#define VOLCILINDRO(radio,altura) ((Pi*(radio*radio)*altura))
#define AREATOTAL(radio,altura) (2*Pi*radio*altura+Pi*radio*radio)

int main(){
	float radio, altura, volumen, Areatotal;
	do
	{
		puts("Introduzca radio del cono: ");
		fflush(stdin);
		scanf("%f",&radio);
		puts("Introduzca la altura del cono: ");
		fflush(stdin);
		scanf("%f",&altura);
	}while((radio <= 0)||(altura <= 0));
	volumen = VOLCILINDRO(radio,altura);
	Areatotal = AREATOTAL(radio,altura);
	printf("El volumen del cilindro es: %f\n",volumen);
	printf("El area total del cilindro es: %f\n",Areatotal);
	return 0;
}*/

//Ejercicio 7.4
/*
int mayor();
void main(void){
	printf("El mayor es: %d",mayor());
}

int mayor(){
	int i,m;
	puts("Dame un numero: ");
	fflush(stdin);
	scanf("%d",&m);
	puts("Dame otro numero: ");
	fflush(stdin);
	scanf("%d",&i);
	if( i > m){
		m = i;
	}
	puts("Dame un numero: ");
	fflush(stdin);
	scanf("%d",&i);
	if(i > m){
		m = i;
	}
	return (m);
}*/

//Ejercicio 7.5
/*
long int funcionx();
int main(){
	int n, i;
	puts("Cuanto numeros de la funcion?: ");
	fflush(stdin);
	scanf("%d",&n);
	puts("Secuencia de funcionx: 0,1,2");
	for(i = 3; i <= n; i++ ){
		printf(",%d",funcionx());
	}
	return 0;
}
long int funcionx(){
	static int x = 0;
	static int y = 1;
	static int z = 2;
	int aux;
	aux = x + 2 * y + z;
	x = y;
	y = z;
	z = aux;
	return z;
}*/

//Ejercicio 7.6
/*
int cociente(int n, int m);
void main(void){
	int n,m;
	do
	{
		puts("Dame dos numeros: ");
		fflush(stdin);
		scanf("%d %d",&n,&m);
	}while((n <= 0)||(m <= 0));
	
	printf("El cociente es: %d\n",cociente(n,m));
}

int cociente(int n, int m){
	int c, Mayor, menor, acu;
	if(n < m){
		Mayor = m;
		menor = n;
	}
	else{
		Mayor = n;
		menor = m;
	}
	acu = menor;
	c = 0;
	while(acu <= Mayor){
		acu += menor;
		c++;
	}
	return (c);
}*/

//Ejercicio 7.7
/*
int resto(int n, int m);

void main(void){
	int n,m;
	do {
		puts("Dame dos numeros: ");
		fflush(stdin);
		scanf("%d %d",&n,&m);
	}while((n <= 0)||(m <= 0));
	printf("El cociente es: %d",resto(n,m));
}

int resto(int n, int m){
	int Mayor, menor, acu;
	if(n < m){
		Mayor = m;
		menor = n;
	}
	else{
		Mayor = n;
		menor = m;
	}
	acu = menor;
	while(acu <= Mayor){
		acu += menor;
	}
	return (Mayor - acu - menor);
}*/

//Ejercicio 7.8
/*long int funcionx(int n);

int main(){
	int n,i;
	printf("Cuantos numeros de la funcionx ?: ");
	scanf("%d",&n);
	printf("\nSecuancia de funcionx: 0,1,2");
	for(i=3; i<=n; i++){
		printf(",%d",funcionx(i));
	}
}

long int funcionx(int n){
	long int x = 0 ,y = 1,z = 2, i, aux;
	if(n <= 2)
		return n;
	else{
		for(i = 3; i<=n; i++){
			aux = x + 2 *y +z;
			x = y;
			y = z;
			z = aux;
		}
		return z;
	}
}*/
