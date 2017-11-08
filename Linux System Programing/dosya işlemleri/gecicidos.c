/**
 *normalde örnekte mktemp mkstemp veya tmpfile 
 * fonksiyonlarını kullanmamızı istiyordu
 * ancak gcc mktemp ve tmpfile fonksiyonlarını derlemiyor.
 * ileride ayrıntılı bir şekilde bakrsın bu konuya
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char tmpname[L_tmpnam];
	char *filename;
	FILE *tmpfp;

	filename = mkdtemp(tmpname);

	printf("temporary filename is : %s\n", filename);
	tmpfp = tmpfile();
	if(tmpfp)
		printf("opened a temporary file ok \n");
	else
		perror("tmpfile");

	exit(0);
}
