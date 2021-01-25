#include"ChessBase.h"
#include<vector>
#ifndef KINGS_H
#define KINGS_H

using std::vector;

class kings :public chess
{
public:
	kings();
	kings(int row, int column, char camp);
	virtual void setStatus(int row, int column, char camp, bool die);
	/*virtual*/ vector<vector<int> > canMove();
	virtual void eatMove(vector<int> v);
protected:
	bool found = false;//мOз_д¤игд¤
};

#endif
