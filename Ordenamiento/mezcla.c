/**
 * @file mezcla.c
 * @author Kevin Jafet Moran Orozco
 * @brief Divide el arreglo en dos hasta que solo tenga un elemento, luego los mezcla de modo que siempre quede el más pequeño a la izquierda
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

void merge (int arr[], int beg, int mid, int end)
{
  int output[end - beg + 1];
  int i = beg, j = mid + 1, k = 0;
  // mezclamos los arreglos
  while (i <= mid && j <= end)
    {
      if (arr[i] <= arr[j])
	{
	  output[k] = arr[i];
	  k += 1;
	  i += 1;
	}
      else
	{
	  output[k] = arr[j];
	  k += 1;
	  j += 1;
	}
    }
  // rellenamos los sobrante de la izquierda
  while (i <= mid)
    {
      output[k] = arr[i];
      k += 1;
      i += 1;
    }
  // rellenamos los sobrante de la derecha
  while (j <= end)
    {
      output[k] = arr[j];
      k += 1;
      j += 1;
    }
  // movemos al arreglo original
  for (i = beg; i <= end; i += 1)
    {
      arr[i] = output[i - beg];
    }
}

void mergeSort (int arr[], int beg, int end)
{

  if (beg < end)
    {
      int mid = (beg + end) / 2;
      //dividimos a la mitad el arreglo
      mergeSort (arr, beg, mid);	// dividimos el arreglo izquierdo
      mergeSort (arr, mid + 1, end);	// dividimos el arreglo derecho
      merge (arr, beg, mid, end);	// mezclamos
    }
}

void imprimeArreglo (int *arr, int length)
{
  printf ("\n");
  for (int i = 0; i < length; i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");
}

int
main ()
{

  int a[10] = { 1, 5, 3, 8, 9, 7, 6, 8, 1, 2};

  mergeSort (a, 0, 10 - 1);

  imprimeArreglo (a, 10);

  return 0;
}
