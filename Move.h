struct Move {
	int column;
	int row;
	int choise;
	int score;
	Move() {}
	Move(int column, int row, int choise)
	{
		this->column = column;
		this->row = row;
		this->choise = choise;
	}
	Move(int score) {
		this->score = score;
	}

};