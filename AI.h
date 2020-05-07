#include <vector>
#include <iostream>
using namespace std;
class AI {
private:
	const char computer = 'C';
	const char player = 'P';
	const char tie = 'T';
	const static enum playFieldPossibilities { O, X, Empty };
	Playfield *field;


public:

	AI(Playfield&  field) {
		this->field = &field;
	}

	void play() {
		Move bestMove = findMove(playFieldPossibilities::O);
		bestMove.choise = playFieldPossibilities::O;
		field->doMove(bestMove);
	}

	Move findMove(int playChoise) {
		char winner = field->getWinner();
		//Break condition
		if (winner == computer) {
			return Move(10);
		}
		else if (winner == player) {
			return Move(-10);
		}
		else if (winner == tie) {
			return Move(0);
		}


		//Recursion. Put moves in the vector
		std::vector<Move> moves;
		for (int i = 0; i < field->getColumns(); i++) {
			for (int d = 0; d < field->getRows(); d++) {
				if (field->isPositionFree(i, d)) {
					Move move;
					move.column = i;
					move.row = d;
					field->setPlayChoise(i, d, playChoise);
					if (playChoise == playFieldPossibilities::O) {
						move.score = findMove(playFieldPossibilities::X).score;
					}
					else {
						move.score = findMove(playFieldPossibilities::O).score;
					}

					moves.push_back(move);

					field->setPlayChoise(i, d, playFieldPossibilities::Empty);
				}
			}
		}


		//The best move 
		int bestmove = 0;
		if (playChoise == playFieldPossibilities::O) {
			int bestScore = -1000000;
			for (int i = 0; i < moves.size(); i++) {
				if (moves[i].score > bestScore) {
					bestmove = i;
					bestScore = moves[i].score;
				}
			}

		}
		else {
			int bestScore = 1000000;
			for (int i = 0; i < moves.size(); i++) {
				if (moves[i].score < bestScore) {
					bestmove = i;
					bestScore = moves[i].score;
				}
			}

		}

		return moves[bestmove];
	}
};
