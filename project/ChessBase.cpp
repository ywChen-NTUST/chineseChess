#include"ChessBase.h"
#include"chessboard.h"

using namespace Chen_Yan_Yu_Board;

chess::chess()
{

}
chess::chess(int row, int column) :rowPos(row), colPos(column)
{
	dead = true;
}

bool chess::getDead()
{
	return dead;
}

void chess::setDead(bool b)
{
	dead = b;
}
vector<int> chess::getPosition()
{
	return vector<int>{rowPos, colPos};
}

vector<vector<int> > chess::canMove()
{
	//do nothing
	return vector<vector<int>>{};
}
void chess::eatMove(vector<int> v)
{
	//do nothing
}