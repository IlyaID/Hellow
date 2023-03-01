/*Можно сделать так. Завести две переменные: double x=0, y=0.
Читать строку слева направо. Если пришла цифра b=='0' или '1', то выполнить x=2*x+b-'0'; y*=2;
Если пришла запятая - присвоить y=1. В конце, если y ненулевой, то поделить x на y.
Например,
для строки 101 : x=5, y=0. Ответ 5.
101,101 : x=45, y=8. Ответ 45/8=5.625
101, : x=5, y=1. Ответ 5.
,101 : x=5, y=8. Ответ 5/8=0.625. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char fbin[35];
    
    scanf("%s", &fbin);
    
    double x = 0, y = 0;

    long long len_fbin = strlen(fbin); 

        
    for(int i = 0; i < len_fbin; i++){
        if(fbin[i] == '0' || fbin[i] == '1'){
            x = 2 * x + fbin[i] - '0';
            y *= 2;
            
        }
        else {
            y = 1;
        }
    }

    if(y != 0){
        printf ("%.12lf", (x/y));
    }    
    else{
        printf ("%.12lf", x);
    }
    
    return 0;
}
