#define MAXTOKEN 100
#define BUFSIZE 1000

enum { NAME, PARENS, BRACKETS, ARGS };

void dcl(void);
void dirdcl(void);

int getch(void);
void ungetch(int c);
void ungetstr(char *s);

extern char buf[/*BUFSIZE*/];
extern int bp; // last free buf position

int gettoken(void);

extern int tokentype;
extern char token[/*MAXTOKEN*/];
extern char name[/*MAXTOKEN*/];
extern char datatype[/*MAXTOKEN*/];
extern char desc[/*1000*/]; // description
