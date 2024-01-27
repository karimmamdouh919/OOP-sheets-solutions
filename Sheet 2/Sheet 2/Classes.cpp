#include <iostream>
using namespace std;

/*class student {
	private:
		string name;
		float age;
		int id;
		double m[10]= { 1,3,4,5,6,7,8,9,10 };
		double avg;
	public: 
		student(string x="karim",float y=19, int z=1234) {
			name = x;
			age = y;
			id = z;
			age = 10*(11 / 2);
			age /= 10;
		}
		student(student &w) {
			name = w.name;
			age = w.age;
			id = w.id;
		}
		void display() {
			cout << name << '\n' << age << '\n' << id << '\n';
			for (int i = 0; i < 10; ++i)cout << m[i] << endl;
			cout << avg << endl;
		}
};*/
class complex {
	int r, i;
	public:
		//complex(int x=0, int y=0) :r(x), i(y) {};
		complex(int x = 0, int y = 0) { r = x, i = y; }
		complex(complex& w) {
			r = w.r;
			i = w.i;
		}
		void display() {
			cout << r << "+i" << i << endl;
		}
		float turnReal() {
			float z = sqrt(r * r + i * i);
			return z;
		}
		complex product(complex w) {
			complex t;
			t.r = r * w.r - i * w.i;
			t.i = i * w.r + r * w.i;
			return t;
		}
};

int main()
{
	/*student x, y("mahmoud", 22.5, 5678);
	x.display();
	y.display();
	student z(y);
	z.display();*/
	complex a(2, 5), b(a);
	a.display();
	b.display();
	cout << a.turnReal();
	complex c = a.product(b);
	c.display();


	return 0;
}