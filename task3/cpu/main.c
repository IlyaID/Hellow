#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 
 
#ifndef REGISTERS 
#define REGISTERS 4 
#endif 


int main() { 
    uint_least8_t REG[REGISTERS] = {0, 0, 0, 0}; 
    if(REGISTERS > 4) { 
        printf("-1"); 
        return 0; 
    } 
     
    int x = 1; 
    while(x != 0 ) { 
        scanf("%d", &x); 
        if (x == 3) { 
            scanf("%d", &x); 
            if(x-5 >= REGISTERS) { 
                printf("-1"); 
                return 0; 
            } 
            int y = x - 5; 
            scanf("%d", &x); 
            REG[y] = x; 
            continue; 
        } 
        if (x == 1) { 
            scanf("%d", &x); 
            if(x-5 >= REGISTERS) { 
                printf("-1"); 
                return 0; 
            } 
            int y = x - 5; 
            scanf("%d", &x); 
            if(y >= REGISTERS) { 
                printf("-1"); 
                return 0; 
            } 
            REG[y] += REG[x-5]; 
            continue; 
        } 
        if (x == 2) { 
            scanf("%d", &x); 
            if(x-5 >= REGISTERS) { 
                printf("-1"); 
                return 0; 
            } 
            int y = x - 5; 
            scanf("%d", &x); 
            if(y >= REGISTERS) { 
                printf("-1"); 
                return 0;    
            } 
            REG[y] -= REG[x-5]; 
            continue; 
        } 
        if (x == 4) { 
            for(int i = 0; i < REGISTERS; i++) { 
                printf("%d ", REG[i]); 
            } 
            printf("\n"); 
            continue; 
        } 
    } 
 
    return 0; 
}
