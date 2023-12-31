#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca <> NULL - udalo sie wczytac
 * Zwraca == NULL - podczas wczytywania wystapil blad
 */
Matrix * readFromFile(char * fname) {
				int r,c;
				int ir, ic;
				FILE * fin =  fopen(fname,"r");
				Matrix * mat = NULL;

				if (fin != NULL) {
					fscanf(fin,"%d %d",&r,&c); //Wczytanie wymiarow macierzy
					mat = createMatrix(r,c); //Utworzenie pustej macierzy r x c
					if (mat != NULL) {
						for (ir = 0; ir < r; ir++) 
							for (ic = 0; ic < c; ic++)
								if(fscanf(fin, "%lf",&(mat->data[ir][ic]))<1){
									printf("BLAD!: Wczytano element niebedacy liczba\n");
									exit(0);
								}									//Wypelnienie pustej macierzy danymi z pliku
					} else {
								fprintf(stderr,"Wystąpił problem podczas tworzenia macierzy o rozmiarach %d x %d dla danych z pliku: %s\n", r, c, fname);
					}

					fclose(fin);
				} else {
								fprintf(stderr,"Nie mogę otworzyć pliku o nazwie: %s\n", fname);
				}

				return mat; // Macierz stworzona i wypelniona
}

void printToScreen(Matrix *mat) { //Wypisanie macierzy na ekran
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
void printToFile(Matrix *mat, FILE* plik) { //Wypisanie macierzy na ekran
	int i,j;
	
	for (i = 0; i<mat->r; i++) {
		
		for (j = 0; j < mat->c; j++) {
			fprintf(plik,"%f", mat->data[i][j]);
		}
		if(i+1<mat->r){
			fprintf(plik," ");
		}
		
	}
	
}

Matrix * createMatrix(int r, int c) {
		int i;
		Matrix * mat = (Matrix*) malloc(sizeof(Matrix));
		if (mat != NULL) {
			mat->r = r;
			mat->c = c;
			mat->data = (double**) malloc(sizeof(double*) * r);
			for (i=0; i < r; i++) {
					mat->data[i] = (double*) malloc(sizeof(double) * c); // Dane w macierzy przechowywane sa tak ze
																		// Mamy tyle wskaznikow ile jest rzedow i kazdy z tych wskaznikow				
																		// ma przypisany wektor liczb tylu ile jest kolumn np. liczba z rzedu 2 kolumny 3 jest pod dane[2][3]
			}
		}

		return mat;
}

void freeMatrix(Matrix * mat) {//Zwolnienie pamieci
  int i;
	for (i=0;i < mat->r; i++)
		free(mat->data[i]);
	free(mat->data);
	free(mat);
}

