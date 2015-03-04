/********************************************************
 * Filename: Gameboard.h
 * Author: Tara Massey
 * Date: 01/15/2015
 *
 * Purpose: Declare class Gameboard
 *
*********************************************************/

#ifndef MASSEYTA_GAMEBOARD_H
#define MASSEYTA_GAMEBOARD_H


class Gameboard
{
	private:
		char array[25][55];
		int row;
		int col;
	public:
		Gameboard();
		Gameboard(int rows, int cols);
		char setBlankArray();
		void setRow(int rows);
		void setCol(int cols);
		void displayArray();
		void oscillatorStart();
		void gliderStart();
		void gunStart();
		void updateArray();
};

#endif
