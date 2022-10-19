#pragma once
#include "Base.h"
#include "Data.h"
using namespace std;

class Speaker : public VYZ {
private:
	FIO speakFIO; //ФИО
	string vuz; //ВУЗ
	string tema; //тема
	string annot; //аннотация
public:
	Speaker();
	Speaker(ifstream& fin);
	~Speaker();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};