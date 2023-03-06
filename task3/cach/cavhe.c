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
    int A[20][20];
    int B[20][20];
    unsigned int n = 0, d =0;
    scanf("%d %d", &n, &d);
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
           A[i][j] = Evklid(i + 1, j +1 );
           B[i][j] = Evklid(n - i + 1, n - j + 1);
        }
    }
    
    unsigned int coun = 0;
    int sum = 0;
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
           for(unsigned k = 0; k < n; k++ ) {
                sum += A[i][k] * B[k][j];
                if (sum % d == 0) coun++;
           }
        }
    }

    printf("%u", coun);

return 0;

}