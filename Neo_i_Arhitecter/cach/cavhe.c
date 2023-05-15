#include <stdio.h>
#include <stdlib.h>


int Evklid(int x, int y){
    if (x != y) {
        if (x > y) {
            Evklid(x -y, y);
        }
        else {
            Evklid(x, y - x); 
        }
     }
     else {
        return x;
     }
     
}

int main(){
    int A[1024][1024];
    int B[1024][1024];
     int n = 0, d =0;
    scanf("%d %d", &n, &d);
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
           A[i][j] = Evklid(i + 1, j + 1);
           B[i][j] = Evklid(n - i + 1, n - j + 1);
        }
    }
    
     int coun = 0;
    
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            int sum = 0;
            for( int k = 0; k < n; k++ ) {
                sum += A[i][k] * B[j][k];
            }
            if (sum % d == 0) coun++;
           
        }
    }

    printf("%d", coun);

return 0;

}
