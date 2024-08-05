#include "dcl.h"

#include <string.h>
#include <ctype.h>

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char desc[1000];

int gettoken(void) {
	char *p = token, c;

	while((c = getch()) == ' ' || c == '\t')
		;

	if(c == '(') {
		if((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else if(isalpha(c) && name[0] != '\0') {
			for(*p++ = '(', *p++ = c; (*p++ = getch()) != ')'; )
				;

			*p = '\0';

			return tokentype = ARGS;
		} else {
			ungetch(c);

			return tokentype = '(';
		}
	} else if(c == '[') {
		for(*p++ = c; (*p++ = getch()) != ']'; )
			;

		*p = '\0';

		return tokentype = BRACKETS;
	} else if(isalpha(c)) {
		for(*p++ = c; isalnum(c = getch()); )
			*p++ = c;

		*p = '\0';

		ungetch(c);
		
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}
