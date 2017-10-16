//----------------------------------------------------------------------
// File: fileInput.c
//
// Functions: fileIntput(char fileName[], char thisGeneration[][])
//----------------------------------------------------------------------
#include "gameOfLifeHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#pragma warning(disable: 4996) 
#define ROWS 25
#define COLUMNS 40
//----------------------------------------------------------------------
// Function: fileIntput(char fileName[], char thisGeneration[ROWS][COLUMNS])
//
// Title: File Input
//
// Description: This file contains the fileInput function. fileInput 
//	takes the input from a file, breaks it down character by character
//	and loads it into a 2d character array that it is passed
//
// Programmer: Matthew Schroder
//
// Date: 11/30/2015
// Version: 1.0
//
// Environment:
// Hardware: Intel Xeon PC
// Software: MS Windows 7 for execution;
// Compiles under Microsoft Visual Studio 2013
//
// Input: accepts .txt text file from user specified location along with a 
//	two-dimensional character array which it will alter with the contents
//	of the file and the size of both the rows and columns of the array
//
// Output: No output -- changes the array it is given directly
//
// Called By: main()
//
// Parameters:
//  char fileName[] -- a string containing the input txt file name
//	char thisGeneration[][] -- a 2-d character array that will be 
//		filled with the contents from the file
//
// Returns: void
//
// History Log:
//	11/30/2015: MTS completed ver 1.0
//----------------------------------------------------------------------

void fileInput(char fileName[], char thisGeneration[ROWS][COLUMNS])
{

	FILE * inFileHandle = fopen(fileName, "r"); //open the file
	
	char c = ' ';
	int i = 0;
	int x = 0;
	for (i = 0; i < ROWS; i++) //loop through the array by rows
	{
		for (x = 0; x < COLUMNS; x++)  //loop through the array by columns
		{
			c = fgetc(inFileHandle);  //pull out each character from the file
			if (c != '\n')
				thisGeneration[i][x] = c; //load it into the array
			else
				x -= 1;  //if there is a newline, skip it and go back the the index of the array that would have been skipped
		}
	}
	fclose(inFileHandle); //close the file
}