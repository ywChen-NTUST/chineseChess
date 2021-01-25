#include"cannons.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

cannons::cannons()
{

}

cannons::cannons(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > cannons::canMove()
{
	vector<vector<int> > valid;
	bool findEnemy = false;
	for (int i = 1; colPos - i >= 0; i++)//往左走
	{
		if (board::piece[rowPos][colPos - i] != 0)//如果左邊有棋子
		{
			for (i = i + 1; colPos - i >= 0; i++)//則其後方的第一個敵人可以吃
			{
				if (color == 'b' && board::checkColor(rowPos, colPos - i) == 'r')//如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos - i});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos, colPos - i) == 'b')//如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos - i});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//顯示左方可以移動
		{
			valid.push_back(vector<int>{rowPos, colPos - i});
		}
	}
	findEnemy = false;
	for (int i = 1; colPos + i <= 8; i++)//往右走
	{
		if (board::piece[rowPos][colPos + i] != 0)//如果右邊有棋子
		{
			for (i = i + 1; colPos + i <= 8; i++)//則其後方的第一個敵人可以吃
			{
				if (color == 'b' && board::checkColor(rowPos, colPos + i) == 'r')//如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos + i});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos, colPos + i) == 'b')//如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos + i});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//顯示右方可以移動
		{
			valid.push_back(vector<int>{rowPos, colPos + i});
		}
	}
	findEnemy = false;
	for (int i = 1; rowPos - i >= 0; i++)//往上走
	{
		if (board::piece[rowPos - i][colPos] != 0)//如果上方有棋子
		{
			for (i = i + 1; rowPos - i >= 0; i++)//則其後方的第一個敵人可以吃
			{
				if (color == 'b' && board::checkColor(rowPos - i, colPos) == 'r') //如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos - i, colPos});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos - i, colPos) == 'b') //如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos - i, colPos});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//顯示上方可以移動
		{
			valid.push_back(vector<int>{rowPos - i, colPos});
		}
	}
	findEnemy = false;
	for (int i = 1; rowPos + i <= 9; i++)//往下走
	{
		if (board::piece[rowPos + i][colPos] != 0)//如果下方有棋子
		{
			for (i = i + 1; rowPos + i <= 9; i++)//則其後方的第一個敵人可以吃
			{
				if (color == 'b' && board::checkColor(rowPos + i, colPos) == 'r')//如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos + i, colPos});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos + i, colPos) == 'b')//如果是敵人
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos + i, colPos});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//顯示下方可以移動
		{
			valid.push_back(vector<int>{rowPos + i, colPos});
		}
	}

	return valid;
}

void cannons::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void cannons::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}