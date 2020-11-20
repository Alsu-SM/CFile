#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <io.h>

#include "CFile.h"
using namespace std;



CMyDataFile::CMyDataFile(string n, string h) : CFile(n, h) {
	this->fullName = n + '.' + h;
}

CMyDataFile::~CMyDataFile() {

}

void CMyDataFile:: Write(string studentName, string studentSurname, int birthYear, string status)
{
	
	ofstream out(this->fullName, std::ios::app);
	if (out.is_open())
	{
		out << studentName << " " << studentSurname << " " << birthYear << " " << status << "\n";
	}
	out.close();

}
