/* Write a C program to read a string (a line as well) and append it to the given file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 10000

void error (char *errMsg) {
	int len;
	char msg[BUFSIZE];
	len = sprintf(msg, "ERROR: %s\n", errMsg);
	write (1, msg, len);
	exit(1);
}

int main (int args, char *argv[]) {
	if (args != 2) 
		error ("Insufficient arguments");
	int destFd;
	char *destFile;
	int rRet;
	char buf[BUFSIZE];
	destFile = argv[1];
	destFd = open (destFile, O_APPEND | O_WRONLY);
	write (1, "Enter string: ", 14);
	if ((rRet = read (0, buf, BUFSIZE)) == -1) {
		error ("Cannot read from stdin");
	}
	if ((write (destFd, buf, rRet)) == -1) {
		error ("Cannot append to file");
	}
	close (destFd);
}

