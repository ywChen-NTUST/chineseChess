#include"Display.h"

Display* Display::Instance;

const std::wstring Display::chessBoard[21] =
{
	L" １ˉ２ˉ３ˉ４ˉ５ˉ６ˉ７ˉ８ˉ９ ",
	L" ╔═╤═╤═╤═╤═╤═╤═╤═╗ ",
	L" ║ˉ│ˉ│ˉ│＼│／│ˉ│ˉ│ˉ║ ",
	L" ╠─┼─┼─┼─┼─┼─┼─┼─╣ ",
	L" ║ˉ│ˉ│ˉ│／│＼│ˉ│ˉ│ˉ║ ",
	L" ╠─┼─┼─┼─┼─┼─┼─┼─╣ ",
	L" ║ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ║ ",
	L" ╠─┼─┼─┼─┼─┼─┼─┼─╣ ",
	L" ║ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ║ ",
	L" ╠─┴─┴─┴─┴─┴─┴─┴─╣ ",
	L" ║ˉˉˉ楚河ˉˉˉˉˉ漢界ˉˉˉ║ ",
	L" ╠─┬─┬─┬─┬─┬─┬─┬─╣ ",
	L" ║ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ║ ",
	L" ╠─┼─┼─┼─┼─┼─┼─┼─╣ ",
	L" ║ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ║ ",
	L" ╠─┼─┼─┼─┼─┼─┼─┼─╣ ",
	L" ║ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ║ ",
	L" ╠─┼─┼─┼─┼─┼─┼─┼─╣ ",
	L" ║ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ│ˉ║ ",
	L" ╚═╧═╧═╧═╧═╧═╧═╧═╝ ",
	L" 九ˉ八ˉ七ˉ六ˉ五ˉ四ˉ三ˉ二ˉ一 "
};

const std::wstring Display::recordBoard[21] = 
{
	L" ╔═ˉ戰ˉ況ˉ顯ˉ示ˉ═╗",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ║ˉˉˉˉˉˉˉˉˉˉˉ║",
	L" ╚═══════════╝"
};

const std::wstring Display::statusBoard[21] = 
{
	L"╔═══ˉ訊ˉ息ˉ顯ˉ示ˉ════╗ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"╠───ˉ棋ˉ子ˉ狀ˉ態ˉ────╣ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"╠───ˉ操ˉ作ˉ說ˉ明ˉ────╣ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ˉEsc 選單ˉˉ< 悔棋ˉ> 還原ˉˉ║ ",
	L"║ ˉˉEnterˉˉ 選取棋子 ˉˉ  ˉ║ ",
	L"║ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ║ ",
	L"║ ˉˉˉ↑ ˉˉˉˉˉˉˉˉˉ  ˉ║ ",
	L"║ ˉˉ←ˉ→ ˉ方向鍵選取游標  ˉ║ ",
	L"║ ˉˉˉ↓ ˉˉˉˉˉˉˉˉˉ  ˉ║ ",
	L"╚════════════════╝ "
};

const std::wstring  Display::chessIcon[15] =
{
	L"",
	L"將", L"士", L"象", L"車", L"馬", L"包", L"卒",
	L"帥", L"仕", L"相", L"車", L"傌", L"炮", L"兵"
};

std::map<int, int> Display::deadChessCount =
{
	//chesscode : count
	{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0},
	{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}
};

bool Display::selectChess = false;
std::vector<std::vector<int> > Display::movePointsCopy;
int Display::nowRowCopy = 0;
int Display::nowColCopy = 0;

Display::Display()
{
	//將輸出設為unicoode 形式
	_setmode(_fileno(stdout), _O_WTEXT);

	//取得輸出handle，當需要改輸出設定時使用
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//initialize status
	for (int i = 1; i <= 14; i++)
	{
		Display::deadChessCount[i] = 0;
	}

	//initialize cursor's pos
	cursor.X = 0;
	cursor.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor);

	//將文字輸出設為黑底白字
	outputTextColor(Color::D_white, Color::black);
}
Display::~Display()
{
	std::wcout << "You can't delete it!!! There might have some problem";
}

