ma: ma.o cma.o

wbslage_test: wbslage_test.o
	gcc wbslage_test.o -o wbslage_test
wbslage_test.o: wbslage_test.c
	gcc -c wbslage_test.c

