#include <iostream>
#include <string>
using namespace std;

class student {
	string name;
	float age;
	int id;
	double m[3];
public:
	student( string n = "", float a=0, int i=0,double arr[]={}) {
		name = n;
		age = a;
		id = i;
		for (int i = 0; i < 3; ++i)m[i] = arr[i];
	}
	student(student &x){
		name = x.name;
		age = x.age;
		id = x.id;
		for (int i = 0; i < 3; ++i)m[i] = x.m[i];
	}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "ID: " << id << endl;
		for (int i = 0; i < 3; ++i)cout << "Mark " << i + 1 << " : " << m[i] << endl;
	}

};


int main() {
	double arr1[] = { 1,1,1 };
	double arr2[] = { 2,2,2 };
	student s1("Karim", 19.0, 1111, arr1), s2(s1);
	s1.display();
	s2.display();

	return 0;
}