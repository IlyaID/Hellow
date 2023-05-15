#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int x;
    scanf("%d", &x);
    long long res;
    for (long long i = x * x; i < x * x * x; i++){
        if((i * i)%(x * x * x) == i){
            res = i;
        };
    }
    printf("%lld", res);
}