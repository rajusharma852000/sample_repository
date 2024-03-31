#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

template <class T>
T postFixCalculator(string& str){
    if(str.empty()) return 0;
    stringstream check1(str);
    string intermediate;
    stack<T> stack;
    while(getline(check1, intermediate, ' ')){
        if(intermediate == "+" || intermediate == "*" || intermediate == "/"){
            T val2 = stack.top();
            stack.pop();
            T val1 = stack.top();
            stack.pop();
            if(intermediate == "+") stack.push(val1 + val2);
            else if(intermediate == "*") stack.push(val1 * val2);
            else if(intermediate == "/") stack.push(val1 / val2);
        }
        else{
            stack.push(stod(intermediate));
        }
    }
    return stack.top();
}

int main(){
    string str = "4 2 * 3 5 * +";
    cout << postFixCalculator<double>(str) << endl;
    return 0;
}
