#ifndef LIFE_H
#define LIFE_H
#include <stdio.h>
#include <stdlib.h>
#define ROWS 25
#define COLUMNS 40

void fileInput(char fileName[], char thisGeneration[ROWS][COLUMNS]);

void getCurrentGeneration(char thisGeneration[ROWS][COLUMNS],
	int number_of_neighbors[ROWS][COLUMNS]);

int * number_of_neighbors(char lives[ROWS][COLUMNS]);

char * calculateNextGeneration(char thisGeneration[ROWS][COLUMNS],
	int number_of_neighbors[ROWS][COLUMNS]);

char displayGrid(char lives[ROWS][COLUMNS]);

char * switchGenerations(char thisGeneration[ROWS][COLUMNS],
	char nextGeneration[ROWS][COLUMNS]);

#endif