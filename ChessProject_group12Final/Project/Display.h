#pragma once
#include<Windows.h>
#include<io.h>
#include<fcntl.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>

#include"chessboard.h"

enum Color
{
	black = 0,	//  黑色
	D_blue = 1,	//暗藍色(靛色)
	D_green = 2,	//暗綠色
	D_cyan = 3,	//暗青色
	D_red = 4,	//暗紅色(酒紅色)
	D_purple = 5,	//暗紫色
	D_yellow = 6,	//暗黃色(暗金色)
	D_white = 7,	//暗白色(淺灰色)
	gray = 8,	//  灰色(深灰色)
	L_blue = 9,	//亮藍色
	L_green = 10,	//亮綠色
	L_cyan = 11,	//亮青色
	L_red = 12,	//亮紅色
	L_purple = 13,	//亮紫色
	L_yellow = 14,	//亮黃色
	white = 15,	//  白色
};

class Display
{
private:
	HANDLE hConsole;
	COORD cursor;
	Color frontBoardColor, backBoardColor;

	static const std::wstring chessBoard[21];
	static const std::wstring recordBoard[21];
	static const std::wstring statusBoard[21];
	static const std::wstring chessIcon[15];
	static std::map<int, int> deadChessCount;

	static bool selectChess;
	static std::vector<std::vector<int> > movePointsCopy;
	static int nowRowCopy;
	static int nowColCopy;

	void printChessStatusTable();
	//std::wstring stringToWstring(const std::string s);
	void outputTextColor(const Color frontColor, const Color bgColor);

public:
	static Display* Instance;

	Display();
	~Display();
	bool SetWindowSize(short Width, short Height);

	void cleanScreen();
	void pause();
	void reset();
	void setColor(const Color frontColor, const Color bgColor);
	void moveCursor(int x, int y);

	void printBeginScreen();
	void printBoard();

	void printChess();
	void printCanMoveAndEat(std::vector<std::vector<int> > movePoints, int nowRow, int nowCol);
	void clearCanMoveAndEat();
	void printMenu();
	void printWinMenu();
	void printMenuSelect(int row, int lastrow = 0);
	void clearMenu();

	void printRound(std::string nowColor);
	void printWin(std::string winColor);
	void printSelectedChess(int chessCode);
	void printIllegalMsg();
	void printAlmostWinAlert(std::string almostWinColor);
	void clearAlmostwinAlert();
	void printDead(int chessCode);

	void printRecord(std::vector<std::wstring>& record);
};