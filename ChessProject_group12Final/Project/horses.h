#include"ChessBase.h"
#include<vector>

#ifndef HORSES_H
#define HORSES_H

using std::vector;

class horses :public chess
{
public:
	horses();
	horses(int row, int column, char camp);
	virtual void setStatus(int row, int column, char camp, bool die);
	/*virtual*/ vector<vector<int> > canMove();
	virtual void eatMove(vector<int> v);
protected:

};

#endif