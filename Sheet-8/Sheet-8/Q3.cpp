#include <iostream>
#include <math.h>
#include <string>

using namespace std;


class shape{
protected:
    float l,h;
public:
    void read(){
        cout << "Enter Length: " ;
        cin >> l;
        cout << "Enter Height: " ;
        cin >> h;
    }
    virtual float area() = 0;
    void display(){
        cout << this -> area();
    }
};

class square : virtual public shape{
public:
    float area(){
        return l * l;
    }
};

class traingle : virtual public shape{
public:
    float area(){
        return 0.5 * l * h;
    }
};

class Sqpyramid : public traingle, public square{
public:
  float area(){
      return traingle::area() + square::area();
  }
};

int main(){
    traingle b;
    square c;
    Sqpyramid d;
    shape *p[3] = {&b , &c , &d};
    for(int i=0 ; i<3 ; ++i){
        cout << i+1 << '-';
        p[i] -> read();
        p[i] -> display();
        cout << endl;
    }


    return 0;
}




