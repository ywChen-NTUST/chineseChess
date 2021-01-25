#include"chariots.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

chariots::chariots()
{

}

chariots::chariots(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > chariots::canMove()
{
	vector<vector<int> > valid;
	for (int i = 1; colPos - i >= 0; i++)//往左走
	{
		if (board::piece[rowPos][colPos - i] == 0)//如果左邊沒棋子
		{
			valid.push_back(vector<int>{rowPos, colPos - i});
		}
		else
		{
			if (color == 'b' && board::checkColor(rowPos, colPos - i) == 'r')//是敵人
			{
				valid.push_back(vector<int>{rowPos, colPos - i});
			}
			if (color == 'r' && board::checkColor(rowPos, colPos - i) == 'b')//是敵人
			{
				valid.push_back(vector<int>{rowPos, colPos - i});
			}
			break;
		}
	}
	for (int i = 1; colPos + i <= 8; i++)//往右走
	{
		if (board::piece[rowPos][colPos + i] == 0)//如果右邊沒棋子
		{
			valid.push_back(vector<int>{rowPos, colPos + i});
		}
		else
		{
			if (color == 'b' && board::checkColor(rowPos, colPos + i) == 'r')//是敵人
			{
				valid.push_back(vector<int>{rowPos, colPos + i});
			}
			if (color == 'r' && board::checkColor(rowPos, colPos + i) == 'b')//是敵人
			{
				valid.push_back(vector<int>{rowPos, colPos + i});
			}
			break;
		}
	}
	for (int i = 1; rowPos - i >= 0; i++)//往上走
	{
		if (board::piece[rowPos - i][colPos] == 0)//如果上方沒棋子
		{
			valid.push_back(vector<int>{rowPos - i, colPos});
		}
		else//顯示上方可以移動
		{
			if (color == 'b' && board::checkColor(rowPos - i, colPos) == 'r')//是敵人
			{
				valid.push_back(vector<int>{rowPos - i, colPos});
			}
			if (color == 'r' && board::checkColor(rowPos - i, colPos) == 'b')//是敵人
			{
				valid.push_back(vector<int>{rowPos - i, colPos});
			}
			break;
		}
	}
	for (int i = 1; rowPos + i <= 9; i++)//往下走
	{
		if (board::piece[rowPos + i][colPos] == 0)//如果下方有棋子
		{
			valid.push_back(vector<int>{rowPos + i, colPos});
		}
		else//顯示下方可以移動
		{
			if (color == 'b' && board::checkColor(rowPos + i, colPos) == 'r')//是敵人
			{
				valid.push_back(vector<int>{rowPos + i, colPos});
			}
			if (color == 'r' && board::checkColor(rowPos + i, colPos) == 'b')//是敵人
			{
				valid.push_back(vector<int>{rowPos + i, colPos});
			}
			break;
		}
	}

	return valid;
}

void chariots::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void chariots::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}