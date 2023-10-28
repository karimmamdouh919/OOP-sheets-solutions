#include <iostream>
#include <string>
using namespace std;

class complex {
	int r, i;
public:
	complex(int x = 0, int y = 0) {
		r = x;
		i = y;
	}
	void display() {
		cout << r << " + i" << i << endl;
	}
	double toReal() {
		return sqrt(r * r + i * i);
	}
	complex multi(complex x) {
		complex p;
		p.r = r * x.r - i * x.i;
		p.i = r * x.i + x.r * i;
		return p;
	}
	complex division(complex x) {
		complex d;
		d.r = (r * x.r - i * x.i)/(x.r * x.r + x.i * x.i);
		d.i = (r * x.i + x.r * i)/(x.r * x.r + x.i * x.i);
		return d;
	}
	double compare(complex y) {
		return max(toReal(), y.toReal());
	}
	double avg(complex x){
		return (toReal() + x.toReal()) / 2;
	}

};


int main() {
	complex a(1, 2), b(3, 4), c(5, 6), d(7,8);
	a.display();
	b.display();
	c.display();
	d.display();
	complex e = a.multi(b);
	complex f = c.division(d);
	complex g = a.compare(b);
	complex h = c.avg(d);
	e.display();
	f.display();
	g.display();
	h.display();
	return 0;
}