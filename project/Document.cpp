#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"Document.h"
#include"chessboard.h"

using std::fstream;
using std::string;
using std::ios;
using std::cerr;

namespace Chen_Yan_Yu_Document
{
	document::document(string name, int a[10][9], int &t) :fileName(name)
	{
		file.open(name, ios::in);
		if (file.fail())
		{
			cerr << "Can not open file";
			exit(1);
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				file >> a[i][j];
			}
		}
		file >> t;
		file.close();
	}

	void document::writeBoard(int a[10][9], int &t)
	{
		file.open(fileName, ios::out);
		if (file.fail())
		{
			cerr << "Can not open file";
			exit(1);
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				file << a[i][j] << " ";
			}
			file << "\n";
		}
		file << t << "\n";
		file.close();
	}
}