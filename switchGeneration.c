#include "gameOfLifeHeader.h"

char * switchGenerations(char thisGeneration[ROWS][COLUMNS], char nextGeneration[ROWS][COLUMNS])
{
	int height;
	int width;

	for (width = 0; width < ROWS; width++) 
	{
		for (height = 0; height < COLUMNS; height++)
			thisGeneration[width][height] = nextGeneration[width][height];
	}
	return thisGeneration;
}
