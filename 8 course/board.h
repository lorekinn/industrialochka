#pragma once
#define MAXSIDE 25

class Board {
private:
	int SIDE, MINES;
public:
	void cheat(char realBoard[][MAXSIDE]);
	void printBoard(char GameBoard[][MAXSIDE]);
	void play();
	void Level();
};
