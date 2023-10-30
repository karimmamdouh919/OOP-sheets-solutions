#include <iostream>
#include <math.h>
using namespace std;


class XD {
	float x[10];
	int n;
public:
	bool isPrime(int x) {
		if (x == 1)return 0;
		for (int i = 2; i < x; ++i) {
			if (x % i == 0)return 0;
		}
		return 1;
	}
	void set() {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}
	}
	float avg() {
		float s = 0, c = 0;
		for (int i = 0; i < n; ++i) {
			int a = int(x[i]);
			if (isPrime(a)) {
				s += x[i];
				c++;
			}
		}
		return s / c;
	}

	float maxPrime() {
		int idx;
		for (int i = 0; i < n; ++i) {
			int a = int(x[i]);
			if (isPrime(a)) {
				idx = i;
				break;
			}
		}
		float mx = x[idx];
		for (int i = idx; i < n; ++i) {
			int a = int(x[i]);
			if (isPrime(a)) {
				if (mx < x[i])mx = x[i];
			}
		}
		return mx;
	}
	void display() {
		cout << "X: \t\t\t\t prime?:\n";
		for (int i = 0; i < n; ++i) {
			cout << x[i] << " \t\t\t\t\t";
			int a = int(x[i]);
			if (isPrime(a))cout << "Prime\n";
			else cout << "Not prime\n";
		}
		cout << "Primes avg: " << avg() << endl;
		cout << "Max prime: " << maxPrime() << endl;
	}
	friend class opns;

};

class YD {
	float y[10];
	int a,m;
public:
	void set() {
		cin >> a >> m;
		for (int i = 0; i < m; ++i) {
				cin >> y[i];
			}	
	}
	float avg() {
		float s = 0, c = 0;
		for (int i = 0; i < m; ++i) {
			int b = int(y[i]);
			if (b % a == 0) {
				s += y[i];
				c++;
			}
		}
		return s / c;
	}
	float max() {
		int idx;
		for (int i = 0; i < m; ++i) {
			int b = int(y[i]);
			if (b%a==0) {
				idx = i;
				break;
			}
		}
		float mx = y[idx];
		for (int i = idx; i < m; ++i) {
			int b = int(y[i]);
			if (b%a==0) {
				if (mx < y[i])mx = y[i];
			}
		}
		return mx;
	}
	void display() {
		cout << "Y: \t\t\t\t divisable by " << a << "?: \n";
		for (int i = 0; i < m; ++i) {
			cout << y[i] << " \t\t\t\t\t";
			int b = int(y[i]);
			if (b%a==0)cout << "Yes\n";
			else cout << "No\n";
		}
		cout << "Avg: " << avg() << endl;
		cout << "Max: " << max() << endl;
	}
	friend class opns;
};

class opns {
public:
	void compare(XD a, YD b) {
		if (a.avg() > b.avg()) a.display();
		else b.display();
	}
	float sum(XD a, YD b) {
		return a.maxPrime() + b.max();
	}

};

int main() {
	XD a;
	a.set();
	a.display();
	YD b;
	b.set();
	b.display();
	opns c;
	c.compare(a, b);
	cout << c.sum(a, b);
	return 0;
}