#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main() {
    FILE* fp = fopen("source", "rb");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint32_t* buff = (uint32_t*)calloc(size, sizeof(char));
    fread(buff, sizeof(char), size, fp);
    fclose(fp);
    int i = 0;
    while(1) {
        if(buff[i] == (uint32_t)0x54fffee1) {
            buff[i] = (uint32_t)0x54fffee0;
            break;
        }
        i++;
    }
    fp = fopen("cracked", "wb");
    fwrite(buff, sizeof(char), size, fp);
    fclose(fp);
    return 0;
}