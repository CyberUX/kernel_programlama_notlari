/**
 * bir unix işletim sisiteminde en basit veri tabanı geçerli kullanıcıların
 * birleştirilmiş bilgilerinin tutulduğu /etc/passwd metin dosyasıdır.
 * bu dosyada her kullanıcı için bir satır ve her satırda : işareti ile ayrılmış 7 sutun bulunur.
 * bunlar kullanıcı ismi, şifrelenmiş parola, kullanıcı kimliği(uid), grup kimliği(gid), 
 * kullanıcının gerçek ismi ve hesapla ilgili diğer açıklamalar, ev dizini
 * ve bağlantı kubuğu (başlangıçta çalışacak kabuk)
 * bu bilgilerin hepsini getwuid fonksiynuyla alabiliriz.
 * struct yapısı aşikar, daha fazla bilgi için man getwuid
 */
#include<sys/types.h>
#include<pwd.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>     // getlogin fonksiyonu çalışmadığından hatayı anlamak için koydum.
#include<string.h>    // kullandığım dağıtım bilginin alınmasına müsade etmiyor.
int main()
{
	uid_t uid;
	gid_t gid;

	struct passwd *pw;
	uid = getuid();
	gid = getgid();

	
	if(getlogin()==NULL)
		fprintf(stderr,"getlogin kullanıcı bilgilrinialamadı çünkü;\n%s", strerror(errno));
	else
		printf("user is %s\n",getlogin());

	printf("user ID: uid=%d, gid=%d\n",uid, gid);

	pw = getpwuid(uid);
	printf("uid passwd etry:\n name=%s, uid=%d, gid=%d, home=%s, shell= %s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

	pw = getpwnam("root");
	printf("root passwd etry\n");
	printf("uid passwd etry:\n name=%s, uid=%d, gid=%d, home=%s, shell= %s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

	exit(0);
}
