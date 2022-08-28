#include <stdio.h>
#include <string.h>
#include <math.h>

//Ejercicio 5.10
/*
int bisiesto(int a);
int ndd(int m, int a){
	switch(m){
		case 1,3,5,7,8,10,12:
			return (31);
		case 2:
			if(bisiesto(a)){
				return (29);
			}
			else{
				return(28);
			}
			default: return (30);
	}
}

int main(){
	int m,a;
	do
	{
		puts("Introduzca a�o entero: ");
		fflush(stdin);
		scanf("%d",&a);
	}while(a<0);
	do
	{
		puts("Introduzca el mes entero: ");
		fflush(stdin);
		scanf("%d",&m);
	}while((m<0)||(m>12));
	puts("El numero de dias");
	printf("del mes %d del a�o %d es: \n",m,a);
	printf(" %d ",ndd(m,a));
	return 0;
}
int bisiesto(int x){
	if(x % 400 == 0){
		return 1;
	}
	else if(x % 100 == 0){
		return 0;
	}
	else{
		return (x % 4 == 0);
	}
}*/
//Ejercicio 5.11
/*
int bisiesto(int x);

int main(){
	int mes, anio;
	puts("Introduzca el mes entre 1 y 12: ");
	fflush(stdin);
	scanf("%d",&mes);
	puts("Introduzca el a�o: ");
	fflush(stdin);
	scanf("%d",&anio);
	if (mes == 2){
		if(bisiesto(anio)){
			printf("Tiene 29 dias");
		}
		else{
			printf("Tiene 28 dias");
		}
	}
	else{
		if((mes==4)||(mes==6)||(mes==9)||(mes == 11)){
			printf("Tiene 30 dias\n");
			
		}
		else{
			printf("Tiene 31 dias\n");
		}
	}
	return 0;
}
int bisiesto(int x){
	if(x % 400 == 0){
		return 1;
	}
	else if(x % 100 == 0){
		return 0;
	}
	else{
		return (x % 4 == 0);
	}
}*/

//Ejercicio 5.12
/*
int main(){
	float a,b,c,d,x1,x2;
	puts("Introduzca los tres coeficientes: ");
	fflush(stdin);
	scanf("%f %f %f",&a,&b,&c);
	if(a != 0){
		d = b * b -4 * a * c;
		if(d<0){
			puts("Dos soluciones reales y distintas: ");
			x1 = (-b + sqrt(d))/(2 * a);
			x2 = (-b - sqrt(d))/(2 * a);
			printf("x1 = %6.2f  x2 = %6.2f\n",x1,x2);
		}
		else if(d == 0){
			puts("Dos soluciones reales e iguales: ");
			x1 = (-b)/(2 * a);
			printf("x = %6.2f\n",x1);
		}
		else{
			puts("No tiene solucion real");
			puts("Tiene dos soluciones complejas");
			x1 = (-b)/(2 *a);
			x2 = sqrt(-d) / (2 * a);
			puts("Primera solucion: ");
			printf("Parte real: %6.2f\n",x1);
			printf("Parte imaginaria: %6.2",x2);
			puts("Seguna solucion: ");
			printf("Parte real: %6.2f\n",x1);
			printf("Parte imaginaria: %6.2f",-x2);
		}
	}
	else if( b != 0){
		printf("Una solucion simple: %6.2f\n",-c/b);
	}
	else if(c == 0){
		puts("Se introdujo una identidad igual a 0 = 0");
	}
	else{
		puts("Sin solucion");
	}
	return 0;
}*/

//Ejercicio 5.13
/*
void main(){
	float x;
	puts("Introduzca un numero: ");
	fflush(stdin);
	scanf("%f",&x);
	if(x < 0){
		puts("Menor que cero");
	}
	else{
		puts("Mayor que cero");
	}
}*/

//Ejercicio 5.14
/*
void main(){
	float x, y, z;
	puts("Introduce 3 numeros cualesquiera: ");
	fflush(stdin);
	scanf("%f %f %f",&x,&y,&z);
	if( ( x <= y )&&( y <= z )){
		puts("Estan ordenados");
	}
	else {
		puts("No estan ordenados");
	}
}*/

