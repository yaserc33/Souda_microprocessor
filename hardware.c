#include "hardware.h" 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 



short regA = 0;
short regB = 0;
short reg0 = 0;
short imm_value;
short carry = 0;
short overflow = 0;
int  pc  = 0;    // Program counter






// Main execution loop for the simulator
void execute(int lines, int instruction_memory[lines][8], int mode) {
    

    while (pc < lines) {
        int *instruction = instruction_memory[pc];
        
        // Decode and execute the current instruction
        mapper(instruction);
        
        if (mode == 2) {
            printf("\n~~~~~~~~~~~~~~~~~~~~~status~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("reg A= %x | reg B= %x | reg o= %x | imm= %x | pc= %x | carry= %x || overflow= %x \n",regA,regB,reg0,imm_value,pc,carry,overflow);
            printf("Press enter to continue...");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"); 
            while (getchar() != '\n'); // Wait for user in step-by-step mode

        }
        
        // Increment program counter
    }
    printf("\n\n\n\nend of the file exiting the simulator...\n");
}



// Decode and execute a single 8-bit instruction
void mapper(int instruction[8]) {
    int J = instruction[0];       // Leftmost bit
    int C = instruction[1];
    int D1 = instruction[2];
    int D0 = instruction[3];
    int Sreg = instruction[4];
    int S = instruction[5];
    imm_value = (instruction[5] << 2) | (instruction[6] << 1) | instruction[7];  // Immediate value (last 3 bits)


   
    // Each case corresponds to one of these instructions:
    if (J == 1) {
        pc = imm_value;
        alu(0,0,0); 
        if(run == 2) printf("Unconditional Jump to %d\n", imm_value);

    } 

    else if (C == 1 && J == 0) {
        // JC = imm (Conditional Jump if carry set)
            if (carry == 1){
                pc = imm_value;
                alu(0,0,0);   
                if(run == 2)  printf("Conditional Jump to %d if carry\n", imm_value);
            }else{
                if(run == 2)  printf("No Conditional Jump \n");
                pc++;
             }

        
    }

    else if (J == 0 && C == 0 && D1 == 0 && D0 == 0 && Sreg == 0 && S==0 ) {
        // RA =RA + RB
        regA = alu(regA, regB, 0);
        regA &= 0xF;  // Ensure reg is within 4-bit range
        if(run == 2) printf("RA = RA + RB :: RA = %d\n", regA);
        ++pc;

    }

    else if (J == 0 && C == 0 && D1 == 0 && D0 == 1 && Sreg == 0 && S==0 ) {
        // RB= RA + RB
        regB = alu(regA, regB, 0);
        regB &= 0xF;  // Ensure reg is within 4-bit range
        if(run == 2) printf("RB = RA + RB :: RB = %d\n", regB);
        ++pc;
    
    }

    else if (J == 0 && C == 0 && D1 == 0 && D0 == 0 && Sreg == 0 && S == 1) {
        // RA = RA - RB
        regA = alu(regA, regB, 1);
        regA &= 0xF;  // Ensure reg is within 4-bit range
        if(run == 2) printf("RA = RA - RB :: RA = %d\n", regA);
        ++pc;
    }

    else if (J == 0 && C == 0 && D1 == 0 && D0 == 1 && Sreg == 0 && S == 1) {
        // RB = RA - RB
        regB = alu(regA, regB, 1);
        regB &= 0xF;  // Ensure reg is within 4-bit range
        if(run == 2) printf("RB = RA - RB :: RB = %d\n", regB);
        ++pc;
    }


    else if (J == 0 && C == 0 && D1 == 1 && D0 == 0 && Sreg == 0 && S== 0) {
        // RO = RA
        reg0 = regA;
        if (run == 1) {
            printf("%d ", reg0);
        } else {
            printf("RO = RA :: RO = %d\n", reg0);  
          }
        ++pc; 
    }
    else if (J == 0 && C == 0 && D1 == 0 && D0 == 0 && Sreg == 1) {
        // RA = imm
        regA = imm_value;
        if(run == 2 ) printf("RA = imm :: RA = %d\n", regA);
        ++pc;
    }
    else if (J == 0 && C == 0 && D1 == 0 && D0 == 1 && Sreg == 1) {
        // RB = imm
        regB = imm_value;
        if(run == 2 ) printf("RB = imm :: RB = %d\n", regB);
        ++pc;
    }
}


//ALU
short alu(short a, short b, int op) {
    carry = 0;        // Reset carry and overflow 
    overflow = 0;
    int result;

    if (op == 0) {
        
        result = a + b;
        carry = (result > 15);       // Carry set if sum exceeds 4-bit limit
        result &= 0xF;
        
        

        // Set overflow flag if there's a signed overflow
        overflow = ((a & 0x8) == (b & 0x8)) && ((a & 0x8) != (result & 0x8));
    } 
    else {
        // Subtraction (a - b)
        result = a - b;

        // Set carry (borrow) flag for subtraction
        carry = (result < 0);        // Borrow if result is negative
        result = (result + 16) & 0xF;
        

        // Set overflow flag if there's a signed overflow
        overflow = ((a & 0x8) != (b & 0x8)) && ((a & 0x8) != (result & 0x8));
    }
    
    return result;
}
