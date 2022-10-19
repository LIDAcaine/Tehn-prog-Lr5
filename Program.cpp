#include "Program.h"

Program::Program() {
	try {
		SetType(3);
		SetErr(false);
		cout << "День: ";
		cin >> this->day;
		if (this->day <= 0 || this->day > 31)
			throw 1;
		cout << "Месяц: ";
		cin >> this->month;
		if (this->month < 1 || this->month > 12)
			throw 2;
		cout << "Год: ";
		cin >> this->year;
		if (this->year <1)
			throw 3;
		cout << "Часы: ";
		cin >> this->hour;
		if (this->hour < 0 || this->hour > 23)
			throw 4;
		cout << "Минуты: ";
		cin >> this->minute;
		if (this->minute < 0 || this->minute > 59)
			throw 5;
		cin.ignore(256, '\n');
		cout << "Название конференции: ";
		getline(cin, this->title);
	}
	catch (int err) {
		SetErr(true);
		switch (err) {
		case 1:
			cout << "День должен быть числом от 1 до 31!" << endl;
			break;
		case 2:
			cout << "Месяц должен быть число от 1 до 12!" << endl;
			break;
		case 3:
			cout << "Год должен быть числом от 1!" << endl;
			break;
		case 4:
			cout << "Часы должны быть числом от 0 23!" << endl;
			break;
		case 5:
			cout << "Минуты должны быть числом от 0 до 59!" << endl;
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
	cout << "Выберите редактируемый параметр:" << endl
		<< "[1] Дата." << endl
		<< "[2] Время." << endl
		<< "[3] Название." << endl
		<< "[0] Отмена." << endl
		<< ">> ";
	cin >> choose;
	try {
		switch (choose)
		{
		case 1:
			cout << "Выберите редактируемый параметр:" << endl
				<< "[1] День." << endl
				<< "[2] Месяц." << endl
				<< "[3] Год." << endl
				<< "[0] Отмена." << endl
				<< ">> ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "Текущее: ";
				cout << this->day << endl << "Новое >> ";
				cin >> F;
				if (F <= 0 || F > 31)
					throw 1;
				day = F;
				break;
			case 2:
				cout << "Текущее: ";
				cout << this->month << endl << "Новое >> ";
				cin >> F;
				if (F < 1 || F > 12)
					throw 2;
				month = F;
				break;
			case 3:
				cout << "Текущее: ";
				cout << this->year << endl << "Новое >> ";
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
			cout << "Выберите редактируемый параметр:" << endl
				<< "[1] Часы." << endl
				<< "[2] Минуты." << endl
				<< "[0] Отмена." << endl
				<< ">> ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "Текущее: ";
				cout << this->hour << endl << "Новое >> ";
				cin >> F;
				if (F < 0 || F > 23)
					throw 4;
				hour = F;
				break;
			case 2:
				cout << "Текущее: ";
				cout << this->minute << endl << "Новое >> ";
				cin >> F;
				if (F < 0 || F > 59)
					throw 5;
				minute = F;
				break;
			default:
				break;
			}
		case 3:
			cout << "Текущее: ";
			cout << this->title << endl
				<< "Новое >> ";
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
			cout << "День должен быть числом от 1 до 31!" << endl;
			break;
		case 2:
			cout << "Месяц должен быть число от 1 до 12!" << endl;
			break;
		case 3:
			cout << "Год должен быть числом от 1!" << endl;
			break;
		case 4:
			cout << "Часы должны быть числом от 0 23!" << endl;
			break;
		case 5:
			cout << "Минуты должны быть числом от 0 до 59!" << endl;
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
	out << "Программа: " << endl
		<< "Дата: " << this->day<<"."<<this->month<<"."<<this->year <<  endl
		<< "Время: " << this->hour<<":"<<this->minute << endl
		<< "Название:" << this->title << endl
		<< "=================================" << endl;
}