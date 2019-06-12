#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<map>
#include"KeyIn.h"
#include"Document.h"
#include"ChessBase.h"
#include"cursor.h"
#include"soldiers.h"
#include"cannons.h"
#include"horses.h"
#include"chariots.h"
#include"elephants.h"
#include"guards.h"
#include"kings.h"
#include"chessboard.h"
#include"Display.h"

using namespace Chen_Yan_Yu_Board;
using namespace Chen_Yan_Yu_KeyIn;
using namespace Chen_Yan_Yu_Document;
using namespace std;

void placeInitialChess(map<string, chess*>& blackMap, map<string, chess*>& redMap);
void determineMessage(string name, vector<int> fromPos, vector<int> toPos, int turn, vector<wstring>& outputMessage);
int chessNameToCode(string chessName, char color);
void changeChessboard(int twoDimArr[10][9], vector<int> fromPos, vector<int> toPos);
bool defense(int turn, map<string, chess*>& blackMap, map<string, chess*>& redMap);

int main()
{
	KeyIn control;
	cursor cur;
	Display::Instance = new Display();
	Display *output = Display::Instance;
	output->SetWindowSize(99, 21+1);

	map<string, chess*> blackMap;
	map<string, chess*> redMap;
	vector<wstring> outputMessage;
	int turn;

	//print main screen
	output->printBeginScreen();
	output->moveCursor(79, 16);
	while (control.readKey() != 0x0D)//Enter
	{
		//nothing
	}

	RESTART:

	//read file
	document txtControl("Initial.txt", board::piece, turn);
	placeInitialChess(blackMap, redMap);

	//print Board
	output->printBoard();
	output->printChess();
	if (turn == 1)
	{
		output->printRound("red");
	}
	else
	{
		output->printRound("black");
	}
	output->moveCursor(28, 1);

	vector<int> fromPos, toPos;
	string blackName = "";
	string redName = "";

	while (true)
	{
		char key;

		//*check win or not*//
		if (redMap["king2"]->getDead() || blackMap["king1"]->getDead())//win
		{
			if (redMap["king2"]->getDead())
			{
				output->printWin("black");
			}
			else
			{
				output->printWin("red");
			}

			output->printWinMenu();

			int menuSelect = 1;
			output->printMenuSelect(menuSelect, 1);
			while (true)
			{
				key = control.readKey();
				if (key == 0x48/*UP*/)
				{
					int originalSelect = menuSelect;
					if (menuSelect == 1)
					{
						menuSelect = 2;
					}
					else
					{
						menuSelect -= 1;
					}
					output->printMenuSelect(menuSelect, originalSelect);
				}
				else if (key == 0x50/*DOWN*/)
				{
					int originalSelect = menuSelect;
					if (menuSelect == 2)
					{
						menuSelect = 1;
					}
					else
					{
						menuSelect += 1;
					}
					output->printMenuSelect(menuSelect, originalSelect);
				}
				else if (key == 0x0D/*Enter*/)
				{
					if (menuSelect == 1)
					{
						//new game
						//initialize
						int initialBoard[10][9] = {
							4,5,3,2,1,2,3,5,4,
							0,0,0,0,0,0,0,0,0,
							0,6,0,0,0,0,0,6,0,
							7,0,7,0,7,0,7,0,7,
							0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,
							14,0,14,0,14,0,14,0,14,
							0,13,0,0,0,0,0,13,0,
							0,0,0,0,0,0,0,0,0,
							11,12,10,9,8,9,10,12,11
						};
						turn = 1;
						txtControl.writeBoard(initialBoard, turn);

						blackMap.clear();
						redMap.clear();
						outputMessage.clear();
						output->reset();
						fromPos.clear();
						toPos.clear();
						cur.changePos(-(cur.getCursorPos()[0]), -(cur.getCursorPos()[1]));
						control.setSelected(false);
						control.setEsc(false);

						output->moveCursor(79, 16);

						goto RESTART; //row50

						//break;
					}
					else if (menuSelect == 2)
					{
						return 0;
					}
				}
			}

		}/*end win process*/

		/*check almost win*/
		bool redAlmostWin = defense(0, blackMap, redMap);
		bool blackAlmostWin = defense(1, blackMap, redMap);

		if (redAlmostWin && blackAlmostWin)
		{
			if (turn == 0)
			{
				output->printAlmostWinAlert("black");
			}
			else
			{
				output->printAlmostWinAlert("red");
			}
		}
		else if (redAlmostWin)
		{
			output->printAlmostWinAlert("red");
		}
		else if (blackAlmostWin)
		{
			output->printAlmostWinAlert("black");
		}
		else
		{
			output->clearAlmostwinAlert();
		}

		output->moveCursor(cur.getCursorPos()[1] * 4 + 28, cur.getCursorPos()[0] * 2 + 1);
		/*end almost win process*/


		key = control.readKey();

		//*menu control*//
		if (key == 0x1B/*ESC*/)
		{
			output->printMenu();
			int menuSelect = 0;
			output->printMenuSelect(menuSelect);

			while (true)
			{
				key = control.readKey();

				if (key == 0x1B/*ESC*/)
				{
					break;
				}
				else if (key == 0x48/*UP*/)
				{
					cur.changeRow(-1);
					int oldMenuSelect = menuSelect;

					menuSelect -= 1;
					if (menuSelect < 0)
					{
						menuSelect = 2;
					}

					output->printMenuSelect(menuSelect, oldMenuSelect);
				}
				else if (key == 0x50/*DOWN*/)
				{
					cur.changeRow(1);
					int oldMenuSelect = menuSelect;

					menuSelect += 1;
					if (menuSelect > 2)
					{
						menuSelect = 0;
					}

					output->printMenuSelect(menuSelect, oldMenuSelect);
				}
				else if (key == 0x0D/*Enter*/)
				{
					if (menuSelect == 0)
					{
						break;
					}
					else if (menuSelect == 1)
					{
						//new game
						//initialize
						int initialBoard[10][9] = {
							4,5,3,2,1,2,3,5,4,
							0,0,0,0,0,0,0,0,0,
							0,6,0,0,0,0,0,6,0,
							7,0,7,0,7,0,7,0,7,
							0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,
							14,0,14,0,14,0,14,0,14,
							0,13,0,0,0,0,0,13,0,
							0,0,0,0,0,0,0,0,0,
							11,12,10,9,8,9,10,12,11
						};
						turn = 1;
						txtControl.writeBoard(initialBoard, turn);

						blackMap.clear();
						redMap.clear();
						outputMessage.clear();
						output->reset();
						fromPos.clear();
						toPos.clear();
						cur.changePos(-(cur.getCursorPos()[0]), -(cur.getCursorPos()[1]));
						control.setSelected(false);
						control.setEsc(false);
						
						output->moveCursor(79, 16);

						goto RESTART; //row50

						//break;
					}
					else if (menuSelect == 2)
					{
						return 0;
					}
				}
			}

			//close menu
			output->clearMenu();
			output->moveCursor(cur.getCursorPos()[1] * 4 + 28, cur.getCursorPos()[0] * 2 + 1);
		}//*End menu control*//

		else if (key == ','/*<*/)
		{
			/*printPreviousBoard();
			writeFile();*/
		}//*End repent control*//
		else if (key == '.'/*>*/)
		{
			/*printOriginalBoard();
			writeFile();*/
		}//**End recovery control*//

		else if (key == 0x48/*UP*/)
		{
			cur.changePos(-1, 0);//游標移動到上面一格
			output->moveCursor(cur.getCursorPos()[1] * 4 + 28, cur.getCursorPos()[0] * 2 + 1);
		}
		else if (key == 0x50/*DOWN*/)
		{
			cur.changePos(1, 0);//游標移動到下面一格
			output->moveCursor(cur.getCursorPos()[1] * 4 + 28, cur.getCursorPos()[0] * 2 + 1);
		}
		else if (key == 0x4B/*LEFT*/)
		{
			cur.changePos(0, -1);//游標移動到左邊一格
			output->moveCursor(cur.getCursorPos()[1] * 4 + 28, cur.getCursorPos()[0] * 2 + 1);
		}
		else if (key == 0x4D/*RIGHT*/)
		{
			cur.changePos(0, 1);//游標移動到右邊一格
			output->moveCursor(cur.getCursorPos()[1] * 4 + 28, cur.getCursorPos()[0] * 2 + 1);
		}//**End cursor control*//

		else if (key == 0x0D/*ENTER*/)
		{
			if (!control.getSelected()/*not selected*/)
			{
				//print can move
				fromPos = cur.getCursorPos();

				if (turn == 1)
				{
					for (auto iter = redMap.begin(); iter != redMap.end(); iter++)
					{
						if ((iter->second)->getPosition() == fromPos && !((iter->second)->getDead()))
						{
							//iter->second.canMove();
							redName = iter->first;
							output->printCanMoveAndEat(redMap[redName]->canMove(), fromPos[0], fromPos[1]);
							output->printSelectedChess(board::getBoard(fromPos));
							output->moveCursor(fromPos[1] * 4 + 28, fromPos[0] * 2 + 1);

							control.setSelected(true);
							break;
						}
					}
				}
				else
				{
					for (auto iter = blackMap.begin(); iter != blackMap.end(); iter++)
					{
						if ((iter->second)->getPosition() == fromPos && !((iter->second)->getDead()))
						{
							//(iter->second)->canMove();
							blackName = iter->first;
							output->printCanMoveAndEat(blackMap[blackName]->canMove(), fromPos[0], fromPos[1]);
							output->printSelectedChess(board::getBoard(fromPos));
							output->moveCursor(fromPos[1] * 4 + 28, fromPos[0] * 2 + 1);

							control.setSelected(true);
							break;
						}
					}
				}
			}//**End select chess control*//
			else
			{
				toPos = cur.getCursorPos();

				//no move
				if (toPos == fromPos)
				{
					output->clearCanMoveAndEat();
					if (turn == 1)
					{
						output->printRound("red");
					}
					else
					{
						output->printRound("black");
					}
					output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);
					control.setSelected(false);
				}
				else
				{
					if (board::getBoard(toPos) == 0/*move only*/)
					{
						
						if (turn == 1)
						{
							vector<vector<int> > moveable = redMap[redName]->canMove();
							for (unsigned int i = 0; i < moveable.size(); i++)
							{
								if (moveable[i] == toPos)
								{
									redMap[redName]->eatMove(toPos);
									changeChessboard(board::piece, fromPos, toPos);
									output->printChess();

									determineMessage(redName, fromPos, toPos, turn, outputMessage);//中式記譜法
									output->printRecord(outputMessage);

									output->clearCanMoveAndEat();
									//change turn
									if (turn == 1)
									{
										turn = 0;
										output->printRound("black");
									}
									else
									{
										turn = 1;
										output->printRound("red");
									}
									output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);

									control.setSelected(false);

									break;
								}
							}

							//access wrong position
							if (control.getSelected())
							{
								output->printIllegalMsg();
								output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);
							}
						}
						else
						{
							vector<vector<int> > moveable = blackMap[blackName]->canMove();
							for (unsigned int i = 0; i < moveable.size(); i++)
							{
								if (moveable[i] == toPos)
								{
									blackMap[blackName]->eatMove(toPos);
									changeChessboard(board::piece, fromPos, toPos);
									output->printChess();

									determineMessage(blackName, fromPos, toPos, turn, outputMessage);//中式記譜法
									output->printRecord(outputMessage);

									output->clearCanMoveAndEat();
									//change turn
									if (turn == 1)
									{
										turn = 0;
										output->printRound("black");
									}
									else
									{
										turn = 1;
										output->printRound("red");
									}
									output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);

									control.setSelected(false);

									break;
								}
							}

							//access wrong position
							if (control.getSelected())
							{
								output->printIllegalMsg();
								output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);
							}
						}
						
					}/*end move chess part*/
					else if (board::getBoard(toPos) >= 1 && board::getBoard(toPos) <= 14 /*eat*/)
					{
						//print dead
						if (turn == 1)
						{
							vector<vector<int> > moveable = redMap[redName]->canMove();
							for (unsigned int i = 0; i < moveable.size(); i++)
							{
								if (moveable[i] == toPos)
								{
									
									redMap[redName]->eatMove(toPos);
									for (auto iter = blackMap.begin(); iter != blackMap.end(); iter++)
									{
										if ((iter->second)->getPosition() == toPos)
										{
											blackMap[iter->first]->setDead(true);
											changeChessboard(board::piece, fromPos, toPos);
											output->printChess();
											output->printDead(chessNameToCode(iter->first, 'b'));
											determineMessage(redName, fromPos, toPos, turn, outputMessage);//中式記譜法
											output->printRecord(outputMessage);

											output->clearCanMoveAndEat();
											//change turn
											if (turn == 1)
											{
												turn = 0;
												output->printRound("black");
											}
											else
											{
												turn = 1;
												output->printRound("red");
											}
											output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);

											control.setSelected(false);

											break;
										}
									}

									break;
								}

							}

							//access wrong position
							if (control.getSelected())
							{
								output->printIllegalMsg();
								output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);
							}
						}
						else
						{
							vector<vector<int> > moveable = blackMap[blackName]->canMove();
							for (unsigned int i = 0; i < moveable.size(); i++)
							{
								if (moveable[i] == toPos)
								{
									
									blackMap[blackName]->eatMove(toPos);
									for (auto iter = redMap.begin(); iter != redMap.end(); iter++)
									{
										if ((iter->second)->getPosition() == toPos)
										{
											redMap[iter->first]->setDead(true);
											changeChessboard(board::piece, fromPos, toPos);
											output->printChess();
											output->printDead(chessNameToCode(iter->first, 'r'));
											determineMessage(blackName, fromPos, toPos, turn, outputMessage);//中式記譜法
											output->printRecord(outputMessage);

											output->clearCanMoveAndEat();
											//change turn
											if (turn == 1)
											{
												turn = 0;
												output->printRound("black");
											}
											else
											{
												turn = 1;
												output->printRound("red");
											}
											output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);

											control.setSelected(false);

											break;
										}
									}

									break;
								}
							}

							//access wrong position
							if (control.getSelected())
							{
								output->printIllegalMsg();
								output->moveCursor(toPos[1] * 4 + 28, toPos[0] * 2 + 1);
							}
						}
					}/*end eat chess part*/

					//write file
					txtControl.writeBoard(board::piece, turn);

				}
			}//**End move chess control*//

		}

	}
	
}

