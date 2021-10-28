#include <iostream>
#include <string>
using namespace std;

class Playfield
{
private:
	const static int rows = 3;
	const static int columns = 3;
	const static enum playFieldPossibilities { O,
											   X,
											   Empty };
	int playfield[rows][columns];
	char winner;

public:
	Playfield()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int d = 0; d < columns; d++)
			{
				playfield[i][d] = playFieldPossibilities::Empty;
			}
		}

		winner = 'N';
	}

	const int getRows() const
	{
		return rows;
	}

	const int getColumns() const
	{
		return columns;
	}

	void setPlayChoise(int i, int d, int playChoise)
	{
		playfield[i][d] = playChoise;
	}

	void doMove(Move move)
	{

		if (isPositionFree(move.row, move.column))
		{
			setPlayChoise(move.row, move.column, move.choise);
		}
		else
		{
			cout << "Wrong position" << endl;
		}
	}

	bool isPositionFree(int row, int column)
	{
		if (playfield[row][column] == playFieldPossibilities::Empty)
			return true;
		else
			return false;
	}

	void print()
	{
		cout << "     1."
			 << "2."
			 << "3." << endl;
		cout << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << (i + 1) << "    ";
			for (int d = 0; d < columns; d++)
			{
				if (playfield[i][d] != 0 && playfield[i][d] != 1)
					cout << "*"
						 << " ";
				else
					cout << playfield[i][d] << " ";
			}

			cout << endl;
		}
	}

	bool checkWinHorizontal()
	{
		int counter_0 = 0; //counter for answer 0
		int counter_1 = 0; //counter for answer 1
		for (int i = 0; i < rows; i++)
		{
			for (int d = 0; d < columns; d++)
			{
				if (playfield[i][d] == playFieldPossibilities::O)
					counter_0++;
				if (playfield[i][d] == playFieldPossibilities::X)
					counter_1++;
			}
			if (counter_0 == 3)
			{
				winner = 'C';
				return true;
			}
			if (counter_1 == 3)
			{
				winner = 'P';
				return true;
			}
			counter_0 = 0;
			counter_1 = 0;
		}

		return false;
	}

	bool chekWinVertical()
	{
		int counter_0 = 0;
		int counter_1 = 0;
		for (int i = 0; i < rows; i++)
		{ // Column
			for (int d = 0; d < columns; d++)
			{ // Row
				if (playfield[d][i] == playFieldPossibilities::O)
					counter_0++;
				if (playfield[d][i] == playFieldPossibilities::X)
					counter_1++;
			}
			if (counter_0 == 3)
			{
				winner = 'C';
				return true;
			}
			if (counter_1 == 3)
			{
				winner = 'P';
				return true;
			}
			counter_0 = 0;
			counter_1 = 0;
		}

		return false;
	}

	bool checkWinDiagonal()
	{
		//Diagonal Left-Right
		int counter_0 = 0;
		int counter_1 = 0;
		for (int i = 0; i < rows; i++)
		{
			if (playfield[i][i] == playFieldPossibilities::O)
				counter_0++;
			if (playfield[i][i] == playFieldPossibilities::X)
				counter_1++;
		}
		if (counter_0 == 3)
		{
			winner = 'C';
			return true;
		}
		if (counter_1 == 3)
		{
			winner = 'P';
			return true;
		}
		counter_0 = 0;
		counter_1 = 0;

		//Diagonal Right-Left
		int columnIndex = 2; //column
		for (int i = 0; i < rows; i++)
		{ //Row
			if (playfield[i][columnIndex] == playFieldPossibilities::O)
				counter_0++;
			if (playfield[i][columnIndex] == playFieldPossibilities::X)
				counter_1++;
			columnIndex--;
		}
		if (counter_0 == 3)
		{
			winner = 'C';
			return true;
		}
		if (counter_1 == 3)
		{
			winner = 'P';
			return true;
		}

		return false;
	}

	bool checkWin()
	{
		bool winResult = false;
		winResult = checkWinHorizontal();
		if (winResult)
			return winResult;
		winResult = chekWinVertical();
		if (winResult)
			return winResult;
		winResult = checkWinDiagonal();
		if (winResult)
			return winResult;
		return winResult;
	}

	bool checkTie()
	{
		bool winResult = checkWin();
		if (winResult)
			return false;
		int counter = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int d = 0; d < columns; d++)
			{
				if (playfield[i][d] != 2)
					counter++;
			}
		}
		if (counter == 9)
			return true;

		return false;
	}

	char getWinner()
	{
		if (checkTie())
			winner = 'T';
		char winnerToReturn = winner;
		winner = 'N';
		return winnerToReturn;
	}
};