// * 設定視窗大小，寬度與高度以字元數計算，若是設定超過螢幕大小則設定成最大。(注意:字元大小以半形計算，全形字佔兩個半行字寬)
bool Display::SetWindowSize(short Width, short Height)
{
	COORD NewSBSize = GetLargestConsoleWindowSize(hConsole);
	if (Width >= NewSBSize.X) {
		Width = NewSBSize.X - 1;
	}
	if (Height >= NewSBSize.Y) {
		Height = NewSBSize.Y - 1;
	}
	//CanvasWidth = Width / 2;
	//CanvasHeight = Height;
	SMALL_RECT windowSize = { 0, 0, Width, Height };
	SetConsoleScreenBufferSize(hConsole, NewSBSize);
	//InitCanvas();
	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize))
	{
		std::wcout << "SetConsoleWindowInfo failed with error " << GetLastError() << std::endl;
		return false;
	}
	return true;
}

void Display::cleanScreen()
{
	outputTextColor(Color::D_white, Color::black);
	system("cls");
}

void Display::pause()
{
	cursor.X = 0;
	cursor.Y = 21;
	SetConsoleCursorPosition(hConsole, cursor);

	outputTextColor(Color::D_white, Color::black);
	system("pause");
}

void Display::reset()
{
	//initialize status
	for (int i = 1; i <= 14; i++)
	{
		Display::deadChessCount[i] = 0;
	}

	//initialize cursor's pos
	cursor.X = 0;
	cursor.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor);

	//將文字輸出設為黑底白字
	outputTextColor(Color::D_white, Color::black);
}

void Display::setColor(const Color frontColor, const Color bgColor)
{
	frontBoardColor = frontColor;
	backBoardColor = bgColor;
	outputTextColor(frontBoardColor, backBoardColor);
}

void Display::moveCursor(int x, int y)
{
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(hConsole, cursor);

}

