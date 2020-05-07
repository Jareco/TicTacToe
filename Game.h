class Game
{
private:
	int movePosition;
	int inputMove;
	bool win = false;
	Playfield field;
	InputMoveParser moveParser;

public:

	Game(){}

	void start()
	{
		printPlayingInformation();
		char choice;
		cin >> choice;

		if (choice == 'p') {
			playAgainstHuman();
		}
		else {
			playAgainstComputer();
		}
	}


	void printPlayingInformation()
	{
		cout << "You should choose the position, where you can set you answer." << endl;
		cout << "Play with number 1 or 0." << endl;
		cout << "Play against computer: 'c' or play against player: 'p'" << endl;
		cout << "Player or Computer: ";
	}

	void playAgainstHuman()
	{
		do {
			win = field.checkWin();
			if (win == true) {
				field.print();
				cout << "You won!" << endl;
				break;
			}
			if (field.checkTie()) {
				field.print();
				cout << "Tie!" << endl;
				break;
			}
			field.print();
			cout << "Position: ";
			cin >> movePosition;
			cout << "Choice: ";
			cin >> inputMove;
			Move moveToDo = moveParser.parse(movePosition, inputMove);
			field.doMove(moveToDo);
			cout << endl;
		} while (true);
	}

	void playAgainstComputer()
	{
		cout << "Use only 1 for playing with computer." << endl;
		AI computerPlayer(field);
		int indexOfPlayer = 0;

		do {

			win = field.checkWin();
			if (win == true) {
				field.print();
				cout << "Win!" << endl;
				break;
			}


			if (indexOfPlayer % 2 == 0) {
				field.print();
				cout << "Position: ";
				cin >> movePosition;
				cout << "Choice: ";
				cin >> inputMove;
				Move moveToDo = moveParser.parse(movePosition, inputMove);
				field.doMove(moveToDo);
				indexOfPlayer++;
				win = field.checkWin();
				if (win == true) {
					field.print();
					cout << "Win!" << endl;
					break;
				}
				if (field.checkTie()) {
					field.print();
					cout << "Tie!" << endl;
					break;
				}
			}
			else {
				computerPlayer.play();
				indexOfPlayer++;
				if (win == true) {
					field.print();
					cout << "Win!" << endl;
					break;
				}

			}

		} while (true);
	}

};