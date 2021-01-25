#include"guards.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

guards::guards()
{

}

guards::guards(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > guards::canMove()
{
	vector<vector<int> > valid;
	if (color == 'b' && board::checkColor(rowPos - 1, colPos - 1) != 'b' && rowPos - 1 >= 0 && colPos - 1 >= 3)//左上方不為我方
	{
		valid.push_back(vector<int>{rowPos - 1, colPos - 1});
	}
	if (color == 'r' && board::checkColor(rowPos - 1, colPos - 1) != 'r' && rowPos - 1 >= 7 && colPos - 1 >= 3)//左上方不為我方
	{
		valid.push_back(vector<int>{rowPos - 1, colPos - 1});
	}


	if (color == 'b' && board::checkColor(rowPos - 1, colPos + 1) != 'b' && rowPos - 1 >= 0 && colPos + 1 <= 5)//右上方不為我方
	{
		valid.push_back(vector<int>{rowPos - 1, colPos + 1});
	}
	if (color == 'r' && board::checkColor(rowPos - 1, colPos + 1) != 'r' && rowPos - 1 >= 7 && colPos + 1 <= 5)//右上方不為我方
	{
		valid.push_back(vector<int>{rowPos - 1, colPos + 1});
	}


	if (color == 'b' && board::checkColor(rowPos + 1, colPos - 1) != 'b' && rowPos + 1 <= 2 && colPos - 1 >= 3)//左下方不為我方
	{
		valid.push_back(vector<int>{rowPos + 1, colPos - 1});
	}
	if (color == 'r' && board::checkColor(rowPos + 1, colPos - 1) != 'r' && rowPos + 1 <= 9 && colPos - 1 >= 3)//左下方不為我方
	{
		valid.push_back(vector<int>{rowPos + 1, colPos - 1});
	}

	if (color == 'b' && board::checkColor(rowPos + 1, colPos + 1) != 'b' && rowPos + 1 <= 2 && colPos + 1 <= 5)//右下方不為我方
	{
		valid.push_back(vector<int>{rowPos + 1, colPos + 1});
	}
	if (color == 'r' && board::checkColor(rowPos + 1, colPos + 1) != 'r' && rowPos + 1 <= 9 && colPos + 1 <= 5)//右下方不為我方
	{
		valid.push_back(vector<int>{rowPos + 1, colPos + 1});
	}

	return valid;
}


void guards::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void guards::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}