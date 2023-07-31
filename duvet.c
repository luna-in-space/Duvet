//TODO: add a way to visualize spreadsheet
//TODO: before doing that, make it possible to see which cells have data in them
#include"cell.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define ROWS 20
#define COLUMNS 20 

//define ANSI escape codes, these are there to make certain output in different colors, so the output is more readable
#define ANSI_COLOR_MAGENTA "\x1b[38;2;255;85;151m" //hex 0xff5597
#define ANSI_COLOR_RESET   "\x1b[0m"

cell cellsArray[ROWS * COLUMNS];
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
		int activeCell = cellPicker(activeRow, activeColumn);
//	printf("%d", activeCell); /*just making sure cellPicker works*/
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
	
	cleanupCells();
	}

	return 0;
}
