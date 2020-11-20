#pragma once
#include <string>
using namespace std;

int menu();

class CFile {

	string name;
	string header;
	string fullName;

public:

	string getHeader() {
		return header;
	}
	~CFile();
	CFile(string, string);

	int stringLength();
	int stringCount();


	bool Create(string);
	bool Open(string);
	void Close();
	int Seek(int);
	void Read(int);
	void Write();
	int GetPosition();
	int GetLength();
};

class CMyDataFile : public CFile {

	string name;
	string header;
	string fullName;

public:

	~CMyDataFile();
	
	CMyDataFile(string n, string h);
	
	void Write(string studentName, string studentSurname, int birthYear, string status);

	
};
