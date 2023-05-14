#pragma once
#define MAXSIDE 25

class Board {
private:
	int SIDE, MINES;
public:
	int countMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]);
	bool checkBoard(char GameBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int* movesLeft);
	bool isValid(int row, int col);
	bool isMine(int row, int col, char board[][MAXSIDE]);
	void Move(int* x, int* y);
	void RandomMove(int* x, int* y, int moves[][2], int moveIndex);
	void GenerateMove(int moves[][2], int movesLeft);
	void printBoard(char GameBoard[][MAXSIDE]);
	void endBoard(char GameBoard[][MAXSIDE]);
	void place(int mines[][2], char realBoard[][MAXSIDE]);
};
