#include"ChessBase.h"
#include<vector>

#ifndef CHARIOT_H
#define CHARIOT_H

using std::vector;

class chariots :public chess
{
public:
	chariots();
	chariots(int row, int column, char camp);
	virtual void setStatus(int row, int column, char camp, bool die);
	/*virtual*/ vector<vector<int> > canMove();
	virtual void eatMove(vector<int> v);
protected:

};

#endif