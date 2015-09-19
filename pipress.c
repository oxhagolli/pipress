/*
	SUPER HIGH COMPRESSION ALGORITHM
	Orens Xhagolli - Conor Jackson - Kenneth Reuter

	Compile with C99
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
	Taken from programming simplified examples.
*/
int cmpstr(char *first, char *second) {
	while (*first == *second) {
		if (*first == '\0' || *second == '\0')
			break;

		first++;
		second++;
	}

	if (*first == '\0' && *second == '\0')
		return 0;
	else
		return -1;
}

/*
	returns the nth digit of pi. 
*/
int pidig(int n) {
	return (int)'1';
}

/**
	This reads the file and breaks it down to chunks.
	chunksize = bytes
*/
int readfile(char* filename, bool hex, int chunksize) {
	FILE * fpointer;

	fpointer = fopen(filename, "r");

	if (fpointer == NULL) {
		printf("Something went wrong. Microsoft style.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Printing the contents of %s:\n", filename);
	
	char c;
	int count = 0;
	while ((c = fgetc(fpointer))!= EOF) {
		count++;
		if (hex) {
			//TODO: Here's the data.
			printf("%0x", (int)c);
		}
		else {
			printf("%c", c);
		}
		if (count > 3) {
			printf("\n%i\n", count);
			count = 0;
		}
	}
	fclose(fpointer);
}

int pipointer(char * str) {
	int n = 0; //Nth digit
	while ( 1 ) { //if not fully implemented might run forever
		bool hypothesis = true;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] != pidig(i + n)) {
				hypothesis = false;
				break;
			}
		}
		if (hypothesis) {
			break;
		}
		n++;
	}
	return n;
}

int main(void){
	printf("%i", pipointer("1"));
	return 0;
}
