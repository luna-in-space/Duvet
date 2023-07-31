#include"cell.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


//define ANSI escape codes, these are there to make certain output in different colors, so the output is more readable
#define ANSI_COLOR_MAGENTA "\x1b[38;2;255;85;151m" //hex 0xff5597
#define ANSI_COLOR_RESET   "\x1b[0m"

void cellInit(){
	for(int i = 0; i < ROWS * COLUMNS; i++){
		cellsArray[i].charData = NULL;
		cellsArray[i].charData = malloc(32 * sizeof(char)); //Allocates 32 bytes of memory for character data per cell
	}
}

void freeCellMemory(int cellIndex){
	cellsArray[cellIndex].charData = NULL;
	free(cellsArray[cellIndex].charData);
}

void cleanupCells(){
	for (int i = 0; i < ROWS * COLUMNS; i++) {
		freeCellMemory(i);
	}
}

void cellModifier(int activeCell){
	char numOrChar;
	char charInput[32];
	int intInput;
	
	printf("Would you like to put (N)umber data or (C)haracter data: ");
	scanf (" %c", &numOrChar);

	switch (tolower(numOrChar)){
		case 'n':
		printf("Input your data: ");	
			scanf("%d", &intInput);
			cellsArray[activeCell].numberData = intInput;
			cellsArray[activeCell].isChar = 0;
		break;
		
		case 'c':
		printf("Input your data: ");
			scanf("%31s", charInput);
		cellsArray[activeCell].charData = strdup(charInput);
		cellsArray[activeCell].isChar = 1; //used for cellreader to know what kind of data is in the cell
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


int cellPicker(int row, int column){
	int activeCell = ((column-1 + row -1) * COLUMNS);
	return activeCell;
}
