/* Sys Info using uname */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/utsname.h>
#define BUFSIZE 10000 // MAXIMUM BUFFER SIZE

/* ERROR MESSAGE */
void error (char *errMsg) {
	int len;
	char msg[BUFSIZE];
	len = sprintf(msg, "ERROR: %s\n", errMsg);
	write (2, msg, len);
	exit(1);
}

int main(int argc, char *argv[]) {
	struct utsname sysInfo;
	char data [BUFSIZE];
	int len;
	if ((uname (&sysInfo)) == -1)
		error ("Unknown system");
	
	len = sprintf(data, "SYSTEM INFORMATION \n");
	len += sprintf(data+(len+1), "-----------------------------------------------------------\n");
	len += sprintf(data+(len+1), "OS name:\t %s\n", sysInfo.sysname);
	len += sprintf(data+(len+1), "Release:\t %s\n", sysInfo.release);
	len += sprintf(data+(len+1), "Version:\t %s\n", sysInfo.version);
	len += sprintf(data+(len+1), "Node name:\t %s\n", sysInfo.nodename);
	len += sprintf(data+(len+1), "Machine:\t %s\n", sysInfo.machine);
	write (1, data, len+1);
}
