#include "Admin.h"

Admin::Admin() {
	SetType(2);
	SetErr(false);
	cout << "������� ��� ��������������:" << endl << "���: ";
		cin.ignore(256, '\n');
		getline(cin, this->adminFIO.Name);
		cout << "�������: ";
		getline(cin, this->adminFIO.SurName);
		cout << "��������: ";
		getline(cin, this->adminFIO.LastName);
		cout << "������� ���������: ";
		getline(cin, this->position);
		cout << "������� ������� ��������������: ";
		getline(cin, this->respons);

}

Admin::Admin(ifstream& fin) {
	SetType(2);
	fin.ignore(256, '\n');
	getline(fin, this->adminFIO.Name);
	getline(fin, this->adminFIO.SurName);
	getline(fin, this->adminFIO.LastName);
	getline(fin, this->position);
	getline(fin, this->respons);
}

Admin::~Admin() {
	cout << "prep dstrctr" << endl;
}

void Admin::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	string s_temp;
	cout << "�������� ������������� ��������:" << endl
		<< "[1] ���." << endl
		<< "[2] ���������." << endl
		<< "[3] ������� ���������������." << endl
		<< "[0] ������." << endl;
	cin >> choose;
		switch (choose) {
		case 1:
			cout << "�������: ";
			cout << this->adminFIO.Name << " "
				<< this->adminFIO.SurName << " "
				<< this->adminFIO.LastName << endl
				<< "�����:  ��� >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\t������� >> ";
			getline(cin, fio_temp.SurName);
			cout << "\t�������� >> ";
			getline(cin, fio_temp.LastName);
			adminFIO = fio_temp;
			break;
		case 2:
			cout << "�������: ";
			cout << this->position << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			position = s_temp;
			break;
		case 3:
			cout << "�������: ";
			cout << this->respons << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			respons = s_temp;
			break;
		default:
			break;
		}
	
}

void Admin::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->adminFIO.Name << endl
		<< this->adminFIO.SurName << endl
		<< this->adminFIO.LastName << endl
		<< this->position << endl
		<< this->respons << endl;
}

void Admin::Print(ostream& out) {
	out << "�������������:" << endl
		<< "���: " << this->adminFIO.Name << " " << this->adminFIO.SurName << " " << this->adminFIO.LastName << endl
		<< "���������: " << this->position << endl
		<< "������� ���������������: " << this->respons << endl
		<< "=================================" << endl;
}