#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class level {
protected:
	string course[5];
	float dg[5];
	int credit[5];
public:
	void read() {
		for (int i = 0; i < 5; ++i) {
			cout << "Enter the name of the Course " << i + 1 << " : ";
			cin >> course[i];
			cout << endl << "Enter the Course grade : ";
			cin >> dg[i];
			cout << endl << "Enter the Course #CH: ";
			cin >> credit[i];
		}
	}
	void display() {
		cout << "Course name: \t\t\t Course grade: \t\t\t Credit hour:\n";
		for (int i = 0; i < 5; ++i) {
			cout << course[i] << " \t\t\t " << dg[i] << " \t\t\t " << credit[i] << endl;
		}
	}
};

class student : public level{
	string name;
	int id, total_c;
	float total_d;
	char gpa;
public:
	void read() {
		cout << "Enter student's name: ";
		cin >> name;
		cout << "Enter student's ID : ";
		cin >> id;
		level::read();
		total_c = 0, total_d = 0;
		for (int i = 0; i < 5; ++i) {
			total_d += dg[i];
			total_c += credit[i];
		}
		float avg = total_d / 5;
		if (avg >= 90) gpa = 'A';
		else if (avg >= 80 && avg < 90) gpa = 'B';
		else if (avg >= 65 && avg < 80) gpa = 'C';
		else if (avg >= 60 && avg < 65) gpa = 'D';
		else gpa = 'F';
	}
	void display() {
		float avg = total_d / 5;
		cout << "Student name: " << name << "\t Student ID: " << id << "\t GPA: ";
		if (avg >= 85 && avg < 90) cout << gpa << '+' << endl;
		else if (avg >= 75 && avg < 80) cout << gpa << '+' << endl;
		else cout << gpa << endl;
	}
};


int main() {
	int n;
	cin >> n;
	student a[10000];
	for (int i = 0; i < n; ++i) {
		a[i].read();
		a[i].display();
	}
	return 0;
}

