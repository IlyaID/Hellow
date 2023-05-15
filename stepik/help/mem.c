#include "pdp.h"

word mem[MEMSIZE];

word reg[8];    //регистры R0, R1, ..., R7

Arg ss, dd;

byte b_read(address adr)
{
	byte b_res;
	
	if ((adr & 1) == 0)
		b_res = (byte)(mem[adr]);
	else
		b_res = (byte)(mem[adr-1] >> 8);
	
	return b_res;
}

void b_write(address adr, byte val)
{
	if ((adr & 1) == 0)
		mem[adr] = (word)val;
	else
		mem[adr-1] |= (((word)val) << 8);
}

void w_write(address adr, word val)
{
	if (adr < 8)                           //не в память должно записываться, а в регистр
		reg[adr] = val;
	else
	{
		assert((adr & 1) == 0);
		mem[adr] = val;	
	}
}

word w_read(address adr)
{
	assert((adr & 1) == 0);
	return mem[adr];
}





void load_data(char *name_file)
{
	address adr_in_mem = 0;
	unsigned char N = 0;
	
	FILE *data_file = NULL;
	
	if (strcmp(name_file, "console") == 0)
		data_file = stdin;
	else
	{
		data_file = fopen(name_file, "r");
		
		if (data_file == NULL)
		{
			perror("\nError, can't open the file\n");
			exit(1);
		}
	}
	
	while (fscanf(data_file, "%hx %hhx", &adr_in_mem, &N) == 2)  
	{
		for (unsigned char i = 0; i < N; i++)
		{
			byte num;
			
			if (1 != fscanf(data_file, "%hhx", &num))
			{
				Log(ERROR, "Error type reading\n");
				exit(3);
			}	
			
			b_write(adr_in_mem, num);
			
			adr_in_mem++;
		}
	}
}



void mem_dump(address adr, unsigned int size)
{
	for (unsigned int i = 0; i < size/2; i++)
	{
		word res = w_read(adr);
		
		Log(INFO, "%06o: %06o %04x\n", adr, res, res);
		adr += 2;
	}
}


void clear_mem()
{
	memset(mem, 0, sizeof(mem));
}