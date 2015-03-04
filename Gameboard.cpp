
#include<iostream>
#include<string>
#include<iomanip>
#include<cstring>
#include "Gameboard.h"

using std::cout;
using std::endl;



/*********************************************************************
 * Function: Gameboard::Gameboard()
 *
 * Description: Default class constructor
 *
 * Input: None
 *
 * Output: None
 * ******************************************************************/

Gameboard::Gameboard()
{}


/*********************************************************************
 * Function: Gameboard::Gameboard(int rows, int cols)
 *
 * Description: Class constructor
 *
 * Input: Assigns initial value to variables in class
 *
 * Output: None
 * ******************************************************************/

Gameboard::Gameboard(int rows, int cols)
{
	array[25][55];
	row = rows;
	col = cols;
}


/*********************************************************************
 * Function: char Gameboard::setBlankArray()
 *
 * Description: Sets the array back to a "blank" state by assigning
 * each coordinate on the 2d array a '.' character.
 *
 * Input: None
 *
 * Output: Returns a 2d array
 * ******************************************************************/

char Gameboard::setBlankArray()
{
	for(int i = 0; i < 25; i++)
	{
		for(int k =0; k < 55; k++)
			array[i][k] = '.';
	}

	return array[25][55];
}


/*********************************************************************
 * Function: void Gameboard::setRow(int rows)
 *
 * Description: Set function to set the private variable "row" to the
 * value passed in the interger "rows" from the main function.
 *
 * Input: Accepts integer value as parameter
 *
 * Output: Sets the value of the private variable "row"
 * ******************************************************************/

void Gameboard::setRow(int rows)
{
	row = rows;
}



/*********************************************************************
 * Function: void Gameboard::setCol(int cols)
 *
 * Description: Set function to set the private variable "col" to the
 * value passed in the interger "cols" from the main function.
 *
 * Input: Accepts integer value as parameter
 *
 * Output: Sets the value of the private variable "col"
 * ******************************************************************/

void Gameboard::setCol(int cols)
{	
	col = cols;
}



/*********************************************************************
 * Function: void Gameboard::displayArray()
 *
 * Description: Prints the current contents of the private 2d array
 * to the screen.
 *
 * Input: None
 *
 * Output: Prints private 2d array to screen
 * ******************************************************************/

void Gameboard::displayArray()
{
	for(int i = 5; i < 20; i++)
	{
		for(int k = 5; k < 50; k++)
			cout << array[i][k];
		cout << endl;
	}
}


/*********************************************************************
 * Function: void Gameboard::oscillatorStart()
 *
 * Description: Assigns a character 'O' to specific coordinates of
 * the private 2d array, creating the user's chosen pattern.Coordinates
 * are private class variables.
 *
 * Input: None
 *
 * Output: Prints the current state of the private 2d array
 * ******************************************************************/

void Gameboard::oscillatorStart()
{

	array[row][col] = 'O';
	array[row][col - 1] = 'O';
	array[row][col + 1] = 'O';

	for(int i = 5; i < 20; i++)
	{
		for(int k = 5; k < 50; k ++)
			cout << array[i][k];
		cout << endl;
	}
}



/*********************************************************************
 * Function: void Gameboard::gliderStart()
 *
 * Description: Assigns a character 'O' to specific coordinates of
 * the private 2d array, creating the user's chosen pattern.Coordinates
 * are specific class variables.
 *
 * Input: None
 *
 * Output: Prints the current state of the private 2d array
 * ******************************************************************/


void Gameboard::gliderStart()
{
	array[row -1][col] = 'O';
	array[row][col +1] = 'O';
	array[row +1][col -1] = 'O';
	array[row+1][col] = 'O';
	array[row +1][col +1] = 'O';

	for(int rows = 5; rows < 20; rows++)
	{
		for(int cols = 5; cols < 50; cols++)
			cout << array[rows][cols];
		cout << endl;
	}
}


/*********************************************************************
 * Function: void Gameboard::gunStart()
 *
 * Description: Assigns a character 'O' to specific coordinates of
 * the private 2d array, creating the user's chosen pattern.
 *
 * Input: None
 *
 * Output: Prints the current state of the private 2d array
 * ******************************************************************/

