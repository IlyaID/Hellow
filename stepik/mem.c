#include <stdio.h>

typedef unsigned char byte;         //8 bit
typedef unsigned short int word;    //16 bit
typedef word Adress;                //16 bit

#define MEMSIZE (64*1024)


byte mem[MEMSIZE];

void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void w_write(Adress adr, word w);
word w_read(Adress adr);

int main() {
    byte b0 = 0x0a;
    //пишем байт, читаем байт
    b_write(2, b0);
    byte bres = b_read(2);
    printf("%02hhx == %02hhx", b0, bres);

    // пишем 2 байта читаем слово
    Adress a = 4;
    byte b1 = 0x0b;
    b0 = 0x0a;
    word w = 0x0b0a;
    b_write(a, b0);
    b_write(a+1, b1);
    word wres = w_read(a);
    printf("ww/br \t %04hhx == %02hhx%02hhx\n", wres, b1, b0);

    return 0;
}

void b_write(Adress adr, byte b){
    mem[adr] = b;
}
byte b_read(Adress adr){
    return mem[adr];
}

void w_write(Adress adr, word w){

}
word w_read(Adress adr){
    word w = mem[a+1] << 8;
    printf("w = %x\n", w);
    return
}

