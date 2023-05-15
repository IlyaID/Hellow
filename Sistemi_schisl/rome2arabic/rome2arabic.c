#include <string.h>
#include <stdio.h>
 
void arabic_to_Rome(int number, char* result) {
 
    const char* str_rome[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values_rome[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
 
    
    for (int i = 0; i < 13; ++i) {
        while (number - values_rome[i] >= 0) {
            strcat(result, str_rome[i]);
            number -= values_rome[i];
        }
    }
}

int Rome_to_arabic(char number[]) {
 
    const char* str_rome[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values_rome[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
 
    int result = 0;
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 13; j++){
            if (str_rome[j] == number[i]) {
                result += values_rome[j];
                break;
            }
        }
    }
    return result;
}
 
int main() {
    char* str[64];
    scanf("%s", &str);
    printf("%d\n",Rome_to_arabic(*str));
    return 0;
}