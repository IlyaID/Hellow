#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%d", &n);

    int *addres = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%x", &addres[i]);
    }

    int log_res;
    scanf("%x", &log_res);

    int page_number = (log_res >> 26) & 0x3F;
    int page_off_set = log_res & 0x3FFFFFF;

    if (page_number >= n) {
        printf("error\n");
        return 0;
    }

    int fiz_res = addres[page_number] + page_off_set;
    printf("%x\n", fiz_res);

    free(addres);

    return 0;
}