void Gameboard::gunStart()
{

/* Creating the left block pattern */
	array[10][6] = 'O';
	array[10][7] = 'O';
	array[11][6] = 'O';
	array[11][7] = 'O';

/* Creating the right block pattern */
	array[8][40] = 'O';
	array[8][41] = 'O';
	array[9][40] = 'O';
	array[9][41] = 'O';

/* Creating the left hive pattern */
	array[8][19] = 'O';
	array[8][18] = 'O';
	array[9][17] = 'O';
	array[9][21] = 'O';
	array[10][16] = 'O';
	array[10][22] = 'O';
	array[11][16] = 'O';
	array[11][7] = 'O';
	array[11][22] = 'O';
	array[11][23] = 'O';
	array[11][20] = 'O';
	array[12][16] = 'O';
	array[12][22] = 'O';
	array[13][17] = 'O';
	array[13][21] = 'O';
	array[14][18] = 'O';
	array[14][19] = 'O';

/* Creating the right ship pattern */
	array[6][30] = 'O';
	array[7][30] = 'O';
	array[7][28] = 'O';
	array[8][26] = 'O';
	array[8][27] = 'O';
	array[9][26] = 'O';
	array[9][27] = 'O';
	array[10][26] = 'O';
	array[10][27] = 'O';
	array[11][30] = 'O';
	array[11][28] = 'O';
	array[12][30] = 'O';

	for(int rows = 5; rows < 20; rows++)
	{
		for(int cols = 5; cols < 50; cols++)
			cout << array[rows][cols];
		cout << endl;
	}

}



/*********************************************************************
 * Function: void Gameboard::updateArray()
 *
 * Description: Function goes through each coordinate on a 2d array.
 * At each coordinate the function checks eight surrounding coordinates.
 * If the coordinate is assigned 'O' the function adds one to integer
 * "neighbors." The function then assigns a '.' or 'O' character to
 * a second array based on the value stored in "neighbors." After all
 * coordinates have been checked, the contents of the second 2d array
 * are assigned to the private class 2d array, updating the game board.
 *
 * Input: None
 *
 * Output: Assigns new values to private variable array
 * ******************************************************************/

void Gameboard::updateArray()
{
	int neighbors;
	char boardTwo[25][55];

	for(int rows = 0; rows < 25; rows++)
	{
		for(int cols = 0; cols < 55; cols++)
			boardTwo[rows][cols] = '.';
	}

/* Checking eight surrounding cells for an alive cells and counting alive cells found */
	neighbors = 0;
	for(int rows = 0; rows < 25; rows++)
	{
		for(int cols =0; cols < 55; cols++)
		{
			if(array[rows -1][cols] == 'O')		//top
				neighbors = neighbors +1;
			if(array[rows +1][cols] == 'O') 	//bottom
				neighbors = neighbors +1;
			if(array[rows][cols- 1] == 'O')		// left
				neighbors = neighbors +1;
			if(array[rows][cols +1] == 'O')		// right
				neighbors = neighbors +1;
			if(array[rows -1][cols -1] == 'O') 	//Upper left
				neighbors = neighbors +1;
			if(array[rows +1][cols -1] == 'O') 	// Lower left
				neighbors = neighbors +1;
			if(array[rows -1][cols +1] == 'O') 	//Upper right
			 	neighbors = neighbors +1;
			if(array[rows +1][cols +1] == 'O') 	// lower right
				neighbors = neighbors +1;

/* Filling in, one cell at a time, the new board so the cells in the main board are not changing, thus altering results of the next cell */		
			if(neighbors < 2 || neighbors > 3)
			{
				if(array[rows][cols] == 'O')
					boardTwo[rows][cols] = '.';
			}
			if(neighbors == 2)
			{
				if(array[rows][cols] == 'O')
					boardTwo[rows][cols] = 'O';
			}
			if(neighbors == 3)
				boardTwo[rows][cols] = 'O';

			neighbors = 0;

		}
	}

	for(int rows =0; rows < 25; rows++)
	{
		for(int cols = 0; cols < 55; cols++)
			array[rows][cols] = boardTwo[rows][cols];
	}

}
