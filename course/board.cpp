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
		if (*x > SIDE-1 || *y > SIDE-1)
		{
			printf("Введенные числа не должны превышать %d. Попробуйте снова.\n", SIDE-1);
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

void Board::place(int mines[][2], char realBoard[][MAXSIDE])
{
	bool spot[MAXSIDE * MAXSIDE];

	memset(spot, false, sizeof(spot));

	for (int i = 0; i < MINES; )
	{
		int random = rand() % (SIDE * SIDE);
		int x = random / SIDE;
		int y = random % SIDE;

		if (spot[random] == false)
		{
			mines[i][0] = x;
			mines[i][1] = y;
			realBoard[mines[i][0]][mines[i][1]] = '*';
			spot[random] = true;
			i++;
		}
	}
}

void Board::initialise(char realBoard[][MAXSIDE], char GameBoard[][MAXSIDE])
{
	srand(time(NULL));
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			GameBoard[i][j] = realBoard[i][j] = '-';
		}
	}
}

void Board::replace(int row, int col, char board[][MAXSIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			if (board[i][j] != '*')
			{
				board[i][j] = '*';
				board[row][col] = '-';
			}
		}
	}
}

void Board::play()
{
	bool gameOver = false;
	char realBoard[MAXSIDE][MAXSIDE], GameBoard[MAXSIDE][MAXSIDE];

	int movesLeft = SIDE * SIDE - MINES, x, y;
	int mines[MAXMINES][2];

	do {
		initialise(realBoard, GameBoard);
		place(mines, realBoard);
		int currentMoveIndex = 0;

		while (gameOver == false)
		{
			cout << ("Поле выглядит так: \n");
			printBoard(GameBoard);
			Move(&x, &y);

			if (currentMoveIndex == 0)
			{
				if (isMine(x, y, realBoard) == true)
					replace(x, y, realBoard);
			}

			currentMoveIndex++;

			gameOver = checkBoard(GameBoard, realBoard, mines, x, y, &movesLeft);

			if ((gameOver == false) && (movesLeft == 0))
			{
				cout << ("\nТы выиграл! Конечная доска выглядит так:\n");
				endBoard(GameBoard);
				gameOver = true;
			}
		}
		char playAgain;
		cout << ("Хотите начать игру заново? (Y/N): ");
		scanf(" %c", &playAgain);
		if (playAgain == 'Y' || playAgain == 'y') {
			Level();
		}
	} while (gameOver == false);
}

void Board::playRandomize()
{
	bool gameOver = false;
	char realBoard[MAXSIDE][MAXSIDE], GameBoard[MAXSIDE][MAXSIDE];

	int movesLeft = SIDE * SIDE - MINES, x, y;
	int mines[MAXMINES][2];
	int moves[MOVESIZE][2];

	do {
		initialise(realBoard, GameBoard);
		place(mines, realBoard);
		GenerateMove(moves, movesLeft);
		int currentMoveIndex = 0;

		while (gameOver == false)
		{
			cout << ("Поле выглядит так: \n");
			printBoard(GameBoard);
			RandomMove(&x, &y, moves, currentMoveIndex);

			if (currentMoveIndex == 0)
			{
				if (isMine(x, y, realBoard) == true)
					replace(x, y, realBoard);
			}

			currentMoveIndex++;

			gameOver = checkBoard(GameBoard, realBoard, mines, x, y, &movesLeft);

			if ((gameOver == false) && (movesLeft == 0))
			{
				cout << ("\nТы выиграл! Конечная доска выглядит так:\n");
				endBoard(GameBoard);
				gameOver = true;
			}
		}
		char playAgain;
		cout << ("Хотите начать игру заново? (Y/N): ");
		scanf(" %c", &playAgain);
		if (playAgain == 'Y' || playAgain == 'y') {
			Level();
		}
	} while (gameOver == false);
}

