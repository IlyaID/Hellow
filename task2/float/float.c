#include <stdio.h>
#include <stdlib.h>


void float_to_frak(double num, double eps, int *chislitel, int *znamenatel)
{
  int a = 1; int b = 1;
  int mn = 2; // множитель для начального приближения
  int iter = 0;
  chislitel = a; znamenatel = b; 
    // Поиск начального приближения
  double c = 1;

  do {
    b++;
    c = (double)a / b;
  } while ((num - c) < 0);

  if ((num - c) < eps) {
    chislitel = a;
    znamenatel = b;
  }

  b--;
  c = (double)a / b;
  if ((num - c) > -eps) {
    chislitel = a;
    znamenatel = b;
  }
  // Уточнение
  while (iter < 20000) {
    int cc = a*mn, zz = b*mn;
    iter++;

    do {
      zz++;
      c = (double)cc / zz;
    } while ((num - c) < 0);

    if ((num - c) < eps) {
      chislitel = cc; znamenatel = zz;
      
    }
    zz--;
    c = (double)cc / zz;

    if ((num - c) > -eps) {
      chislitel = cc; znamenatel = zz;
      
    }

    mn++;
  }
}


int main() {
  double input;
  int chislitel, znamenatel;
  double eps = 0.0000001;
  scanf("%f", &input);
  float_to_frak(input, eps, &chislitel, &znamenatel);
  printf("(%d/%d)", chislitel, znamenatel);  
  return 0;
}