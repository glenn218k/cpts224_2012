CC=gcc
TARGETS=libcma.so ma proreco_test usakgb_test lansdon_test clean_lite
OPTIONS=-g -fPIC

all: $(TARGETS)

libcma.so: cma.o
	$(CC) $(OPTIONS) -shared cma.o -o libcma.so

cma.o: cma.c cma.h
	$(CC) $(OPTIONS) -c cma.c -o cma.o

ma.o: ma.c cma.h
	$(CC) $(OPTIONS) -c ma.c -o ma.o

ma: ma.o libcma.so
	$(CC) ma.o -o ma -L. -lcma

proreco_test: proreco_test.o cma.o
	$(CC) proreco_test.o -o proreco_test -L. -lcma

proreco_test.o: proreco_test.c cma.h cma.c
	$(CC) $(OPTIONS) -c proreco_test.c -o proreco_test.o

usakgb_test: usakgb_test.o cma.o
	$(CC) usakgb_test.o cma.o -o usakgb_test

usakgb_test.o: usakgb_test.c
	$(CC) -c usakgb_test.c

lansdon_test: lansdon_test.o cma.o
	$(CC)  lansdon_test.o -o lansdon_test -L. -lcma
lansdon_test.o: lansdon_test.c cma.h cma.c
	$(CC) $(OPTIONS) -c lansdon_test.c -o lansdon_test.o

wbslage_test: wbslage_test.o
	gcc  -g wbslage_test.o -o wbslage_test

wbslage_test.o: wbslage_test.c
	gcc -g -c wbslage_test.c

ropin5_test: ropin5_test.o
	$(CC) ropin5_test.o -o ropin5_test

ropin5_test.o: ropin5_test.c
	$(CC) -c ropin5_test.c

clean:
	-rm *.o
	-rm $(TARGETS)
clean_lite:
	-rm *.o
