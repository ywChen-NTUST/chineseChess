#include<conio.h>
#include"KeyIn.h"

namespace Chen_Yan_Yu_KeyIn
{
	using namespace std;
	char KeyIn::readKey()
	{
		key = _getch();
		return key;
	}
	bool KeyIn::getSelected()
	{
		return selected;
	}
	bool KeyIn::getEsc()
	{
		return escTable;
	}
	void KeyIn::setSelected(bool b)
	{
		selected = b;
	}
	void KeyIn::setEsc(bool b)
	{
		escTable = b;
	}
}

/*
	char KeyIn::readKey()
	{
		key = _getch();

		switch (key)
		{
		case 0x0D://enter
			if (escTable == true)
			{
				//執行該動作
			}
			else
			{
				if (selected == true)//把棋子放在該游標位置
				{
					//判斷可不可以放,或者在manager判斷
				}
				else//選棋的函式
				{

				}
			}
			break;
		case 0x1B://esc
			if (escTable == true)
			{
				//關閉主選單
				escTable = false;
			}
			else
			{
				//跳出主選單
				escTable = true;
			}
			break;
		case 0x48://up
			//游標移動到上面一格
			break;
		case 0x50://down
			//游標移動到下面一格
			break;
		case 0x4D://right
			//游標移動到右邊一格
			break;
		case 0x4B://left
			//游標移動到左邊一格
			break;
		}
		return key;
	}

*/