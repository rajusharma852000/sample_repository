#include <iostream>
using namespace std;

class Complex{
    float x;
    float y;
public:
    Complex(float x = 0, float y = 0)
    {
        this->x = x;
        this->y = y;
    }
    friend Complex operator+(const Complex& , const Complex&);
    friend Complex operator-(const Complex& , const Complex&);
    friend Complex operator*(const Complex& , const Complex&);
    friend Complex operator+(const Complex& , const Complex&);
    friend ostream& operator<<(ostream& , const Complex&);
    Complex conjugate(Complex& c){
        Complex temp;
        temp.x = c.x;
        temp.y = -c.y;
        return temp;
    }
};
Complex operator+(const Complex &c1, const Complex  &c2)
{
    Complex temp;
    temp.x = c1.x + c2.x;
    temp.y = c1.y + c2.y;
    return temp;
}
Complex operator-(const Complex &c1, const Complex  &c2)
{
    Complex temp;
    temp.x = c1.x - c2.x;
    temp.y = c1.y - c2.y;
    return temp;
}
Complex operator*(const Complex &c1, const Complex  &c2)
{
    Complex temp;
    temp.x = c1.x * c2.x - c1.y * c2.y;
    temp.y = c1.x * c2.y + c1.y * c2.x;
    return temp;
}
ostream& operator<<(ostream& dout, const Complex& c){
    if(c.y >= 0)dout << c.x << " + " << c.y << "i"<<endl;
    else dout << c.x << " - " << -c.y << "i"<<endl;
    return dout;
}

int main()
{
    Complex c1(1, -1), c2(2, 2), c3(3, 3);
    Complex c4 = c2 - c1;
    cout<<c1<<c2<<c3<<c4;
}
