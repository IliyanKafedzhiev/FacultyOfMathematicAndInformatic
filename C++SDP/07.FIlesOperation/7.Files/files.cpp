#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

/**
 * Четене от текстов файл
 */
void readText() {
	ifstream f("essay.txt");
	if (!f)	{
		cerr << "Error opening file!" << endl;
	} else {
		cout << "Words in the file:" << endl;
		char word[100];
		while (f >> word) // operator>> връща псевдоним
			// към входния поток f; операторът за
			// преобразуване към bool казва дали състоянието
			// на потока е good. Когато стигнем края на файла,
			// се връща false
		{
			cout << word << endl;
		}
		// с оператор >> четем до разделител - интервал, нов ред, табулация;
		// не можем да прочетем цял ред - ще стигнем до първия интервал/табулация;
		// ! ако искаме да четем по редове - използваме f.getline(<низ>, <макс. дължина>);
		f.close();
	}
}

class Student {
private:
	int fn;
	double grade;
	char name[40];
public:
	Student(int _fn, double _grade, char const* _name) :
		fn(_fn), grade(_grade)
	{
		strncpy(name, _name, 39);
		name[39] = '\0';
	}
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, Student const&);
};

istream& operator>>(istream& is, Student& s) {
	is >> s.fn >> s.grade;
	is.getline(s.name, 40);
	return is;
}

ostream& operator<<(ostream& os, Student const& s) {
	os << s.fn << " " << s.grade << " " << s.name << endl;
	return os;
}

/**
 * Писане в текстов файл
 */
void writeText() {
	Student s1(40000, 5.50, "Ivan Petroff");
	Student s2(40001, 3.50, "Петър Иванов");
	Student s3(40002, 6.00, "Петър Петров");
	ofstream fo("students.txt");
	fo << s1 << s2 << s3;
	fo.close();
}

/**
 * Отваря текстов файл както за четене, така и за запис; подменя началото на 2-ия ред.
 */
void readWriteText() {
	fstream f("essay.txt");
	char line[100];
	f.getline(line, 100);
	f << "DO NOT READ THIS!\n";
	cout << "The line is: " << line;
	f.close();
}

/**
 * Четене от текстов файл и запис в двоичен
 */
void readTextWriteBinary() {
	Student s(0, 0, "");
	ifstream fi("students.txt");
	ofstream fo("students.dat", ios::out | ios::binary);
	while (fi >> s)
	{
		cout << "Student found: " << s;
		fo.write((char const*)&s, sizeof(s));
	}
	fi.close();
	fo.close();
}

/**
 * Четене на всички студенти от двоичен файл
 */
void readBinary() {
	Student s(0, 0, "");
	ifstream fi("students.dat", ios::in | ios::binary);
	while (fi.read((char*)&s, sizeof(s))) {
		cout << "From students.dat: " << s;
	}
	fi.close();
}

/**
 * Четене от двоичен файл - пряк достъп до i-ти елемент
 */
Student readStudent(int i) {
	Student s(0, 0, "");
	ifstream fi("students.dat", ios::in | ios::binary);
	fi.seekg(i * sizeof(Student));
	fi.read((char*)&s, sizeof(s));
	if (!fi)
	{
		cerr << "Няма такъв студент!";
		return s;
	}
	cout << "Студент с пореден номер " << i;
	cout << ": " << s;
	fi.close();
	return s;
}

/**
 * Запис в двоичен файл - пряк достъп до i-ти елемент
 */
void writeStudent(int i, Student const& s) {
	fstream fo("students.dat", ios::in | ios::out | ios::binary);
	fo.seekp(i * sizeof(Student));
	fo.write((char const*)&s, sizeof(s));
	fo.close();
}


int main() {

	readText();

	writeText();

	// Добавяне на данни към съществуващ файл:
	ofstream fo("students.txt", ios::app);
	fo << "40003 5.99 Ivan Ivanov" << endl;
	fo.close();

	// Добавяне на данни към несъществуващ файл - създава се нов файл:
	ofstream fo2("students2.txt", ios::app);
	fo2 << "Този файл го нямаше" << endl;
	fo2.close();

	readWriteText();
	// след изпълнението на горния метод essay.txt вече е с променено съдържание

	readTextWriteBinary();

	Student s(0, 0,"");
	cout << "Enter faculty number, grade and name: ";
	cin >> s;
	readBinary();
	writeStudent(2, readStudent(1));
	Student gp(40003, 3.20, "Георги Петров");
	writeStudent(10000, gp);

	// Генерирани от тестовата програма файлове:
	// students.txt, students2.txt, students.dat

	return 0;
}
