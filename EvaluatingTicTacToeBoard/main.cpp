// EvaluatingTicTacToeBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.

//TODO: create an override evaluate function to take in a Board object instead.
//TODO: Add constructor override that can take in a 3x3 char array to initialize a Board object
//TODO: Add constrictor overrise that allows for declaring a new board with char arguments?
#include "pch.h"
#include <iostream>
#include "Board.h"

int main()
{
	char board[3][3] =
	{
		{ 'x', '_', 'o'},
		{ '_', 'x', 'o'},
		{ '_', '_', 'o'}
	};

	int value = Board::evaluate(board);
	std::cout << "The value of this board is " << value;

	std::getchar();
}

