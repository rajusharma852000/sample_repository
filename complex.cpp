#include<iostream>

using namespace std;

template< class T>
class Complex{
	T x;
	T y;
public:
	Complex(T x, T y){
		this->x = x;
		this->y = y;
	}
	Complex(){
		//defalut
	 }
	
	Complex operator+(Complex& c){
		Complex temp;
		temp.x = x + c.x;
		temp.y = y + c.y;
		return temp;
	}
	Complex operator-(Complex& c){
		Complex temp;
		temp.x = x - c.x;
		temp.y = y - c.y;
		return temp;
	}
	Complex operator*(Complex& c){
		Complex temp;
		temp.x = x*c.x - y*c.y;
		temp.y = x*c.y + y*c.x;
		return temp;
	}
	void conjugate(Complex& c){
		x = x;
		y = -y;
	}
	void print(){
		if(y >= 0)cout<<x<<" + "<<y<<"i"<<endl;
		else cout<<x<<" - "<<(-y)<<"i"<<endl;

	}
};

int main(){
	Complex<int> c1(5,6), c2(4,7);
	Complex<int>c3 = c1 + c2;  //c1.operator+(c2);
	c3.print();
	Complex<int> c4 = c1 - c2;
	c4.print();
	Complex<int> c5 = c1 * c2;
	c5.print();
	c1.conjugate(c1);
	c1.print();
	
}
