#include <iostream>
#include <math.h>
#include <string>

using namespace std;



class base{
protected:
    double a[30], b[30], x;
    int n;
public:
    int fact(int x){
        int f = 1;
        for(int i=2 ; i<=x ; ++i) f *= i;
        return f;
    }
    int comb(int a, int b){
        return fact(a)/(fact(a-b)*fact(b));
    }
    void read(){
        cout << "Enter n and x: " ;
        cin >> n >> x;
        cout << "Enter values of a: \n";
        for(int i=0 ; i<n ; ++i){
            cin >> a[i];
            int t1 = int(a[i]), t2 = int(x);
            b[i] = comb(t1,t2);
        }
    }
    double maxB(){
        int mx = b[0];
        for(int i=0 ; i<n ; ++i){
            if(mx < b[i])mx = b[i];
        }
        return mx;
    }
    double minB(){
        int mn = b[0];
        for(int i=0 ; i<n ; ++i){
            if(mn > b[i])mn = b[i];
        }
        return mn;
    }
    virtual double diff(){
        return maxB() - minB();
    }
};

class drive1 : virtual public base {
protected:
    double d1[30];
public:
    void set(){
        base::read();
        for(int i=0 ; i<n ; ++i){
            d1[i] = 0;
            int t = int(a[i]);
            for(int j=0 ; j<=i ; ++j){
                if(t%2)d1[i] += b[j] - a[j];
                else d1[i] += b[j] - a[j];
            }
        }
    }
    double diff(){
        return (n%2==0) ? abs(d1[n/2]-d1[n/2-1]) : d1[n/2];
    }
};

class drive2 : virtual public base {
protected:
    double d2[30];
public:
    void set(){
        base::read();
        for(int i=0 ; i<n ; ++i){
            d2[i] = 1;
            int t = int(a[i]);
            for(int j=0 ; j<=i ; ++j){
                if(t%2)d2[i] *= b[j] + a[j];
                else d2[i] *= b[j] + a[j];
            }
        }
    }
    double diff(){
        return abs(d2[0] - d2[n-1]);
    }
};

class drive : public drive1, public drive2 {
    int d[30];
public:
    void set(){
        drive1::set();
        drive2::set();
        for(int i=0 ; i<n ; ++i)d[i] = int(a[i]*d1[i]+b[i]*d2[i]);
    }
    double diff(){
        int s = 0;
        for(int i=0 ; i<n ; ++i){
            double t = int(d[i]);
            s -= t;
        }
        return s;
    }
};

int main(){
    base *p, a;
    drive1 b;
    drive2 c;
    drive d;
    p = &a;
    p -> read();
    cout << p -> diff() << endl;
    p = &b;
    b.set();
    cout << p -> diff() << endl;
    p = &c;
    c.set();
    cout << p -> diff() << endl;
    p = &d;
    d.set();
    cout << p -> diff() << endl;
    return 0;
}





