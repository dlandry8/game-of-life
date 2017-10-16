#include "gameOfLifeHeader.h"




int * number_of_neighbors(char lives[ROWS][COLUMNS]) 
{
	int neighbor[ROWS][COLUMNS] = { 0 };
	int columns = 0;
	int rows = 0;

	for (rows = 0; rows < ROWS; rows++)
	{
		for (columns = 0; columns < COLUMNS; columns++)
		{
			if (rows > 0 && columns > 0)
				neighbor[rows][columns] += getNeighborValue(lives, rows - 1, columns - 1);
			if (rows > 0)
			{
				neighbor[rows][columns] += getNeighborValue(lives, rows - 1, columns);
				if (columns < COLUMNS - 1)
					neighbor[rows][columns] += getNeighborValue(lives, rows - 1, columns + 1);
			}
			if (columns > 0)
			{
				neighbor[rows][columns] += getNeighborValue(lives, rows, columns - 1);
				if (rows < ROWS - 1)
					neighbor[rows][columns] += getNeighborValue(lives, rows + 1, columns - 1);
			}
			if (columns < COLUMNS - 1)
				neighbor[rows][columns] += getNeighborValue(lives, rows, columns + 1);
			if (rows < ROWS - 1)
				neighbor[rows][columns] += getNeighborValue(lives, rows + 1, columns);
			if ((rows < (ROWS - 1)) && (columns < (COLUMNS - 1)))
				neighbor[rows][columns] += getNeighborValue(lives, rows + 1, columns + 1);
		}
	}
	return neighbor;
}

int getNeighborValue(char lives[ROWS][COLUMNS], int rows, int columns)
{
	if (lives[rows][columns] == ' ')
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}
