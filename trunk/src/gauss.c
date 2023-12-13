#include "gauss.h"

int eliminacja_wiersz(int k, Matrix *mat, Matrix *b){ 	//data[r][c]
	
		if(mat->data[k-1][k-1]<0.0000001){
			
			return 1;
		}
		for(int i=k;i<mat->r;i++){
			double cz=(mat->data[i][k-1])/mat->data[k-1][k-1]; //czynnik potrzebny do zerowania
			for(int j=k-1;j<mat->c;j++){
				mat->data[i][j]-=(mat->data[k-1][j])*cz;
			}
			b->data[i][0]-=(b->data[k-1][0])*cz;
								
			}
			
			
		
		
		
	return 0;
	
}



/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
		 
		 
		 for(int k=1; k<mat->r;k++){
			 if(eliminacja_wiersz(k, mat, b)){
				 return 1;
			 }
			 
		 }
		 

		return 0;
}

