#ifndef KEYIN
#define KEYIN

namespace Chen_Yan_Yu_KeyIn
{
	class KeyIn
	{
	public:
		char readKey();//manager用迴圈不停呼叫readKey讀取
		bool getSelected();
		bool getEsc();
		void setSelected(bool b);
		void setEsc(bool b);
	private:
		char key;
		bool selected = false;//判斷現在選棋子了沒
		bool escTable = false;//判斷使用者是否叫出選單
	};
}

#endif

