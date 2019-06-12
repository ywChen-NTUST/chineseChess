#include"ChessBase.h"
#include<vector>

#ifndef SOLDIERS_H
#define SOLDIERS_H

using std::vector;

class soldiers :public chess
{
public:
	soldiers();
	soldiers(int row, int column, char camp);
	virtual void setStatus(int row, int column, char camp, bool die);
	/*virtual*/ vector<vector<int> > canMove();
	virtual void eatMove(vector<int> v);
protected:
	bool crossRiver = false;
};

#endif
