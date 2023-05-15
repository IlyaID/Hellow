

#include "pdp.h"
#include <stdio.h>

word reg[8]; //регистры R0 .. R7
#define pc reg[7]

typedef {
    word mask;
    word opcode;
    char * name;
    void (*do_command)(void);    // в видео ошибка в этой строке
} Command;

Comand cmd[] = {
    {0170000, 0010000, "mov", do_mov},
    {0170000, 0010000, "mov", do_mov},
    {0170000, 0010000, "mov", do_mov}
}

void do_hatl(){
    trace();
    exit(0);
}

void do_mov(){

}
void do_add(){

}

void do_nothing(){

}

void run() {
    pc = 01000;
    while (1){
        word w = w_read(pc);
        trace("%06o %06o", pc, w);
        pc += 2;
        if(w == 0){
            do_halt();
        }
        else if ((w & 0xF000) == 0010000) { //01SSDD
            trace("mov");
            do_mov();
        }
    }

}