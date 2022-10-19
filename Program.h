#pragma once
#include "Base.h"
using namespace std;

class Program : public VYZ {
private:
	int day; //день
	int month; //месяц
	int year; //год
	int hour; //часы
	int minute; //минуты
	string title; //название
public:
	Program();
	Program(ifstream& fin);
	~Program();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};