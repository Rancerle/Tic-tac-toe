#include <iostream>
#include <string>
#include "ticTac.h"

void setBoard();
void drawBoard();
int game(int currentPlayer, int scoreOne, int scoreTwo);

Square board[3][3];

int main()
{
	int currentPlayer = 1;
	int scoreOne = 0;
	int scoreTwo = 0;
	int endgame = 0;

	while (endgame != 1)
	{
		endgame = game(currentPlayer, scoreOne, scoreTwo);
	}

	cout << "Thank you for playing, have a nice day!" << endl;

	return 0;
}

void setBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = Square(EMPTY, " ");
		}
	}
}

int game(int currentPlayer, int scoreOne, int scoreTwo)
{
	int gameInProgress = 0;
	int boardFull = 0;
	int keepPlaying;
	int widthWise = 0;
	int heightWise = 0;
	int goAhead = 0;

	setBoard();

	cout << "Current Score: "<< scoreOne << "-" << scoreTwo << endl;
	while (gameInProgress != 1)
	{
		goAhead = 0;
		while (goAhead != 1)
		{
			drawBoard();
			cout << "Player " << currentPlayer << ", please select the square you would like." << endl;
			cout << "Width wise: ";
			cin >> widthWise;
			cout << endl;
			cout << "Height wise: ";
			cin >> heightWise;
			cout << endl;

			if ((widthWise < 1 || widthWise > 3) || (heightWise < 1 || heightWise > 3))
			{
				cout << "I'm sorry, but that selection is out of bounds. Please try again." << endl;
				cout << endl;
			}
			else if (board[heightWise - 1][widthWise - 1].getStatus() != EMPTY)
			{
				cout << "I'm sorry, but that square is already taken." << endl;
				cout << endl;
			}
			else
			{
				cout << "Okay, you have taken square (" << widthWise << ", " << heightWise << ") " << endl;
				cout << endl;
				goAhead = 1;
			}
		}

		board[heightWise - 1][widthWise - 1] = board[heightWise - 1][widthWise - 1].move(currentPlayer);

		boardFull += 1;

		if ((board[0][0].getStatus() != EMPTY && board[0][0].getStatus() == board[0][1].getStatus() && board[0][1].getStatus() == board[0][2].getStatus())
		  ||(board[1][0].getStatus() != EMPTY && board[1][0].getStatus() == board[1][1].getStatus() && board[1][1].getStatus() == board[1][2].getStatus())
		  ||(board[2][0].getStatus() != EMPTY && board[2][0].getStatus() == board[2][1].getStatus() && board[2][1].getStatus() == board[2][2].getStatus())
		  ||(board[0][0].getStatus() != EMPTY && board[0][0].getStatus() == board[1][1].getStatus() && board[1][1].getStatus() == board[2][2].getStatus())
		  ||(board[2][0].getStatus() != EMPTY && board[2][0].getStatus() == board[1][1].getStatus() && board[1][1].getStatus() == board[0][2].getStatus())
		  ||(board[0][0].getStatus() != EMPTY && board[0][0].getStatus() == board[1][0].getStatus() && board[1][0].getStatus() == board[2][0].getStatus())
		  ||(board[0][1].getStatus() != EMPTY && board[0][1].getStatus() == board[1][1].getStatus() && board[1][1].getStatus() == board[2][1].getStatus())
		  ||(board[0][2].getStatus() != EMPTY && board[0][2].getStatus() == board[1][2].getStatus() && board[1][2].getStatus() == board[2][2].getStatus()))
		{
			switch (currentPlayer)
			{
			case 1:
				cout << "Player 1 wins!" << endl;
				cout << endl;
				drawBoard();
				scoreOne++;
				gameInProgress = 1;
				break;
			case 2:
				cout << "Player 2 wins!" << endl;
				cout << endl;
				drawBoard();
				scoreTwo++;
				gameInProgress = 1;
				break;
			}
		}

		else if (boardFull == 9)
		{

			cout << "It's a draw!" << endl;
			drawBoard();
			cout << endl;
			gameInProgress = 1;

		}

		else
		{
			cout << "Player " << currentPlayer << "'s turn is over." << endl;
			cout << endl;
			switch (currentPlayer)
			{
			case 1:
				currentPlayer = 2;
				break;
			case 2:
				currentPlayer = 1;
				break;
			}
		}
	}

	cout << "would you like to play again? (1 = yes, 2 = no)" << endl;
	cin >> keepPlaying;
	cout << endl;

	switch (keepPlaying)
	{
	case 1:
		cout << "Okay, let's play again!" << endl;
		cout << endl;
		currentPlayer = 1;
		game(currentPlayer, scoreOne, scoreTwo);
		break;

	default:
		cout << "Okay, that was a fun game!" << endl;
		cout << endl;
		return 1;
		break;
	}
}

void drawBoard()
{
	for (int i = 2; i > -1; i--)
	{
		cout << " *****" << "*****" << "*****" << endl;
		cout << i + 1 << "* " << board[i][0].getMark() << " *"
					  << "* " << board[i][1].getMark() << " *"
					  << "* " << board[i][2].getMark() << " *" << endl;
		cout << " *****" << "*****" << "*****" << endl;
	}
	cout << "  |1| " << " |2| " << " |3| " << endl;
	cout << endl;
}