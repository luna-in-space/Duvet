#include<stdio.h>
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

int main(void){
	int activeRow;
	int activeColumn;
	for(int i = 0; i < 400; i++){
		cellsArray[i].id = i;
		cellsArray[i].charData = malloc(32 * sizeof(char)); //gives every cell a unique identifier, and allocates 32 bytes of memory for character data per cell
	}
	printf("Choose your row:");
		scanf("%d", &activeRow);
	printf("Choose your column:");
		scanf("%d", &activeColumn);
		int activeCell = cellpicker(activeRow, activeColumn);
//	printf("%d", activeCell); /*just making sure cellpicker works*/
	char modifyOrRead; 
	printf("What would you like to do? (m)odify value/(r)ead value: ");
	scanf(" %c", &modifyOrRead);
		modifyOrRead = tolower(modifyOrRead);
			if (modifyOrRead != ('m') && (modifyOrRead != 'r')){

			printf("error, must enter m or r\n");
				return -1;
			}
			else if (modifyOrRead == ('m')){
				printf("modify");
			}
			else{ 
					printf("read");
				}
	return 0;
}
