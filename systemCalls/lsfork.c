/* ls | sort */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(int args, char *argv[]) {
	int fd[2], pid;
	pipe(fd);
	pid = fork();
	if(pid > 0) {
		close(1);		// Closing stdout
		dup(fd[1]);		// Duplicating stdout
		close(fd[0]);
		close(fd[1]);
		//system ("ls");
		execlp ("ls", "ls %s", argv[1], NULL);
	}
	else if(pid == 0) {
		close(0);		// Closing stdin
		dup(fd[0]);		// Duplicating stdin
		close(fd[0]);
		close(fd[1]);
		//system("sort");
		execlp ("sort", "sort", NULL);
	}
	return 0;
}
