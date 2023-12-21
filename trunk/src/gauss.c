#include "gauss.h"
#include <math.h>


int eliminacja_wiersz(int k, Matrix *mat, Matrix *b, int * W){ 	//data[r][c]   BEDE MUSIAL CHYBA POLACZYC TUTAJ A i b macierze do jednej macierzy
		
		
		
		
		if(fabs(mat->data[k-1][W[k-1]])<0.0000001){
			
			printf("mat->data[%d][%d]=0\n",k-1,W[k-1]);
			
			return 1;
		}
		for(int i=k;i<mat->r;i++){
			
			
			double cz=(mat->data[i][W[k-1]])/mat->data[k-1][W[k-1]]; //czynnik potrzebny do zerowania
			for(int j=k-1;j<mat->c;j++){
				mat->data[i][W[j]]-=(mat->data[k-1][W[j]])*cz;
				
			}
			b->data[i][0]-=(b->data[k-1][0])*cz;
			
								
			}
			
		
		
		
		
	return 0;
	
}





/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b, int * W){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
		 
		 
		 for(int k=1; k<mat->r+1;k++){
			 
			 int max=k-1;
			 for(int i=0;i<(mat->c);i++){
				 
				
			if(abs(mat->data[k-1][W[k-1]])<abs(mat->data[k-1][W[i]])){
			
				max=i;
				 
				
				}
				
				
				
			
			}
			
			//W[k-1] <-> max
			int tmp=W[k-1];
			W[k-1]=W[max];
			W[max]=tmp;
			
			
			
			 if(eliminacja_wiersz(k, mat, b, W)){
				 return 1;
			 }
			 
		 }
		
		for (int i = 0; i < b->r; i++) {
			if(mat->data[i][b->c - 1 - i] != 0) {
				b->data[i][0] = b->data[i][0] / mat->data[i][mat->c - 1 - i];
			} else {
				return 1;
			}
		}
		if( b->r == mat->r && mat->c == mat->r) {
			for(int i = 0; i < mat->r; i++) {
				double div = mat->data[i][mat->c - 1 - i];
				for(int j = 0; j < mat->c; j++) {
					mat->data[i][j] = mat->data[i][j] / div;
				}
			}
		}
		
		for (int i = b->r - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				b->data[i-1][0] -= b->data[j+1][0] * mat->data[j][j];
				mat->data[j][j] = 0;
			}	
		}
		 
		 

		return 0;
}

