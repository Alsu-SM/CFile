#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <io.h>

#include "CFile.h"
using namespace std;


void CMyDataFile::Write(string s) { 

	if (1)
	{

		ofstream out(this->fullName, ios_base::out | ios_base::app);
		if (out.is_open())
		{
			out << s;
		}
		out.close();
		cout << "\n������ ����� CMyDataFile\n";
	}
}


CMyDataFile::CMyDataFile(string n, string h) : CFile(n, h) { //�����������
	
}

CMyDataFile::~CMyDataFile() {

}

//���������� ���������� ������� � ������� "���� ������"
int CMyDataFile::HowManyEntries() {
	return this->stringCount();
}