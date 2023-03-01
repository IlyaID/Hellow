#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long int read_s_to_ten(char *input_str, int rad)
{
   long long int n = 0;
   while (*input_str != '\0') {
     int k;
     if (*input_str>='0' && *input_str <= '9' ) {k = *input_str - '0';}
     else if (*input_str >= 'a' && *input_str<= 'z'){
        k = *input_str - 'a' + 10;
        }
     else if (*input_str >= 'A' && *input_str<= 'Z'){
        k = *input_str - 'A' + 10;
        }
     else continue;
     n = rad*n + k;
     input_str++;
   }
   return n;
}

 
char base_symbol(int input_N){   //Описываем символы для вывода
    char out[]={'0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z'};
    return out[input_N];
}
 
void ten_to_any(int input_N, int base){
    if (input_N < base) {
        printf("%c", base_symbol(input_N));
        return;
    }
    ten_to_any(input_N/base,base);
    printf("%c", base_symbol(input_N % base));
}
 
int main(){
    char input_str[100000];
    int new_base,old_base;
     // old_base - исходная cистема cчисления, new_base - конечная система счисления, input_str - вводимое число
    scanf("%d", &old_base);
    scanf("%s", &input_str);
    scanf("%d", &new_base);
    long long int N_ten = read_s_to_ten(input_str, old_base);
    ten_to_any(N_ten,new_base);
    
    return 0;
}