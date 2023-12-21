#include "backsubst.h"
#include <stdio.h>
#include <math.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */


int  backsubst(Matrix *x, Matrix *mat, Matrix *b, int * W) {
		
		for (int i=0; i < b->r; i++) {
			if(fabs(mat->data[W[i]][i]) < 0.000001)
			{
				
				
				return 1;
				
			}
			
		}
		

		x->data[W[(x->r)-1]][0] = b->data[W[(b->r)-1]][0] / mat->data[W[(mat->r)-1]][(mat->c)-1]; 
		
		
		
		double suma;
		if( x->r == mat->r)
		{
			for (int i = x->r - 2; i>=0; i--)
			{
				
				suma=b->data[W[i]][0];
				
				for (int j = x->r-1; j > i; j--)
				{ 	
					
					suma-=x->data[W[j]][0] * mat->data[W[i]][j];
					

				}
				x->data[W[i]][0] = (double)(suma/mat->data[W[i]][i]);
				
			}
			int z = x->r;
			if (z % 2 == 0)
			{
				for(int i = 0; i < z/2; i++)
				{
					double tmp = x->data[i][0];
					x->data[i][0] = x->data[z-i-1][0];
					x->data[z-i-1][0] = tmp;
				}
			}else {
				for(int i = 0; i < (z-1)/2; i++)
				{
					double tmp = x->data[i][0];
					x->data[i][0] = x->data[z-i-1][0];
					x->data[z-i-1][0] = tmp;
				}
			}
			return 0;
		}
		else
		{
			return 2;
		}
		
		
}
