#include "pdp.h"

extern Arg ss, dd;

int test_mem()
{
    address a;
    byte b0, b1, bres;
    word w, wres;

	
    // пишем байт, читаем байт
    fprintf(stderr, "\n Пишем и читаем байт по четному адресу\n");
    a = 0;
    b0 = 0x12;
    b_write(a, b0);
    bres = b_read(a);
	
	//отладочная печать
	printf("a = %hhx  |||  b0 = %hhx  |||  bres = %hhx \n", a, b0, bres);
	
    fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0, bres);
    assert(b0 == bres);
    // аналогично стоит проверить чтение и запись по нечетному адресу

	
    // пишем слово, читаем слово
    fprintf(stderr, "Пишем и читаем слово\n");
    a = 2;        // другой адрес
    w = 0x3456;
    w_write(a, w);
    wres = w_read(a);
    //отладочная печать
	printf("a = %x  |||  w = %x  |||  wres = %x \n", a, w, wres);
	
    fprintf(stderr, "a=%06o w=%04x wres=%04x\n", a, w, wres);
    assert(w == wres);
	
	
	// работа с нечетным адресом 
    // пишем 2 байта, читаем 1 слово
    fprintf(stderr, "Пишем 2 байта, читаем слово\n");
    a = 3;        // другой адрес
    w = 0xa1b2;
    // little-endian, младшие разряды по меньшему адресу
    b0 = 0xb2;
    b1 = 0xa1;
    b_write(a-1, b0);
	//wres = w_read(a-1);
	//printf("\n%d ||||||||", wres);
    b_write(a, b1);
    wres = w_read(a-1);
    // тут полезно написать отладочную печать a, w, wres
    fprintf(stderr, "a=%06o b1=%02hhx b0=%02hhx wres=%04x \n", a, b1, b0, wres);
    assert(w == wres);
	
	
	//пишем слово, читаем 2 байта
	a = 4;
	w = 0x1234;
	
	byte bres0 = 0x34;
	byte bres1 = 0x12;
	
	w_write(a, w);
	b0 = b_read(a);
	b1 = b_read(a+1);
	Log(TESTS, "пишем слово, чиатем 2 байта\n");
	Log(TESTS, "a=%06o b1=%02hhx b0=%02hhx wres=%04x \n", a, b1, b0, w);
	assert(b0 == bres0);
	assert(b1 == bres1);
	
	return 0;
}

// тест, что мы правильно определяем команды mov, add, halt
void test_parse_mov()
{
    Log(INFO, "%s\n", __FUNCTION__);
	
    Command cmd = parse_cmd(0017654);
	assert(1 == 0);
	//Log(INFO, "%s", cmd.name);
    assert(strcmp(cmd.name, "mov"));
    Log(INFO, "\n ... OK\n");
}
// тест, что мы разобрали правильно аргументы ss и dd в mov R5, R3
void test_mode0()
{
    Log(INFO, "%s\n", __FUNCTION__);
    reg[3] = 12;    // dd
    reg[5] = 34;    // ss
    Command cmd = parse_cmd(0010503);     
	cmd.do_func();
    assert(ss.val == 34);
    assert(ss.adr == 5);
    assert(dd.val == 12);
    assert(dd.adr == 3);
    Log(INFO, "\n ... OK\n");
}
// тест, что mov и мода 0 работают верно в mov R5, R3
void test_mov()
{
    Log(INFO, "%s\n", __FUNCTION__);
    reg[3] = 12;    // dd
    reg[5] = 34;    // ss
    Command cmd = parse_cmd(0010503);
    cmd.do_func();
    assert(reg[3] = 34);
    assert(reg[5] = 34);
    Log(INFO, "\n ... OK\n");
}
