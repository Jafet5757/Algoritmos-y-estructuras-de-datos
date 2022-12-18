#include <stdio.h>
#include <stdlib.h>

// Constantes simb�licas

#define TRUE  1
#define FALSE 0


// Comprobar si una reina est� bien colocada
// -----------------------------------------
// La reina de la fila i est� bien colocada si no est�
// en la columna ni en la misma diagonal que cualquiera
// de las reinas de las filas anteriores
//
// Par�metros
//   fila   - Fila de la reina cuya posici�n queremos validar
//   reinas - Vector con las posiciones de las reinas
//   n      - N�mero de reinas


int comprobar (int fila, int reinas[], int n) 
{
  int i;

  for (i=0; i<fila; i++)
      if (  ( reinas[i]==reinas[fila] )                      // Misma columna
         || ( abs(fila-i) == abs(reinas[fila]-reinas[i]) ) ) // Misma diagonal
         return FALSE;

  return TRUE;
}


// Mostrar el tablero con las reinas
// ---------------------------------
// Par�metros:
//   reinas - Vector con las posiciones de las distintas reinas
//   n      - N�mero de reinas

void mostrarTablero (int reinas[], int n)
{
  int i,j;

  for (i=0; i<n; i++) {

      for (j=0; j<n; j++) {

          if (reinas[i]==j)
             printf("#");
          else
             printf("-");
      }

      printf(" %d %d\n",i,reinas[i]);
  }

  printf("\n");
}


// Colocaci�n de una reina
// -----------------------
// Par�metros
//   fila   - Fila de la reina que queremos colocar
//   reinas - Vector con las posiciones de las reinas
//   n      - N�mero de reinas

int colocarReina (int fila, int reinas[], int nreinas)
{
  int ok = FALSE;

  if (fila<nreinas) {

     // Quedan reinas por colocar

     for (reinas[fila]=0; reinas[fila]<nreinas; reinas[fila]++) {

         // Comprobamos si la posici�n 
         // de la reina actual es v�lida

         if (comprobar(fila,reinas,nreinas)) {

            // Si es as�, intentamos colocar
            // las reinas restantes

            colocarReina (fila+1, reinas, nreinas);
         }
     } 
  
  } else {

     // No quedan reinas por colocar (soluci�n)

     mostrarTablero(reinas,nreinas);
  }

  return ok;
}


// Programa principal
// ------------------

void main ()
{
  int *reinas;  // Vector con las posiciones de las reinas de cada fila
  int nreinas;  // N�mero de reinas
  int i;        // Contador


  // Leer n�mero de reinas 
  // (par�metro del programa)

  nreinas = 8;

  // Colocar las reinas en el tablero

      // Crear vector din�micamente

      reinas = (int*) malloc ( nreinas*sizeof(int) );

      // Inicializar vector:
      // (inicialmente, ninguna reina est� colocada)

      for (i=0; i<nreinas; i++)
          reinas[i] = -1;

      // Colocar reinas (algoritmo recursivo)

      colocarReina(0,reinas,nreinas);

      // Liberar memoria

      free (reinas);
   
}
