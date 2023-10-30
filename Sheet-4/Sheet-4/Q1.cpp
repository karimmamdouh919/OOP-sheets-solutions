
#include <iostream>

using namespace std;


class product {
	string name;
	float price, tax;
	int serial;
	static int pserial;
public:
	product() {
		serial = pserial;
		pserial -= 10;
	}
	void set() {
		cin >> name >> price >> tax;
	}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Net Price: " << price + tax << endl;
		cout << "Serial Number: " << serial << endl;
	}
	static void displayPserial() {
		cout << pserial << endl;
	}
};



int product::pserial = 10000;



int main() {
	product a, b, c;
	a.set();
	b.set();
	c.set();
	a.display();
	b.display();
	c.display();
	a.displayPserial();
	product::displayPserial();

	return 0;
}