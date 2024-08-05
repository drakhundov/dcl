#include "dcl.h"

#include <stdio.h>
#include <string.h>

/* convert declarations to words */

int main(int argc, char *argv[])
{
	int type, un = 0;
	char temp[MAXTOKEN];

	while (--argc > 0 && *(++argv)[0] == '-')
	{
		switch (*++argv[0])
		{
		case 'u':
			un = 1;
			break;

		default:
			printf("error: wrong parameter %s\n", *argv[0]);
		}
	}

	if (un)
	{ // undcl
		while (gettoken() != EOF)
		{
			strcpy(desc, token);

			while ((type = gettoken()) != '\n')
			{
				if (type == PARENS || type == BRACKETS)
				{
					strcat(desc, token);
				}
				else if (type == '*')
				{
					sprintf(temp, "*%s", desc);

					if (!((type = gettoken()) == NAME))
					{
						sprintf(temp, "(%s)", temp);
					}

					ungetstr(token);

					strcpy(desc, temp);
				}
				else if (type == NAME)
				{
					sprintf(temp, "%s %s", token, desc);
					strcpy(desc, temp);
				}
				else
				{
					printf("invalid input at %s\n", token);
					continue;
				}
			}

			printf("%s\n", desc);
		}
	}
	else
	{
		while (gettoken() != EOF)
		{ /* 1st token is */
			datatype[0] = desc[0] = name[0] = '\0';

			strcat(datatype, token); /* datatype */

			if (strcmp(datatype, "const") == 0)
			{
				strcat(datatype, " ");
				continue;
			}

			dcl();

			printf("%s %s %s\n", name, desc, datatype);
		}
	}

	return 0;
}
