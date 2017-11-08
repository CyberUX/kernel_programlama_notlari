/*
 *struct sockaddr_in {
    short int          sin_family;  // Adres ailesi
    unsigned short int sin_port;    // Port numarası
    struct in_addr     sin_addr;    // Internet adresi
    unsigned char      sin_zero[8]; // struct sockaddr ile aynı boyda  };

 *Internet adresi (tarihi sebeplerden ötürü korunmakta)
    struct in_addr {
    unsigned long s_addr; // 32-bit yani 4 bytes  };

 *veri dönüştürme fonksiyonları (#include <arpa/inet.h> kütüphanesinde tanımlı)  
    htons() -- "Host to Network Short" -- konaktan ağa short
    htonl() -- "Host to Network Long" -- konaktan ağa long
    ntohs() -- "Network to Host Short" -- ağdan konağa short
    ntohl() -- "Network to Host Long" -- ağdan konağa long 
 
 * -inet_addr(). Bu işlev bir IP adresini yukarıdaki gibi sayılardan ve noktalardan oluşan bir biçemden alıp unsigned
 		long türünde bir sayıya çevirir. örenk -->> ina.sin_addr.s_addr = inet_addr("10.12.110.57");
   -inet_aton() ("aton"u, "ascii to network" olarak okuyun): 
   -inet_ntoa() ("ntoa"yı "network to ascii" olarak okuyun).

 *struct hostent {
    char    *h_name;	h_name -- Konağın resmi ismi. 
    char    **h_aliases;  h_aliases -- Söz konusu konağın alternatif isimleri, NULL ile sonlandırılmış karakter dizileri 
    int     h_addrtype;  _addrtype -- Dönen adresin türü, genellikle AF_INET değerini alır.
    int     h_length;		h_length -- Byte cinsinden adresin uzunluğu. 
    char    **h_addr_list;  h_addr_list -- Konağın ağ adresinin sıfır sonlandılmalı dizisi.Konak adresleri ağ bayt sıralamasına sahiptir. 
	};
  #define h_addr h_addr_list[0]  h_addr -- h_addr_list listesindeki ilk adres. 

 *struct hostent *gethostbyname(const char *name); anlaşılacağı üzere verilen adresi (biz argv[1] ="localhost" dicez) 
	struct hostent tipinde döndürür.struct hostent bir yukarı bak.
 
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>

#define DATA "bu yazıyı sunucuya gönder alsın :)v "

int main(int argc, char *argv[]) 
{
	int sock;
	struct sockaddr_in server;
	struct hostent *hp;
	char buff[1024];
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0) {
		perror("socket failed");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	
	hp = gethostbyname(argv[1]);  
	if(hp == 0) {
		perror("gethostname failed");
		exit(1);
	}
	
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(5000);

	if(connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) { // server ın adresine bağlan
		perror("connect failed");
		exit(1);
	}
	
	if(send(sock, DATA, sizeof(DATA), 0) < 0) {
		perror("send failed");
		exit(1);
	}
	
	printf("sent %s\n",DATA);
	close(sock);
	
	return 0;
}
