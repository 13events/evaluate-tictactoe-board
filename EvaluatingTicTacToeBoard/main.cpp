// EvaluatingTicTacToeBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.

//TODO: create an override evaluate function to take in a Board object instead.
//TODO: Add constructor override that can take in a 3x3 char array to initialize a Board object
//TODO: Add constrictor overrise that allows for declaring a new board with char arguments?
#include "pch.h"
#include "Game.h"
#include <iostream>

int main()
{
	Game tictactoe = Game(true);

	Move bestMove = tictactoe.findBestMove();

	std::cout << "The best move is: \n";
	std::cout << "Row: " << bestMove.row << "\n";
	std::cout << "Col: " << bestMove.col << "\n";
	
	

	std::getchar();
}

