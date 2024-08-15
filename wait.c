#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	int status;
	int num_children = 5;
	char *argv[] = {"/bin/ls", "-l", "/tmp",  NULL};
	char *envp[] = {NULL};

	for (int i = 0; i < num_children; i++)
	{
		pid = fork();
		if (pid < 0 )
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(argv[0], argv, envp);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	return 0;
}
