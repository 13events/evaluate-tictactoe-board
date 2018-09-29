#pragma once
#include <iostream>
#define N 3

/// <summary>	A board object representing a tic tac toe board with 9 squares (3 x 3) </summary>
///
/// <remarks>	Jose, 9/28/2018. </remarks>

class Board {
	private:
		char board[3][3];
	public:
		Board();
		void print();
		char * getBoard();
		static int evaluate(char b[3][3]);

};
