#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

#define MEMSIZE (64*1024)
#define SIZE 100
#define pc reg[7]
#define REG_SIZE 8

typedef unsigned char byte;
typedef unsigned short int word;
typedef word address;

typedef struct {
	word mask;
	word opcode;
	char *name;
	void (*do_func)(void);
} Command;

typedef struct {
    word val;     // значение (что)
    address adr;    // адрес (куда)
} Arg;

enum level{
	DEBUG,
	TRACE,
	TESTS,
	INFO,
	ERROR
};

void b_write (address adr, byte val);
byte b_read (address adr);

void w_write (address adr, word val);
word w_read (address adr);

void load_data(char *name_file);
void mem_dump(address adr, unsigned int size);

void Log(unsigned int level, char *str, ...);
unsigned int set_log_level(unsigned int level);

void run();

void do_halt();
void reg_dump();
void do_mov();
void do_add();
void do_unknown();

Arg get_mr(word w);

Command parse_cmd(word w);

int test_mem();
int test_file();

void test_parse_mov();
void test_mode0();
void test_mov();

extern word reg[8];

void clear_mem();
