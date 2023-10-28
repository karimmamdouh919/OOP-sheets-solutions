#include "GCD.h"
#include <iostream>
#include <string>
using namespace std;



int main() {
	GCD a, b, c;
	a.set();
	b.set();
	c = c.compareMin(a, b);
	c.display();

	return 0;
}