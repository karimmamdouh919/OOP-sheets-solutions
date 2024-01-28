#include <iostream>
#include <string>
using namespace std;

class Data{
	string name;
	float age;
	int id;
	float salary[5];
	float tax[5];
	
public:
	float Ntax[5];
	friend istream& operator>>(istream &in, Data &x){
		cin >> x.name >> x.age >> x.id;
		for(int i=0 ; i<5 ; ++i){
			in >> x.salary[i] >> x.tax[i];
			x.Ntax[i]=x.salary[i] - x.tax[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream &out, Data x){
			out << x.name << "\t\t\t" << x.age << "\t\t\t" << x.id << "\t\t\t";
		return out;
	}


};
class employee{
	Data p[20];
	float ntax[20];
	int n;
public:
	void set(){
		for(int i=0 ; i<n ; ++i){
			cin >> p[i];
			ntax[i]=p[i].Ntax[5];
		}
	}
	void display(){
			cout << "Name: \t\t\tAge: \t\t\tID:  x.id << \t\t\tNetsalary: \n";
		for(int i=0 ; i<n ; ++i)
			cout << p[i] <<  ntax[i] << endl;
	}
	float mx(){
		float m = ntax[0];
		for(int i=0 ; i<n ; ++i)
			if(ntax[i]>m)swap(ntax[i],m);
		return m;
	}
	bool operator>(employee x){
		return (mx()>x.mx());
	}
	friend void compare(employee x,employee y){
		if(x>y)x.display();
		else y.display();
};

int main(){


	system("pause");
	return 0;
}