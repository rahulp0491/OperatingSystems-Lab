/* ls | sort */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

/* ERROR MESSAGE */
void error (char *errMsg) {
	int len;
	char msg[BUFSIZE];
	len = sprintf(msg, "ERROR: %s\n", errMsg);
	write (2, msg, len);
	exit(1);
}

int main(int args, char *argv[]) {
	int fd[2], pid;
	pipe(fd);
	pid = fork();
	if(pid > 0) {
		close(1);		// CLOSING STDOUT
		dup(fd[1]);		// DUPLICATING STDOUT FILE DESCRIPTOR
		close(fd[0]);
		close(fd[1]);
		execlp ("ls", "ls %s", argv[1], NULL); // LOADING NEW PROGRAM 'ls'
	}
	else if(pid == 0) {
		close(0);		// CLOSING STDIN
		dup(fd[0]);		// DUPLICATING STDIN FILE DESCRIPTOR
		close(fd[0]);
		close(fd[1]);
		execlp ("sort", "sort", NULL); // LOADING NEW PROGRAM 'sort'
	}
	else
		error ("Cannot create new process");
	return 0;
}
