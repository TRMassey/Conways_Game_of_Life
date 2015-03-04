#include "functions.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;


/*********************************************************************
 * Function: int displayMenu()
 *
 * Description: Prints menu choices for user and prompts for user input.
 * Receives the user's menu choice, uses a validation function, and
 * returns a valid choice to the main function.
 *
 * Input: User inputs a menu choice as a string
 *
 * Output: Prints menu choices. Returns the user's menu choice as an
 * integer to the main function.
 * ******************************************************************/

int displayMenu()
{
	string choice;
	bool truth;
	int numChoice;

	cout << "Please choose a starting pattern from the following options: " << endl;
	cout << "1.   The Simple Oscillator" << endl;
	displayOscillator();
	cout << endl;
	cout << "2.   The Glider" << endl;
	displayGlider();
	cout << endl;
	cout << "3.   The Gosper Glider Gun" << endl;
	displayGun();
	cout << endl;
	cout << endl << "Or type 4 to exit the program: " << endl;
	getline(cin, choice);
	truth = switchValidation(choice);
	while(truth == false)
	{
		cout << "Please choose a valid number from 1 - 4: " << endl;
		getline(cin, choice);
		truth = switchValidation(choice);
	}
	numChoice = atoi(choice.c_str());

	addLines();

return numChoice;
}


/*********************************************************************
 * Function: void displayOscillator
 *
 * Description: Prints a simple oscillator pattern on a 3x3 2d array.
 *
 * Input: None
 *
 * Output: Prints pattern to screen.
 * ******************************************************************/

void displayOscillator()
{
	char display[3][3];

/* Initialize the starting array by creating an empty game board */
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
			display[row][col] = '.';
	}

/* Fill int he shape pattern */
	for(int row = 1; row <2; row++)
	{
		for(int col = 0; col < 3; col++)
			display[row][col] = 'O';
	}

/* Print the pattern */
	cout << endl;
	for(int row = 0; row < 3; row++)
	{
		for(int col =0; col < 3; col++)
			cout << display[row][col];
		cout << endl;
	}
}


/*********************************************************************
 * Function: void displayGlider()
 *
 * Description: Prints a simple glider pattern on a 3x3 2d array.
 *
 * Input: None
 *
 * Output: Prints pattern to screen.
 * ******************************************************************/

void displayGlider()
{

	char display[3][3];

/* Initialize the starting array by ccreating  an empty game board */
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
			display[row][col] = '.';
	}

/* Fill in the starting pattern */
	display[0][1] = 'O';
	display[1][2] = 'O';
	for(int row = 2; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
			display[row][col] = 'O';
	}

/* Print the completed pattern */
	cout << endl;
	for(int row = 0; row < 3; row++)
	{
		for(int col =0; col < 3; col++)
			cout << display[row][col];
		cout << endl;
	}
}


/*********************************************************************
 * Function: void displayGun()
 *
 * Description: Prints a glider gun pattern on a 10x26 2d array.
 *
 * Input: None
 *
 * Output: Prints pattern to screen.
 * ******************************************************************/

void displayGun()
{

	char display[10][26];

/* Initialize the arry by creating an empty game board */
	for(int row = 0; row < 10; row++)
	{
		for(int col = 0; col < 26; col++)
			display[row][col] = '.';
	}

/* Fill in four shapes to create the pattern */

// Left block
	display[5][0] = 'O';
	display[5][1] = 'O';
	display[6][0] = 'O';
	display[6][1] = 'O';

// Right block
	display[2][24] = 'O';
	display[2][25] = 'O';
	display[3][24] = 'O';
	display[3][25] = 'O';

// Left Hive
	display[3][7] = 'O';
	display[3][8] = 'O';
	display[4][6] = 'O';
	display[4][10] = 'O';
	display[5][5] = 'O';
	display[5][11] = 'O';
	display[6][5] = 'O';
	display[6][9] = 'O';
	display[6][11] = 'O';
	display[6][12] = 'O';
	display[7][5] = 'O';
	display[7][11] = 'O';
	display[8][6] = 'O';
	display[8][10] = 'O';
	display[9][7] = 'O';
	display[9][8] = 'O';

// Right Ship
	display[0][19] = 'O';
	display[1][19] = 'O';
	display[1][17] = 'O';
	display[2][15] = 'O';
	display[2][16] = 'O';
	display[3][15] = 'O';
	display[3][16] = 'O';
	display[3][20] = 'O';
	display[4][15] = 'O';
	display[4][16] = 'O';
	display[5][19] = 'O';
	display[5][17] = 'O';
	display[6][19] = 'O';
	
/* Print thte completed pattern */
	cout << endl;
	for(int row = 0; row < 10; row++)
	{
		for(int col =0; col < 26; col++)
			cout << display[row][col];
		cout << endl;
	}
}



/*********************************************************************
 * Function: void addLines()
 *
 * Description: Prints 50 lines of black space to clear the screen
 *
 * Input: None
 *
 * Output: Prints 50 blank lines to the screen
 * ******************************************************************/

void addLines()
{
	for(int i = 0; i < 50; i ++)
		cout << endl;
}



/*********************************************************************
 * Function: bool switchValidation(string userChoice)
 *
 * Description: Checks a string from the user for validity. Checks for
 * each character being a digit, converts the string to an integer, and
 * checks to make suer the integer is in an acceptable range.
 *
 * Input: Function accepts a string for validation
 *
 * Output: Returns false if the string has anything but a digit. Returns
 * false if the converted iteger is out of range. Otherwise, returns
 * true.
 * ******************************************************************/

bool switchValidation(string userChoice)
{
	int asNum;

	for(int i = 0; i < userChoice.length(); i++)
	{
		if(!(isdigit(userChoice.at(i))))
			return false;
	}

	asNum = atoi(userChoice.c_str());

	if(asNum > 4 || asNum < 1)
		return false;
	else
		return true;

}


/*********************************************************************
 * Function: bool coordValidation(string row, string col)
 *
 * Description: Checks two strings from the user for validity. Checks for
 * each character being a digit, converts the string to an integer, and
 * checks to make suer the integer is in an acceptable range.
 *
 * Input: Function accepts a string for validation
 *
 * Output: Returns false if the string has anything but a digit. Returns
 * false if the converted iteger is out of range. Otherwise, returns
 * true.
 * ******************************************************************/

bool coordValidation(string row, string col)
{
	int numRow;
	int numCol;

	for(int i = 0; i < row.length(); i++)
	{
		if(!(isdigit(row.at(i))))
			return false;
	}

	for(int i = 0; i < col.length(); i++)
	{
		if(!(isdigit(col.at(i))))
			return false;
	}

	numRow = atoi(row.c_str());
	numCol = atoi(col.c_str());

	if(numRow < 0 || numRow > 14)
		return false;
	if(numCol < 0 || numCol > 44)
		return false;
	else
		return true;
}

/*********************************************************************
 * Function: bool iterationValidation(string times)
 *
 * Description: Checks a string from the user for validity. Checks for
 * each character being a digit.
 *
 * Input: Function accepts a string for validation
 *
 * Output: Returns false if the string has anything but a digit.
 * Otherewise, returns true.
 * ******************************************************************/

bool iterationsValidation(string times)
{
	int numTimes;

	for(int i = 0; i < times.length(); i++)
	{
		if(!(isdigit(times.at(i))))
			return false;
	}

	numTimes = atoi(times.c_str());

	if(numTimes == 0)
		return false;	

	return true;
}

