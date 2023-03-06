#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    freopen("bit_3.dat", "r", stdin);
    freopen("bit_3.ans", "w", stdout);
    int x;
    scanf("%x", &x);
    if(x & (1 << 4))
    {
        if(x & (1 << 5))
            printf("bk");
        else
            printf("rd");
    }
    else if(x & (1 << 5))
        printf("bw");
    else
        printf("bn");
        

    return 0;
}