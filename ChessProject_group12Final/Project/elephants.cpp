#include"elephants.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

elephants::elephants()
{

}

elephants::elephants(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > elephants::canMove()
{
	vector<vector<int> > valid;
	if (board::piece[rowPos - 1][colPos - 1] == 0)//左上方沒棋子
	{
		if (color == 'b' && rowPos - 2 >= 0 && colPos - 2 >= 0 && board::checkColor(rowPos - 2, colPos - 2) != 'b')//黑方
		{
			valid.push_back(vector<int>{rowPos - 2, colPos - 2});
		}
		if (color == 'r' && rowPos - 2 >= 5 && colPos - 2 >= 0 && board::checkColor(rowPos - 2, colPos - 2) != 'r')//紅方
		{
			valid.push_back(vector<int>{rowPos - 2, colPos - 2});
		}
	}
	if (board::piece[rowPos - 1][colPos + 1] == 0)//右上方沒棋子
	{
		if (color == 'b' && rowPos - 2 >= 0 && colPos + 2 <= 8 && board::checkColor(rowPos - 2, colPos + 2) != 'b')//黑方
		{
			valid.push_back(vector<int>{rowPos - 2, colPos + 2});
		}
		if (color == 'r' && rowPos - 2 >= 5 && colPos + 2 <= 8 && board::checkColor(rowPos - 2, colPos + 2) != 'r')//紅方
		{
			valid.push_back(vector<int>{rowPos - 2, colPos + 2});
		}
	}
	if (board::piece[rowPos + 1][colPos - 1] == 0)//左下方沒棋子
	{
		if (color == 'b' && rowPos + 2 <= 4 && colPos - 2 >= 0 && board::checkColor(rowPos + 2, colPos - 2) != 'b')//黑方
		{
			valid.push_back(vector<int>{rowPos + 2, colPos - 2});
		}
		if (color == 'r' && rowPos + 2 <= 9 && colPos - 2 >= 0 && board::checkColor(rowPos + 2, colPos - 2) != 'r')//紅方
		{
			valid.push_back(vector<int>{rowPos + 2, colPos - 2});
		}
	}
	if (board::piece[rowPos + 1][colPos + 1] == 0)//右下方沒棋子
	{
		if (color == 'b' && rowPos + 2 <= 4 && colPos + 2 <= 8 && board::checkColor(rowPos + 2, colPos + 2) != 'b')//黑方
		{
			valid.push_back(vector<int>{rowPos + 2, colPos + 2});
		}
		if (color == 'r' && rowPos + 2 <= 9 && colPos + 2 <= 8 && board::checkColor(rowPos + 2, colPos + 2) != 'r')//紅方
		{
			valid.push_back(vector<int>{rowPos + 2, colPos + 2});
		}
	}

	return valid;
}


void elephants::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void elephants::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}