void Board::cheat(char realBoard[][MAXSIDE])
{
	cout << ("Расположение мин:\n");
	printBoard(realBoard);
}
void Board::hack()
{
	bool gameOver = false;
	char realBoard[MAXSIDE][MAXSIDE], GameBoard[MAXSIDE][MAXSIDE];

	int movesLeft = SIDE * SIDE - MINES, x, y;
	int mines[MAXMINES][2];

	do {
		initialise(realBoard, GameBoard);
		place(mines, realBoard);
		cheat(realBoard);
		cout << ("\n\n\n");
		int currentMoveIndex = 0;

		while (gameOver == false)
		{
			cout << ("Поле выглядит так: \n");
			printBoard(GameBoard);
			Move(&x, &y);

			if (currentMoveIndex == 0)
			{
				if (isMine(x, y, realBoard) == true)
					replace(x, y, realBoard);
			}

			currentMoveIndex++;

			gameOver = checkBoard(GameBoard, realBoard, mines, x, y, &movesLeft);

			if ((gameOver == false) && (movesLeft == 0))
			{
				cout << ("\nТы выиграл! Конечная доска выглядит так:\n");
				endBoard(GameBoard);
				gameOver = true;
			}
		}
		char playAgain;
		cout << ("Хотите начать игру заново? (Y/N): ");
		scanf(" %c", &playAgain);
		if (playAgain == 'Y' || playAgain == 'y') {
			Level();
		}
	} while (gameOver == false);
}
void Board::Level()
{
	int level;

	cout << ("Выберите уровень игры:\n");
	cout << ("Начальный (9x9, 10 мин) - 0 || Игра с минами - 3;\n");
	cout << ("Продвинутый (16x16, 40 мин) - 1 || Игра с минами - 4\n");
	cout << ("Божественный (24х24, 99 мин) - 2 || Игра с минами - 5\n");
	cout << ("Играет система (уровни соответственны списку) - 6; 7; 8\n");
	cout << ("Правила игры - 10\n");

	while (true) {
		if (scanf("%d", &level) != 1) {
			cout << "Ошибка: некорректный ввод. Пожалуйста, повторите попытку." << endl;
			while (getchar() != '\n');
			continue;
		}
		if (level == BEGINNER)
		{
			SIDE = 9;
			MINES = 10;
			play();
			break;
		}
		if (level == ADVANCED)
		{
			SIDE = 16;
			MINES = 40;
			play();
			break;
		}
		if (level == JESUS)
		{
			SIDE = 24;
			MINES = 99;
			play();
			break;
		}
		if (level == BEGINNERHACK)
		{
			SIDE = 9;
			MINES = 10;
			hack();
			break;
		}
		if (level == ADVANCEDHACK)
		{
			SIDE = 16;
			MINES = 40;
			hack();
			break;
		}
		if (level == JESUSHACK)
		{
			SIDE = 24;
			MINES = 99;
			hack();
			break;
		}
		if (level == RANDOMBEGIN)
		{
			SIDE = 9;
			MINES = 10;
			playRandomize();
			break;
		}
		if (level == RANDOMADVANCED)
		{
			SIDE = 16;
			MINES = 40;
			playRandomize();
			break;
		}
		if (level == RANDOMJESUS)
		{
			SIDE = 24;
			MINES = 99;
			playRandomize();
			break;
		}
		if (level == RULES)
		{
			cout << ("--------------------");
			cout << ("\nПравила игры: \nЧтобы открыть клетку - нужно ввести номер строки и столбца (Например: 1 2)\n");
			cout << ("Для победы на поле должны остаться только открытые\n");
			cout << ("Когда играет система - мины не видны, ходы генерируются случайным образом\n");
			cout << ("Кроме того, первый ход не может быть проигрышным\n");
			cout << ("--------------------\n");
			continue;
		}
		cout << "Такого варианта нет, попробуй ещё раз\n";
	}
}
