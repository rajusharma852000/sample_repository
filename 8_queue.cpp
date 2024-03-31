#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int key){
        val = key;
        next = NULL;
    }
};
class queue{
    Node *_front, *_rear;
    int _size;
public: 
    queue(){
        _front = NULL;
        _rear = NULL;
        _size = 0;
    }
    void enQueue(int key){
        _size++;
        if(_front == NULL){
            _front = new Node(key);
            _rear = _front;
        }
        else{
            _rear->next = new Node(key);
            _rear = _rear->next;
        }
    }
    int dequeue(){
        if(_front == NULL){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        _size --;
        int data = _front->val;
        if(_front == _rear){
            delete _front;
            _front = _rear = NULL;
        }
        else{
            Node* temp = _front;
            _front = _front->next;
            delete temp;
        }
        return data;
    }
    int size(){
        return _size;
    }
    bool isEmpty(){
        if(_front == NULL) return true;
        else return false;
    }
    int front(){
        if(_front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else return _front->val;
    }
};
int main(){
    queue q;
   
}
