#include "dcl.h"

#include <stdio.h>

char buf[BUFSIZE];
int bp = 0;

int getch(void) {
	if(bp > 0) {
		return buf[--bp];
	} else {
		return getchar();
	}
}

void ungetch(int c) {
	if(bp + 1 < BUFSIZE && c) {
		buf[bp++] = c;
	} else {
		printf("error: buffer is full\n");
	}
}

void ungetstr(char *s) {
	if(*s) ungetstr(s+1);

	ungetch(*s);
}
