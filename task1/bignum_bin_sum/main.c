#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char a[1001], b[1001], c[1001];
    scanf("%s", &a);
    scanf("%s", &b);
    

    int len_a = strlen(a);
    int len_b = strlen(b);
    


    int i = len_a - 1;
    int j = len_b - 1;
    int len_c = 0;
    int um = 0;

    while(i >= 0 && j >= 0){

        int x = a[i] - '0';
        int y = b[j] - '0';
        c[len_c++] = (x + y + um) % 2;
        um = (x + y + um) / 2;
        i--;
        j--;
    }
        
    while(i >= 0){
        int x = a[i] - '0';
        c[len_c++] = (x + um) % 2;
        um = (x + um) / 2;
        i--;
    }

    while(j >= 0){
        int y = b[j] - '0';
        c[len_c++] = (y + um) % 2;
        um = (y + um) / 2;
        j--;
    }

    if(um != 0){
        c[len_c++] = um;
        
    }

    while(len_c >= 2 && c[len_c - 1] == 0 ){
        len_c--;
    }

    for(int i = len_c - 1; i >= 0; i--){
        printf("%c", c[i] + '0');
    }

    return 0;
    
}