#include "Program.h"

Program::Program() {
	try {
		SetType(3);
		SetErr(false);
		cout << "����: ";
		cin >> this->day;
		if (this->day <= 0 || this->day > 31)
			throw 1;
		cout << "�����: ";
		cin >> this->month;
		if (this->month < 1 || this->month > 12)
			throw 2;
		cout << "���: ";
		cin >> this->year;
		if (this->year <1)
			throw 3;
		cout << "����: ";
		cin >> this->hour;
		if (this->hour < 0 || this->hour > 23)
			throw 4;
		cout << "������: ";
		cin >> this->minute;
		if (this->minute < 0 || this->minute > 59)
			throw 5;
		cin.ignore(256, '\n');
		cout << "�������� �����������: ";
		getline(cin, this->title);
	}
	catch (int err) {
		SetErr(true);
		switch (err) {
		case 1:
			cout << "���� ������ ���� ������ �� 1 �� 31!" << endl;
			break;
		case 2:
			cout << "����� ������ ���� ����� �� 1 �� 12!" << endl;
			break;
		case 3:
			cout << "��� ������ ���� ������ �� 1!" << endl;
			break;
		case 4:
			cout << "���� ������ ���� ������ �� 0 23!" << endl;
			break;
		case 5:
			cout << "������ ������ ���� ������ �� 0 �� 59!" << endl;
			break;
		}
	}
	
}

Program::Program(ifstream& fin) {
	SetType(3);
	fin >> this->day;
	fin >> this->month;
	fin >> this->year;
	fin >> this->hour;
	fin >> this->minute;
	fin.ignore(256, '\n');
	getline(fin, this->title);
}

Program::~Program() {
	cout << "std dstrctr" << endl;
}

void Program::Edit() {
	SetErr(false);
	int choose;
	char i_temp;
	int F;
	string s_temp;
	char f_temp;
	cout << "�������� ������������� ��������:" << endl
		<< "[1] ����." << endl
		<< "[2] �����." << endl
		<< "[3] ��������." << endl
		<< "[0] ������." << endl
		<< ">> ";
	cin >> choose;
	try {
		switch (choose)
		{
		case 1:
			cout << "�������� ������������� ��������:" << endl
				<< "[1] ����." << endl
				<< "[2] �����." << endl
				<< "[3] ���." << endl
				<< "[0] ������." << endl
				<< ">> ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "�������: ";
				cout << this->day << endl << "����� >> ";
				cin >> F;
				if (F <= 0 || F > 31)
					throw 1;
				day = F;
				break;
			case 2:
				cout << "�������: ";
				cout << this->month << endl << "����� >> ";
				cin >> F;
				if (F < 1 || F > 12)
					throw 2;
				month = F;
				break;
			case 3:
				cout << "�������: ";
				cout << this->year << endl << "����� >> ";
				cin >> F;
				if (F < 1)
					throw 3;
				year = F;
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "�������� ������������� ��������:" << endl
				<< "[1] ����." << endl
				<< "[2] ������." << endl
				<< "[0] ������." << endl
				<< ">> ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "�������: ";
				cout << this->hour << endl << "����� >> ";
				cin >> F;
				if (F < 0 || F > 23)
					throw 4;
				hour = F;
				break;
			case 2:
				cout << "�������: ";
				cout << this->minute << endl << "����� >> ";
				cin >> F;
				if (F < 0 || F > 59)
					throw 5;
				minute = F;
				break;
			default:
				break;
			}
		case 3:
			cout << "�������: ";
			cout << this->title << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			title = s_temp;
			break;
		default:
			break;
		}
	}
	catch (int err)
	{
		SetErr(true);
		switch (err) {
		case 1:
			cout << "���� ������ ���� ������ �� 1 �� 31!" << endl;
			break;
		case 2:
			cout << "����� ������ ���� ����� �� 1 �� 12!" << endl;
			break;
		case 3:
			cout << "��� ������ ���� ������ �� 1!" << endl;
			break;
		case 4:
			cout << "���� ������ ���� ������ �� 0 23!" << endl;
			break;
		case 5:
			cout << "������ ������ ���� ������ �� 0 �� 59!" << endl;
			break;
		}
	}
}

void Program::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->day << endl
		<< this->month << endl
		<< this->year << endl
		<< this->hour << endl
		<< this->minute << endl
		<< this->title << endl;
}

void Program::Print(ostream& out) {
	out << "���������: " << endl
		<< "����: " << this->day<<"."<<this->month<<"."<<this->year <<  endl
		<< "�����: " << this->hour<<":"<<this->minute << endl
		<< "��������:" << this->title << endl
		<< "=================================" << endl;
}