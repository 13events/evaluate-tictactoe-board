#include "pch.h"
#include "Board.h"

/// <summary>	Default constructor, sets Board to starting state. </summary>
///
/// <remarks>	Jose, 9/28/2018. </remarks>

Board::Board()
{

	player = 'x';
	opponent = 'o';

	////fill in the board with 1-9
	//int number = 49;
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		board[i][j] = number;
	//		number++;
	//	}
	//}

	//print();

	/*markSpace(0, 0, true);
	std::cout << "Modified board: \n";
	print();
	std::cout << "BoardState: \n";
	print();*/

	

}

void Board::print()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j]  << "|";
		}
		std::cout << "\n";
	}

}

void Board::markSpace(int row, int col, char symbol)
{
	board[row][col] = symbol;
	
}

/// <summary>	Gets the board. </summary>
///
/// <remarks>	Jose, 9/28/2018. </remarks>
///
/// <returns>	Null if it fails, else the array representing the board. </returns>

std::array<std::array<char,3>, 3> Board::getBoard()
{
	return this->board;

}

