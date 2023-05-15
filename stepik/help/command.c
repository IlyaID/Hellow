#include "pdp.h"

extern Arg ss, dd;

Command cmd[] = {
	{0170000, 0010000, "mov", do_mov},
	{0170000, 0060000, "add", do_add},
	{0177777, 0000000, "halt", do_halt},
	{0000000, 0000000, "unknown", do_unknown}
};



void do_halt()
{
	reg_dump();
	Log(INFO, "THE END!!!\n");
	exit(0);
}

void reg_dump()
{
	Log(INFO, "r0:%o r1:%o r2:%o r3:%o r4:%o r5:%o r6:%o r7:%o\n", reg[0], reg[1], reg[2], reg[3], reg[4], reg[5], reg[6], reg[7]);
}



void do_mov() 
{
	w_write(dd.adr, ss.val);
}
void do_add() 
{
	w_write(dd.adr, ss.val + dd.val);
}
void do_unknown(){}






void run()
{
	pc = 01000;         //program counter
	
	while (1)
	{
		word w = w_read(pc);
		
		Log(INFO, "%06o %06o : ", pc, w);
		pc += 2;
		
		for (unsigned int i = 0;; i++)
		{
			if ((w & cmd[i].mask) == cmd[i].opcode)
			{
				Log(INFO, cmd[i].name);
				
				Log(INFO, "\n");
				
				dd = get_mr(w);
				ss = get_mr(w >> 6);     //убрать dd для определения ss
				
				cmd[i].do_func();

				break;
			}
		}
	}
}


Arg get_mr(word w)
{
    Arg res;
    
	int r = w & 7;          // номер регистра
	int m = (w >> 3) & 7;
	
	switch (m) {
    // мода 0, R1
    case 0:
        res.adr = r;        // адрес - номер регистра
        res.val = reg[r];   // значение - число в регистре
        Log(TRACE, "R%d ", r);
        break;


    // мода 1, (R1)
    case 1:
        res.adr = reg[r];           // в регистре адрес
        res.val = w_read(res.adr);  // по адресу - значение
        Log(TRACE, "(R%d) ", r);
        break;


    // мода 2, (R1)+ или #3
    case 2:
        res.adr = reg[r];           // в регистре адрес
        res.val = w_read(res.adr);  // по адресу - значение
        reg[r] += 2;                // TODO: +1
        // печать разной мнемоники для PC и других регистров
        if (r == 7)
            Log(TRACE, "#%o ", res.val);
        else
            Log(TRACE, "(R%d)+ ", r);
        break;


    // мы еще не дописали другие моды
    default:
        Log(ERROR, "Mode %d not implemented yet!\n", m);
        exit(1);
	}
	
    return res;
}


Command parse_cmd(word w)
{
	for (unsigned int i = 0;; i++)
	{
		if ((w & cmd[i].mask) == cmd[i].opcode)
		{
			Log(INFO, cmd[i].name);
				
			dd = get_mr(w);
			ss = get_mr(w >> 6);     //убрать dd для определения ss
				
			cmd[i].do_func();
				
			Log(INFO, "\n");

			return cmd[i];
		}
	}
}

