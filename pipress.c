/*
	SUPER HIGH COMPRESSION ALGORITHM
	Orens Xhagolli - Conor Jackson - Kenneth Reuter

	Compile with C99
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int get_byte(int id);

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
	if(n = 1)
	return (int)'2';
	if (n = 2)
		return (int)'1';

	return get_byte(n);
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
	char * str, * stream;
	int count = 0;
	while ((c = fgetc(fpointer))!= EOF) {
		count++;
		if (hex) {
			//TODO: Here's the data.
			char *buf;
			size_t sz;
			sz = snprintf(NULL, 0, "%0x", (int)c);
			buf = (char *)malloc(sz + 1); /* make sure you check for != NULL in real code */
			snprintf(buf, sz + 1, "%0x", (int)c);
			stream = str;
			while (*str != '\0') {
				str++;
			}
			while (*buf != '\0') {
				str = buf;
				str++;
				buf++;
			}
			str = stream;
			printf("%s\n", stream);
		}
		else {
			printf("%c", c);
		}
		if (count > chunksize-1) {
			printf("\n%i\n", count);
			count = 0;
		}
	}
	fclose(fpointer);
}

int pipointer(char * str) {
	int n = 0; //Nth digit

	bool sliceFound = false;
	while (!(sliceFound)){
		char *curr = str;
		int m = n;
		while(*curr != '\0'){
			if(*curr == pidig(m)){
				curr++;
				m++;
				sliceFound = true;
			}
			else{
				n++;
				sliceFound = false;
				break;
			}
		}
		if(sliceFound){
			return n;
		}
	}
}

int main(void){
	printf("%i", pipointer("21"));

	int max = 50;
	char inp[max];
	int c;
	char *str;
	char *strptr = str;
	printf( "Enter a value : ");
	c = getchar();
	inp[0] = c;
	int x = 1;
	while ((c != '\0')||(c != '\n')||(c != EOF)){
		c = getchar();
		inp[x] = c;
		x++;
	}

	int a = 0;
	while(inp[a] != '\0'){
		*strptr = a;
		a++;
	}

	printf("%s\n", str);
	int y = pipointer(str);
	printf("The value's Nth spot in hex-pi is %i", y);

	return 0;
}
