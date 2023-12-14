#include "gauss.h"
#include <math.h>
void test(Matrix *mat) { //Wypisanie macierzy na ekran
	int i,j;
	printf("[ \n");
	for (i = 0; i<mat->r; i++) {
		printf("  ");
		for (j = 0; j < mat->c; j++) {
			printf("%f ", mat->data[i][j]);
		}
		printf("; \n");
	}
	printf("]\n");
}

int eliminacja_wiersz(int k, Matrix *mat, Matrix *b, int * W){ 	//data[r][c]   BEDE MUSIAL CHYBA POLACZYC TUTAJ A i b macierze do jednej macierzy
		
		printf("k=%d\n",k);
		
		test(mat);
		test(b);
		if(fabs(mat->data[k-1][W[k-1]])<0.0000001){
			test(mat);
			printf("k=%d\n", k);
			printf("mat->data[%d][%d]=0\n",k-1,W[k-1]);
			
			return 1;
		}
		for(int i=k;i<mat->r;i++){
			
			printf("Przed cz:\n");
			test(mat);
			printf("cz=(%f)A[%d][%d]/(%f)A[%d][%d]\n", mat->data[i][W[k-1]], i, W[k-1], mat->data[k-1][W[k-1]],k-1,W[k-1]);
			double cz=(mat->data[i][W[k-1]])/mat->data[k-1][W[k-1]]; //czynnik potrzebny do zerowania
			for(int j=k-1;j<mat->c;j++){
				mat->data[i][W[j]]-=(mat->data[k-1][W[j]])*cz;
				printf("A[%d][%d]-=(A[%d][%d]*%f)\n", i, W[j], k-1, W[j], cz);
			}
			b->data[i][0]-=(b->data[k-1][0])*cz;
			printf("b[%d][%d]-=(%f)b[%d][%d]*%f\n", i, 0,b->data[k-1][0], k-1, 0, cz);
								
			}
			
		
		test(mat);
		test(b);
		printf("-----\n");
		
		
	return 0;
	
}

void uporzadkowanie_macierzy(Matrix *mat, int *W){
	for(int j=0;j<mat->c;j++){
		if(W[j]!=j){
			printf("Wiersz: %d <-> %d\n", W[j], j);
		for(int i=0;i<mat->r;i++){
			
				
				double tmp=mat->data[i][W[j]];
				printf("%f <-> %f\n", tmp, mat->data[i][j]);
				mat->data[i][W[j]]=mat->data[i][j];
				mat->data[i][j]=tmp;
				
				
				
				
			}
			
			int p=W[j];
			W[j]=j;
			W[p]=p;
		}
		
		
	}
	
	
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
			 printf("Element diagonalny A[%d][%d]\n", k-1, W[k-1]);
			 int max=k-1;
			 for(int i=0;i<(mat->c);i++){
				 
				 printf("Porownuje A[%d][%d] i A[%d][%d]\n", k-1, W[k-1], k-1, W[i]);
			if(abs(mat->data[k-1][W[k-1]])<abs(mat->data[k-1][W[i]])){
				
				printf("%f<%f\n", fabs(mat->data[k-1][W[max]]),fabs(mat->data[k-1][W[i]]));
				max=i;
				 
				
				}
				else{
					printf("%f>=%f\n", fabs(mat->data[k-1][W[max]]),fabs(mat->data[k-1][W[i]]));
				}
				
				
			
			}
			printf("%d<->%d\n", W[k-1],W[max]);
			//W[k-1] <-> max
			int tmp=W[k-1];
			W[k-1]=W[max];
			W[max]=tmp;
			
			
			
			 if(eliminacja_wiersz(k, mat, b, W)){
				 return 1;
			 }
			 
		 }
		 
		 uporzadkowanie_macierzy(mat, W);
		 //printf("UPORZADKOWANA MACIERZ: \n");
		 //test(mat);

		return 0;
}

