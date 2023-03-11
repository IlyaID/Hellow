#include <string.h>
#include <stdio.h>
 
void arabic_to_Rome(int n, char* result) {
 
    const char* str_rome[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values_rome[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
 
    result[0] = 0;
    for (int i = 0; i < 13; ++i) {
        while (n - values_rome[i] >= 0) {
            strcat(result, str_rome[i]);
            n -= values_rome[i];
        }
    }
}
 
int main() {
    char str[64];
    int num;
    scanf("%d", &num);
    arabic_to_Rome(num, str);
    printf("%d = %s\n", num, str);
}