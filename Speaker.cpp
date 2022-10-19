#include "Speaker.h"
Speaker::Speaker() {
	SetType(1);
	SetErr(false);
	cout << "������� ���:" << endl << "���: ";
	cin.ignore(256, '\n');
		getline(cin, this->speakFIO.Name);
		cout << "�������: ";
		getline(cin, this->speakFIO.SurName);
		cout << "��������: ";
		getline(cin, this->speakFIO.LastName);
		cout << "������� ���/�����������: ";
		getline(cin, this->vuz);
		cout << "������� ���� �������: ";
		getline(cin, this->tema);
		cout << "������� ��������� � �������:";
		getline(cin, this->annot);
	
}

Speaker::Speaker(ifstream& fin) {
	SetType(1);
	fin.ignore(256, '\n');
	getline(fin, this->speakFIO.Name);
	getline(fin, this->speakFIO.SurName);
	getline(fin, this->speakFIO.LastName);
	getline(fin, this->vuz);
	getline(fin, this->tema);
	//fin.ignore(256, '\n');
	getline(fin, this->annot);
}

Speaker::~Speaker() {
	cout << "pers dstrctr";
}

void Speaker::Edit() {
	int choose;
	FIO fio_temp;
	string s_temp;
	cout << "�������� ������������� ��������:" << endl
		<< "[1] ���." << endl
		<< "[2] ���/�����������." << endl
		<< "[3] ����." << endl
		<< "[4] ���������." << endl
		<< "[0] ������." << endl;
	cin >> choose;

		switch (choose) {
		case 1:
			cout << "�������: ";
			cout << this->speakFIO.Name << " "
				<< this->speakFIO.SurName << " "
				<< this->speakFIO.LastName << endl
				<< "�����:  ��� >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\t������� >> ";
			getline(cin, fio_temp.SurName);
			cout << "\t�������� >> ";
			getline(cin, fio_temp.LastName);
			speakFIO = fio_temp;
			break;
		case 2:
			cout << "�������: ";
			cout << this->vuz << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			vuz = s_temp;
			break;
		case 3:
			cout << "�������: ";
			cout << this->tema << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			tema = s_temp;
			break;
			break;
		case 4:
			cout << "�������: ";
			cout << this->annot << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			annot = s_temp;
			break;
		default:
			break;
		}
	
}

void Speaker::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->speakFIO.Name << endl
		<< this->speakFIO.SurName << endl
		<< this->speakFIO.LastName << endl
		<< this->vuz << endl
		<< this->tema << endl
		<< this->annot << endl;
}

void Speaker::Print(ostream& out) {
	out << "�����������:" << endl
		<< "���:" << this->speakFIO.Name << " " << this->speakFIO.SurName << " " << this->speakFIO.LastName << endl
		<< "���/�����������:" << this->vuz << endl
		<< "����:" << this->tema << endl
		<< "���������:" << this->annot << endl
		<< "=================================" << endl;
}