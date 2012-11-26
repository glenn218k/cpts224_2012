CC=gcc
TARGETS=ma libcma.so proreco_test clean_lite
OPTIONS=-g


all: $(TARGETS)

libcma.so: cma.o
	$(CC) $(OPTIONS) -shared cma.o -o libcma.so

cma.o: cma.c cma.h
	$(CC) $(OPTIONS) -fPIC -c cma.c -o cma.o

ma.o: ma.c cma.h
	$(CC) $(OPTIONS) -c ma.c -o ma.o

ma: ma.o libcma.so
	$(CC) ma.o -o ma -L. -lcma

proreco_test: proreco_test.o cma.o
	$(CC) proreco_test.o -o proreco_test -L. -lcma

proreco_test.o: proreco_test.c cma.h cma.c
	$(CC) $(OPTIONS) -c proreco_test.c -o proreco_test.o

clean:
	-rm *.o
	-rm proreco_test
	-rm libcma.so
	-rm ma
clean_lite:
	-rm *.o
