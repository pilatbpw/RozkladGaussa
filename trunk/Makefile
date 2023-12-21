all:
		gcc -Wall --pedantic src/*.c -o bin/gauss

przyklad: all
		bin/gauss dane/A dane/b

test_comp:
		@gcc -Wall --pedantic testy/test.c -o bin/test
		
test1: all test_comp
		bin/gauss dane/T1A dane/T1b
		@echo
		@echo Test 1 - poprawne dane 3x3:
		@echo
		@bin/test testy/test1
		@rm  bin/wynik
		
test2: all test_comp
		bin/gauss dane/T2A dane/T2b
		@echo
		@echo Test 2 - poprawne dane, zera na przekatnej:
		@echo
		@bin/test testy/test2
		@rm  bin/wynik
		
test3: all test_comp
		bin/gauss dane/T3A dane/T3b
		@echo
		@echo Test 3 - poprawne dane, macierz osobliwa:
		@echo
		@bin/test testy/test3
		@rm  bin/wynik
		
test4: all test_comp
		bin/gauss dane/T4A dane/T4b
		@echo
		@echo Test 4 - niepoprawne dane, zawierające litery, znak wykrzynika:
		@echo
		@bin/test testy/test4
		@rm  bin/wynik



