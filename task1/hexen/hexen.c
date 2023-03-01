#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_digit(char c){
    if (c>='0' && c <='9') {
        return c - '0';
    }
    return 10 + c - 'A';
}

const char* to_binary(int x){
    static const char* res[16] ={
        "0000","0001","0010","0011",
        "0100","0101","0110","0111",
        "1000","1001","1010","1011",
        "1100","1101","1110","1111"
    };
    return res[x];
}

int main(){
    static char num[1000000 + 1];
    scanf("%s", num);
    int a = 0;
    static char buf[4000000 + 1];

    int n = strlen(num);
    for (int i = 0;i < n; ++i) {
        const char* b = to_binary(get_digit(num[i]));
        strcpy(buf + a, b);
        a += 4; 
    }

    const char* ans = buf;
    for (int i = 0; i < 3 && *ans == '0';++i){
        ++ans;
    }
    printf("%s\n", ans);

    return 0;
}
