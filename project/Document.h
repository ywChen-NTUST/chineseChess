#include<string>
#include<fstream>

#ifndef DOCUMENT_H
#define DOCUMENT_H
namespace Chen_Yan_Yu_Document
{
	using std::string;
	using std::fstream;
	class document
	{
	public:
		document();//We do not use it.
		document(string name, int a[10][9], int &t);
		void writeBoard(int a[10][9], int &t);
	private:
		string fileName;
		fstream file;
	};
}


#endif

