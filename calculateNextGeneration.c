#include "gameOfLifeHeader.h"

char * calculateNextGeneration(char thisGeneration[ROWS][COLUMNS],
	int number_of_neighbors[ROWS][COLUMNS])
{

	int neighbor, columns, rows;
	char nextGeneration[ROWS][COLUMNS];

	for (rows = 0; rows < ROWS; rows++)
	{
		for (columns = 0; columns < COLUMNS; columns++)
		{
			neighbor = number_of_neighbors[rows][columns];
			if (neighbor == 3)
			{
				nextGeneration[rows][columns] = '*';
			}
			else if (neighbor == 2 && thisGeneration[rows][columns] == '*')
			{
				nextGeneration[rows][columns] = '*';
			}
			else
			{
				nextGeneration[rows][columns] = ' ';
			}
		}
	}
	return nextGeneration;
}
