#pragma once
#include "Base.h"
using namespace std;

class Program : public VYZ {
private:
	int day; //����
	int month; //�����
	int year; //���
	int hour; //����
	int minute; //������
	string title; //��������
public:
	Program();
	Program(ifstream& fin);
	~Program();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};