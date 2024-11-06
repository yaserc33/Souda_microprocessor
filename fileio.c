#include "fileio.h" 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 




// Reads the number of lines in the binary file
short length_bin_file() {
    printf("\n         Welcome to our Simulator\n");
    printf("-----------Souda Microprocessor-------------\n");
    printf("\nloading %s ... \n",dir);
    

    FILE *file = fopen(dir, "r");  
    if (file == NULL) {
        perror("\n\nUnable to find the file");
        exit(1);
    }

    int linecount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') linecount++;
    }

    fclose(file);
    return linecount;
}

// oppen .bin 
void load_bin_file(int lines, int instruction_memory[lines][8]) {
    FILE *binfile = fopen(dir, "r");  
    if (binfile == NULL) {
        perror("\n\nUnable to find the file");
        exit(1);
    }

    //load each line in .bin file into -:: instruction_memory[][]
    char linebuffer[10];  // Buffer (8 bits + newline + null terminator)
    for (int i = 0; i < lines; i++) {
        if (fgets(linebuffer, sizeof(linebuffer), binfile) != NULL) {
            for (int j = 0; j < 8; j++) {
                instruction_memory[i][j] = linebuffer[j] - '0';  // Convert '0', '1' to 0, 1
            }
        }
    }
    
    fclose(binfile);
}

// ask user for running mode: line by line or normal
short run_mode() {
    char ch;
    printf("\n-----------Select Running Mode-------------\n");
    printf("r : to run the code\n");
    printf("s : to run the code line by line\n");

    while (1) {
        printf("Enter Mode (r or s): ");
        scanf(" %c", &ch);  
        while (getchar() != '\n');  // Clear any leftover characters in the buffer

        if (ch == 'r' || ch == 'R') {
            printf("\n------executing the file in Continuous mode --------\n\n"); 
            return 1;  
        }
        if (ch == 's' || ch == 'S') {
            printf("\n------executing the file in Step-by-step mode------\n\n"); 
            return 2;   
        }
        printf("Invalid choice, please try again!\n");
    }
}

