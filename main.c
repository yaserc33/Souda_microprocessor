#include <string.h>
#include "fileio.h"
#include "hardware.h"

char dir[50];  // <dir> of file.bin
int run ;    //run mode flag


int main(int argc, char *argv[]) {


    // Copy the  filename into dir
    strcpy(dir, argv[1]);

    //<fileio.c>  get how many line in   
    int lines_in_bin = length_bin_file();
    
    //declare instructuinon memory 
    int ins_memory[lines_in_bin][8];


    // <fileio.c> load file.bin into instructuinon memory array 
    load_bin_file(lines_in_bin, ins_memory);
    

    run = run_mode(); //<fileio.c>  2 for line-by-line, 1 for continuous run
    
    
    // <hardware.c> excute the instructions in ins_memory
    execute(lines_in_bin, ins_memory, run);
    
    return 0;
}