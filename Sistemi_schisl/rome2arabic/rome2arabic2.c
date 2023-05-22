#include <stdio.h>
#include <string.h>

int main()
{
    char massive[100] = "";
    int prev = 0;
    int res = 0;
    scanf("%s", massive);
    for (int i = strlen(massive) - 1; i > -1; i--) {
        switch (massive[i]) {
        case 'M':
            res += 1000;
            prev = 1000;
            break;
        case 'D':
            if (500 >= prev) {
                res += 500;
                prev = 500;
            }
            else {
                res -= 500;
                prev = 500;
            }
            break;
        case 'C':
            if (100 >= prev) {
                res += 100;
                prev = 100;
            }
            else {
                res -= 100;
                prev = 100;
            }
            break;
        case 'L':
            if (50 >= prev) {
                res += 50;
                prev = 50;
            }
            else {
                res -= 50;
                prev = 50;
            }
            break;
        case 'X':
            if (10 >= prev) {
                res += 10;
                prev = 10;
            }
            else {
                res -= 10;
                prev = 10;
            }
            break;
        case 'V':
            if (5 >= prev) {
                res += 5;
                prev = 5;
            }
            else {
                res -= 5;
                prev = 5;
            }
            break;
        case 'I':
            if (1 >= prev) {
                res += 1;
                prev = 1;
            }
            else {
                res -= 1;
                prev = 1;
            }
            break;
        default:
            break;
        };
    }
    printf("%d", res);
    return 0;
}
