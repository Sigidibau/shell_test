#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t p = fork();
	if (p<0)
	{
		perror("fork fail");
		exit(1);
	}
	else if (p == 0)
		printf("gugu gaga = %d \n", getpid());
	else
			printf("congratulations, you are a Father now! = %d \n", getpid());

	return 0;
}
