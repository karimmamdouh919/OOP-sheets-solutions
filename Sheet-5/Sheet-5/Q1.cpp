#include <iostream>
using namespace std;


class product {
	float p[20];
	int n, a, b;
	float avg;
public:
	void set() {
		avg = 0;
		cin >> n;
		do {
			cin >> a >> b;
		} while (a >= b || a < 0 || b < 0);

		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			if (i >= a && i <= b)avg += p[i];
		}
		avg /= n;
	}
	product operator+(float tax) {
		product s;
		for (int i = 0; i < n; ++i) {
			s.p[i] = tax + (p[i] + tax * p[i]);
		}
		return s;
	}

	friend product operator+(float tax, product a) {
		product s;
		for (int i = 0; i < a.n; ++i) {
			s.p[i] = tax + (a.p[i] + tax * a.p[i]);
		}
		return s;
	}
	product operator+(product a) {
		product s;
		for (int i = 0; i < n; ++i) {
			s.p[i] = p[i] + a.p[i];
		}
		return s;
	}
	bool operator>(product x) {
		for (int i = 0; i < n; ++i) {
			if (p[i] < x.p[i])return 0;
		}
		return 1;
	}
	bool operator<(product x) {
		return (avg < x.avg);
	}
	float operator[](int i) {
		return p[i];
	}
	void display() {
		cout << "A: " << a << "\nB: " << b << "\nAverage: " << avg << endl;
	}
	int Rn() {
		return n;
	}
};

int main() {
	product x, y, z;
	x.set();
	y.set();
	x.display();
	y.display();
	z = x + 3.0;
	z = 3.0 + y;
	if (x < y)cout << "y greater than x\n";
	else cout << "y smaller than or equal to x\n";
	if (x > y)cout << "x's average smaller than y's\n";
	else cout << "x's average smaller than or equal to y's\n";
	cout << "Xi:\t\t\tYi:\t\t\tZi:\n";
	for (int i = 0; i < x.Rn(); ++i) {
		cout << x[i] << "\t\t\t" << y[i] << "\t\t\t" << z[i] << endl;
	}

	return 0;
}
