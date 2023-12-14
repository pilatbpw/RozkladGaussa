#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	
				for (int i=0; i < b->r; i++) {
					if(mat->data[i][i] != 0)
					{
						x->data[i][0] = b->data[i][0] / mat->data[i][i]; 
					}
					else
					{
						return 1;
					}
				}
				if( x->r == mat->r)
				{
					for (int i = x->r - 1; i>0; i--)
					{
						for (int j = x->r; j > 1; j--)
						{
							//x->data[i-1][0] -= (b->data[j][0] * mat->data[i-1][j]) / mat->data[i-1][i-1];
							x->data[i-1][0] -= x->data[j-1][0] * mat->data[i-1][j-1];
						}
					}
					return 0;
				}
				else
				{
					return 2;
				}
}
