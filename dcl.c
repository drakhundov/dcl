#include "dcl.h"

#include <string.h>
#include <stdio.h>

void dcl(void) {
	int ns;

	for(ns = 0; gettoken() == '*'; )
		++ns;

	dirdcl();

	while(ns-- > 0) {
		strcat(desc, " pointer to");
	}
}

void dirdcl(void) {
	int type;

	if(tokentype == '(') {
		dcl();

		if(tokentype != ')') {
			printf("error: missing ')'\n");
		}
	} else if(tokentype == NAME) {
		strcpy(name, token);
	} else {
		printf("error: expected name or (dcl)\n");
	}

	while((type=gettoken()) == PARENS || type == BRACKETS || type == ARGS) {
		if(type == PARENS) {
			strcat(desc, " function returning");
		} else if(tokentype == ARGS) {
			strcat(desc, " function with args ");
			strcat(desc, token);
			strcat(desc, " returning");
		} else {
			strcat(desc, " array");
			strcat(desc, token);
			strcat(desc, " of");
		}
	}
}
