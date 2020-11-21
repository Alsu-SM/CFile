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
string birthYear;
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

		case 1: //создание нового файла
			cout << "Для работы со структурой, выбирайте расширение dat\nДля работы с обычным текстом - расширение txt\n" << endl;

			cout << "\nВведите название файла: ";
			cin >> fileName;
			cout << "\nВведите разрешение файла: ";
			cin >> header;
			Name = fileName + '.' + header;
			file->Create(Name);
			cout << "\n\nНовый файл создан" << endl;
			if (header == "txt")
				file = new CFile(fileName, header);
			if (header == "dat")
				myfile = new CMyDataFile(fileName, header);
			
			break;
		
		case 2: //открытие существующего файла
			cout << "Для работы со структурой, выбирайте расширение dat.\nДля работы с обычным текстом - расширение txt\n" << endl;

			cout << "\nВведите название файла: ";
			cin >> fileName;
			cout << "\nВведите разрешение файла: ";
			cin >> header;
			Name = fileName + '.' + header;
			
			isOpen = file->Open(Name);
			if (isOpen)
			{
				cout << "\n\nФайл успешно открыт" << endl;
				if (header == "txt")
					file = new CFile(fileName, header);
				if (header == "dat")
					myfile = new CMyDataFile(fileName, header);
			}
			else {
				cout << "\n\nНе удалось найти файл, попробуйте еще раз" << endl;
			}
			break;
		case 3: //закрыть выбранный файл
			if (header == "txt")
				file->Close();
			if (header == "dat")
				myfile->Close();
			cout <<"\nФайл закрыт\n\n"<< endl;
			break;
		case 4: //установить указатель
			cout << "Функция устанавливает указатель положения в файле\n\nВведите: \n1) Положительное число для выбора позиции внутри файла\n2) 0 для переноса указателя в начало файла\n3) -1 для переноса указателя в конец файла\n\nВаш выбор: ";
			cin >> seek;
			
			if (header == "txt")
				file->Seek(seek);
			if (header == "dat")
				myfile->Seek(seek);

			cout << "\nУказатель успешно перенесен\n" << endl;
			break;
		case 5: //чтение файла
			cout << "Как вы хотите прочитать файл:\n1 - полностью\n2 - с выбранной позиции" << endl;
			int ans;
			cout << "\nВаш выбор: ";
			cin >> ans;
			cout << "\nОткрываем выбранный файл для чтения:\n" << endl;
			
			if (header == "txt")
				file->Read(ans);
			if (header == "dat")
				myfile->Read(ans);;
			break;
		case 6: //запись в файл
			if (header == "txt")
			{
				string s;
				cout << "\nЗапись в файл. Признак окончания - сочетание клавиш Ctrl-Z\n" << endl;
				char c;
				while ((c = getchar()) != EOF)
					s += c;
				file->Write(s);
			}
			if (header == "dat") 
			{
				cout << "\nДобавить запись о студенте\n" << endl;
				cout << "Введите имя: "; cin >> studentName;
				cout << "Введите фамилию: "; cin >> studentSurname;
				cout << "Введите год рождения: "; cin >> birthYear;
				cout << "Введите статус студента: "; cin >> status;

				string s = studentName + " " + studentSurname + " " + birthYear + " " + status + "\n";

				myfile->Write(s);
			}
			
			break;

		case 7: // возвращает текущую позицию в файле
			if (header == "txt")
				cout << "\nУказатель установлен на позицию: " << file->GetPosition() << endl;
			if (header == "dat")
				cout << "\nУказатель установлен на позицию: " << myfile->GetPosition() << endl;
			
			break;
		case 8: // возвращает длину файла в символах
			if (header == "txt")
				cout << "Длина файла: " << file->GetLength() << " символов." << endl;
			if (header == "dat")
			{
				cout << "Длина файла: " << myfile->GetLength() << " символов." << endl;
				cout << "Всего в базе: " <<myfile->HowManyEntries() <<" записей"<< endl;
			}
			
			break;
		case 9:
			exit(0);
			break;
		}
	}
	return 0;
}