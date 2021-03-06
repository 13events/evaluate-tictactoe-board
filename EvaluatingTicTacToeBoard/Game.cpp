#include "pch.h"
#include "Game.h"
#include <algorithm>


Game::Game()
{
	
	this->player = 'x';
	this->opponent = 'o';

	//set blank board state
	
	for (int i = 0; i < board.board.size(); i++) {
		for (int j = 0; j < board.board.size(); j++) {
			board.markSpace(i, j, '_');
		}
	}
	//print initial state
	board.print();
}

Game::Game(bool prebuiltBoard)
{
	this->player = 'x';
	this->opponent = 'o';

	//set board to inital state of
	/* 
	X | O | O 
	-----------
	O | X | X
	-----------
	_ | _ | _
	*/

	board.markSpace(0, 0, player);
	board.markSpace(0, 1, opponent);
	board.markSpace(0, 2, opponent);
	
	board.markSpace(1, 0, opponent);
	board.markSpace(1, 1, player);
	board.markSpace(1, 2, player);

	board.markSpace(2, 0, '_');
	board.markSpace(2, 1, '_');
	board.markSpace(2, 2, '_');

	//display initial state
	board.print();
}

bool Game::isMovesLeft()
{
	//std::array<std::array<char,3>,3> boardState = board.getBoard();

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
			if (board.board[i][j] != 'x' && board.board[i][j] != 'o')
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
	//std::array<std::array<char, 3>, 3> boardState = board.getBoard();

	//boardState[0][0];
	//check for row 'x' or 'o' victory
	for (auto row = 0; row < board.board.size(); row++) {
		if (board.board[row][0] == board.board[row][1] && board.board[row][1] == board.board[row][2]) {
			if (board.board[row][0] == 'x') {
				return +10;
			}
			else if (board.board[row][0] == 'o')
				return -10;
		}
	}

	//check columns for 'x' or 'o' victory
	for (int column = 0; column < board.board.size(); column++) {
		if (board.board[0][column] == board.board[1][column] && board.board[1][column] == board.board[2][column]) {
			if (board.board[0][column] == 'x')
				return +10;
			else if (board.board[0][column] == 'o')
				return -10;
		}
	}

	//check diagonals
	if (board.board[0][0] == board.board[1][1] && board.board[1][1] == board.board[2][2]) {
		if (board.board[0][0] == 'x')
			return +10;
		else if (board.board[0][0] == '0')
			return -10;

	}

	if (board.board[0][2] == board.board[1][1] && board.board[1][1] == board.board[2][0])
		if (board.board[0][2] == 'x')
			return +10;
		else if (board.board[0][2] == 'o')
			return -10;

	//return nothing if none have won
	return 0;
}

int Game::minimax(int depth, bool isMax)
{
	//get board state
	//std::array<std::array<char, 3>, 3> boardState = board.getBoard();
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
		for (int i = 0; i < board.board.size(); i++) {
			for (int j = 0; j < board.board.size(); j++) {
				//check if cell is empty
				if (board.board[i][j] != 'x' && board.board[i][j] != 'o') {
					
					char previousMove = board.board[i][j];
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
		for (int i = 0; i < board.board.size(); i++) {
			for (int j = 0; j < board.board.size(); j++) {
				//check if cell is empty.
				if (board.board[i][j] != 'x' && board.board[i][j] != 'o') {
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
	//std::array<std::array<char, 3>, 3> boardState = board.getBoard();

	//traverse throgu cells, evaluate minimax function for all
	// empty cells and return the cell with the best(optimal) value.
	for (int i = 0; i < board.board.size(); i++) {
		for (int j = 0; j < board.board.size(); j++) {
			//check if cell is empty
			if (board.board[i][j] != player && board.board[i][j] != opponent) {

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

	
	return bestMove;
}
