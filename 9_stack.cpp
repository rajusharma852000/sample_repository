#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <class T>
class Stack{
	T *arr;
	int last;
	int capacity;
public:
	//constructor
	Stack(int size){
		capacity = size;
		last = -1;
		arr = new T[size];
	}
	
	//defalut constructor
	Stack(){ }
	
	//to insert
	void push(T val){
		if(last+1 == capacity){
			cout<<"Stack is full"<<endl;
			return ;
		}
		arr[++last] = val;
	}
	
	//to delete
	T pop(){
		if(last == -1){
			cout<<"Stack in Empty"<<endl;
			return -1;
		}
		T val = arr[last--];
		return val;
	}
	
	//top element 
	T top(){
		return arr[last];
	}
	
	//size of stack
	T size(){
		return last+1;
	}
	
	//Postfix calcultor
	T postfixCalculator(string& str){
		if(str.empty()) return 0;
		 stringstream check1(str);
    		string intermediate;
    		while(getline(check1, intermediate, ' ')){
	    		if(intermediate == "+" || intermediate == "*" || intermediate == "/"){
	    			T val1 = pop();
				T val2 = pop();
				if(intermediate == "+") push(val1+val2);
				else if(intermediate == "*") push(val1*val2);
				else if(intermediate == "/") push(val1/val2);
			}
			else{
				push(stod(intermediate));
			
			}
		}
		return top();
		
	}
};

int main(){
	Stack<double>s(20);
	string str = "1.5 2.5 2 * *";
	cout<<"res: "<<s.postfixCalculator(str)<<endl;
	
}

//santing yard algo
