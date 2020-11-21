#pragma once
#include <string>
using namespace std;

int menu();

/*
* Базовый класс CFile - включает в себя методы работы с обычными текстовыми файлами.
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
* Производный класс CMyDataFile - работает с текстовыми файлами, содержащими в себе простую
* структуру: имя, фамилия, год рождения и статус студента.
* Наследует большинство методов работы с файлами у класса CFile.
* Имеет свой метод записи в файл и метод, возвращающий количество записей в базе. 
* Поле header определяет, к какому классу принадлежит объект: 
* файлы, относящиеся к CFile, имеют расширение txt,
* а файлы, относящиеся к CMyDataFile, имеют расширение dat.
*/
class CMyDataFile : public CFile {


public:

	~CMyDataFile();
	
	CMyDataFile(string n, string h);
	
	int HowManyEntries();

	void Write(string s);
};