void placeInitialChess(map<string, chess*>& blackMap, map<string, chess*>& redMap)
{
	int code;
	int count[15] =
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
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			code = board::piece[i][j];

			if (code != 0)
			{
				count[code] += 1;
			}

			if (code == 1) {
				blackMap["king1"] = new kings(i, j, 'b');
				blackMap["king1"]->setStatus(i, j, 'b', false);
			}
			else if (code == 8)
			{
				redMap["king2"] = new kings(i, j, 'r');
				redMap["king2"]->setStatus(i, j, 'r', false);
			}

			else if (code == 2)
			{
				blackMap["guard" + to_string(count[code])] = new guards(i, j, 'b');
				blackMap["guard" + to_string(count[code])]->setStatus(i, j, 'b', false);
			}
			else if (code == 9)
			{
				redMap["guard" + to_string(count[code] + 2)] = new guards(i, j, 'r');
				redMap["guard" + to_string(count[code] + 2)]->setStatus(i, j, 'r', false);
			}

			else if (code == 3)
			{
				blackMap["elephant" + to_string(count[code])] = new elephants(i, j, 'b');
				blackMap["elephant" + to_string(count[code])]->setStatus(i, j, 'b', false);
			}
			else if (code == 10)
			{
				redMap["elephant" + to_string(count[code] + 2)] = new elephants(i, j, 'r');
				redMap["elephant" + to_string(count[code] + 2)]->setStatus(i, j, 'r', false);
			}

			else if (code == 4)
			{
				blackMap["chariot" + to_string(count[code])] = new chariots(i, j, 'b');
				blackMap["chariot" + to_string(count[code])]->setStatus(i, j, 'b', false);
			}
			else if (code == 11)
			{
				redMap["chariot" + to_string(count[code] + 2)] = new chariots(i, j, 'r');
				redMap["chariot" + to_string(count[code] + 2)]->setStatus(i, j, 'r', false);
			}

			else if (code == 5)
			{
				blackMap["horse" + to_string(count[code])] = new horses(i, j, 'b');
				blackMap["horse" + to_string(count[code])]->setStatus(i, j, 'b', false);
			}
			else if (code == 12)
			{
				redMap["horse" + to_string(count[code] + 2)] = new horses(i, j, 'r');
				redMap["horse" + to_string(count[code] + 2)]->setStatus(i, j, 'r', false);
			}
			else if (code == 6)
			{
				blackMap["cannon" + to_string(count[code])] = new cannons(i, j, 'b');
				blackMap["cannon" + to_string(count[code])]->setStatus(i, j, 'b', false);
			}
			else if (code == 13)
			{
				redMap["cannon" + to_string(count[code] + 2)] = new cannons(i, j, 'r');
				redMap["cannon" + to_string(count[code] + 2)]->setStatus(i, j, 'r', false);
			}

			else if (code == 7)
			{
				blackMap["soldier" + to_string(count[code])] = new soldiers(i, j, 'b');
				blackMap["soldier" + to_string(count[code])]->setStatus(i, j, 'b', false);
			}
			else if (code == 14)
			{
				if (count[code] + 5 == 10)
				{
					redMap["soldier" + to_string(0)] = new soldiers(i, j, 'r');
					redMap["soldier" + to_string(0)]->setStatus(i, j, 'r', false);
				}
				else
				{
					redMap["soldier" + to_string(count[code] + 5)] = new soldiers(i, j, 'r');
					redMap["soldier" + to_string(count[code] + 5)]->setStatus(i, j, 'r', false);
				}
			}

		}
	}

	//fill hole
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 0; j < optimalChessCount[i] - count[i]; i++)
		{
			if (i == 1) {
				blackMap["king1"] = new kings(-100, -100, 'b');
				blackMap["king1"]->setStatus(-100, -100, 'b', true);
			}
			else if (i == 8)
			{
				redMap["king2"] = new kings(-100, -100, 'r');
				redMap["king2"]->setStatus(-100, -100, 'r', true);
			}

			else if (i == 2)
			{
				blackMap["guard" + to_string(count[i] + j + 1)] = new guards(-100, -100, 'b');
				blackMap["guard" + to_string(count[i] + j + 1)]->setStatus(-100, -100, 'b', true);
			}
			else if (i == 9)
			{
				redMap["guard" + to_string(2 + count[i] + j + 1)] = new guards(-100, -100, 'r');
				redMap["guard" + to_string(2 + count[i] + j + 1)]->setStatus(-100, -100, 'r', true);
			}

			else if (i == 3)
			{
				blackMap["elephant" + to_string(count[i] + j + 1)] = new elephants(-100, -100, 'b');
				blackMap["elephant" + to_string(count[i] + j + 1)]->setStatus(-100, -100, 'b', true);
			}
			else if (i == 10)
			{
				redMap["elephant" + to_string(2 + count[i] + j + 1)] = new elephants(-100, -100, 'r');
				redMap["elephant" + to_string(2 + count[i] + j + 1)]->setStatus(-100, -100, 'r', true);
			}

			else if (i == 4)
			{
				blackMap["chariot" + to_string(count[i] + j + 1)] = new chariots(-100, -100, 'b');
				blackMap["chariot" + to_string(count[i] + j + 1)]->setStatus(-100, -100, 'b', true);
			}
			else if (i == 11)
			{
				redMap["chariot" + to_string(2 + count[i] + j + 1)] = new chariots(-100, -100, 'r');
				redMap["chariot" + to_string(2 + count[i] + j + 1)]->setStatus(-100, -100, 'r', true);
			}

			else if (i == 5)
			{
				blackMap["horse" + to_string(count[i] + j + 1)] = new horses(-100, -100, 'b');
				blackMap["horse" + to_string(count[i] + j + 1)]->setStatus(-100, -100, 'b', true);
			}
			else if (i == 12)
			{
				redMap["horse" + to_string(2 + count[i] + j + 1)] = new horses(-100, -100, 'r');
				redMap["horse" + to_string(2 + count[i] + j + 1)]->setStatus(-100, -100, 'r', true);
			}
			else if (i == 6)
			{
				blackMap["cannon" + to_string(count[i] + j + 1)] = new cannons(-100, -100, 'b');
				blackMap["cannon" + to_string(count[i] + j + 1)]->setStatus(-100, -100, 'b', true);
			}
			else if (i == 13)
			{
				redMap["cannon" + to_string(2 + count[i] + j + 1)] = new cannons(-100, -100, 'r');
				redMap["cannon" + to_string(2 + count[i] + j + 1)]->setStatus(-100, -100, 'r', true);
			}

			else if (i == 7)
			{
				blackMap["soldier" + to_string(count[i] + j + 1)] = new soldiers(-100, -100, 'b');
				blackMap["soldier" + to_string(count[i] + j + 1)]->setStatus(-100, -100, 'b', true);
			}
			else if (i == 14)
			{
				if (count[i] + j + 1 + 5 == 10)
				{
					redMap["soldier" + to_string(0)] = new soldiers(-100, -100, 'r');
					redMap["soldier" + to_string(0)]->setStatus(-100, -100, 'r', true);
				}
				else
				{
					redMap["soldier" + to_string(5 + count[i] + j + 1)] = new soldiers(i, j, 'r');
					redMap["soldier" + to_string(5 + count[i] + j + 1)]->setStatus(i, j, 'r', false);
				}
			}
		}
	}
}

