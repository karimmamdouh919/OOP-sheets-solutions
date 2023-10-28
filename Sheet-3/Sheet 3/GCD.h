#pragma once
class GCD
{
	float x[20], y[20];
	int n;
	int g[20];
public:
	int gcd(float a, float b) {
		int x = int(a), y = int(b);
		int g;
		for (int i = min(x, y); i > 0; --i) {
			if (x % i == 0 && y % i == 0) {
				g = i;
				break;
			}
		}
		return g;
	}
	void set() {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
			if (x[i] < 0) {
				while (x[i] < 0)cin >> x[i];
			}
		}
		for (int i = 0; i < n; ++i) {
			cin >> y[i];
			if (y[i] < 0) {
				while (y[i] < 0)cin >> y[i];
			}
			g[i] = gcd(x[i], y[i]);
		}
	}
	void display() {
		cout << "X: \t\t\t Y: \t\t\t G:\n";
		for (int i = 0; i < n; ++i)
			cout << x[i] << " \t\t\t " << y[i] << " \t\t\t " << g[i] << endl;
	}
	int minGCD() {
		int mn = g[0];
		for (int i = 0; i < n; ++i) {
			if (g[i] < mn)mn = g[i];
		}
		return mn;
	}
	GCD compareMin(GCD a, GCD b) {
		if (minGCD() > a.minGCD())return a;
		return b;
	}
};



