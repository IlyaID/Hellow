#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int x;
    sscanf(getenv("CODE"), "%x", &x);
    if(x & (1 << 2))
        printf("ha");
    else 
        printf("nh");

    return 0;
}