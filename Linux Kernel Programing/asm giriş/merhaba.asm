;linux kernel dersler -> sys_call çalışma mantığı için
; %rax							%rdi			%rsi			%rdx		
;  0	read	sys_read	fs/read_write.c		unsigned int fd		char *buf		size_t count
;  1	write	sys_write	fs/read_write.c		unsigned int fd	const	char *buf		size_t count
;  2	open	sys_open	fs/open.c		const char *filename	int flags		int mode
;  3	close	sys_close	fs/open.c		unsigned int fd
;  60		sys_exit				int error_code
; diğer sistem çağrıları için x_64 linux sys_call bak
section .data
	text db "merhaba dunya",10

section .text
	global _start

_start:
	mov rax, 1  ; rax sys_write kullanılacağından 1 yapılır.
	mov rdi, 1  ; rdi standart çıktı ya yazı yazılacağından 1 yapılır
	mov rsi, text ; yazılacak *buf 
	mov rdx, 14   ; kaç karakter yazılacağı
	syscall	     ;sys_write kernel çağrısını  çağır

	mov rax, 60	; sys_exit çağrısın  çağırıyoruz
	mov rdi, 0
	syscall
; derleme işlemi için nasm -f elf64 merhaba.asm -o merhaba.o object dosyalarını böylece oluşturuyoruz.
; linkleme işlmei için ld merhaba.o -o merhaba  ./merhaba çalıştırıyoruz.
