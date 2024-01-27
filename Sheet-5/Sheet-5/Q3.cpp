#include <iostream>
#include <math.h>
using namespace std;


class matrix {
	double M[10][10];
	int n, m;
public:
	bool isPrime(double x) {
		int t = int(x);
		for (int i = 2; i < t; ++i)if (t % i == 0)return 0;
		return 1;
	}
	void read() {
		do { cin >> m >> n; } while (n <= 0 || m <= 0);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				cin >> M[i][j];
			}
			double s = 0;
			for (int j = 0; j < n - 1; ++j) {
				if (M[i][j] > 0 && isPrime(M[i][j]))s += M[i][j];
			}
			M[i][n - 1] = s;
		}
	}
	void display() {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << M[i][j] << ' ';
			}
			cout << '\n';
		}

	}
	double operator[](int x) {
		return M[x][n - 1];
	}

	matrix operator*(matrix a) {
		matrix x;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < a.n; ++j) {
				x.M[i][j] = 0;
				for (int k = 0; k < n; ++k) {
					x.M[i][j] += M[i][k] * a.M[k][j];
				}
			}
		}
		return x;
	}
	bool operator>=(matrix x) {
		for (int i = 0; i < m; ++i) {
			if (M[i][n - 1] < x.M[i][n - 1])return 0;
		}
		return 1;
	}
	int Rm() {
		return m;
	}
};


int main() {
	matrix a, b, c;
	a.read();
	b.read();
	a.display();
	b.display();
	c = a * b;
	c.display();


	return 0;
}