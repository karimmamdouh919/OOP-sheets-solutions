#include <iostream>
#include <string>
#include <math.h>
using namespace std;


struct Data {
	string name;
	float salary, tax;
	void read() {
		cin >> name >> salary >> tax;
	}
	void print() {
		cout << "Name: " << name << "\nSalary: " << salary << "\nTax: " << tax << endl;
	}
};

class employee {
    Data e[10];
	int n;
public:
	void set() {
		cin >> n;
		for (int i = 0; i < n;++i) {
			e[i].read();
		}
	}
	void display() {
		for (int i = 0; i < n;++i) {
			e[i].print();
		}
	}
	friend class NS;

};
class NS {
	float nsl[10];
public:
	void set(employee x) {
		for (int i = 0; i < x.n; ++i) {
			nsl[i] = x.e[i].salary - x.e[i].tax;
		}
	}
	float sum(employee x) {
		float s = 0;
		for (int i = 0; i < x.n; ++i) {
			s += nsl[i];
		}
		return s;
	}
	employee compare(employee x, employee y) {
		if (sum(x) > sum(y))return x;
		return y;
	}
};


int main(){
	
	return 0;
}