void Display::printBeginScreen()
{
	cursor.X = 0;
	cursor.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::L_blue, Color::white);
	//99*21
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"      ####  #    # ##### #    # ######  ####  ######         ####  #    # ######  ####   ####      " << std::endl;
	std::wcout << L"     #    # #    #   #   ##   # #      #      #             #    # #    # #      #      #          " << std::endl;
	std::wcout << L"     #      ######   #   # #  # #####   ####  #####         #      ###### #####   ####   ####      " << std::endl;
	std::wcout << L"     #      #    #   #   #  # # #           # #             #      #    # #           #      #     " << std::endl;
	std::wcout << L"     #    # #    #   #   #   ## #      #    # #             #    # #    # #      #    # #    #     " << std::endl;
	std::wcout << L"      ####  #    # ##### #    # ######  ####  ######         ####  #    # ######  ####   ####      " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                _                 __                                         |                     " << std::endl;
	std::wcout << L"               |_)  _ _  _  _    |_  _  _|_ _   _   _|_ _     _ _|_ _   __|_ |                     " << std::endl;
	std::wcout << L"               |   | (/__> _>    |__| |  |_(/_ |     |_(_)   _>  |_(/| |  |_ o                     " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;
	std::wcout << L"                                                                                                   " << std::endl;

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printBoard()
{
	cursor.X = 0;
	cursor.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor);
	for (int i = 0; i < 21; i++)
	{
		outputTextColor(Color::L_blue, Color::white);
		std::wcout << recordBoard[i];
		outputTextColor(Color::black, Color::D_yellow);
		std::wcout << chessBoard[i];
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << statusBoard[i] << std::endl;
	}
	std::wcout << std::endl;

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printChess()
{
	int existChessCount[15] = 
	{
		0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0
	};
	const int optimalChessCount[15] = 
	{
		0,
		1,2,2,2,2,2,5,
		1,2,2,2,2,2,5
	};

	cursor.Y = 1;
	for (int i = 0; i < 10; i++)
	{
		cursor.X = 28 + 0;
		for (int j = 0; j < 9; j++)
		{
			SetConsoleCursorPosition(hConsole, cursor);

			if (Chen_Yan_Yu_Board::board::checkColor(i, j) != 'n')
			{
				if (Chen_Yan_Yu_Board::board::checkColor(i,j) == 'b')
				{
					outputTextColor(Color::black, Color::white);
				}
				else
				{
					outputTextColor(Color::L_red, Color::white);
				}
				std::wcout << chessIcon[Chen_Yan_Yu_Board::board::piece[i][j]] << std::endl;

				existChessCount[Chen_Yan_Yu_Board::board::piece[i][j]] += 1;
			}
				
			//next x
			cursor.X += 4;
		}
		//next line
		cursor.Y += 2;
	}

	//chess status initialize
	for (int i = 1; i <= 14; i++)
	{
		int dead = optimalChessCount[i] - existChessCount[i];
		if (dead < 0)
		{
			dead = 0;
		}
		Display::deadChessCount[i] = dead;
	}
	printChessStatusTable();

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printCanMoveAndEat(std::vector<std::vector<int> > movePoints, int nowRow, int nowCol)
{
	//print selected point
	cursor.X = 28 + nowCol * 4;
	cursor.Y = 1 + nowRow * 2;
	SetConsoleCursorPosition(hConsole, cursor);
	if (Chen_Yan_Yu_Board::board::checkColor(nowRow, nowCol) == 'b')
	{
		outputTextColor(Color::black, Color::L_cyan);
	}
	else if (Chen_Yan_Yu_Board::board::checkColor(nowRow, nowCol) == 'r')
	{
		outputTextColor(Color::D_red, Color::L_cyan);
	}
	std::wcout << chessIcon[Chen_Yan_Yu_Board::board::piece[nowRow][nowCol]];

	//print can move and eat
	for (unsigned int i = 0; i < movePoints.size(); i++)
	{
		cursor.X = 28 + movePoints[i][1] * 4;
		cursor.Y = 1 + movePoints[i][0] * 2;
		SetConsoleCursorPosition(hConsole, cursor);
		//print can move
		if (Chen_Yan_Yu_Board::board::checkColor(movePoints[i][0], movePoints[i][1]) == 'n')
		{
			outputTextColor(Color::black, Color::D_white);
			std::wcout << chessBoard[1 + movePoints[i][0] * 2][1 + movePoints[i][1] * 2] /*<< chessBoard[1 + movePoints[i][0] * 2][1 + movePoints[i][1] * 4 + 1]*/;
		}
		//print can eat
		else
		{
			if (Chen_Yan_Yu_Board::board::checkColor(movePoints[i][0], movePoints[i][1]) == 'b')
			{
				outputTextColor(Color::black, Color::L_purple);
			}
			else
			{
				outputTextColor(Color::D_red, Color::L_purple);
			}
			std::wcout << chessIcon[Chen_Yan_Yu_Board::board::piece[movePoints[i][0]][movePoints[i][1]]];
		}
	}

	//keep a copy and setting
	Display::selectChess = true;
	Display::movePointsCopy = movePoints;
	Display::nowRowCopy = nowRow;
	Display::nowColCopy = nowCol;

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::clearCanMoveAndEat()
{
	cursor.X = 27;
	cursor.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor);

	outputTextColor(Color::black, Color::D_yellow);
	for (int i = 0; i < 21; i++)
	{
		cursor.X = 27;
		std::wcout << chessBoard[i];
		cursor.Y += 1;
		SetConsoleCursorPosition(hConsole, cursor);
	}
	std::wcout << std::endl;

	printChess();
	
	//change setting
	Display::selectChess = false;

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printMenu()
{
	std::wstring menu[7] = {
		L"╔════╗",
		L"║ˉˉˉˉ║",
		L"╠────╣",
		L"║ˉˉˉˉ║",
		L"╠────╣",
		L"║ˉˉˉˉ║",
		L"╚════╝"
	};
	std::wstring text[3] = {
		L"繼續遊戲",
		L"重新開始",
		L"離開遊戲"
	};
	cursor.X = 46;
	cursor.Y = 7;
	//SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::L_blue, Color::D_white);
	for (int i = 0; i < 7; i++)
	{
		cursor.X = 46;
		SetConsoleCursorPosition(hConsole, cursor);
		std::wcout << menu[i];
		cursor.Y += 1;
	}

	cursor.X = 48;
	cursor.Y = 8;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::black, Color::D_white);
	for (int i = 0; i < 3; i++)
	{
		cursor.X = 48;
		SetConsoleCursorPosition(hConsole, cursor);
		std::wcout << text[i];
		cursor.Y += 2;
	}


	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printWinMenu()
{
	printMenu();

	cursor.X = 48;
	cursor.Y = 8;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::gray, Color::D_white);
	std::wcout << L"繼續遊戲";

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printMenuSelect(int row, int lastrow)
{
	std::wstring text[3] = {
		L"繼續遊戲",
		L"重新開始",
		L"離開遊戲"
	};
	cursor.X = 48;

	cursor.Y = 8 + lastrow * 2;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::black, Color::D_white);
	std::wcout << text[lastrow];

	cursor.Y = 8 + row * 2;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::L_blue, Color::white);
	std::wcout << text[row];

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::clearMenu()
{
	cursor.X = 27;
	cursor.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor);

	outputTextColor(Color::black, Color::D_yellow);
	for (int i = 0; i < 21; i++)
	{
		cursor.X = 27;
		std::wcout << chessBoard[i];
		cursor.Y += 1;
		SetConsoleCursorPosition(hConsole, cursor);
	}
	std::wcout << std::endl;

	printChess();

	if (selectChess)
	{
		printCanMoveAndEat(movePointsCopy, nowRowCopy, nowColCopy);
	}

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printRound(std::string nowColor)
{
	cursor.X = 76;
	cursor.Y = 3;
	SetConsoleCursorPosition(hConsole, cursor);
	
	if (nowColor == "red")
	{
		//red
		outputTextColor(Color::L_red, Color::D_white);
		std::wcout << L"紅方";
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << L"ˉ回合";

		cursor.X = 74;
		cursor.Y += 1;
		SetConsoleCursorPosition(hConsole, cursor);
		for (int j = 0; j < 14; j++)
		{
			std::wcout << L" ";
		}
	}
	else if(nowColor == "black")
	{
		//black
		outputTextColor(Color::black, Color::D_white);
		std::wcout << L"黑方";
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << L"ˉ回合";

		cursor.X = 74;
		cursor.Y += 1;
		SetConsoleCursorPosition(hConsole, cursor);
		for (int j = 0; j < 14; j++)
		{
			std::wcout << L" ";
		}
	}

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printWin(std::string winColor)
{
	
	if (winColor == "red")
	{
		//clean status windows
		cursor.X = 66;
		cursor.Y = 1;
		outputTextColor(Color::L_blue, Color::D_white);
		for (int i = 0; i < 5; i++)
		{
			SetConsoleCursorPosition(hConsole, cursor);
			for (int j = 0; j < 30; j++)
			{
				std::wcout << L" ";
			}
			cursor.Y += 1;
		}
		
		cursor.X = 76;
		cursor.Y = 3;
		SetConsoleCursorPosition(hConsole, cursor);
		//red
		outputTextColor(Color::L_red, Color::D_white);
		std::wcout << L"紅方";
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << L"ˉ獲勝";
	}
	else if (winColor == "black")
	{
		//clean status windows
		cursor.X = 66;
		cursor.Y = 1;
		outputTextColor(Color::L_blue, Color::D_white);
		for (int i = 0; i < 5; i++)
		{
			SetConsoleCursorPosition(hConsole, cursor);
			for (int j = 0; j < 30; j++)
			{
				std::wcout << L" ";
			}
			cursor.Y += 1;
		}

		cursor.X = 76;
		cursor.Y = 3;
		SetConsoleCursorPosition(hConsole, cursor);
		//black
		outputTextColor(Color::black, Color::D_white);
		std::wcout << L"黑方";
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << L"ˉ獲勝";
	}

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printSelectedChess(int chessCode)
{
	if (chessCode >= 1 && chessCode <= 14)
	{
		cursor.X = 74;
		cursor.Y = 4;
		SetConsoleCursorPosition(hConsole, cursor);
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << L"您選擇了ˉ";

		if (chessCode <= 7)
		{
			outputTextColor(Color::black, Color::D_white);
		}
		else
		{
			outputTextColor(Color::L_red, Color::D_white);
		}
		std::wcout << chessIcon[chessCode];
	}
	std::wcout << L"ˉ";

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printIllegalMsg()
{
	cursor.X = 74;
	cursor.Y = 4;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::L_red, Color::D_white);
	std::wcout << L"不合法的操作！";

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printAlmostWinAlert(std::string almostWinColor)
{
	cursor.X = 76;
	cursor.Y = 2;
	SetConsoleCursorPosition(hConsole, cursor);

	if (almostWinColor == "red")
	{
		outputTextColor(Color::black, Color::D_white);
		std::wcout << L"黑方";
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << L"被將軍";
	}
	else if (almostWinColor == "black")
	{
		outputTextColor(Color::L_red, Color::D_white);
		std::wcout << L"紅方";
		outputTextColor(Color::L_blue, Color::D_white);
		std::wcout << L"被將軍";
	}

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}
void Display::clearAlmostwinAlert()
{
	cursor.X = 76;
	cursor.Y = 2;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::L_blue, Color::D_white);
	std::wcout << L"ˉˉˉˉˉ";

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printDead(int chessCode)
{
	Display::deadChessCount[chessCode] += 1;
	printChessStatusTable();
}

void Display::printRecord(std::vector<std::wstring>& record)
{
	cursor.X = 3;
	cursor.Y = 1;
	SetConsoleCursorPosition(hConsole, cursor);
	outputTextColor(Color::L_blue, Color::white);

	int startIndex = 0;
	//prevent print over range
	if (record.size() > 19)
	{
		startIndex = record.size() - 19;
	}

	for (unsigned int i = 0; i < 19; i++)
	{
		if (i >= record.size())
		{
			break;
		}
		cursor.X = 3;
		SetConsoleCursorPosition(hConsole, cursor);
		std::wcout << std::setw(2) << i + startIndex + 1 << " ";
		std::wcout << record[i + startIndex];

		//clear lastest msg
		for (int t = 0; t < 18 - ((int)record[i + startIndex].length() * 2); t++)
		{
			std::wcout << L" ";
		}

		cursor.Y += 1;
	}

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

void Display::printChessStatusTable()
{
	cursor.X = 66;
	cursor.Y = 7;
	SetConsoleCursorPosition(hConsole, cursor);

	std::map<int, int> chessCount =
	{
		//chesscode:count
		{1, 1}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 5},
		{8, 1}, {9, 2}, {10, 2}, {11, 2}, {12, 2}, {13, 2}, {14, 5}
	};

	for (int i = 1; i <= 7; i++)
	{
		cursor.Y = 7;

		outputTextColor(Color::black, Color::D_white);
		
		for (int j = 0; j < chessCount[i]; j++)
		{
			SetConsoleCursorPosition(hConsole, cursor);
			if (j < chessCount[i] - Display::deadChessCount[i])
			{
				std::wcout << chessIcon[i];
			}
			else
			{
				std::wcout << L"Ｘ";
			}
			
			cursor.Y += 1;
		}

		cursor.X += 2;
	}
	cursor.X += 2;
	for (int i = 8; i <= 14; i++)
	{
		cursor.Y = 7;

		outputTextColor(Color::L_red, Color::D_white);

		for (int j = 0; j < chessCount[i]; j++)
		{
			SetConsoleCursorPosition(hConsole, cursor);
			if (j < chessCount[i] - Display::deadChessCount[i])
			{
				std::wcout << chessIcon[i];
			}
			else
			{
				std::wcout << L"Ｘ";
			}
			cursor.Y += 1;
		}

		cursor.X += 2;
	}

	//initialize
	outputTextColor(Color::D_white, Color::black);
	cursor.X = 0;
	cursor.Y = 0;
}

/*std::wstring Display::stringToWstring(const std::string s)
{
	std::wstring ws;
	ws.assign(s.begin(), s.end());
	return ws;
}*/

void Display::outputTextColor(const Color frontColor, const Color bgColor)
{
	int colorIndex = bgColor * 16 + frontColor;
	SetConsoleTextAttribute(hConsole, colorIndex);
}