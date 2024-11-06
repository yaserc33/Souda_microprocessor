#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char* chrFileNameInput[]){
	char	chrBuff[10];
	char	chrBuffOp[2];
	char	chrBuff2[20];
	char	chrBuffForOp[20];

	FILE *ptrSourceFile;
	FILE *ptrDestinationFile;

	int	intJ		=0;
	int	intC		=0;
	int	intD1		=0;
	int	intD0		=0;
	int	intSreg		=0;
	int 	intMinus	=0;
	int	intLiteralDigit2=0;
	int	intLiteralDigit1=0;
	int	intLiteralDigit0=0;

	char	*chrDestinationFileName;
	char	*chrSourceFileName;
	char	*chrFileName;

	chrFileName = strtok(chrFileNameInput[1],".");
	chrSourceFileName=strcat(chrFileName,".asm");
	printf("Source File is: %s\n",chrSourceFileName);

	ptrSourceFile=fopen(chrSourceFileName,"r");
	if(ptrSourceFile==NULL){
		printf("ERROR!! COULD NOT FIND THE SOURCE FILE %s\n",chrSourceFileName);
		return 1;
	}

        chrFileName = strtok(chrFileNameInput[1],".");
	chrDestinationFileName=strcat(chrFileName,".bin");
	printf("Output File is: %s\n",chrDestinationFileName);


	ptrDestinationFile=fopen(chrDestinationFileName,"w");
	if(ptrSourceFile==NULL){
		printf("ERROR!! AN ISSUE OCCURED WHILE OPENING THE DESTINATION FILE\n");
		return 1;
	}


	while(fgets(chrBuff,sizeof(chrBuff),ptrSourceFile)!=NULL){
                for(int a=0;a<sizeof(chrBuff)-1;a++){
                        if(chrBuff[a]!='\n'){
				chrBuff2[a]=chrBuff[a];

			}
			else{
				break;
			}
		}
		strcpy(chrBuffForOp,chrBuff2);
		char* line = strtok(chrBuffForOp,"=");
		line=strtok(chrBuffForOp,"-");
		while(line !=NULL){
			chrBuffOp[0]=line[0];
			chrBuffOp[1]=line[1];
			line=strtok(NULL,"+");
		}
		int m=0;
		while(chrBuff2[m]!='='){
			m++;
		}
		if(toupper(chrBuff2[m+1])=='R'){
			intSreg=0;
			if(chrBuff2[m+3]=='+'){
				intLiteralDigit2=0;
			}
			else if(chrBuff2[m+3]=='-'){
				intLiteralDigit2=1;
			}
			else if(chrBuff2[m+3]==NULL){
                                if      (toupper(chrBuffOp[1])=='A'){
                                        printf("INVALID INPUT!");
					return 1;
                                }
                                else if (toupper(chrBuffOp[1])=='B'){
                                        printf("INVALID INPUT!");
					return 1;
                                }
                                else if (toupper(chrBuffOp[1])=='O'){
                                        intD1   =1;
                                        intD0   =0;
                                        intJ    =0;
                                        intC    =0;
                                }
                                else{
                                        printf("INVALID INPUT!");
                                        return 1;
                                }

			}
			else{
				printf("INVALID INPUT!");
				return 1;
			}
		}
		else if((int)chrBuff2[m+1]>47 &&(int)chrBuff2[m+1]<56){
			intSreg=1;
			switch ( (int)chrBuff2[m+1] ){
				case 48:
					intLiteralDigit2=0;
					intLiteralDigit1=0;
					intLiteralDigit0=0;
					break;
                                case 49:
                                        intLiteralDigit2=0;
                                        intLiteralDigit1=0;
                                        intLiteralDigit0=1;
                                        break;

                                case 50:
                                        intLiteralDigit2=0;
                                        intLiteralDigit1=1;
                                        intLiteralDigit0=0;
                                        break;

                                case 51:
                                        intLiteralDigit2=0;
                                        intLiteralDigit1=1;
                                        intLiteralDigit0=1;
                                        break;

                                case 52:
                                        intLiteralDigit2=1;
                                        intLiteralDigit1=0;
                                        intLiteralDigit0=0;
                                        break;

                                case 53:
                                        intLiteralDigit2=1;
                                        intLiteralDigit1=0;
                                        intLiteralDigit0=1;
                                        break;

                                case 54:
                                        intLiteralDigit2=1;
                                        intLiteralDigit1=1;
                                        intLiteralDigit0=0;
                                        break;

                                case 55:
                                        intLiteralDigit2=1;
                                        intLiteralDigit1=1;
                                        intLiteralDigit0=1;
                                        break;
				default:
					printf("INVALID INPUT!");
					return 1;
			}

		}
		else{
			printf("INVALID INPUT!");
			return 1;
		}
			if(toupper(chrBuffOp[0])=='R'){
				if	(toupper(chrBuffOp[1])=='A'){
					intD1	=0;
					intD0	=0;
					intJ	=0;
					intC	=0;
				}
				else if	(toupper(chrBuffOp[1])=='B'){
					intD1	=0;
					intD0	=1;
					intJ	=0;
					intC	=0;
				}
				else if	(toupper(chrBuffOp[1])=='O'){
					intD1	=1;
					intD0	=0;
					intJ	=0;
					intC	=0;
				}
				else{
					printf("INVALID INPUT!");
					return 1;
				}
			}
			else if(toupper(chrBuffOp[0])=='J'){
				 if(chrBuffOp[1]==NULL){
					intD1	=0;
					intD0	=0;
					intJ	=1;
					intC	=0;
				}
				else if(toupper(chrBuffOp[1])=='C'){
					intD1	=0;
					intD0	=0;
					intJ	=0;
					intC	=1;
				}
				else{
					printf("INVALID INPUT!");
					return 1;
				}
			}
                        fprintf(ptrDestinationFile,"%d%d%d%d%d%d%d%d\n",intJ,intC,intD1,intD0,intSreg,intLiteralDigit2,intLiteralDigit1,intLiteralDigit0);
	}
fclose(ptrSourceFile);
fclose(ptrDestinationFile);
return 0;
}

