# Souda Microprocessor Simulator and Assembler

This project provides a simulator and assembler for  a 4-bit custom processor.



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
make help: Displays usage instructions.

make assemble: Compiles the assembler only.

make simulate: Compiles the simulator only.

make all: Compiles both the assembler and simulator.

make clean: Removes compiled executables and temporary files.

make help: Displays usage instructions.



## Acknowledgments

This simulator and assembler were developed as part of the CX-202: Problem Solving Skills using C course project. Special thanks to Dr. Abid Rafique and Qamar Moavia for project guidance and support.

