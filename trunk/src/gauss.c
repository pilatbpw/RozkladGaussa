#include "gauss.h"

void zamiana_wierszy(int k, Matrix *mat, int * W){
	int max=k-1;
	for(int i=k-1;i<mat->r;i++){
		if(mat->data[max][k-1]<mat->data[i][k-1]){
			max=i;


		}

	}
	int tmp=W[k-1];
	W[k-1]=W[max];
	W[max]=tmp;

}


int eliminacja_wiersz(int k, Matrix *mat, Matrix *b, int * W){ 	//data[r][c]
		
		zamiana_wierszy(k, mat, W);
		if(abs(mat->data[W[k-1]][k-1])<0.0000001){
			
			return 1;
		}
		for(int i=k;i<mat->r;i++){
			double cz=(mat->data[W[i]][k-1])/mat->data[W[k-1]][k-1]; //czynnik potrzebny do zerowania
			for(int j=k-1;j<mat->c;j++){
				mat->data[W[i]][j]-=(mat->data[W[k-1]][j])*cz;
			}
			b->data[W[i]][0]-=(b->data[W[k-1]][0])*cz;
								
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
		 
		 
		 for(int k=1; k<mat->r;k++){
			 if(eliminacja_wiersz(k, mat, b,W)){
				 return 1;
			 }
			 
		 }
		 
		for(int i=0;i<mat->r;i++){
			printf("W[%d]=%d ",i, W[i]);
		}
		printf("\n");
		return 0;
}

