#include <iostream>
#include <math.h>
using namespace std;


class Data {
	double d1[20], d2[20];
	int n;
public:
	void set() {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> d1[i];
		for (int i = 0; i < n; ++i) {
			double s = 0;
			for (int j = 0; j <= i; ++j) {
				double temp = abs(d1[j]);
				s += d1[i] * 1 / pow(2.0, j);
			}
			d2[i] = s;
		}
	}
	Data operator+=(Data x) {
		for (int i = 0; i < n; ++i) {
			d1[i] += x.d1[i];
		}
		for (int i = 0; i < n; ++i) {
			d2[i] += x.d2[i];
		}
		return *this;
	}
	Data operator++() {
		for (int i = 0; i < n; ++i) {
			++d1[i];
		}
		for (int i = 0; i < n; ++i) {
			++d2[i];
		}
		return *this;
	}
	Data operator++(int) {
		Data x = *this;
		for (int i = 0; i < n; ++i) {
			++d1[i];
			++d2[i];
		}
		return x;
	}
	bool operator>(Data x) {
		;for (int i = 0; i < n; ++i) {
			if (d2[i] <= x.d2[i])return 0;
		}
		return 1;
	}
	double operator[](int a) {
		return d2[a];
	}
	friend void compare(Data, Data);
	friend void Compare(Data, Data);
	int Rn() {
		return n;
	}
	void display() {
		cout << "D1:\t\t\t\tD2:\n";
		for (int i = 0; i < n; ++i) {
			cout << d1[i] << "\t\t\t\t" << d2[i] << endl;
		}
	}
};

void Compare(Data x, Data y) {
	for (int i = 0; i < x.Rn(); ++i) {
		if (y[i] > x[i]) { x.display();return; }
	}
	y.display();
}
void compare(Data x, Data y) {
	if (y > x)x.display();
	else y.display();
}

int main() {
	Data a, b;
	a.set();
	b.set();
	b = a++;
	b.display();
	a.display();
	b = ++a;
	b.display();
	a.display();
	a += b;
	a.display();
	Compare(a, b);
	compare(a, b);

	return 0;
}