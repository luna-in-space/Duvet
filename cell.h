#ifndef CELL_H
#define CELL_H

#define ROWS 20
#define COLUMNS 20
typedef struct cell{
        char* charData;
        int  numberData;
        int isChar;
} cell;
extern cell cellsArray[ROWS * COLUMNS]; //This array must be declared as extern, or the program will not compile properly

void initCells();
void freeCellMemory(int cellIndex);
void cleanupCells();
void cellModifier(int activeCell);
void cellReader(int activeCell);
int cellPicker(int row, int column);

#endif //CELL_H
