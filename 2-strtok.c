#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[])
{
	char str[] = "something-here";
	char* token = strtok(str, " - ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " - ");
	}
	return (0);
}
