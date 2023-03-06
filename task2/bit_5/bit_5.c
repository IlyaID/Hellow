#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int result = 0;
    char str[256];

    while(1 == scanf("%s", &str)) {

        if(strcmp(str, "ma") == 0) {
            result |= 1;
        }
        if(strcmp(str, "cl") == 0) {
            result |= 1 << 1;
        }
        if(strcmp(str, "ha") == 0) {
            result |= 1 << 2;
        }
        if(strcmp(str, "tr") == 0) {
            result |= 1 << 3;
        }
        if(strcmp(str, "rd") == 0) {
            result |= 1 << 4;
        }
        if(strcmp(str, "bw") == 0) {
            result |= 1 << 5;
        }
        if(strcmp(str, "bk") == 0) {
            result |= 3 << 4;
            }
        if(strcmp(str, "ge") == 0) {
            result |= 1 << 6;
        }
        if(strcmp(str, "gy") == 0) { 
            result |= 1 << 7;
        }
        if(strcmp(str, "da") == 0) {
            result |= 3 << 6;
        }
    }
    printf("%x", result);
    return 0;
}