#include <iostream>
#include "ticTac.h"

Square::Square()
{
	occupied = EMPTY;
	mark = " ";
}

Square::Square( Status initOccupied, string initMark)
{
	occupied = initOccupied;
	mark = initMark;
}

Square Square::move(int currentPlayer) const
{
	Square newSquare;

	switch (currentPlayer)
	{
	case 1:
		newSquare = { PLAYERONE , "X"};
		return newSquare;
		break;
	case 2:
		newSquare = { PLAYERTWO , "O"};
		return newSquare;
		break;
	default:
		cout << "error, does not compute..." << endl;
		newSquare = { EMPTY , " "};
		return newSquare;
		break;
	}
}

Status Square::getStatus() const { return occupied; }

string Square::getMark() const { return mark; }