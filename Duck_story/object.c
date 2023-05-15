#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main() {
    fseek(stdin, 0L, SEEK_END);
    int size = ftell(stdin);
    rewind(stdin);
    char * buff = (char *) calloc(size, 1);
    fread(buff, 1, size, stdin);
    int i = 0;
    while(1) {   
        if(*((uint32_t *)(buff+i)) == 0xc1d80845) {
            *((uint32_t *)(buff+i)) = 0x90c9deeb;
            break;
        }

        i++;
    }

    fwrite(buff, 1, size, stdout);
    fclose(stdin);
    free(buff);
    return 0;
}