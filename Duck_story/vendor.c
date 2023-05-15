#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    scanf("%d", &a);
    a = a ^ 0x756E6547 ^ 0x68747541;
    a = a ^ 0x49656E69 ^ 0x69746E65;
    a = a ^ 0x6C65746E ^ 0x444d4163;
    printf("%d", a);
    return 0;
}