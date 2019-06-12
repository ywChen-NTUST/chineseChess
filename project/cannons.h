#include"ChessBase.h"
#include<vector>

#ifndef CANNONS_H
#define CANNONS_H

using std::vector;

class cannons :public chess
{
public:
	cannons();
	cannons(int row, int column, char camp);
	virtual void setStatus(int row, int column, char camp, bool die);
	/*virtual*/ vector<vector<int> > canMove();
	virtual void eatMove(vector<int> v);
protected:

};

#endif
