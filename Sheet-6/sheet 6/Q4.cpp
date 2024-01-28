#include <iostream>
#include <string>
#include <math.h>

using namespace std;


class data1 {
protected:
    string nd1;
    int d1[20], n;
public:
    void read() {
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter nd1: ";
        cin >> nd1;
        for (int i = 0; i < n; ++i) {
            cout << "Enter d1[" << i << "]: ";
            cin >> d1[i];
        }
    }
    float total() {
        float s = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < i + 2; ++j) {
                if (d1[i] % 2) s += pow(float(d1[i]), (j));
                else s += pow(float(d1[i]), 2 * (j));
            }
        }
        return s;
    }
    void print() {
        cout << "n: " << n << "\tnd1: " << nd1 << '\n';
        for (int i = 0; i < n; ++i)cout << "d1[" << i << "]: " << d1[i] << endl;
    }
};


class data2 {
protected:
    string nd2;
    int d2[20], m;
public:
    void read() {
        cout << "Enter m: ";
        cin >> m;
        cout << "Enter nd2: ";
        cin >> nd2;
        for (int i = 0; i < m; ++i) {
            cout << "Enter d2[" << i << "]: ";
            cin >> d2[i];
        }
    }
    float total() {
        float s = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < i + 2; ++j) {
                if (d2[i] >= 0) s += pow(float(d2[i]), j);
                else s += pow(float(d2[i]), 2 * j);
            }
        }
        return s;
    }
    void print() {
        cout << "m: " << m << "\tnd2: " << nd2 << '\n';
        for (int i = 0; i < m; ++i)cout << "d2[" << i << "]: " << d2[i] << endl;
    }
};


class data : public data1, public data2 {
    string nd;
    int tsum;
public:
    void set() {
        data1::read();
        data2::read();
        cout << "Enter nd: ";
        cin >> nd;
        tsum = data1::total() + data2::total();
    }
    void print() {
        cout << "nd: " << nd << "\ttsum: " << tsum;
    }
};


int main() {
    data x;
    x.set();
    x.print();
    return 0;
}
