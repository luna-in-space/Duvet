//TODO: add a way to visualize spreadsheet
//TODO: before doing that, make it possible to see which cells have data in them
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
	char* charData;
	int  numberData;
	int isChar;
	} cell;

cell cellsArray[ROWS * COLUMNS];

void freeCellMemory(int cellIndex){
		free(cellsArray[cellIndex].charData);	
		cellsArray[cellIndex].charData = NULL;
		return;
}
int cellpicker(int row, int column){

	int activeCell = ((column-1) + (row -1) *COLUMNS);

	return activeCell;
}

void cellModifier(int activeCell){
	char numOrChar;
	char charInput[32];
	int intInput;

	printf("Would you like to put (N)umber data or (C)haracter data:");
	scanf(" %c", &numOrChar);

	switch(numOrChar){
		case 'N':
		case 'n':
		printf("Input your data:");
			scanf("%d", &intInput);
			cellsArray[activeCell].numberData = intInput; 
			cellsArray[activeCell].isChar = 0; //suggestion: it may be smarter to do this with boolean, and just do [isChar = true or false]
		break;
		
		case 'C':
		case 'c':
		printf("Input your data:");
				scanf("%31s", charInput);
		cellsArray[activeCell].charData = strdup(charInput);
		cellsArray[activeCell].isChar = 1; //used for cellReader to know what data is in the cell
		break;

		default:
		printf("Invalid choice, please input either N or C\n");
		break;
	}

	return;
	}

void cellReader(int activeCell){
	if (cellsArray[activeCell].isChar == 0){
		printf("the cell contains the integer "ANSI_COLOR_MAGENTA" %d\n"ANSI_COLOR_RESET, cellsArray[activeCell].numberData);
	}
		else{
		printf("the cell contains the label " ANSI_COLOR_MAGENTA "%s\n" ANSI_COLOR_RESET, cellsArray[activeCell].charData);	
		}
		return;
}
int main(void){
	int activeRow;
	int activeColumn;
	for(int i = 0; i < ROWS * COLUMNS; i++){
		cellsArray[i].charData = malloc(32 * sizeof(char)); //Allocates 32 bytes of memory for character data per cell
		cellsArray[i].charData = NULL;
	}
	while(1){
	printf("Choose your row (1-%d), or 0 to quit:", ROWS);
		scanf("%d", &activeRow);
	if(activeRow == 0){
		break;
	}
	if(activeRow < 1 || activeRow > ROWS) {
		printf("Not a valid row, please choose a row between 1 and %d\n", ROWS);
		continue;
	}
	printf("Choose your column(1-%d)", COLUMNS);
		scanf("%d", &activeColumn);
	
	if(activeColumn < 1 || activeColumn > COLUMNS) {
		printf("Not a valid column, please choose a column between 1 and %d\n", COLUMNS);
		continue;
	}
		int activeCell = cellpicker(activeRow, activeColumn);
//	printf("%d", activeCell); /*just making sure cellpicker works*/
	char modifyOrRead; 
	printf("What would you like to do? (M)odify value/(R)ead value");
	scanf(" %c", &modifyOrRead);
		modifyOrRead = tolower(modifyOrRead);
			if (modifyOrRead != 'm' && modifyOrRead != 'r'){

			fprintf(stderr, "error, must enter m or r\n");
				return -1;
				break;
			}
			else if (modifyOrRead == ('m')){
			cellModifier(activeCell);
			
			}
			else{ 
				cellReader(activeCell);
				}
	}
	for (int i = 0; i < ROWS * COLUMNS; i++){
	freeCellMemory(i);
	}

	return 0;
}
