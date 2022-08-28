#include<stdio.h>
#include<math.h>
//Ejercicio 4.9
/*int main(){
	float a, b, c, d, e, f, denominador, x, y;
	puts("Introduce el valor de a de b y de c: ");
	fflush(stdin);
	scanf("%f %f %f",&a,&b,&c);
	puts("Introduce el valor de d de e y de f: ");
	fflush(stdin);
	scanf("%f %f %f",&d,&e,&f);
	denominador = a*e-b*d;
	if(denominador==0){
		printf("No solucion");
	}
	else {
		x = (c * e - b * f)/denominador;
		y = (a * f - c * d)/denominador;
		printf("La solucion es: \n");
		printf("X = %f, Y = %f",x,y);
	}
	return 0;
}*/

//Ejercicio 4.10
/*const float pi = 3.141592;
int main(){
	float base, altura, area, volumen;
	puts("Ejercicio para caluclar el area y el volumen de un cilindro");
	puts("Introduce el valor de la base y la altura: ");
	fflush(stdin);
	scanf("%f %f",&base,&altura);
	if(base <= 0 || (altura <= 0)){
		printf("No solucion");
	}
	else{
		area = 2* pi * base * base + 2 * pi * base * altura;
		volumen = pi * base * base * altura;
		printf("\n La solucion es: \n");
		printf("Area total = %f \n",area);
		printf("Volumen total = %f \n",volumen);
	}
	return 0;
}*/

//Ejercicio 4.11
/*
int main(){
	float a,b,c,p,area;
	puts("Intoduce el valor de los 3 lados del triangulo: ");
	fflush(stdin);
	scanf("%f %f %f",&a,&b,&c);
	if((a<=0)||(b<=0)||(c<=0)||((a+b)<c)||((a+c)<b)||((b+c)<a)){
		printf("No solucion");
	}
	else{
		p = (a+b+c)/2;
		area = pow(p * (p-a)*(p-b)*(p-c),0.5);
		printf("La solucion es: \n");
		printf("Area = %f \n",area);
	}
	return 0;
} */

//Ejercicio 4.12
/*
int main(){
	const float pi = 3.141592;
	float cateto1,cateto2,hipotenusa,angulo;
	puts("Intoduce el valor de los catetos: ");
	fflush(stdin);
	scanf("%f %f",&cateto1,&cateto2);
	if((cateto1 <= 0)||(cateto2 <= 0)){
		printf("No solucion");
	}
	else{
		hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
		angulo = 180/pi * asin(cateto1/hipotenusa);
		printf("La solucion es: \n");
		printf("Hipotenusa = %f\n",hipotenusa);
		printf("Angulo = %f\n",angulo);
		printf("Otro angulo = %f\n",90-angulo);
	}
	return 0;
}*/

//Ejercicio 4.13
/*
int main(){
	const float G = 6.67e-8;
	float masa1, masa2, distancia, fuerza;
	puts("Dame la masa de dos cuerpos en gramos:\n ");
	fflush(stdin);
	scanf("%f %f",&masa1,&masa2);
	puts("Dame la distancia entre ellos en centimetros:\n ");
	fflush(stdin);
	scanf("%f",&distancia);
	if((masa1 <= 0)||(masa2 <=0)||(distancia <= 0)){
		printf("No hay solucion");
	}
	else{
		fuerza = G * masa1 - masa2 /(distancia * distancia);
		printf("La solucion es: \n");
		printf("Fuerza en dinas = %f \n",fuerza);
	}
	return 0;
}*/

//Ejercicio 4.14
/*
int main(){
	int a, b, producto, cociente, resto;
	puts("Introduzca dos numeros: \n");
	fflush(stdin);
	scanf("%d %d",&a,&b);
	producto = a * b;
	cociente = a/b;
	resto = a % b;
	printf("Producto = %d\n",producto);
	printf("Cociente = %d\n",cociente);
	printf("Resto = %d\n",resto);
	return 0;
}*/

//Ejercicio 4.15
/*
int main(){
	int x,y,Mayor;
	puts("Intoduzca dos numeros enteros: \n");
	fflush(stdin);
	scanf("%d %d",&x,&y);
	Mayor = x;
	if(x < y){
		Mayor = y;
	}
	printf("\nEl mayor es: %d",Mayor);
	return 0;
}*/

//Ejercicio 4.16
/*
int main(){
	int hectometros, decametros, metros, decimetros;
	printf("Introduzca hectometros, decametros y metros:");
	fflush(stdin);
	scanf("%d %d %d",&hectometros, &decametros, &metros);
	decimetros = ((hectometros * 10 + decametros)*10 + metros)*10;
	printf("Numero de decimetros es %d \n", decimetros);
	return 0;
} */

//Ejercicio 4.17
/*
int main(){
	int semanas, dias, horas, minutos, segundos, acu;
	printf("Introduzca segunos: ");
	fflush(stdin);
	scanf("%d",&acu);
	segundos = acu % 60;
	acu = acu /60;
	minutos = acu %60;
	acu = acu/60;
	horas = acu % 24;
	acu = acu / 24;
	dias = acu % 7;
	semanas = acu/7;
	printf("Numero de segundos %d\n", segundos);
	printf("Numero de minutos %d\n", minutos);
	printf("Numero de horas %d\n", horas);
	printf("Numero de dias %d\n", dias);
	printf("Numero de semanas %d\n",semanas);
	return 0;
}*/

//Ejercicio 4.18
/*
int main(){
	float m, energia;
	const float c = 2.997925e+10;
	puts("Introduzca la masa: ");
	fflush(stdin);
	scanf("%f",&m);
	energia = c * m * m * m;
	printf("\nEnergia en ergios: %f",energia);
	return 0;
}*/

//Ejercicio 4.19
/*
int main(){
	float pies, pulgadas, yardas, metros, centimetros;
	puts("Introduzca la unidad de medida en pies: ");
	fflush(stdin);
	scanf("%f",&pies);
	pulgadas = pies * 12;
	yardas = pies / 3;
	centimetros = pulgadas * 2.54;
	metros = centimetros / 100;
	printf("Pies: %f\n",pies);
	printf("Pulgadas: %f\n", pulgadas);
	printf("Yardas: %f\n",yardas);
	printf("Centimetros: %f\n",centimetros);
	printf("Metros: %f\n",metros);
	return 0;
}*/

//Ejercicio 4.20

/*int main(){
	int n1,n2,n3,n4;
	float media;
	puts("Introduzca 4 numeros enteros: ");
	fflush(stdin);
	scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
	media = (n1 + n2 + n3 + n4) / 4.0;
	printf("La media es: %f",media);
	return 0;
}*/

//Ejercicio 4.8
/*const int M = 6;

int main(){
	int a,b,c;
	puts("Introduce el valor de a y de b");
	scanf("%d%d",&a,&b); //Recibe 2 valores separados por enter
	c = 2 * a-b;
	c -= M;
	b = a+c -M;
	a = b * M;
	printf("\n a = %d\n",a);
	b =- 1;
	printf("b=%6d c=%6d",b,c); //in the .precision format for integer specifiers (d, i, o, u, x, X), precision specifies the minimum number of digits to be written.

	return 0;
}*/

//Ejercicio 4.7
int main(){
	float x,y;
	printf("Dame la longitud de la habitación\n");
	scanf("%f",&x);
	printf("Dame el ancho de la habitación\n");
	scanf("%f",&y);
	printf("Su superficie es %10.4f", x*y);

	return 0;
}