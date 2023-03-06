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
    int 
}