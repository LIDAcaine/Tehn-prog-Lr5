#pragma once
#include "Base.h"
#include "Data.h"
using namespace std;

class Admin : public VYZ {
private:
	FIO adminFIO; //���
	string position; //���������
	string respons; //������� ���������������
public:
	Admin();
	Admin(ifstream& fin);
	~Admin();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};