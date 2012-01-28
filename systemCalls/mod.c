#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <wait.h>
#define BUFSIZE 10000
int sec1, min1, hr1;

int main (int args, char *argv[]) {
	int fd, fd1;
	int status;
	struct tm *time, *time1;
	struct stat fs, fs1;
	char buf[BUFSIZE];
	char buf1[BUFSIZE];
	int ret, ret1;

	fd = open (argv[1], O_RDWR);
	fstat (fd, &fs);
	ret = read (fd, buf, BUFSIZE);
	time = localtime (&fs.st_mtime);
	sec1 = time->tm_sec;
	min1 = time->tm_min;
	hr1 = time->tm_hour;
	close (fd);
	while (1) {
		fd1 = open (argv[1], O_RDWR); 
		fstat (fd1, &fs1);
		time1 = localtime (&fs1.st_mtime);
		if (hr1 != time1->tm_hour || min1 != time1->tm_min || sec1 != time1->tm_sec) {
			
			ret1 = read (fd1, buf1, BUFSIZE);
			//printf("%d\t%d\n", ret, ret1);
			write (1, buf1+ret-1, ret1-ret+1);
			return 0;
		}
		close (fd1);
	}
}
