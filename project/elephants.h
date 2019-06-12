#include"ChessBase.h"
#include<vector>

#ifndef ELEPHANTS_H
#define ELEPHANTS_H

using std::vector;

class elephants :public chess
{
public:
	elephants();
	elephants(int row, int column, char camp);
	virtual void setStatus(int row, int column, char camp, bool die);
	/*virtual*/ vector<vector<int> > canMove();
	virtual void eatMove(vector<int> v);
protected:

};

#endif