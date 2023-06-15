#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define ROWS 20
#define COLUMNS 20 

typedef struct cell{
	int id;
	char* charData;
	int  numberData;
	} cell;

cell cellsArray[400];


int cellpicker(int row, int column){

	int activeCell = ((column + (row -1) *20));

	return activeCell;
}

void cellModifier(int activeCell){
	int intInput;
	printf("input your data:");
	scanf("%d", &intInput);
	cellsArray[activeCell].numberData = intInput; 

	return;
	}

void cellReader(int activeCell){
	printf("the cell contains the integer %d\n", cellsArray[activeCell].numberData);
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

			printf("error, must enter m or r\n");
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
