#include <stdio.h>
#include <stdlib.h>


int Evklid(int x, int y){
    if (x != y) {
        if (x > y){
            Evklid(x -y, y);
        }
        else{
            Evklid(x, y - x); 
        }
     }
     return x;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            
        }
    }
}