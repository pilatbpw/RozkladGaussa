#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

				for (int i = 0; i < b->r; i++) {
					if(mat->data[i][b->c - 1 - i] != 0) {
						x->data[i][0] = b->data[i][0] / mat->data[i][mat->c - 1 - i];
					} else {
						return 1;
					}
				} //przepisuje macierz b do macierzy x, dzieląc liczby przez diagonale w macierzy mat

				if( x->r == mat->r && mat->c == mat->r) {
					for(int i = 0; i < mat->r; i++) {
						double div = mat->data[i][mat->c - 1 - i];
						for(int j = 0; j < mat->c; j++) {
							mat->data[i][j] = mat->data[i][j] / div;
						}
					} // dzieli wszystkie rzędy w macierzy mat przez diagonale, znajdujące się na tych rzędach

					for (int i = x->r - 1; i > 0; i--)
					{
						for (int j = 0; j < i; j++)
						{
							x->data[i-1][0] -= x->data[j+1][0] * mat->data[j][j];
						}	
					} // koncowa faza podstawiania wstecznego	
				} else {
					return 2;
				}

				return 0;
}


