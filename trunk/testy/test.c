#include <stdio.h>

int main(int argc, char * argv[]){
	if(argc<2){
		fprintf(stdout, "Nie podano pliku testowego\n");
	}
	else{
		FILE *plik_test, *plik_wynik;
		char znak1, znak2;

    
		plik_test = fopen(argv[1], "r");
		if (plik_test == NULL) {
			fprintf(stdout, "Nie udalo sie otworzyc pliku %s\n", argv[1]);
			return 0;
		}

    
		plik_wynik = fopen("bin/wynik", "r");
			if (plik_wynik == NULL) {
				
				return 0;
			}

    
    do {
        znak1 = getc(plik_test);
        znak2 = getc(plik_wynik);

        if (znak1 != znak2) {
            
            fclose(plik_test);
            fclose(plik_wynik);
            fprintf(stdout, "Niepoprawny wynik\n");
			return 0;
			
        }
		else{
			
		}
		
			
    } while (znak1 != EOF && znak2 != EOF);

    fclose(plik_test);
    fclose(plik_wynik);
	fprintf(stdout, "Poprawny wynik\n");
    return 0;

	}

}
