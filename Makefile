
CC=gcc
TARGETS=ma libcma.so lansdon_test 
OPTIONS=-g -fPIC

all: $(TARGETS)

libcma.so: cma.o
	$(CC) $(OPTIONS) -shared cma.o -o libcma.so
cma.o: cma.c cma.h
	$(CC) $(OPTIONS) -c cma.c -o cma.o
ma: ma.o cma.o

lansdon_test: lansdon_test.o cma.o
	$(CC)  lansdon_test.o -o lansdon_test -L. -lcma
lansdon_test.o: lansdon_test.c cma.h cma.c
	$(CC) $(OPTIONS) -c lansdon_test.c -o lansdon_test.o

wbslage_test: wbslage_test.o
	gcc wbslage_test.o -o wbslage_test
wbslage_test.o: wbslage_test.c
	gcc -c wbslage_test.c

taytam_test: taytam_test.o
	$(CC) taytam_test.o -o taytam_test
taytam_test.o: taytam_test.c
	$(CC) $(OPTIONS) -c taytam_test.c -o taytam_test.o

clean:
	-rm *.o
	-rm $(TARGETS)
clean_lite:
	-rm *.o

