#include "Speaker.h"
Speaker::Speaker() {
	SetType(1);
	SetErr(false);
	cout << "Введите ФИО:" << endl << "Имя: ";
	cin.ignore(256, '\n');
		getline(cin, this->speakFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->speakFIO.SurName);
		cout << "Отчество: ";
		getline(cin, this->speakFIO.LastName);
		cout << "Введите ВУЗ/организацию: ";
		getline(cin, this->vuz);
		cout << "Введите тему доклада: ";
		getline(cin, this->tema);
		cout << "Введите аннотацию к докладу:";
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
	cout << "Выберите редактируемый параметр:" << endl
		<< "[1] ФИО." << endl
		<< "[2] ВУЗ/организация." << endl
		<< "[3] Тема." << endl
		<< "[4] Аннотация." << endl
		<< "[0] Отмена." << endl;
	cin >> choose;

		switch (choose) {
		case 1:
			cout << "Текущее: ";
			cout << this->speakFIO.Name << " "
				<< this->speakFIO.SurName << " "
				<< this->speakFIO.LastName << endl
				<< "Новое:  Имя >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\tФамилия >> ";
			getline(cin, fio_temp.SurName);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.LastName);
			speakFIO = fio_temp;
			break;
		case 2:
			cout << "Текущее: ";
			cout << this->vuz << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			vuz = s_temp;
			break;
		case 3:
			cout << "Текущее: ";
			cout << this->tema << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			tema = s_temp;
			break;
			break;
		case 4:
			cout << "Текущее: ";
			cout << this->annot << endl
				<< "Новое >> ";
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
	out << "Выступающий:" << endl
		<< "ФИО:" << this->speakFIO.Name << " " << this->speakFIO.SurName << " " << this->speakFIO.LastName << endl
		<< "ВУЗ/организация:" << this->vuz << endl
		<< "Тема:" << this->tema << endl
		<< "Аннотация:" << this->annot << endl
		<< "=================================" << endl;
}