#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
    char s[1];
    scanf("%s", &s);
    if(s[0] == 'f'){
        printf("23");
    }
    if(s[0] == 'd'){
        printf("52");
    }
    if(s[0] == 'l'){
        printf("63");
    }
    return 0;
}