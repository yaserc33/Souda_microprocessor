#ifndef filio_h
#define filio_h

extern char dir[50];  // <dir> of file.bin
extern int run ;    //run mode flag


short length_bin_file();
void load_bin_file(int lines, int instruction_memory[lines][8]);
short run_mode();



#endif
