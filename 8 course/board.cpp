#include "board.h"
#include <iostream>
using namespace std;
#define BEGINNER 0
#define ADVANCED 1
#define JESUS 2
#define RULES 10

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
};
void Board::cheat(char realBoard[][MAXSIDE])
{
	cout << ("Расположение мин:\n");
	printBoard(realBoard);
}
void Board::play() {
};
void Board::Level()
{
	int level;

	cout << ("Выберите уровень игры:\n");
	cout << ("Начальный (9x9, 10 мин) - 0\n");
	cout << ("Продвинутый (16x16, 40 мин) - 1\n");
	cout << ("Божественный (24х24, 99 мин) - 2\n");
	cout << ("Правила игры - 10\n");
	cout << ("TODO: Добавить видимость мин/случайные ходы системы");

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
			//play();
			break;
		}
		if (level == ADVANCED)
		{
			SIDE = 16;
			MINES = 40;
			//play();
			break;
		}
		if (level == JESUS)
		{
			SIDE = 24;
			MINES = 99;
			//play();
			break;
		if (level == RULES)
		{
			cout << ("--------------------");
			cout << ("\nПравила игры: \nЧтобы открыть клетку - нужно ввести номер строки и столбца (Например: 1 2)\n");
			cout << ("Для победы на поле должны остаться только открытые\n");
			cout << ("Когда играет система - мины не видны, ходы генерируются случайным образом");
			cout << ("Кроме того, первый ход не может быть проигрышным\n");
			cout << ("--------------------\n");
			continue;
		}
		cout << "Такого варианта нет, попробуй ещё раз\n";
	}
}