void determineMessage(string name, vector<int> fromPos, vector<int> toPos, int turn, vector<wstring>& outputMessage)//處理中式記譜法的函式
{
	int rowDiff = toPos[0] - fromPos[0], colDiff = toPos[1] - fromPos[1];
	int numArr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	string nameArr[8] = { "","soldier","cannon","horse","chariot","elephant","guard","king" };
	wstring chessArr[15] = { L"",L"卒",L"包" ,L"馬" ,L"車" ,L"象" ,L"士" ,L"將" ,L"兵" ,L"炮" ,L"傌" ,L"車" ,L"相" ,L"仕" ,L"帥" };
	wstring blackWord[9] = { L"１",L"２",L"３" ,L"４" ,L"５" ,L"６" ,L"７" ,L"８" ,L"９" };
	wstring redWord[9] = { L"一",L"二",L"三",L"四",L"五",L"六",L"七",L"八",L"九" };
	wstring answer = L"";
	answer += L"";
	name.erase(name.end() - 1);
	if (turn == 0)//黑色
	{
		answer += L"黑：";
		for (int i = 1; i <= 7; i++)
		{
			if (name == nameArr[i])
			{
				answer += chessArr[i];//黑色棋種
			}
		}

		answer += blackWord[fromPos[1]];//黑色數字

		if (rowDiff == 0 && colDiff != 0)
		{
			answer += L"平";
			answer += blackWord[toPos[1]];
		}
		else if (colDiff == 0)
		{
			if (rowDiff >= 1)
			{
				answer += L"進";
				answer += blackWord[rowDiff - 1];
			}
			else if (rowDiff <= -1)
			{
				answer += L"退";
				rowDiff *= -1;
				answer += blackWord[rowDiff - 1];
			}
		}
		else
		{
			if (rowDiff >= 1)
			{
				answer += L"進";
				answer += blackWord[toPos[1]];
			}
			else if (rowDiff <= -1)
			{
				answer += L"退";
				answer += blackWord[toPos[1]];
			}
		}
	}
	else//紅色
	{
		answer += L"紅：";
		for (int i = 1; i <= 7; i++)
		{
			if (name == nameArr[i])
			{
				answer += chessArr[i + 7];//紅色棋種
			}
		}

		answer += redWord[8 - fromPos[1]];//紅色數字

		if (rowDiff == 0 && colDiff != 0)
		{
			answer += L"平";
			answer += redWord[8 - toPos[1]];
		}
		else if (colDiff == 0)
		{
			if (rowDiff >= 1)
			{
				answer += L"退";
				answer += redWord[rowDiff - 1];
			}
			else if (rowDiff <= -1)
			{
				answer += L"進";
				rowDiff *= -1;
				answer += redWord[rowDiff - 1];
			}
		}
		else
		{
			if (rowDiff >= 1)
			{
				answer += L"退";
				answer += redWord[8 - toPos[1]];
			}
			else if (rowDiff <= -1)
			{
				answer += L"進";
				answer += redWord[8 - toPos[1]];
			}
		}
	}
	outputMessage.push_back(answer);
}

