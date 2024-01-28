#include <iostream>
using namespace std;

class Data {
	int n;
	double a[20], b[20];
public:
	int Rn() {
		return n;
	}
	friend istream& operator>>(istream& in, Data& x) {
		for (int i = 0; i < x.Rn(); ++i)in >> x.a[i];
		x.set();
		return in;
	}
	void set() {
		for (int i = 0; i < n; ++i) {
			double sum = 0;
			for (int j = 1; j <= i + 1; ++j)sum += a[j];
			b[i] = sum;
		}
	}
	double sum() {
		double s = 0;
		for (int i = 0; i < n; ++i)s += b[i];
		return s;
	}
	friend ostream& operator<<(ostream& out, Data x) {
		for (int i = 0; i < x.Rn(); ++i)out << x.b[i] << ' ';
		return out;
	}
	double operator[](int i) {
		return b[i];
	}
	bool operator<(Data x) {
		for (int i = 0; i < n; ++i) {
			if (a[i] < x.a[i])return 0;
			return 1;
		}
	}
	bool operator ==(Data x) {
		if (sum() == x.sum())return 1;
		return 0;
	}
	friend Data compare(Data x, Data y) {
		if (x < y)return x;
		return y;
	}
	friend void compare2(Data x, Data y) {
		if (x == y) cout << "equal";
		else cout << "not equaz";
	}
};
int main() {


	system("pause");
	return 0;
}