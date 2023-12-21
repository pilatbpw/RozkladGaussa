all:
		gcc -Wall --pedantic src/*.c -o bin/gauss

przyklad: all
		bin/gauss dane/A dane/b

test_comp:
		@gcc -Wall --pedantic testy/test.c -o bin/test
		
test1: all test_comp
		bin/gauss dane/T1A dane/T1b
		@echo
		@echo Poprawne dane. Macierz 3x3:
		@echo
		@bin/test testy/test1
		@rm  bin/wynik
		
test2: all test_comp
		bin/gauss dane/T2A dane/T2b
		@echo
		@echo Poprawne dane. Test czy stosuje wybor diagonali. Macierz 4x4:
		@echo
		@bin/test testy/test2
		@rm  bin/wynik
		
test3: all test_comp
		bin/gauss dane/T3A dane/T3b
		@echo
		@echo Poprawne dane. Blad: Macierz jest osobliwa:
		@echo
		@bin/test testy/test3
		@rm  bin/wynik
		
test4: all test_comp
		bin/gauss dane/T4A dane/T4b
		@echo
		@echo Niepoprawne dane. Dane zawierajace litery:
		@echo
		@bin/test testy/test4
		@rm  bin/wynik



