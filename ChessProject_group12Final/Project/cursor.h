#include<vector>

#ifndef CURSOR_H
#define CURSOR_H

using std::vector;

class cursor
{
public:
	cursor();
	void changePos(int r, int c);
	void changeRow(int i);
	vector<int> getCursorPos();
private:
	int rowPos, colPos;//這是在棋盤裡用的
	int row;//遊戲選單裡用的
};

#endif // !CURSOR_H


