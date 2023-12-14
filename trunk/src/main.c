#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;
	int * W=malloc(((A->c)+1)*sizeof(int));
	for(int i=0;i<(A->c)+1;i++){
		W[i]=i;
	}
	
	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);
	//macierz A rozmiaru r=3 rzedow c=3 kolumn numerowana jest:
	/*
	[ a00 a01 a02
	  a10 a11 a12
	  a20 a21 a22 ]
	
	*/
	// komorka [1][0] w macierzy A to:  A->data[1][0]

	res = eliminate(A,b,W);
	if(res){
		fprintf(stdout, "BLAD!: Macierz:\"%s\" jest osobliwa\n", argv[1]);
	}
	else{
		printf("Wynik\n");
		printToScreen(A);
		printToScreen(b);
		for(int i=0;i<(A->c)+1;i++){
			fprintf(stdout, "%d ", W[i]);
			
			
		}
	}
	
	x = createMatrix(b->r, 1);
	/*if (x != NULL) {
		//res = backsubst(x,A,b);

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}
*/
	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
