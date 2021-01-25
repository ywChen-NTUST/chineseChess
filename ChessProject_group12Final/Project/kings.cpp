#include"kings.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

kings::kings()
{

}

kings::kings(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > kings::canMove()
{
	vector<vector<int> > valid;
	int rMove[4] = { 0, 0, -1, 1 };
	int cMove[4] = { 1, -1, 0, 0 };
	if (color == 'b')//黑色
	{//row 0~2 col 3~5
		for (int i = 0; i < 4; i++)
		{
			if (rowPos + rMove[i] >= 0 && rowPos + rMove[i] <= 2 && colPos + cMove[i] >= 3 && colPos + cMove[i] <= 5)
			{
				if (board::checkColor(rowPos + rMove[i], colPos + cMove[i]) != 'b')
				{
					valid.push_back(vector<int>{rowPos + rMove[i], colPos + cMove[i]});
				}
			}
		}
		for (int i = rowPos + 1; i <= 9; i++)//看看有沒有王見王
		{
			if (board::piece[i][colPos] == 0)
			{
				continue;
			}
			else if (board::piece[i][colPos] >= 2 && board::piece[i][colPos] <= 14 && board::piece[i][colPos] != 8)//中間有其他棋子
			{
				break;
			}
			else if (board::piece[i][colPos] == 8)
			{
				valid.push_back(vector<int>{i, colPos});
				break;
			}
		}
	}
	else//紅色
	{//row 7~9 col 3~5
		for (int i = 0; i < 4; i++)
		{
			if (rowPos + rMove[i] >= 7 && rowPos + rMove[i] <= 9 && colPos + cMove[i] >= 3 && colPos + cMove[i] <= 5)
			{
				if (board::checkColor(rowPos + rMove[i], colPos + cMove[i]) != 'r')
				{
					valid.push_back(vector<int>{rowPos + rMove[i], colPos + cMove[i]});
				}
			}
		}
		for (int i = rowPos - 1; i >= 0; i--)//看看有沒有王見王
		{
			if (board::piece[i][colPos] == 0)
			{
				continue;
			}
			else if (board::piece[i][colPos] >= 2 && board::piece[i][colPos] <= 14)//中間有其他棋子
			{
				break;
			}
			else if (board::piece[i][colPos] == 1)
			{
				valid.push_back(vector<int>{i, colPos});
				break;
			}
		}
	}

	return valid;
}

void kings::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void kings::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}