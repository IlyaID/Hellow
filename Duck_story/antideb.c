#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main() {
    FILE* fp = fopen("antideb", "rb");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char * buff = (char *) calloc(size, 1);
    fread(buff, sizeof(char), size, fp);
    fclose(fp);
    int i = 0;
    while(1) {
        if(*((uint32_t *)(buff+i)) == 0x20bf1475) {
            *((uint32_t *)(buff+i)) = 0x20bf1474;
            break;
        }
        i++;
    }
    fp = fopen("antideb_patched", "wb");
    fwrite(buff, sizeof(char), size, fp);
    fclose(fp);
    return 0;
}