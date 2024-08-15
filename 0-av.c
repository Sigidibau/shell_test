#include <stdlib.h>
#include <stdio.h>

int main (int ac, char **argv)
{
	(void)ac;
	while (*argv)
	{
		printf("%s\n", *argv);
		*argv ++;
	}
	return (0);
}

