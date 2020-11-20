#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<Windows.h>


#include "CFile.h"
using namespace std;

CFile* file;
CMyDataFile* myfile;
fstream f;
string fileName, header, Name;
bool isOpen;
string studentName;
string studentSurname;
int birthYear;
string status;
int seek = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (;;)
	{
		int v;
		v = menu();
		switch (v) {

		case 1: //�������� ������ �����
			cout << "��� ������ �� ����������, ��������� ���������� dat.\n��� ������ � ������� ������� - ���������� txt\n" << endl;

			cout << "\n������� �������� �����: ";
			cin >> fileName;
			cout << "\n������� ���������� �����: ";
			cin >> header;
			Name = fileName + '.' + header;
			file->Create(Name);
			cout << "����� ���� ������" << endl;
			if (header == "txt")
				file = new CFile(fileName, header);
			if (header == "dat")
				myfile = new CMyDataFile(fileName, header);
			
			break;
		
		case 2: //�������� ������������� �����
			cout << "��� ������ �� ����������, ��������� ���������� dat.\n��� ������ � ������� ������� - ���������� txt\n" << endl;

			cout << "\n������� �������� �����: ";
			cin >> fileName;
			cout << "\n������� ���������� �����: ";
			cin >> header;
			Name = fileName + '.' + header;
			
			isOpen = file->Open(Name);
			if (isOpen)
			{
				cout << "���� ������� ������" << endl;
				if (header == "txt")
					file = new CFile(fileName, header);
				if (header == "dat")
					myfile = new CMyDataFile(fileName, header);
			}
			else {
				cout << "�� ������� ����� ����, ���������� ��� ���" << endl;
			}
			break;
		case 3: //������� ��������� ����
			if (header == "txt")
				file->Close();
			if (header == "dat")
				myfile->Close();
			cout <<"���� ������"<< endl;
			break;
		case 4: //���������� ���������
			cout << "������� ������������� ��������� ��������� � �����\n �������: \n1) ��������������� ����� ��� ������ ������� ������ �����\n2) 0 ��� �������� ��������� � ������ �����\n3) -1 ��� �������� ��������� � ����� �����\n��� �����: ";
			cin >> seek;
			
			if (header == "txt")
				file->Seek(seek);
			if (header == "dat")
				myfile->Seek(seek);
			break;
		case 5:
			cout << "��� �� ������ ��������� ����:\n1 - ���������\n2 - � ��������� �������" << endl;
			int ans;
			cin >> ans;
			cout << "\n��������� ��������� ���� ��� ������\n" << endl;
			
			if (header == "txt")
				file->Read(ans);
			if (header == "dat")
				myfile->Read(ans);;
			break;
		case 6:
			if (header == "txt")
			{
				cout << "\n������ � ����. ������� ��������� - ������ ������\n" << endl;
				file->Write();
			}
			if (header == "dat") 
			{
				cout << "\n�������� ������ � ��������\n" << endl;
				cout << "������� ���: "; cin >> studentName;
				cout << "������� �������: "; cin >> studentSurname;
				cout << "������� ��� ��������: "; cin >> birthYear;
				cout << "������� ������ ��������: "; cin >> status;
				myfile->Write(studentName, studentSurname, birthYear, status);
			}
			
			break;

		case 7:
			if (header == "txt")
				cout << "\n��������� ���������� �� �������: " << file->GetPosition() << endl;
			if (header == "dat")
				cout << "\n��������� ���������� �� �������: " << myfile->GetPosition() << endl;
			
			break;
		case 8:
			if (header == "txt")
				cout << "����� �����: " << file->GetLength() << " ��������." << endl;
			if (header == "dat")
				cout << "����� �����: " << myfile->GetLength() << " ��������." << endl;
			
			break;
		case 9:
			exit(0);
			break;
		}
	}
	return 0;
}