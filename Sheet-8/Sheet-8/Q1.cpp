#include <iostream>
#include <math.h>
#include <string>

using namespace std;



class Base{
protected:
    double b[30][30],x;
    int n;
public:
    void read(){
        cin >> n;
        for(int i=0 ; i<n-1 ; ++i)
            for(int j=0 ; j<n ; ++j)cin >> b[i][j];
    }
    int GCD(double x, double y){
        int a = int(x), b = int(y);
        if(b==0)return a;
        return GCD(b,a%b);
    }
    double maxGCD(int i){
        int m = GCD(b[0][i],x);
        for(int j=0 ; j<n-1 ; ++j){
            if(m<GCD(b[j][i],x))m = GCD(b[j][i],x);
        }
        double t = m;
        return t;
    }
    void setLastRow(){
        for(int i=0 ; i<n ; ++i){
            b[n-1][i] = maxGCD(i);
        }
    }
    virtual double avg(){
        double s = 0;
        for(int i=0 ; i<n ; ++i){
            s += b[n-1][i];
        }
        return s/n;
    }
    void display(){
        cout << this -> avg();
    }
};

class Drive : public Base{
    double d[30];
public:
    double fact(double x){
        double f = 1;
        for(double i=2 ; i<=x ; ++i){
            f *= i;
        }
        return f;
    }
    void set(){
        Base::read();
        Base::setLastRow();
        for(int i=0 ; i<n ; ++i){
            d[i] = fact(b[n-1][i]);
        }
    }
    double avg(){
        return (d[0]+d[n-1])/2;
    }
};

int main (){
  Base *p,x;
  Drive y;
  p = &x;
  p -> read();
  p -> setLastRow();
  p -> display();
  p = &y;
  y.set();
  cout << y.avg();
  return 0;
}

