#include <iostream>
#include <string>
using namespace std;

class num {
	float n[10];
	int m;
	string t[10];
public:
	float fact(float n);
	bool isPrime(float n);
	void set();
	void display();
	float sum();
};
float num::fact(float n) {
	float f = 1;
	for (float i = 1; i <= n; ++i)
		f *= i;
	return f;
}
bool num::isPrime(float n) {
	int temp = int(n);
	for (int i = temp - 1; i > 1; --i)
		if (temp % i == 0)return 0;
	return 1;
}
void num::set() {
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> n[i];
		if (n[i] < 0) {
			while (n[i] < 0)cin >> n[i];
		}
		if(isPrime(n[i]))t[i]="prime";
		else t[i]="not prime";
	}
}
void num::display() {
	cout << "number: \t\t\t prime?: \t\t\t factorial: " << endl;
	for (int i = 0; i < m; ++i) {
		float f;
		if (t[i] == "prime")f = fact(n[i]);
		else f = 0;
		cout << n[i] << "\t\t\t\t\t" << t[i] << "\t\t\t\t\t" << f << endl;
	}
}
float num::sum() {
	float s = 0;
	for (int i = 0; i < m; ++i) {
		if (isPrime(m[i]))s += m[i];
	}
	return s;
}
int main() {

	num a;
	a.set();
	a.display();

	return 0;
}