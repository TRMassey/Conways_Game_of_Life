/***************************************************************************
 * Program Filename: aassignment1.cpp
 * Author: Tara Massey
 * Date: 01/15/2015
 *
 * Desription: Program creates "The Game of Life," in which the world is
 * represented by an array. In the array there are dead cells and living
 * cells. Living cells can die of loneliness, or overcrowding, based on the
 * number of living cells around them. The user is presented with three
 * starting shapes and an option to quit. The user selects the starting shape
 * and then inputs the starting location. Based off the amount of living
 * cells the shape will change for the number of specified iterations from the
 * user. The program includes a Gameboard Class and includes an additional
 * file with display and validation functions.
 *
 * Input: The user inputs their pattern selection as a string, which is
 * converted to an integer after validation. The user inputs the number of
 * iterations, and inputs ENTER to prompt the next iteration. The user inputs
 * the starting coordinates as a string, which is converted to an integer
 * after validation. The user can input '0' from the main menu to quit.
 *
 * Output: The program prints pattern selections for the user to initially
 * pick from. THe program prints prompts for the user. The program prints
 * iterations of the changing pattern.
 *
****************************************************************************/

#include "functions.h"
#include "Gameboard.h"
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<cstdlib>

using std::endl;
using std::cout;
using std::cin;

int main()
{
	int option;
	int iterations;
	int numRow;
	int numCol;
	bool truth = true;
	string clear;
	string times;
	string row;
	string col;
	Gameboard world;

	world.setBlankArray();
	cout << "THE GAME OF LIFE" << endl << endl << endl;
	cout << "This simulation allows you, the user, to watch an example of cellular automation. With each cycle, you will watch the shape change. " << endl;
	cout << endl;
	option = displayMenu();

	while(option !=0)
	{
		switch(option)
		{
			
			case 1:	cout << "Please enter the amount of cycles you'd like to witness: ";
				getline(cin, times);

				/* Validation for iterations entered */
				truth = iterationsValidation(times);
				while(truth == false)
				{
					cout << "Please enter a valid positive number: " << endl;
					getline(cin, times);
					truth = iterationsValidation(times);
				}
				iterations = atoi(times.c_str());
				addLines();

				cout << "This board represents the world " << endl << endl;
				world.displayArray();
				cout << "Please choose a row to start your shape on (0 - 14): ";
				getline(cin, row);
				cout << endl << "Please choose a column to start your shape on (0 - 44): ";
				getline(cin, col);
				
				/* Validation for coordinates entered */
				truth = coordValidation(row, col);
				while(truth == false)
				{
					cout << "Invalid Input." << endl;
					cout << "Please select a number from 0 to 14 for your row now: ";
					getline(cin, row);
					cout << "Please select a number from 0 to 44 for your column: ";
					getline(cin, col);
					truth = coordValidation(row, col);
				}
				numRow = atoi(row.c_str());
				numCol = atoi(col.c_str());
				numRow = numRow +5;
				numCol = numCol +5;
				world.setRow(numRow);
				world.setCol(numCol);
				addLines();
				
				/* Printing oscillator iterations, with user prompts */
				world.oscillatorStart();
				cout << "Please hit ENTER for next iteration" << endl;
				getline(cin, clear);
				addLines();
				for(int i = 1; i < iterations; i++)
				{
					world.updateArray();
					world.displayArray();
					cout << "Please hit ENTER for next iteration" << endl;
					getline(cin, clear);
					addLines();
				}
				addLines();
				cout << "Iterations complete!" << endl << endl;

				/* Reset the world state and return the user to the menu */
				world.setBlankArray();
				option = displayMenu();
				break;

			case 2: cout << "Please enter the amount of cycles you'd like to witness: ";
				getline(cin, times);

				/* Validation of iterations entered */
				truth = iterationsValidation(times);
				while(truth == false)
				{
					cout << "Please enter a valid positive number: " << endl;
					getline(cin, times);
					truth = iterationsValidation(times);
				}
				iterations = atoi(times.c_str());
				addLines();

				cout << "This board represents the world " << endl << endl;
				world.displayArray();
				cout << "Please choose a row to start your shape on (0 - 14): ";
				getline(cin, row);
				cout << endl << "Please choose a column to start your shape on (0 - 44): ";
				getline(cin, col);
				addLines();

				/* Validation for coordinates entered */
				truth = coordValidation(row, col);
				while(truth == false)
				{
					cout << "Invalid Input." << endl;
					cout << "Please select a number from 0 to 14 for your row now: ";
					getline(cin, row);
					cout << "Please select a number from 0 to 44 for your column: ";
					getline(cin, col);
					truth = coordValidation(row, col);
				}
				numRow = atoi(row.c_str());
				numCol = atoi(col.c_str());
				numRow = numRow +5;
				numCol = numCol +5;
				world.setRow(numRow);
				world.setCol(numCol);

				/* Printing the glider iterations, with user prompts */
				world.gliderStart();
				cout << "Please hit ENTER for next iteration" << endl;
				getline(cin, clear);
				addLines();
				for(int i =1; i < iterations; i++)
				{
					world.updateArray();
					world.displayArray();
					cout << "Please hit ENTER for next iteration" << endl;
					getline(cin, clear);
					addLines();
				}
				addLines();
				cout << "Iterations complete!" << endl << endl;

				/* Reset the world state and return the user to the menu */
				world.setBlankArray();
				option = displayMenu();
				break;

			case 3: cout << "Please enter the amount of cycles you'd like to witness: ";
				getline(cin, times);

				/* Validation of iterations */
				truth = iterationsValidation(times);
				while(truth == false)
				{
					cout << "Please enter a valid positive number: " << endl;
					getline(cin, times);
					truth = iterationsValidation(times);
				}
				iterations = atoi(times.c_str());
				addLines();
				
				/* Printing glider gun iterations, with user prompts */
				world.displayArray();
				cout << "Please hit ENTER to begin the Gosper Glider Gun iterations" << endl;
				getline(cin, clear);
				addLines();
				world.gunStart();
				cout << "Please hit ENTER for next iteration " << endl;
				getline(cin, clear);
				addLines();
				for(int i =1; i < iterations; i++)
				{
					world.updateArray();
					world.displayArray();
					cout << "Please hit ENTER for next iteration " << endl;
					getline(cin, clear);	// starts next cycle (pause button)
					addLines();
				}
				addLines();
				cout << "Iterations complete!" << endl << endl;

				/* Reset the world and return the user to the main menu */
				world.setBlankArray();
				option = displayMenu();
				break;

			case 4: cout << "Thanks for playing!" << endl;
				return 0;
		}
	}

return 0;
}

