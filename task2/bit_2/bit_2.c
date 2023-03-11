#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int input;
    sscanf(getenv("CODE="), "%x", &input);
    if(input & (1 << 2)){
        printf("ha");
    }
    else{ 
        printf("nh");
    }
    return 0;
}