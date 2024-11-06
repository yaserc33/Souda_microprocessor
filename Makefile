#Target : Dependency
FILENAME=fibonacci.asm
run: assemble


simulate:assemble
	./soudaSim  $(FILENAME).asm

assemble:compile
	./Assembler $(FILENAME).bin

compile: Assembler.c soudahSim.c
	gcc -c Assembler.c -o Assembler.o
	gcc -c soudaSim.c -o soudaSim

clean:
	rm Assembler.o Assembler
	rm soudahSim.o soudahSim



help:
	@echo -e 'Hello! Welcome to Souda Assembler & Simulator!\n'
	@echo -e 'The purpose of this software is to take an assembly code file (.asm) loaded with the instructions mentioned bellow to assemble it, generate a binary (bin) code file and pass it to the simulator\n'
	@echo -e 'The simulator will ask the user to either run the code and display the output or to run it in a line-by-line fishion to see how the code and instructions run.\n'
	@echo	---list of supported assembly instructions---
	@echo -e '\n\t1--RA=RA+RB'
	@echo -e '\t2--RB=RA+RB'
	@echo -e '\t3--RA=RA-RB'
	@echo -e '\t4--RB=RA-RB'
	@echo -e '\t5--RO=RA'
	@echo -e '\t6--RA=	immidiate'
	@echo -e '\t7--RB=	immidiate'
	@echo -e '\t8--JC=	immidiate'
	@echo -e '\t9--J=	immidiate\n\n'
	@echo -e 'Usage:\n\n'
	@echo -e '---TARGET:DEPENDENCY'
	@echo -e '1--compile:Assemble.c soudahSim.c\t\t=>Complile the C files into object files'
	@echo -e '2--assemble:compile\t\t\t\t=>Assemble the file only, using the FILENAME as an input'
	@echo -e '3--simulate:assemble\t\t\t\t=>Use the OUTPUT.bin file from the assembly and simulate the program'
	@echo -e '4--run:simulate\t\t\t\t\t=>run the whole program'
	@echo -e '5--clean:\t\t\t\t\t=>remove all the files created by this Makefile'
	@echo -e '6--help:\t\t\t\t\t=>Display information about the Makefile and how to use it'

	@echo	-e '\nThis project has been built by Eng.YasirQx & Eng.Raid as a submission to the first project for the Chip design training program provided by ChipXPRT\n\n'