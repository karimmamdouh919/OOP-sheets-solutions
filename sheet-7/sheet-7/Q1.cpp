/ #include <iostream>
#include <string>
#include <math.h>

using namespace std;


class student {
protected:
    string name;
    float age;
    int id;
public:
    void read() {
        cout << "Enter stuent name: ";
        cin >> name;
        cout << "Enter studnet age: ";
        cin >> age;
        cout << "Enter student ID: ";
        cin >> id;
    }
    void write() {
        cout << "Student name: " << name << "\nAge: " << age << "\nID: " << id << endl;
    }
};

class math : virtual public student {
protected:
    string mc[3];
    double d[3], sum;
public:
    void read() {
        cout << "Enter math courses names and its degress :" << endl;
        for (int i = 0; i < 3; ++i) {
            cin >> mc[i] >> d[i];
            sum += d[i];
        }
    }
    void write() {
        cout << "Math course: \t\t Grade: \n";
        for (int i = 0; i < 3; ++i) {
            cout << mc[i] << "\t\t\t " << d[i] << endl;
        }
    }
};


class cs : virtual public student {
protected:
    string csc[3];
    double d[3], sum;
public:
    void read() {
        cout << "Enter CS courses names and its degress :" << endl;
        for (int i = 0; i < 3; ++i) {
            cin >> csc[i] >> d[i];
            sum += d[i];
        }
    }
    void write() {
        cout << "CS course: \t\t Grade: \n";
        for (int i = 0; i < 3; ++i) {
            cout << csc[i] << "\t\t\t " << d[i] << endl;
        }
    }
};


class result : public math, public cs {
    double total;
    char gpa;
public:
    void read() {
        student::read();
        math::read();
        cs::read();
        total = math::sum + cs::sum;
        double avg = total / 6;
        if (avg >= 90) gpa = 'A';
        else if (avg >= 80 && avg < 90) gpa = 'B';
        else if (avg >= 65 && avg < 80) gpa = 'C';
        else if (avg >= 60 && avg < 65) gpa = 'D';
        else gpa = 'F';
    }
    void write() {
        student::write();
        math::write();
        cs::write();
        double avg = total / 6;
        cout << "Total degree: " << total << "\t\tGPA: ";
        if (avg >= 85 && avg < 90 || avg >= 75 && avg < 80)  cout << gpa << '+' << endl;
        else cout << gpa << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of Students: ";
    cin >> n;
    result x[100];
    for (int i = 0; i < n; ++i) {
        x[i].read();
        x[i].write();
    }


    return 0;
}
