#include "gameOfLifeHeader.h"
#include <string.h>
#include <ctype.h>

// ---------------------------------------------------------------------------
//	Function:		displayGrid
//
//	Title:			Game of Life Output Grid
//
//	Description:	This function outputs the current generation in the
//						Game of Life program to the standard output.  It
//						prompts the user to progress to the next generation
//						and clears the screen.
//
//	Programmer:		David Landry
//
//	Date:			Monday 11/30/2015
//
//	Version:		1.0.0
//
// Environment:
//					Hardware:	Dell Studio XPS 435 T;
//								Intel Core i7 920 CPU @ 2.67 GHz;
//								24,576 MB RAM
//
//					Software:	Windows 10 64-bit version
//								Compiled using Microsoft Visual Studio
//									Community 2013
//
//	Input:			User presses enter to clear screen and move to the next
//						generation.
//	
//	Output:			A 40x25 grid of characters (type char) representing the
//						current generation.  Live "people" are represented by
//						an asterisk character (*).  Spaces not containing live
//						people are represented simply by a space ( ).
//
//	Parameters:		lives[][], a 2-dimensional array representing the
//						coordinates of each "life".
//
//	Returns:		Enter to continue, 'q' to quit.
//
//	Called by:		Main
//
//	Calls:			None
//
//	History Log:	0.1.0	11/24/2015
//								The function has been started with this header
//								block.
//					0.2.0	11/25/2015
//								The grid display has been implemented.
//					0.5.0	11/30/2015
//								The user is given the option to continue to
//								the next generation (enter) or quit (q).
//					1.0.0	12/2/2015
//								The function was implemented into the main
//								function.  The option to reset the program
//								(r) was added.
// ---------------------------------------------------------------------------
char displayGrid(char lives[ROWS][COLUMNS])
{
	int cols = 0;				/* Initialize column counter	*/
	int rows = 0;				/* Initialize row counter		*/
	char characterPress = ' ';	/* Input to continue or quit.	*/
	// The outer for loop moves from row to row.
	for (rows = 0; rows < ROWS; rows++)
	{
		// The inner for loop fills each row with an appropriate character.
		for (cols = 0; cols < COLUMNS; cols++)
		{
			printf("%c", lives[rows][cols]);
		}
		printf("\n");
	}
	// After going through each row, prompt the user to continue to the next
	// generation (by pressing enter) or quit (by pressing q).
	printf("\nPress any key to continue to the next generation");
	printf(" (or q to quit, r to reset).");
	characterPress = tolower(getch());
	return characterPress;
}
