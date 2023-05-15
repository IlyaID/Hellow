#include "pdp.h"

unsigned int log_level = TRACE;



int main(int argc, char *argv[])
{	
	test_parse_mov();
	test_mode0();
	test_mov();
	
	if (argc == 1)
	{
		Log(INFO, "\nData will read from console, if you want read from file, please, write -t and name of file after ./a.out, to break writting enter q\n");
		load_data("console");
	}
	else if (strcmp(argv[1],"-t") == 0)
		load_data(argv[argc-1]);
	else
		Log(INFO, "\nIncorrect program launch\n");
	
	// if (TESTS >= log_level)
		// Log(TESTS, "Test!\n", test_mem());
	
	
	
	run();
	
	clear_mem();
	
    return 0;
}





void Log(unsigned int level, char *str, ...)
{
	if (level >= log_level)
	{
		va_list ap;
		va_start(ap, str);
		
		vprintf(str, ap);	
		
		va_end(ap);
	}
}

unsigned int set_log_level(unsigned int level)
{
	unsigned int old_log = log_level;
	
	log_level = level;
	
	return old_log;
}







int test_file()
{
	load_data("TryBreakPDP.txt");
	mem_dump(64, 4);
	
	return 0;
}