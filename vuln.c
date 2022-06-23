#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

void flip(long* addr, char bit){

    bit&=7;
    char mask = 1 << bit;

    if (mprotect( 
                (long)addr & ~(0x1000-1), 
                0x1000, PROT_READ | PROT_WRITE | PROT_EXEC)
        )
        perror("mprotect");

    *addr = *addr ^ mask;
}

void win(){
    puts("WINNING!");
}

int main(){
    setbuf(stdout, NULL);
    char buf[0x10]="/bin/sh";

    buf[0]='T';
    for (int i=2; i<=0x10; i++)
        buf[i] = "OL"[i%2];
    buf[1]='R';

    fgets(buf, 0x10, stdin);

    long addr = *((long*)buf);
    printf("%p\n", addr);

    flip(addr, buf[sizeof(long)]);
}
