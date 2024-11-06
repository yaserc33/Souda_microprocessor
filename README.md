# Souda Microprocessor Simulator and Assembler

This project provides a simulator and assembler for a 4-bit custom processor. It features two primary registers, **A** and **B**, and an **Arithmetic Logic Unit (ALU)** capable of handling basic arithmetic operations. 


For more information on the  processor architecture and specifications, refer to the document **P1 K2 Assembler.pdf**.




### List of supported assembly instructions
---
        1--RA=RA+RB
        2--RB=RA+RB
        3--RA=RA-RB
        4--RB=RA-RB
        5--RO=RA
        6--RA=  immidiate
        7--RB=  immidiate
        8--JC=  immidiate
        9--J=   immediate




### Key Components
---
- **assemblerV2.c**: Translates microprocessor assembly instructions to binary machine code, generating `.bin` files.
- **fileio.c / fileio.h**: Manages file operations for loading binary files and handling input/output.
- **hardware.c / hardware.h**: Simulates the  microprocessor's ALU, registers, and control logic.
- **main.c**: Simulator’s main loop, allowing users to execute instructions in continuous or step-by-step mode.
- **Makefile**: Automates the build process, offering commands for assembling, simulating, cleaning, and help.





### Usage
---
1. Running the Assembler
The assembler converts assembly code written in assembly language into binary machine code.

```bash
./assembler <assembly_file.asm>
```
Example:
```bash  
./assembler fibonacci.asm
```


2. Running the Simulator
The simulator executes the binary file, simulating the Souda microprocessor's behavior.

```bash
./simulator <binary_file.bin>
```   
Example:
```bash
./simulator fibonacci.bin
```




### running mode
---

When running the simulator, you'll be prompted to choose an execution mode:

Continuous mode (R): Runs all instructions without interruption.

Step-by-step mode (S): Pauses after each instruction, allowing you to observe the state changes interactively.





### Makefile Commands
---


        make help
  to display usage instructions.


        make FILENAME=(you_file_name)
  to run the whole program by compiling it, linking it, assembling it and simulating it (FILE MUST BE IN DIRECTORY AND MUST BE WITHOUT EXTENSION).
        
        make assemble FILENAME=(your_file_name.asm)
  to assemble a .asm file into a .bin file (MUST BE IN SAME DIRECTORY).
        
        make simulate FILENAME=(your_file_name.bin)
  to simulate a bin file and display the output (MUST BE IN THE SAME DIRECTORY).







## Acknowledgments

This simulator and assembler were developed as part of the CX-202: Problem Solving Skills using C course project. Special thanks to Dr. Abid Rafique and Qamar Moavia for project guidance and support.

