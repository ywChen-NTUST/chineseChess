#include"cursor.h"

cursor::cursor() :rowPos(0), colPos(0), row(0)
{

}

void cursor::changePos(int r, int c)
{
	if (rowPos + r >= 0 && rowPos + r <= 9)
	{
		rowPos += r;
	}
	if (colPos + c >= 0 && colPos + c <= 8)
	{
		colPos += c;
	}
}

void cursor::changeRow(int i)
{
	if (row + i >= 3)
	{
		row = 0;
	}
	else if (row + i < 0)
	{
		row = 2;
	}
	else
	{
		row += i;
	}
}

vector<int> cursor::getCursorPos()
{
	return vector<int>{rowPos, colPos};
}