//Ejercicio 5.15
/*
void main(){
	float nota;
	puts("Dame una nota: ");
	fflush(stdin);
	scanf("%f",&nota);
	if((nota < 0.0)||(nota > 10)){
		puts("Error de nota");
	}
	else if (nota < 5.0){
		puts("Suspenso");
	}
	else if(nota < 6.5){
		puts("Aprobado");
	}
	else if (nota < 8.5 ){
		puts("Notable");
	}
	else if (nota < 10){
		puts("Sobresaliente");
	}
	else{
		puts("Matricula de honor");
	}
}*/

//Ejercicio 5.16
/*
void main(){
	float x, Mayor;
	int i;
	puts("Dame un numero: ");
	fflush(stdin);
	scanf("%f",&Mayor);
	for(i=2; i<=5; i++){
		puts("Dame un numero: ");
		fflush(stdin);
		scanf("%f",&x);
		if(Mayor < x){
			Mayor = x;
		}
	}
	printf("El numero mayor es %f\n",Mayor);
}*/

//Ejercicio 5.17
/*
void main(){
	float Horas, Extras, Tasa, SalarioBruto, SalarioNeto;
	puts("Dame las horas: ");
	fflush(stdin);
	scanf("%f",&Horas);
	if(Horas <= 38){
		Extras = 0;
	}
	else{
		Horas = 38;
		Extras = Horas - 38;
	}
	puts("Introduzca la Tasa: ");
	fflush(stdin);
	scanf("%f",&Tasa);
	SalarioBruto = Horas * Tasa + Extras * Tasa * 1.5;
	if(SalarioBruto < 50000.0){
		SalarioNeto = SalarioBruto;
	}
	else {
		SalarioNeto = SalarioBruto * 0.9;
	}
	printf("El Salario Bruto es: %f\n", SalarioBruto);
	printf("El Salario Neto es : %f\n", SalarioNeto);
}*/

//Ejercicio 5.18
/*
void main(){
	int x = 2;
	puts("Arranque");
	if(x <= 3)
	if(x != 0){
		puts("Hola desde el segundo if");
	}
	else{
		puts("Hola desde else");
	}
	puts("Fin \n Arranque nuevo");
	if( x > 3)
	if( x != 0){
		puts("Hola desde el segundo if");
	}
	else{
		puts("Hola desde el else");
	}
	puts("De nuevo fin");
}*/

//Ejercicio 5.19
/*
void main(){
	int n;
	printf("Introduzca n: ");
	fflush(stdin);
	scanf("%d",&n);
	if( n < 0 ){
		puts("Este numero es negativo. Pruebe de nuevo.");
		fflush(stdin);
		scanf("%d",&n);
	}
	else{
		printf("Conforme. n = %d\n",n);
	}
}*/

//Ejercicio 5.20
/*
void main(){
	int x;
	puts("Introduzca un numero: ");
	fflush(stdin);
	scanf("%d",&x);
	if(x == 0){
		printf("%d = 0\n",x);
	}
	else{
		printf("%d != 0\n",x);
	}
}*/

//Ejercicio 5.9

/*int bisiesto(int x);

int main(){
	int x;
	puts("Introduzca el año entero");
	scanf(" %d", &x);
	if(bisiesto(x))
		printf("%d es bisiesto\n", x);
	else
		printf (" %d no es un año bisiesto \n", x);
	
	return 0;
}

int bisiesto(int x){
	if(x % 400 == 0)
		return 1;
	else if(x % 100 == 1)
		return 0;
	else 
		return (x % 4 == 0);
}*/


//Ejercicio 5.7

int main(){
	int x = 10;
	if(x<0)
		printf("%d es negativo\n",x);
	else if (x<= 100)
		printf("0 <= x = %d <= 100<\n",x);
	else
		printf("x = %d  > 100\n", x);
	
	return 0;

}