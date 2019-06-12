#include<vector>
#include"chessboard.h"

namespace Chen_Yan_Yu_Board
{
	using std::vector;
	int board::piece[10][9];
	board::board(int arr[10][9])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				piece[i][j] = arr[i][j];
			}
		}
	}
	void board::set(int arr[10][9])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				piece[i][j] = arr[i][j];
			}
		}
	}
	char board::checkColor(int row, int col)
	{
		if (piece[row][col] >= 1 && piece[row][col] <= 7)
		{
			return 'b';
		}
		else if (piece[row][col] == 0)
		{
			return 'n';
		}
		else
		{
			return 'r';
		}
	}
	int board::getBoard(vector<int> v)
	{
		return board::piece[v[0]][v[1]];
	}
}
