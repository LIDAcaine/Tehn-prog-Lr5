#include "Admin.h"

Admin::Admin() {
	SetType(2);
	SetErr(false);
	cout << "Введите ФИО администратора:" << endl << "Имя: ";
		cin.ignore(256, '\n');
		getline(cin, this->adminFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->adminFIO.SurName);
		cout << "Отчество: ";
		getline(cin, this->adminFIO.LastName);
		cout << "Введите должность: ";
		getline(cin, this->position);
		cout << "Введите область ответсвенности: ";
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
	cout << "Выберите редактируемый параметр:" << endl
		<< "[1] ФИО." << endl
		<< "[2] Должность." << endl
		<< "[3] Область ответственности." << endl
		<< "[0] Отмена." << endl;
	cin >> choose;
		switch (choose) {
		case 1:
			cout << "Текущее: ";
			cout << this->adminFIO.Name << " "
				<< this->adminFIO.SurName << " "
				<< this->adminFIO.LastName << endl
				<< "Новое:  Имя >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\tФамилия >> ";
			getline(cin, fio_temp.SurName);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.LastName);
			adminFIO = fio_temp;
			break;
		case 2:
			cout << "Текущее: ";
			cout << this->position << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			position = s_temp;
			break;
		case 3:
			cout << "Текущее: ";
			cout << this->respons << endl
				<< "Новое >> ";
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
	out << "Алминистратор:" << endl
		<< "ФИО: " << this->adminFIO.Name << " " << this->adminFIO.SurName << " " << this->adminFIO.LastName << endl
		<< "Должность: " << this->position << endl
		<< "Область ответственности: " << this->respons << endl
		<< "=================================" << endl;
}