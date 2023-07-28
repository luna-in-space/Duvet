#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define ROWS 20
#define COLUMNS 20 
//define ANSI escape codes, these are there to make certain output in different colors, so the output is more readable
#define ANSI_COLOR_MAGENTA "\x1b[38;2;255;85;151m" //hex 0xff5597
#define ANSI_COLOR_RESET   "\x1b[0m"
typedef struct cell{
	int id;
	char* charData;
	int  numberData;
	int charOrNum;
	} cell;

cell cellsArray[400];


int cellpicker(int row, int column){

	int activeCell = ((column + (row -1) *20));

	return activeCell;
}

void cellModifier(int activeCell){
	char numOrChar;
	char* charInput[32];
	int intInput;

	printf("Would you like to put (N)umber data or (C)haracter data:");
	scanf(" %c", &numOrChar);

	switch(numOrChar){
		case 'N':
		case 'n':
		printf("case n");
		printf("Input your data:");
			scanf("%d", &intInput);
			cellsArray[activeCell].numberData = intInput; 
			cellsArray[activeCell].charOrNum = 1; //suggestion: it may be smarter to do this with boolean, and just do [isChar = true/false]
		break;
		
		case 'C':
		case 'c':
		printf("case c");
		printf("Input your data:");
				scanf("%s", &charInput);
		cellsArray[activeCell].charData = charInput;
		cellsArray[activeCell].charOrNum = 0; //used for cellReader to know what data is in the cell
		break;

		default:
		printf("not case n or c");
		break;
	}

	return;
	}

void cellReader(int activeCell){
	printf("the cell contains the integer"ANSI_COLOR_MAGENTA" %d\n"ANSI_COLOR_RESET, cellsArray[activeCell].numberData);
		return;
}
int main(void){
	int activeRow;
	int activeColumn;
	for(int i = 0; i < 400; i++){
		cellsArray[i].id = i;
		cellsArray[i].charData = malloc(32 * sizeof(char)); //gives every cell a unique identifier, and allocates 32 bytes of memory for character data per cell
	}
	while(1){
	printf("Choose your row:");
		scanf("%d", &activeRow);
	printf("Choose your column:");
		scanf("%d", &activeColumn);
		int activeCell = cellpicker(activeRow, activeColumn);
//	printf("%d", activeCell); /*just making sure cellpicker works*/
	char modifyOrRead; 
	printf("What would you like to do? (m)odify value/(r)ead value/(q)uit program: ");
	scanf(" %c", &modifyOrRead);
		modifyOrRead = tolower(modifyOrRead);
			if (modifyOrRead != 'm' && modifyOrRead != 'r' && modifyOrRead != 'q'){

			fprintf(stderr, "error, must enter m or r\n");
				return -1;
			}
			else if (modifyOrRead == ('m')){
			cellModifier(activeCell);
			
			}
			else if (modifyOrRead == ('q')){
				break;
			}
			else{ 
				cellReader(activeCell);
				}
	}

	for(int i = 0; i < 400; i++) {
		free(cellsArray[i].charData);	
	}
	return 0;
}
