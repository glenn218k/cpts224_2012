
ropin5_test: ropin5_test.o
	gcc ropin5_test.o -o ropin5_test
ropin5_test.o: 	ropin5_test.c
	gcc -c ropin5_test.c