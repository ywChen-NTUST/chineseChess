#include"ChessBase.h"
#include<vector>

#ifndef GUARDS_H
#define GUARDS_H

using std::vector;

class guards :public chess
{
public:
	guards();
	guards(int row, int column, char camp);
	virtual void setStatus(int row, int column, char camp, bool die);
	/*virtual*/ vector<vector<int> > canMove();
	virtual void eatMove(vector<int> v);
protected:

};

#endif