int chessNameToCode(string chessName, char color)
{
	int ret = 0;

	if (chessName.length() >= 7 && chessName.substr(0, 7) == "soldier")
	{
		ret = 7;
	}
	else if (chessName.length() >= 6 && chessName.substr(0, 6) == "cannon")
	{
		ret = 6;
	}
	else if (chessName.length() >= 5 && chessName.substr(0, 5) == "horse")
	{
		ret = 5;
	}
	else if (chessName.length() >= 7 && chessName.substr(0, 7) == "chariot")
	{
		ret = 4;
	}
	else if (chessName.length() >= 8 && chessName.substr(0, 8) == "elephant")
	{
		ret = 3;
	}
	else if (chessName.length() >= 5 && chessName.substr(0, 5) == "guard")
	{
		ret = 2;
	}
	else if (chessName.length() >= 4 && chessName.substr(0, 4) == "king")
	{
		ret = 1;
	}

	if (color == 'r')
	{
		ret += 7;
	}
	else if (color == 'b')
	{
		ret += 0;
	}

	return ret;
}

void changeChessboard(int twoDimArr[10][9], vector<int> fromPos, vector<int> toPos)
{
	int num;
	num = twoDimArr[fromPos[0]][fromPos[1]];
	twoDimArr[fromPos[0]][fromPos[1]] = 0;
	twoDimArr[toPos[0]][toPos[1]] = num;
}

