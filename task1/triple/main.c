#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long long int tri = 0, ten = 0;
    scanf("%llu",&tri);
    int n = 1;
    while (tri > 0){
        ten += tri % 10 * n;
        tri /= 10;
        n *= 3;
        
    }

    printf("%llu", ten);
        
    return 0;
    
}