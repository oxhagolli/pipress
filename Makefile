# Makefile for our C program

pipress: pipress.o pipress_util.o
	gcc -o pipress pipress.o pipress_util.o

pipress.o: pipress.c
	gcc -c pipress.c

pipress_util.o: pipress_util.c
	gcc -c pipress_util.c
