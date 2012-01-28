/* fsize and directory walk */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#define BUFSIZE 10000
#define DIRSIZE 4096

void error (char *errMsg) {
	int len;
	char msg[BUFSIZE];
	len = sprintf(msg, "ERROR: %s\n", errMsg);
	write (1, msg, len);
	exit(1);
}

int flag = 0;
char *p;
int count = 1;

void fSize (struct stat fS, int fd, char *s) {
	struct stat st;
	int f;
	struct dirent *dr;
	DIR *dir;
	int len;
	char name [BUFSIZE];
	switch (fS.st_mode & S_IFMT) {
		case S_IFDIR :
		dir = fdopendir (fd);
			while ((dr = readdir (dir)) != NULL) {
				char t[BUFSIZE];
				flag = 1;
				strcpy (t, p);
				strcat (t, dr->d_name);
				f = open (t, O_RDONLY);
				fstat (f, &st);
				if (S_ISREG(st.st_mode)) {
					fSize(st, f, dr->d_name);
				}
				else {
					if (flag == 1) {
						len = sprintf (name, "%d  %s  ----  %d Bytes\t\tDirectory\n",count++,  dr->d_name, DIRSIZE);
						write(1, name, len);
					}
				}
				close (f);
			}
		closedir (dir);
		break;
		
		case S_IFREG :
		len = sprintf (name, "%d  %s  ----  %d Bytes\t\tFile\n",count++, s, (int)fS.st_size);
		write (1, name, len);
		break;
		
		default:
		error ("Unknown file type");
		break;
	}
}

int main (int args, char *argv[]) {
	if (args != 2)
		error ("Insufficient arguments");
	char *fName;
	fName = argv[1];
	int fd;
	struct stat fStat;
	if ((fd = open (fName, O_RDONLY)) == -1)
		error ("Could not open file");
	if ((fstat (fd, &fStat)) == -1)
		error ("Could not stat");
	p=fName;
	fSize(fStat, fd, fName);
	close (fd);
}