bool defense(int turn, map<string, chess*>& blackMap, map<string, chess*>& redMap)//判斷被將軍
{
	vector<vector<int>> attack;
	if (turn == 1)//紅方
	{
		vector<int> redKingPos = redMap["king2"]->getPosition();
		for (auto iter = blackMap.begin(); iter != blackMap.end(); iter++)//判斷所有黑色棋子的攻擊範圍
		{
			if ((iter->second)->getDead() == false)//此黑色棋子還沒死
			{
				attack = (iter->second)->canMove();
				for (unsigned int i = 0; i < attack.size(); i++)
				{
					if (redKingPos == attack[i])//顯示紅方被將軍!
					{
						return true;
					}
				}
				attack.clear();
			}
		}

		return false;
	}
	else//黑方
	{
		vector<int> blackKingPos = blackMap["king1"]->getPosition();
		for (auto iter = redMap.begin(); iter != redMap.end(); iter++)//判斷所有紅色棋子的攻擊範圍
		{
			if ((iter->second)->getDead() == false)//此紅色棋子還沒死
			{
				attack = (iter->second)->canMove();
				for (unsigned int i = 0; i < attack.size(); i++)
				{
					if (blackKingPos == attack[i])//顯示紅方被將軍!
					{
						return true;
					}
				}
				attack.clear();
			}
		}

		return false;
	}
}