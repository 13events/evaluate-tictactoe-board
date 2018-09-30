#pragma once
#include <iostream>
#include <vector>
#include <array>
#define N 3

/// <summary>	A board object representing a tic tac toe board with 9 squares (3 x 3) </summary>
///
/// <remarks>	Jose, 9/28/2018. </remarks>

struct Move {
	int row, col;
};


class Board {
	private:
		
			char player, opponent;
	public:
		std::array<std::array<char, 3>, 3> board;
		Board();
		void print();
		void markSpace(int row, int col, char symbol);
		std::array<std::array<char,3>,3> getBoard();
		 
		

};
