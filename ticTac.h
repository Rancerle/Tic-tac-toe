#pragma once
#include <iostream>
#include <string>
#include "playerOcc.h"

using namespace std;

class Square
{
public:

	Square();

	Square(Status occupied, string mark);

	Square move(int currentPlayer) const;

	Status getStatus() const;

	string getMark() const;

private:
	Status occupied;
	string mark;
};