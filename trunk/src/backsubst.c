#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b, int * W) {
	
		for (int i=0; i < b->r; i++) {
			if(mat->data[W[i]][i] != 0)
			{
				printf("(x[%d][0])%f -= (b[%d][0])%f / (A[%d][%d])%f\n", W[i],x->data[W[i]][0],W[i], b->data[W[i]][0],W[i],i, mat->data[W[i]][i]);

				x->data[W[i]][0] = b->data[W[i]][0] / mat->data[W[i]][i]; 
			}
			else
			{
				return 1;
			}
			
		}
		//odtad sie cos pierdzieli
		if( x->r == mat->r)
		{
			for (int i = x->r - 1; i>0; i--)
			{
				for (int j = x->r; j > 1; j--)
				{ 	
					printf("(x[%d][0])%f -= (x[%d][0])%f * (A[%d][%d])%f\n", W[i-1],x->data[W[i-1]][0],W[j-1], x->data[W[j-1]][0],W[i-1],j-1, mat->data[W[i-1]][j-1]);

					//x->data[W[i-1]][0] -= (b->data[W[j]][0] * mat->data[W[i-1]][j]) / mat->data[W[i-1]][i-1];
					x->data[W[i-1]][0] -= x->data[W[j-1]][0] * mat->data[W[i-1]][j-1];
				//	x->data[i-1][0] -= x->data[j-1][0] * mat->data[i-1][j-1];

				}
			}
			return 0;
		}
		else
		{
			return 2;
		}
		
		
}
