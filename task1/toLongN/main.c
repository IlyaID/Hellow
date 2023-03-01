#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *dig;	// массив для хранения числа:
// a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
	int n; 			// размер числа в разрядах
	char sign;	// знак числа
}LongN;



void print_LongN(LongN put){
    printf("%c\n", put.sign);
    for(int i = 0; i <= put.n; i++){
        printf("%d * 100^%d + ", put.dig[i], i);
    }
    
} 

LongN getLongN(char *s){
    LongN result;
    //
    int count = 0;
    if(s[0] == '-'){
        result.sign = 1;
        count = 1;
    }
    if(s[0] == '+' || (s[0] > '1' && s[0] < '9')){
        result.sign = 0;
        count = 1;
    }
    
    result.n = (strlen(s) - count + 1)/2;
    result.dig = calloc(result.n, sizeof(char));

    if((strlen(s) - count)%2 == 1) {
        result.dig[result.n - 1] = s[0 + count] - '0';
    }

    for(int i = strlen(s) - 1, j = 0; i-count > 0; i-=2, j++){
        result.dig[j] = (s[i - 1] - '0') * 10 + (s[i] - '0');
    }

    return result;
}




int main(){
       
    LongN res;
    
    char s[200];
    scanf("%s", s);
    res = getLongN(s);          
    print_LongN(res);                    
    
    
    return 0;
}
