/*Ширина (бит)	Признак	Возможные значения	Условные сокращения
1	пол	1 - male, 0 - female		ma, fe
1	умный	1 - clever, 0 - dummy		cl, du
1	шляпа	1 - hat, 0 - without hat		ha, nh
1	брюки-юбка	1 - trousers, 0 - skirt		tr, sk
2	цвет волос	00 - blonde, 01 - red, 10 - brown, 11 - black	bn, rd, bw,bk
2	цвет глаз	00 - blue, 01 - green, 10 - gray, 11 - dark	bu, ge, gy, da
*/







#include <stdio.h>

int main() {

    int a = 0;
    scanf("%x", &a);
    const char* data[6][4] = {{"fe", "ma", "0", "0"},
                        {"du", "cl" , "0", "0"},
                        {"nh", "ha", "0", "0"},
                        {"sk", "tr", "0", "0"},
                        {"bn", "rd" , "bw", "bk"},
                        {"bu", "ge" , "gy", "da"}};
    for(int i = 0; i < 6; i++) {
        int res = 0;
        if(i < 4) {
            res = (a & (1 << (i))) >> i;
        }
        else if(i == 4) {
            res = (a & (3 << (i))) >> (i);
        }
        else {
            res = (a & (3 << (6))) >> (6);
        }
        printf("%s ", data[i][res]);
    }
    
    return 0;
    }