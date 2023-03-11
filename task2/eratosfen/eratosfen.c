#include <stdbool.h>
#include <stdio.h>
 
void isPrime(long long int n, int* count) {
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            count++;}}
   
}
 

int main() {
    long long int n = 0;
    scanf("%lld", &n);
    int count = 0;
    isPrime(n, &count);
    printf("%d", count);
    return 0;
}