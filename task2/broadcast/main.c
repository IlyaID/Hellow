#include <stdio.h>

int main() {

    unsigned int ip[4] = {}, mask[4] = {};
    scanf("%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
    scanf("%hhu.%hhu.%hhu.%hhu", &mask[0], &mask[1], &mask[2], &mask[3]);

    printf("%hhu.%hhu.%hhu.%hhu", ip[0] | (~mask[0]),
                             ip[1] | (~mask[1]),
                                 ip[2] | (~mask[2]), 
                                    ip[3] | (~mask[3]));
    

    return 0;
}