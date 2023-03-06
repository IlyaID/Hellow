#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int a;
    scanf("%d", &a);
    for(int i = 7; i >= 0; i--) {
        if(a & (1 << i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    return 0;
}