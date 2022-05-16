mymat : mymat.o mainmat.o io_utils.o
	gcc -g -ansi -Wall -pedantic mymat.o mainmat.o io_utils.o -o mymat
mymat.o : mymat.c io_utils.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o
mainmat.o : mainmat.c io_utils.h
	gcc -c -ansi -Wall -pedantic mainmat.c -o mainmat.o
io_utils.o : io_utils.c
	gcc -c -ansi -Wall -pedantic io_utils.c -o io_utils.o
