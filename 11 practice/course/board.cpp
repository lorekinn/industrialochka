#include "board.h"
#include <iostream>
using namespace std;
#define BEGINNER 0
#define ADVANCED 1
#define JESUS 2
#define BEGINNERHACK 3
#define ADVANCEDHACK 4
#define JESUSHACK 5
#define RANDOMBEGIN 6
#define RANDOMADVANCED 7
#define RANDOMJESUS 8
#define RULES 10
#define MAXMINES 99
#define MOVESIZE 526
#pragma warning(disable : 4996)

bool Board::isValid(int row, int col)
{
	return (row >= 0) && (row < SIDE) &&
		(col >= 0) && (col < SIDE);
}

bool Board::isMine(int row, int col, char board[][MAXSIDE])
{
	if (board[row][col] == '*')
		return (true);
	else
		return (false);
}

void Board::Move(int* x, int* y)
{
	while (true)
	{
		printf("Укажите свой выбор строки и столбца: ");
		if (scanf("%d %d", x, y) != 2)
		{
			printf("Неверный формат ввода. Попробуйте снова.\n");
			while (getchar() != '\n') {}
			continue;
		}
		break;
	}
}

void Board::RandomMove(int* x, int* y, int moves[][2], int currentMoveIndex)
{
	*x = moves[currentMoveIndex][0];
	*y = moves[currentMoveIndex][1];

	printf("\nСгенерированный ход: %d, %d\n", *x, *y);
}

void Board::GenerateMove(int moves[][2], int movesLeft)
{
	bool spot[MAXSIDE * MAXSIDE];

	memset(spot, false, sizeof(spot));

	for (int i = 0; i < movesLeft; )
	{
		int random = rand() % (SIDE * SIDE);
		int x = random / SIDE;
		int y = random % SIDE;
		if (spot[random] == false)
		{
			moves[i][0] = x;
			moves[i][1] = y;
			spot[random] = true;
			i++;
		}
	}
}

void Board::printBoard(char GameBoard[][MAXSIDE])
{
	int i, j;

	cout << ("   ");

	for (i = 0; i < SIDE; i++)
		printf("%d ", i);

	cout << ("\n\n");

	for (i = 0; i < SIDE; i++)
	{
		printf("%d  ", i);

		for (j = 0; j < SIDE; j++)
			printf("%c ", GameBoard[i][j]);
		cout << ("\n");
	}
}

void Board::endBoard(char GameBoard[][MAXSIDE])
{
	int i, j;
	cout << ("   ");
	for (i = 0; i < SIDE; i++)
		printf("%d ", i);
	cout << ("\n\n");
	for (i = 0; i < SIDE; i++)
	{
		printf("%d  ", i);
		for (j = 0; j < SIDE; j++)
		{
			if (GameBoard[i][j] == '-')
				printf("* ");
			else
				printf("%c ", GameBoard[i][j]);
		}
		cout << ("\n");
	}
}

int Board::countMines(int row, int col, int mines[][2],
	char realBoard[][MAXSIDE])
{

	int i;
	int count = 0;
	if (isValid(row - 1, col) == true)
	{
		if (isMine(row - 1, col, realBoard) == true)
			count++;
	}

	if (isValid(row + 1, col) == true)
	{
		if (isMine(row + 1, col, realBoard) == true)
			count++;
	}

	if (isValid(row, col + 1) == true)
	{
		if (isMine(row, col + 1, realBoard) == true)
			count++;
	}

	if (isValid(row, col - 1) == true)
	{
		if (isMine(row, col - 1, realBoard) == true)
			count++;
	}

	if (isValid(row - 1, col + 1) == true)
	{
		if (isMine(row - 1, col + 1, realBoard) == true)
			count++;
	}

	if (isValid(row - 1, col - 1) == true)
	{
		if (isMine(row - 1, col - 1, realBoard) == true)
			count++;
	}

	if (isValid(row + 1, col + 1) == true)
	{
		if (isMine(row + 1, col + 1, realBoard) == true)
			count++;
	}

	if (isValid(row + 1, col - 1) == true)
	{
		if (isMine(row + 1, col - 1, realBoard) == true)
			count++;
	}

	return (count);
}

bool Board::checkBoard(char GameBoard[][MAXSIDE], char realBoard[][MAXSIDE],
	int mines[][2], int row, int col, int* movesLeft)
{

	if (GameBoard[row][col] != '-')
		return (false);

	int i, j;

	if (realBoard[row][col] == '*')
	{
		GameBoard[row][col] = '*';

		for (i = 0; i < MINES; i++)
			GameBoard[mines[i][0]][mines[i][1]] = '*';

		printBoard(GameBoard);
		cout << ("\nТы проиграл!\n\n");
		return (true);
	}

	else
	{
		int count = countMines(row, col, mines, realBoard);
		(*movesLeft)--;

		GameBoard[row][col] = count + '0';

		if (!count)
		{
			if (isValid(row - 1, col) == true)
			{
				if (isMine(row - 1, col, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row - 1, col, movesLeft);
			}

			if (isValid(row + 1, col) == true)
			{
				if (isMine(row + 1, col, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row + 1, col, movesLeft);
			}

			if (isValid(row, col + 1) == true)
			{
				if (isMine(row, col + 1, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row, col + 1, movesLeft);
			}

			if (isValid(row, col - 1) == true)
			{
				if (isMine(row, col - 1, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row, col - 1, movesLeft);
			}

			if (isValid(row - 1, col + 1) == true)
			{
				if (isMine(row - 1, col + 1, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row - 1, col + 1, movesLeft);
			}

			if (isValid(row - 1, col - 1) == true)
			{
				if (isMine(row - 1, col - 1, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row - 1, col - 1, movesLeft);
			}

			if (isValid(row + 1, col + 1) == true)
			{
				if (isMine(row + 1, col + 1, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row + 1, col + 1, movesLeft);
			}

			if (isValid(row + 1, col - 1) == true)
			{
				if (isMine(row + 1, col - 1, realBoard) == false)
					checkBoard(GameBoard, realBoard, mines, row + 1, col - 1, movesLeft);
			}
		}

		return (false);
	}
}
