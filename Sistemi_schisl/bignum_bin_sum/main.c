#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char s1[1001], s2[1001], c[1001];
    scanf("%s", &s1);
    scanf("%s", &s2);
    

    int len_1 = strlen(s1);
    int len_2 = strlen(s2);
    


    int i = len_1 - 1;
    int j = len_2 - 1;
    int len_c = 0;
    int um = 0;

    while(i >= 0 && j >= 0){

        int x = s1[i] - '0';
        int y = s2[j] - '0';
        c[len_c++] = (x + y + um) % 2;
        um = (x + y + um) / 2;
        i--;
        j--;
    }
        
    while(i >= 0){
        int x = s1[i] - '0';
        c[len_c++] = (x + um) % 2;
        um = (x + um) / 2;
        i--;
    }

    while(j >= 0){
        int y = s2[j] - '0';
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