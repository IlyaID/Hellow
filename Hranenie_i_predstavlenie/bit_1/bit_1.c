#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int input;
    sscanf(argv[1], "%x", &input);
    if(input & 1) {
        printf("ma");
    }
    else{ 
        printf("fe");
    }
    return 0;
}