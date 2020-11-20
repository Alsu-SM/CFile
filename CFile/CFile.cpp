#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <io.h>

#include "CFile.h"
using namespace std;
bool fileExists = false;
int v = 0;
int seek2 = 0;

int CFile::stringLength() {
	
	int max = 0;
	string s;

	ifstream fin(this->fullName);

	while (getline(fin, s))
	{
		if (s.size() > max)
			max = s.size();
	}

	return max;
}

int CFile::stringCount() {

	int count = 0;
	string s;

	ifstream fin(this->fullName);

	while (getline(fin, s))
	{
		count++;
	}

	return count;

}

int menu() {
	if (fileExists) {
		cout << "\n\nЧто вы хотите сделать?\n" << endl;
		cout << "\n1 - создать новый файл\n2 - открыть существующий файл\n3 - закрыть файл\n4 - сдвинуть указатель в файле\n5 - прочитать файл\n6 - сделать запись в файл\n7 - найти текущую позицию\n8 - найти длину\n\n9 - Выйти" << endl;

		for (;;)
		{
			cout << "\nВаш выбор: ";
			cin >> v;
			cout << "\n";

			if (v < 0 || v > 8) {
				cout << "\nПожалуйста, введите числа от 0 до 8.\n\n" << endl;
				continue;
			}

			break;
		
		}
	}

	else {
		cout << "Добро пожаловать в программу! Что вы хотите сделать?" << endl;
		cout << "\n1 - создать новый файл\n2 - открыть существующий файл" << endl;

		for (;;)
		{
			cout << "\nВаш выбор: ";
			cin >> v;
			cout << "\n";

			if (v < 0 || v > 3) {
				cout << "\nПожалуйста, введите числа от 0 до 2.\n\n" << endl;
				continue;
			}

			break;
		}
		
		fileExists = true;

	}

	return v;
}


CFile::CFile(string n, string h) {
	name = n;
	header = h;
	fullName = name + '.' + header;
}

CFile::~CFile() {

}

bool CFile::Create(string n) {

	seek2 = 0;

	ofstream fcreate(n); 
	fcreate.close(); 

	if (fcreate.is_open())
	{
		return true;
	}
	else return false;

}

bool CFile::Open(string n) {

	seek2 = 0;

	ifstream fopen(n); 

	if (fopen.is_open())
	{
		fopen.close();
		return true;
	}
	else {

		fopen.close();
		return false;
	}
}

void CFile::Close() {
	this->name.clear();
	this->header.clear();
	this->fullName.clear();
	fileExists = false;
}

int CFile::Seek(int n) {
	fstream file(this->fullName);
	if (n == -1)
	{
		file.seekg(0, file.end);
		seek2 = file.end;
	}
	else
	{
		file.seekg(n);
		seek2 = n;
	}
		
	
	return 0;
}

void CFile::Read(int ans) {
	
	fstream file(this->fullName);
	
	if (ans == 2)
		file.seekg(seek2);

	string line;
	while (getline(file, line))
	{
		std::cout << line << std::endl;
	}
	
	
}

void CFile::Write() {
	
	ofstream out(this->fullName, std::ios::app);
	if (out.is_open())
	{
		
		char c;
		//out << "Welcome to CPP" << std::endl;
		while ((c = getchar()) != EOF)
			out << c;
			
	}
	out.close();
}

int CFile::GetPosition() {

	return seek2;

}

int CFile::GetLength() {
	// get length of file:
	fstream file(this->fullName);
	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);
	return length;
}