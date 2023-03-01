#include <stdio.h>

void dec2bin(int num, char* bin) {
    int i = 7;
    while (num) {
        bin[i] = (num % 2);
        num /= 2;
        i--;
    }
}

void notdec2bin(int num, char* bin) {
    int i = 7;
    while (num) {
        bin[i] = ~(num % 2);
        num /= 2;
        i--;
    }
}

int main() {

    int a = 0;
    char res[8] = {};
    scanf("%d", &a);
    if(a > 0){
        dec2bin(a, res);
    }
    else if(a == 0){
        printf("%d", res);
    }
    else {
       notdec2bin(a, res);
    }   
    for(int i = 0; i < 8; i++){
        printf("%d", res[i]);
    }       

    return 0;
}