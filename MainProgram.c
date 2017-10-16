#include "gameOfLifeHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#pragma warning(disable: 4996) 

// ---------------------------------------------------------------------------
//	Function:		main
//
//	Programmers:	Jonathyn Komorita
//					David Landry
//					Matt Schroder
//					Steven Truong
//					Evan Wansa
//
//	Description:	This is the main function for the Game of Life project.
//					It brings together all the functions of this project into
//					one cohesive unit.
//
//	Version:		1.0.0	12/3/2015
//
//	Input:			The function receives the name of the file to be
//					processed.
//
//	Output:			The function prints out a welcome message upon loading or
//					resetting.
//
//	Parameters:		None
//
//	Returns:		EXIT_FAILURE if the user's file cannot be opened.
//					EXIT_SUCCESS when the user exits the program.
//
//	Called by:		None
//
//	Calls:			calculateNextGeneration,
//					displayGrid,
//					fileInput,
//					number_of_neighbors,
//					switchGenerations
//
//	Version History:
//			0.5.0, 12/2/2015
//					Each member of team Something Or Another contributed his
//					function to this main function.  All parts were compiled
//					together, but we are having difficulty switching from
//					current to next generation.
//			1.0.0, 12/3/2015
//					The problem of switching generations has been fixed, but
//					there is a memory bug somewhere, spilling out random
//					characters at the end of the board.  This problem will
//					be addressed in a future build.
// ---------------------------------------------------------------------------
int main(void)
{
	char thisGeneration[ROWS][COLUMNS] = { 0 };
	char nextGeneration[ROWS][COLUMNS] = { 0 };
	int neighbors[ROWS][COLUMNS] = { 0 };
	char(*thisGenPoint)[ROWS][COLUMNS] = thisGeneration;
	char(*nextGenPoint)[ROWS][COLUMNS] = nextGeneration;
	int(*neighborsPoint)[ROWS][COLUMNS] = neighbors;
	char continueOrNot = ' ';
	FILE * inFileHandle = NULL;
	char filename[FILENAME_MAX];
	puts("Welcome to the Game of Life, a colony simulator presented by");
	puts("the group Something or Another, consisting of");
	printf("Jonathyn Komorita, David Landry, Matt Schroder, Steven Truong, ");
	puts("and Evan Wansa.");
	printf("Enter the name of the file to read (source):");
	fgets(filename, FILENAME_MAX, stdin);
	if (filename[strlen(filename) - 1] == '\n')
		filename[strlen(filename) - 1] = '\0';
	else
		while (getchar() != '\n')
			;

	inFileHandle = fopen(filename, "r");
	if (inFileHandle == NULL)
	{
		printf("Could not open file %s for input.\n"
			"Press any key to Continue", filename);
		getch();
		return EXIT_FAILURE;
	}
	// Set up the board based on file input:
	fileInput(filename, thisGeneration);
	do
	{
		// Display the grid:
		continueOrNot = displayGrid(thisGenPoint);
		system("CLS");
		// If the user wants to quit, end the program right now.
		if (continueOrNot == 'q')
			return EXIT_SUCCESS;
		if (continueOrNot == 'r')
			main();

		// Calculate the number of neighbors for each square:
		neighborsPoint = number_of_neighbors(thisGeneration);
		neighborsPoint;
		neighbors;

		// Calculate the next generation.
		nextGenPoint = calculateNextGeneration(thisGenPoint, neighborsPoint);
		nextGenPoint;

		// Make the next generation the current generation.
		thisGenPoint = switchGenerations(thisGenPoint, nextGenPoint);
		thisGenPoint;

		// Continue.

	} while (continueOrNot != 'q' && continueOrNot != 'r');
}