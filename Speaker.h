#pragma once
#include "Base.h"
#include "Data.h"
using namespace std;

class Speaker : public VYZ {
private:
	FIO speakFIO; //���
	string vuz; //���
	string tema; //����
	string annot; //���������
public:
	Speaker();
	Speaker(ifstream& fin);
	~Speaker();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};