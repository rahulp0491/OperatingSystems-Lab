/* fsize and directory walk */

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
char pstring [BUFSIZE];

char *getP (struct stat fS) {
	int len=0;
	bzero (pstring, BUFSIZE);
	if (S_ISDIR (fS.st_mode)) 
		strcat (pstring, "d");
	else if (S_ISREG (fS.st_mode))
		strcat (pstring, "-");
	else if (S_ISLNK (fS.st_mode))
		strcat (pstring, "l");
	else if (S_ISBLK (fS.st_mode))
		strcat (pstring, "b");
	else if (S_ISCHR (fS.st_mode))
		strcat (pstring, "c");
	else if (S_ISSOCK (fS.st_mode))
		strcat (pstring, "s");
	
	if (fS.st_mode & S_IRUSR)
		strcat (pstring, "r");
	else
		strcat (pstring, "-");
	
	if (fS.st_mode & S_IWUSR)
		strcat (pstring, "w");
	else
		strcat (pstring, "-");
	
	if (fS.st_mode & S_IXUSR)
		strcat (pstring, "x");
	else
		strcat (pstring, "-");
	
	if (fS.st_mode & S_IRGRP)
		strcat (pstring, "r");
	else
		strcat (pstring, "-");
	
	if (fS.st_mode & S_IWGRP)
		strcat (pstring, "w");
	else
		strcat (pstring, "-");
	
	if (fS.st_mode & S_IXGRP)
		strcat (pstring, "x");
	else
		strcat (pstring, "-");
	
	if (fS.st_mode & S_IROTH)
		strcat (pstring, "r");
	else
		strcat (pstring, "-");
	
	if (fS.st_mode & S_IWOTH)
		strcat (pstring, "w");
	else
		strcat (pstring, "-");
	if (fS.st_mode & S_IXOTH)
		strcat (pstring, "x");
	else
		strcat (pstring, "-");
	
	return pstring;
}

int blocks=0;
char name [BUFSIZE];
int len=-1;

char * fSize (struct stat fS, int fd, char *s) {
	struct stat st;
	int f;
	struct dirent *dr;
	DIR *dir;
	char *perm;
	struct tm *time;
	char sTime[20];
	struct passwd *pass;
	struct group *gr;
	size_t strtime;
	switch (fS.st_mode & S_IFMT) {
		case S_IFDIR :
		dir = fdopendir (fd);
			while ((dr = readdir (dir)) != NULL) {
				char t[BUFSIZE];
				strcpy (t, p);
				strcat (t, dr->d_name);
				f = open (t, O_RDONLY);
				fstat (f, &st);
				flag = 1;
				if ((st.st_mode & S_IFMT) == S_IFREG) {
					fSize(st, f, dr->d_name);
				}
				else {
					if (flag == 1) {
						if (!(strcmp(dr->d_name, ".") == 0 || strcmp(dr->d_name, "..") == 0)) {
							perm = getP (fS);
							pass = getpwuid (fS.st_uid);
							gr = getgrgid (fS.st_gid);
							time = localtime (&fS.st_mtime);
							strtime = strftime (sTime, sizeof (sTime), "%F %R", time);
							blocks += (int)fS.st_blocks;
							len += sprintf (name+len+1, "%s %d %s %s\t%d\t%s  %s\n", perm, (int)fS.st_nlink, pass->pw_name, gr->gr_name, (int)fS.st_size, sTime, dr->d_name);
						}
					}
				}
				close (f);
			}
		break;
		
		case S_IFREG :
		perm = getP (fS);
		blocks += (int)fS.st_blocks;
		pass = getpwuid (fS.st_uid);
		gr = getgrgid (fS.st_gid);
		time = localtime (&fS.st_mtime);
		strtime = strftime (sTime, sizeof (sTime), "%F %R", time);
		len += sprintf (name+len+1, "%s %d %s %s\t%d\t%s  %s\n", perm, (int)fS.st_nlink, pass->pw_name, gr->gr_name, (int)fS.st_size, sTime, s);
		break;
		
		default:
		error ("Unknown file type");
		break;
	}
	return name;
}

int main (int args, char *argv[]) {
	if (args != 2)
		error ("Insufficient arguments");
	char *fName;
	fName = argv[1];
	int fd;
	char *n;
	char s[100];
	int l;
	struct stat fStat;
	if ((fd = open (fName, O_RDONLY)) == -1) 
		error ("Could not open file");
	if ((fstat (fd, &fStat)) == -1)
		error ("Could not stat");
	p=fName;
	n = fSize(fStat, fd, fName);
	if (S_ISDIR(fStat.st_mode)) {
		l = sprintf (s, "total %d\n", blocks/2); 
		write (1, s, l);
	}
	write (1, name, len+1);
	close (fd);
}
