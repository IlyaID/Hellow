#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned short adr;

byte MEM[65536];

byte b_read  (adr a){
    return MEM[a];
}                   
                                           // читает из "старой памяти" mem байт с "адресом" a.
void b_write (adr a, byte val){
    MEM[a] = val;
}
                                                             // пишет значение val в "старую память" mem в байт с "адресом" a.
word w_read  (adr a){
    return MEM[a] | (MEM[a + 1] << 8);
}
                                                             // читает из "старой памяти" mem слово с "адресом" a.
void w_write (adr a, word val){
    MEM[a] = val & 0x00ff;
    MEM[a+1] = val >> 8;
}                                                             // пишет значение val в "старую память" mem в слово с "адресом" a.




