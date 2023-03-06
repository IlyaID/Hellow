#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    sscanf(argv[1], "%x", &x);
    if(x & 1)
        printf("ma");
    else 
        printf("fe");

    return 0;
}