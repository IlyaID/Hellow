#include <stdio.h>
 
int rtoa(int);
 
enum { NO, YES };
 
int main()
{
    int total; 
    int d;
    int next;
    int lim;
    int quit;
    int subtract;
    int buf;
    int c;
 
    lim = rtoa('M');
    total = buf = next = 0;
    subtract = quit = NO;
 
    while (quit == NO) {
        d = next;
        if ((c = getchar()) == '\n' || next == EOF) {
            next = 0;
            quit = YES;
        } else if ((next = rtoa(c)) < 0) {
            printf("incorrect symbol: %c\n", c);
            return 0;
        } else if (d == 0)
            continue;
 
        if (d >= next) {
            if (d > lim) {
                printf("incorrect order of the numerals\n");
                return 0;
            }
            lim = d;
            total += d - ((subtract == YES) ? buf : 0);
            subtract = NO;
            buf = 0;
        } else {
            if (subtract == YES) {
                printf("incorrect order of the numerals\n");
                return 0;
            }
            subtract = YES;
            buf = d;
        }
    }
    printf("arabic: %d\n", total);
    return 0;
}
    
int rtoa(int c)
{
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return -1;
    }
}