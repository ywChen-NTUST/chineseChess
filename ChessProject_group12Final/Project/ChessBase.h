#include<vector>

#ifndef CHESSBASE_H
#define CHESSBASE_H

using std::vector;

class chess
{
public:
	chess();//We do not use it.
	chess(int row, int column);//constructor, for derived class
	virtual void eatMove(vector<int> v);
	vector<int> getPosition();
	virtual vector<vector<int> > canMove() = 0;
	virtual void setStatus(int row, int column, char camp, bool die) = 0;
	bool getDead();
	void setDead(bool b);
protected:
	bool dead = true;//此棋子是否已被吃
	char color;//此棋子的陣營
	int rowPos = 100;//隨便設的值
	int colPos = 100;//隨便設的值
};


#endif