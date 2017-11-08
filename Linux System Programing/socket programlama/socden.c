#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	/*değişkenlerimiz */


	int sock;
	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;



	/*socket oluştur */
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0) {
		perror("socket oluşturulamadı");
		exit(1);
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY = bu makinenin IP aderesini kullan
	server.sin_port = htons(5000);



	/*bind */
	
	if(bind(sock, (struct sockaddr *)&server, sizeof(server))) {
		perror("bind hatası");
		exit(1);
	}




	/*listen */
	listen(sock, 5); // listen(dinleme yapılacak socket, gelen çağrı kuyruğunda bekleyecek bağlantı sayısı)




	/*accept
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size); */
	
	do {
		mysock = accept(sock, (struct sockaddr *) 0, 0);  // herhangi bir adresten gelen bağlantıyı kabul et
		if(mysock == -1) {
			perror("accept failed");
			exit(1);
		}else {
			memset(buff, 0, sizeof(buff));
			if((rval = recv(mysock, buff, sizeof(buff), 0)) < 0) 
				perror("reading system mesage error");
			else if (rval == 0)
				printf("ending connection");
			else
				printf("MSG :---> %s\n", buff);

			printf("get the message (rval) = %d\n", rval);
			close(mysock);
		}
	}while(1);
	
	return 0;
}


