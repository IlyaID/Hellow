#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("bit_3.dat", "r", stdin);
    freopen("bit_3.ans", "w", stdout);
    int input;
    scanf("%x", &input);
    if(input & (1 << 4)) {
        if(input & (1 << 5)){
            printf("bk");
        }
        else{
            printf("rd");
        }
    }
    else if(input & (1 << 5)) {
        printf("bw");
    }
    else {
        printf("bn");
    }
       
    return 0;
}