/* Write a C program to implement cp command in linux using system calls */

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

int main(int args, char *argv[]) {
	if (args != 3) 
		error ("Insufficient arguments");
	int srcFd, destFd;
	char *srcFile, *destFile;
	int rRet, wRet;
	char buf[BUFSIZE];
	srcFile = argv[1];
	destFile = argv[2];
	srcFd = open(srcFile, O_RDONLY);
	destFd = open(destFile, O_WRONLY);
	if (srcFd == -1 || destFd == -1) {
		error ("Cannot open specified file");
	}
	if ((rRet = read(srcFd, buf, BUFSIZE)) == -1) {
		error ("Cannot read source file");
	}
	close (srcFd);
	if ((wRet = write(destFd, buf, rRet)) == -1) {
		error ("Cannot write to destination file");
	}
	close (destFd);
}
