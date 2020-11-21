#pragma once
#include <string>
using namespace std;

int menu();

/*
* ������� ����� CFile - �������� � ���� ������ ������ � �������� ���������� �������.
*/

class CFile {

protected:
	string name;
	string header;
	string fullName;

public:

	~CFile();
	CFile(string, string);

	
	int stringCount();


	bool Create(string);
	bool Open(string);
	void Close();
	int Seek(int);
	void Read(int);

	virtual void Write(string s);

	int GetPosition();
	int GetLength();
};

/*
* ����������� ����� CMyDataFile - �������� � ���������� �������, ����������� � ���� �������
* ���������: ���, �������, ��� �������� � ������ ��������.
* ��������� ����������� ������� ������ � ������� � ������ CFile.
* ����� ���� ����� ������ � ���� � �����, ������������ ���������� ������� � ����. 
* ���� header ����������, � ������ ������ ����������� ������: 
* �����, ����������� � CFile, ����� ���������� txt,
* � �����, ����������� � CMyDataFile, ����� ���������� dat.
*/
class CMyDataFile : public CFile {


public:

	~CMyDataFile();
	
	CMyDataFile(string n, string h);
	
	int HowManyEntries();

	void Write(string s);
};
