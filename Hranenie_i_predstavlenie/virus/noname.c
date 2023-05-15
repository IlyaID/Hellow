/*
Недалёкое будущее. У Вас оказалось nanobots нанороботов, каждый из которых имеет свой номер (нумерация начинается с 0) и программу. 
Известно, что virused из них заражены нановирусом для нанороботов (говорят, что автор пользовался для написания исходного кода этого вируса текстовым редактором nano).
 Нановирус размножается по такому алгоритму: если он работает на нанороботе номер X, то он заражает нанороботов 
 с номерами X*2, X*3+1, X*4+3, X*5+6... (при каждом заражении разница номеров между подряд идущими заражёнными увеличивается на 1). 
 С вновь заражённых нанороботов вирус уже никуда не распространяется (см. ответ к примеру). И теперь нужно подсчитать: сколько же у Вас заражённых нанороботов?

Входные данные

1 ≤ virused ≤ 102 - количество изначально заражённых,

1 ≤ nanobots ≤ 108 - общее количество нанороботов,

далее virused чисел - номера заражённых нанороботов.

Выходные данные

1 число - количество заражённых нанороботов.



*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int virused, nanobots, nano_virused[100000];
  scanf("%d", & virused);
  scanf("%d", & nanobots);
  for (int i = 0; i < virused; ++i) {
    int x;
    scanf("%d", & x);
    for (int j = x; x < nanobots; x += j++) {
      nano_virused[x] = 1;
    }

  }
  int sch = 0;
  for (int i = 0; i < nanobots; ++i) {
    if (nano_virused[i] == 1)
      sch++;

  }
  printf("%d", sch);
  return 0;
}