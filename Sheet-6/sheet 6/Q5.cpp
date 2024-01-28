#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class rectangle {
protected:
    float rd[10][2];
    int n;
public:
    void read() {
        cout << "Enter number of Rectangles: ";
        cin >> n;
        cout << "Enter each rectangle dimentions: ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) { cin >> rd[i][j]; }
        }
    }
    float area(int i) {
        return rd[i][0] * rd[i][1];
    }
    void print() {
        cout << "Number of Rows: " << n << endl;
        cout << "Dimension 1: \t\t\t Dimension 2:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j)cout << rd[i][j] << "\t\t\t";
            cout << endl;
        }
    }
};


class RArea : public rectangle {
protected:
    float ra[10];
public:
    void set() {
        rectangle::read();
        for (int i = 0; i < n; ++i) {
            ra[i] = area(i);
        }
    }
    void print() {
        rectangle::print();
        cout << "Areas of rectangles: \n";
        for (int i = 0; i < n; ++i)cout << ra[i] << endl;
    }
};

class Pvolume : public RArea {
    float h[10], v[10];
public:
    void set() {
        RArea::set();
        cout << "Enter hights of each rectangle: \n";
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            v[i] = h[i] * ra[i];
        }
    }
    void print() {
        RArea::print();
        cout << "Volume of each rectangle: " << endl;
        for (int i = 0; i < n; ++i)cout << v[i] << endl;
    }
};


int main() {
    Pvolume x;
    x.set();
    x.print();
}