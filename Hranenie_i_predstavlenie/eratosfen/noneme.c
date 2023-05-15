#include <stdio.h>

#include <stdlib.h>

#include <string.h>


int main() {
  unsigned long long int x;
  scanf("%llu", & x);
  unsigned long long int n = x;
  unsigned long long int S[999999];
  S[1] = 0;
  unsigned long long int schet = 1;
  for (unsigned long long int i = 2; i <= n; i++)
    S[i] = 1;
  for (unsigned long long int k = 2; k * k <= n; k++) {
    if (S[k] == 1) {
      for (unsigned long long int l = k * k; l <= n; l += k) {
        S[l] = 0;
      }
    }
  }
  for (unsigned long long int i = 1; i <= n; i++) {
    if (S[i] == 1)
      schet++;
  }
  printf("%llu", schet - 1);
  return 0;
}