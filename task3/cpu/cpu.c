/*
Рассмотрим 8-битный процессор, который может обрабатывать элементарные команды, получая их на вход в виде кодов.

Числа считаются беззнаковыми.

HLT (0) - останов

ADD (1) - сложение

SUB (2) - вычитание

У этих команд аргументы - 2 номера регистров, результат записывается в первый из них.

MOV (3) - присвоение

Аргументы - номер регистра и целое число, которое в него заносится.

IR (4) - вывести все регистры

Регистры и их номера: A (5), B (6), C (7), D (8).

До начала работы программы в регистрах нули.

К сожалению, некоторые чипы получаются с дефектами. У них меньше регистров. В таком случае через параметр -D (аналог #define) при компиляции программе передаётся константа REGISTERS. В таком случае допустимы лишь некоторые из них. Если встретился регистр, которого у данного дефектного чипа нет, то нужно завершить работу эмулятора, выведя число -1, что означает недопустимый номер регистра. Например, если константа REGISTERS определена и её значение равно 2, то допустимы только регистры A и B с кодами 5 и 6 соответственно, а команда 1 6 7 (прибавить к B значение регистра С) приведёт к ошибке Illegal Instruction и в данном эмуляторе нужно вывести -1.

Что будет выведено в результате работы программы? 

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef REGISTERS
#define REGISTERS 4
#endif //REGISTERS
 
int main() {
    uint_least8_t REG[REGISTERS] = { 0, 0, 0, 0};
    if (REGISTERS > 4){
        printf("-1");
        return 0;
    }

    unsigned int input = 0;
    scanf("%u", &input);
        while (input != 0){
            scanf("%u", &input);
            if( input == 3){
                scanf("%u", &input);
                if (input - 5 >= REGISTERS) {
                    printf("-1");
                    return 0;
                }
                unsigned int tmp = input - 5;
                scanf("%u", &input);
                REG[tmp] = input;
                continue;
            }
            if( input == 1){
                scanf("%u", &input);
                if (input - 5 >= REGISTERS) {
                    printf("-1");
                    return 0;
                }
                unsigned int tmp = input - 5;
                scanf("%u", &input);
                if (input - 5 >= REGISTERS) {
                    printf("-1");
                    return 0;
                }
                REG[tmp] += REG[input - 5];
                continue;
            }
            if( input == 2){
                scanf("%u", &input);
                if (input - 5 >= REGISTERS){
                    printf("-1");
                    return 0;
                }
                unsigned int tmp = input - 5;
                scanf("%u ", &input);
                if (input - 5 >= REGISTERS){
                    printf("-1");
                    return 0;
                }
                REG[tmp] -= REG[input - 5];
                continue;
            }
            if (input == 4){
                for (unsigned int i = 0; i < REGISTERS; i++){
                    printf("%d ", REG[i]);
                }
                printf("\n");
                continue;
            }


        }
}

 
 
