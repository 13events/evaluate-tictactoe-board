#include "pch.h"
#include "Board.h"

/// <summary>	Default constructor, sets Board to starting state. </summary>
///
/// <remarks>	Jose, 9/28/2018. </remarks>

Board::Board()
{
	//fill in the board with 1-9
	int number = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = number;
			number++;
		}
	}
}

void Board::print()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j] << "|";
		}
		std::cout << "\n";
	}
}

/// <summary>	Gets the board. </summary>
///
/// <remarks>	Jose, 9/28/2018. </remarks>
///
/// <returns>	Null if it fails, else the array representing the board. </returns>

char * Board::getBoard()
{
	return *this->board;
}

int Board::evaluate(char b[3][3])
{
	//check rows for 'x' or 'o' victory
	for (int row = 0; row < 3; row++) {
		if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
			if (b[row][0] == 'x')
				return +10;
			if (b[row][0] == 'o')
				return -10;
		}
	}

	//check columns for 'x' or 'o' victory
	for (int col = 0; col < 3; col++) {
		if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
			if (b[0][col] == 'x')
				return +10;
			if (b[0][col] == 'o')
				return -10;
		}
	}

	//check diagonals for 'x' or 'o' victory
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
		if (b[0][0] == 'x')
			return +10;
		if (b[0][0] == 'o')
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
		if (b[0][2] == 'x')
			return +10;
		if (b[0][2] == 'o')
			return -10;
	}
	
	//else return 0 if tie.
	return 0;
}
