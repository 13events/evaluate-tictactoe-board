
#pragma once
#include "Board.h"

class Game {
	private:
		Board board;
		char player, opponent;

	public: 
		Game();
		Game(bool prebuiltBoard);
		bool isMovesLeft();
		int evaluate();
		int minimax(int depth, bool isMax);
		Move findBestMove();

};