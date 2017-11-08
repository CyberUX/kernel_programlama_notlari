/**
 *okuma işlmei 1024 byte yani 1kbyte olacak şekilde okuma
 *işlmei bitene kadar yapılır. 
 *okunan değerin boyut nread e aktarılır.ve okuma > 0 olana kadar 
 *yani okuma işlmei olduğu müddetçe okuma yapılır
 *okunan değer 1K lik block değerinden ramde depolanır
 *sonra write ile out dosyasına yazılır.
 */
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char block[1024];
	int in,out;
	int nread;

	in = open("file.in",O_RDONLY);
	out = open("file.out",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while((nread=read(in,block,sizeof(block))) > 0 )
		write(out,block,nread);

	exit(0);
}
