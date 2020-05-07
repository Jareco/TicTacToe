class InputMoveParser
{
private:
	int inputMove;
	const static enum playFieldPossibilities { X, O, Empty };

public:
	InputMoveParser(){}

	Move parse(int movePosition, int inputMove)
	{
		string position = std::to_string(movePosition);
		string stringRow(1, position[0]);
		string stringColumn(1, position[1]);
		int row = std::stoi(stringRow) - 1;
		int column = std::stoi(stringColumn) - 1;

		Move parsedMove(column, row, inputMove);
		return parsedMove;
	}
};