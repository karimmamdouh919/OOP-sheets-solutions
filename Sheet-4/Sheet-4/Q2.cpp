#include <iostream>
#include <math.h>
using namespace std;


class series {
	int x[20];
	double s[20];
	int n;
public:
	int fact(int x) {
		int f = 1;
		for (int i = 2; i <= x; ++i) {
			f *= i;
		}
		return f;
	}
	int combination(int x, int y) {
		return fact(x) / (fact(x - y) * fact(y));
	}
	void set() {
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> x[i];

		for (int i = 1; i <= n; ++i) {
			float sum = 0;
			for (int j = 0; j <= i; ++j) {

				sum += combination(i, j) * pow(x[i - 1], j + 1);
			}
			s[i - 1] = sum;
		}
	}
	void display() {
		cout << "X: \t\t\t\t S:\n";
		for (int i = 0; i < n; ++i) {
			cout << x[i] << " \t\t\t\t " << s[i] << '\n';
		}
	}
	friend double sum(series x) {
		double mn = x.s[0], mx = x.s[0];
		for (int i = 0; i < x.n; ++i) {
			if (mn > x.s[i])mn = x.s[i];
			if (mx < x.s[i])mx = x.s[i];
		}
		return mx + mn;
	}
	friend series compare(series, series);
};

series compare(series x, series y) {
	if (sum(x) > sum(y))return x;
	return y;
}

int main() {

	series x,y;
	x.set();
	y.set();
	x.display();
	y.display();
	series z = compare(x, y);
	z.display();
	return 0;
}