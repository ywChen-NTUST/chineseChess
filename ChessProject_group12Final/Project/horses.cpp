#include"horses.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

horses::horses()
{

}
horses::horses(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > horses::canMove()
{
	vector<vector<int> > valid;
	if (colPos - 2 >= 0 && board::piece[rowPos][colPos - 1] == 0)//左方沒棋子
	{
		if (rowPos + 1 <= 9 && color == 'b' && board::checkColor(rowPos + 1, colPos - 2) != 'b')//左下
		{
			valid.push_back(vector<int>{rowPos + 1, colPos - 2});
		}
		if (rowPos + 1 <= 9 && color == 'r' && board::checkColor(rowPos + 1, colPos - 2) != 'r')//左下
		{
			valid.push_back(vector<int>{rowPos + 1, colPos - 2});
		}
		if (rowPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos - 1, colPos - 2) != 'b')//左上
		{
			valid.push_back(vector<int>{rowPos - 1, colPos - 2});
		}
		if (rowPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos - 1, colPos - 2) != 'r')//左上
		{
			valid.push_back(vector<int>{rowPos - 1, colPos - 2});
		}
	}
	if (colPos + 2 <= 8 && board::piece[rowPos][colPos + 1] == 0)//右方沒棋子
	{
		if (rowPos + 1 <= 9 && color == 'b' && board::checkColor(rowPos + 1, colPos + 2) != 'b')//右下
		{
			valid.push_back(vector<int>{rowPos + 1, colPos + 2});
		}
		if (rowPos + 1 <= 9 && color == 'r' && board::checkColor(rowPos + 1, colPos + 2) != 'r')//右下
		{
			valid.push_back(vector<int>{rowPos + 1, colPos + 2});
		}
		if (rowPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos - 1, colPos + 2) != 'b')//右上
		{
			valid.push_back(vector<int>{rowPos - 1, colPos + 2});
		}
		if (rowPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos - 1, colPos + 2) != 'r')//右上
		{
			valid.push_back(vector<int>{rowPos - 1, colPos + 2});
		}
	}
	if (rowPos - 2 >= 0 && board::piece[rowPos - 1][colPos] == 0)//上方沒棋子
	{
		if (colPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos - 2, colPos - 1) != 'b')//上左
		{
			valid.push_back(vector<int>{rowPos - 2, colPos - 1});
		}
		if (colPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos - 2, colPos - 1) != 'r')//上左
		{
			valid.push_back(vector<int>{rowPos - 2, colPos - 1});
		}
		if (colPos + 1 <= 8 && color == 'b' && board::checkColor(rowPos - 2, colPos + 1) != 'b')//上右
		{
			valid.push_back(vector<int>{rowPos - 2, colPos + 1});
		}
		if (colPos + 1 <= 8 && color == 'r' && board::checkColor(rowPos - 2, colPos + 1) != 'r')//上右
		{
			valid.push_back(vector<int>{rowPos - 2, colPos + 1});
		}
	}
	if (rowPos + 2 <= 9 && board::piece[rowPos + 1][colPos] == 0)//下方沒棋子
	{
		if (colPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos + 2, colPos - 1) != 'b')//下左
		{
			valid.push_back(vector<int>{rowPos + 2, colPos - 1});
		}
		if (colPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos + 2, colPos - 1) != 'r')//下左
		{
			valid.push_back(vector<int>{rowPos + 2, colPos - 1});
		}
		if (colPos + 1 <= 8 && color == 'b' && board::checkColor(rowPos + 2, colPos + 1) != 'b')//下右
		{
			valid.push_back(vector<int>{rowPos + 2, colPos + 1});
		}
		if (colPos + 1 <= 8 && color == 'r' && board::checkColor(rowPos + 2, colPos + 1) != 'r')//下右
		{
			valid.push_back(vector<int>{rowPos + 2, colPos + 1});
		}
	}

	return valid;
}

void horses::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void horses::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}