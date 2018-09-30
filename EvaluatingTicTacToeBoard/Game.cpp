#include "pch.h"
#include "Game.h"
#include <algorithm>


Game::Game()
{
	
	this->player = 'x';
	this->opponent = 'o';
}

Game::Game(bool prebuiltBoard)
{
	this->player = 'x';
	this->opponent = 'o';

	board.markSpace(0, 0, player);
	board.markSpace(0, 1, opponent);
	board.markSpace(0, 2, player);
	
	board.markSpace(1, 0, opponent);
	board.markSpace(1, 0, opponent);
	board.markSpace(1, 0, player);

	board.markSpace(2, 0, '_');
	board.markSpace(2, 1, '_');
	board.markSpace(2, 2, '_');
}

bool Game::isMovesLeft()
{
	std::array<std::array<char,3>,3> boardState = board.getBoard();

	//Debug code
	/*std::cout << "The board state in 'isMovesLeft': \n";
	for (auto i = boardState.begin(); i != boardState.end(); i++) {
		for (auto j = i->begin(); j != i->end(); j++) {
			std::cout << *j << "|";
		}
		std::cout << "\n";
	}*/

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (boardState[i][j] != 'x' || boardState[i][j] != 'o')
				//Debug
				//std::cout << "Moves Left: True";
				return true;
		}
	}
	//Debug
	//std::cout << "Moves Left: False";
	return false;
}

int Game::evaluate()
{
	//get board state
	std::array<std::array<char, 3>, 3> boardState = board.getBoard();

	boardState[0][0];
	//check for row 'x' or 'o' victory
	for (auto row = 0; row < boardState.size(); row++) {
		if (boardState[row][0] == boardState[row][1] && boardState[row][1] == boardState[row][2]) {
			if (boardState[row][0] == 'x') {
				return +10;
			}
			else if (boardState[row][0] == 'o')
				return -10;
		}
	}

	//check columns for 'x' or 'o' victory
	for (int column = 0; column < boardState.size(); column++) {
		if (boardState[0][column] == boardState[1][column] && boardState[1][column] == boardState[2][column]) {
			if (boardState[0][column] == 'x')
				return +10;
			else if (boardState[0][column] == 'o')
				return -10;
		}
	}

	//check diagonals
	if (boardState[0][0] == boardState[1][1] && boardState[1][1] == boardState[2][2]) {
		if (boardState[0][0] == 'x')
			return +10;
		else if (boardState[0][0] == '0')
			return -10;

	}

	if (boardState[0][2] == boardState[1][1] && boardState[1][1] == boardState[2][0])
		if (boardState[0][2] == 'x')
			return +10;
		else if (boardState[0][2] == 'o')
			return -10;

	//return nothing if none have won
	return 0;
}

int Game::minimax(int depth, bool isMax)
{
	//get board state
	std::array<std::array<char, 3>, 3> boardState = board.getBoard();
	int score = evaluate();
	

	//if maximizer has won the game, return their evaluated score
	if (score == 10) {
		return score;
	}

	//if Minimizer has won the game, return their evaluated score
	if (score == -10) {
		return score;
	}

	//if there are no more moves and no winner, then declare tie
	if (isMovesLeft() == false) {
		return 0;
	}

	//if this is maximizers move
	if (isMax) {
		int best = -1000;
		
		//traverse all cells
		for (int i = 0; i < boardState.size(); i++) {
			for (int j = 0; j < boardState.size(); j++) {
				//check if cell is empty
				if (boardState[i][j] != 'x' || boardState[i][j] != 'o') {
					
					char previousMove = boardState[i][j];
					//make player move
					board.markSpace(i, j, player);

					//call miniMax recursibley and select max value
					best = std::max(best, minimax(depth + 1, !isMax));

					//undo the last move
					board.markSpace(i, j, '_');
					
				}
			}
		}

		return best;
	}
	//If it is the minimizers move
	else {
		int best = 1000;

		//go through all cells
		for (int i = 0; i < boardState.size(); i++) {
			for (int j = 0; j < boardState.size(); j++) {
				//check if cell is empty.
				if (boardState[i][j] != 'x' || boardState[i][j] != 'o') {
					//make move as opponent
					board.markSpace(i, j, opponent);

					//call minimax recusively and select min value
					best = std::min(best, minimax(depth + 1, !isMax));

					//undo last move
					board.markSpace(i, j, '_');
				}
			}
		}
		return best;
	}
}

Move Game::findBestMove()
{
	int bestValue = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;
	std::array<std::array<char, 3>, 3> boardState = board.getBoard();

	//traverse throgu cells, evaluate minimax function for all
	// empty cells and return the cell with the best(optimal) value.
	for (int i = 0; i < boardState.size(); i++) {
		for (int j = 0; j < boardState.size(); j++) {
			//check if cell is empty
			if (boardState[i][j] != 'x' || boardState[i][j] != 'o') {

				//make player move
				board.markSpace(i, j, player);

				//evaluate score for this move
				int moveValue = minimax(0, false);

				//undo move
				board.markSpace(i, j, '_');

				//if value of current move is more than the best move, 
				//then update the bestMove
				if (moveValue > bestValue) {
					bestMove.row = i;
					bestMove.col = j;
					bestValue = moveValue;
				}
			}
		}
	}

	std::cout << "Best move value is : " << bestValue;
	return bestMove;
}
