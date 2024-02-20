#include<iostream>
using namespace std;
template<class T>
class vector {
private:
    //private variablles
    T *arr;
    int _size;
    int _cap;
public:

    //constructor
    vector() {
        arr = new T[1];
        _size = 0;
        _cap = 1;
    }

    //desturctor
    ~vector() {
        delete[] arr;
    }

    //push function
    void push_back(T data) {
        
        //if capacity is full, create a new array of size capacity*2
        if (_size == _cap) {
            T *temp = new T[_cap * 2];
            for (int i = 0; i < _cap; i++) {
                temp[i] = arr[i];
            }

            //release the memory: old array
            delete[] arr;
            arr = temp;
            _cap *= 2; 
        }

        //push the data
        arr[_size] = data;
        _size++;
    }

    //remove element :pop function
    T pop_back() {

        //if vector in empty
        if (_size == 0) {
            cout << "vector is empty" << endl;
            return -1;
        }

        //store the data to be returned in a variable (say "data")
        T data = arr[_size - 1];
        _size--;

        //if size is 1/4 of the capacity, reduce the capacity by half
        if (_size == _cap / 4) {
            T *temp = new T[_cap / 2];
            for (int i = 0; i < _size; i++) {
                temp[i] = arr[i];
            }

            //release the memory (old array)
            delete[] arr;
            arr = temp;
            _cap /= 2;  //half the capacity
        }

        //return the data
        return data;
    }

    //size function
    int size(){
        return _size;
    }

    //loadFactor function: (size / cap)
    double loadFactor(){
        return (double) _size/_cap;
    }

    //overloading subscript operator
    T operator[](const int& ind){
        return arr[ind];
    }
};

//main function
int main() {
    vector<float> v;
    v.push_back(1);
    cout<<"laodFactor: "<<v.loadFactor()<<endl;
    v.push_back(2);
    cout<<"laodFactor: "<<v.loadFactor()<<endl;
    v.push_back(3);
    cout<<"laodFactor: "<<v.loadFactor()<<endl;
    v.push_back(4);
 
}
