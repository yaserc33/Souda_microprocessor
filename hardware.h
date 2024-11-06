#ifndef hardware_h
#define hardware_h


extern int run ;    //run mode flag


void execute(int lines, int instruction_memory[lines][8], int mode);
void mapper(int instruction[8]);
short alu(short a, short b, int op);       




#endif