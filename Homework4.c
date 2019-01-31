#include <stdio.h>
#include <stdlib.h>

// 1
int PathfindWithObstacles(int x, int y)
{
	if (x == 0 && y == 0)
	{
		return 0;
	}
	else if (x == 3 && y == 1) // obstacle
	{
		return 0;
	}
	else if (x == 4 && y == 0) // obstacle
	{
		return 0;
	}
	else if (x == 2 && y == 5) // obstacle
	{
		return 0;
	}
	else if (x == 6 && y == 6) // obstacle
	{
		return 0;
	}
	else if (x == 0 ^ y == 0)
	{
		return 1;
	}
	else
	{
		return PathfindWithObstacles(x - 1, y) + PathfindWithObstacles(x, y - 1);
	}
}

// 3
#define M 8
#define N 8

int board[M][N];

void annul()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0;
		}
	}
}

void printBoard()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%3d", board[i][j]);
		}
		printf("\n");
	}
}

int Horse(int y, int x, int step)
{
	if (y < 0 || x < 0 || y >= M || x >= N || board[y][x] != 0)
	{
		return 0;
	}
	else if (step == M * N)
	{
		board[y][x] = step;
		return 1;
	}

	else
	{
		board[y][x] = step;

		if (Horse(y + 2, x + 1, step + 1) == 1)
		{
			return 1;
		}

		if (Horse(y + 2, x - 1, step + 1) == 1)
		{
			return 1;
		}

		if (Horse(y + 1, x + 2, step + 1) == 1)
		{
			return 1;
		}

		if (Horse(y + 1, x - 2, step + 1) == 1)
		{
			return 1;
		}

		if (Horse(y - 1, x - 2, step + 1) == 1)
		{
			return 1;
		}

		if (Horse(y - 1, x + 2, step + 1) == 1)
		{
			return 1;
		}

		if (Horse(y - 2, x + 1, step + 1) == 1)
		{
			return 1;
		}

		if (Horse(y - 2, x - 1, step + 1) == 1)
		{
			return 1;
		}

		board[y][x] = 0;
		return 0;
	}
}

int main()
{
	// 1
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%5d", PathfindWithObstacles(i, j));
		}
		printf("\n\n");
	}

	printf("\n");

	// 3
	annul();
	printf("\n");
	Horse(4, 3, 1);
	printBoard();

	return 0;
}