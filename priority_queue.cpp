#include<iostream>
#include<vector>
using namespace std;

// template <class X, class Y>
class priority_queue{
    vector<int>pq;
public:
    priority_queue(){
        //constructor
    }
    void Heapify(int ind){
        int left = ind*2 + 1;
        int right = ind*2 + 2;
        int largest = ind;
        if(left < pq.size() && pq[largest] < pq[left])                  
            largest = left;
        if(right < pq.size() && pq[largest] < pq[right])
            largest = right;
        if(largest != ind){
            swap(pq[largest], pq[ind]);   
            Heapify(largest);
        }
    }
    void increaseKey(int ind, int data){
        pq[ind] = data;
        int parent = (ind-1)/2;
        while(ind > 0 && pq[parent] < pq[ind]){
            swap(pq[parent], pq[ind]);
            ind = parent;
            parent = (ind-1)/2;
        }
    }
    void push(int data){
        pq.push_back(0);
        increaseKey(pq.size() - 1, data);
    }
    int pop(){
        if(pq.empty()){
            cout<<"Priority_queue is empty";
            return -1;
        }
        int data = pq[0];
        pq[0] = pq[pq.size() -1];
        pq.pop_back();
        Heapify(0);
        return data;
    }
    int print(){
        for(int i = 0; i < pq.size(); i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
    int top(){
        if(pq.empty()){
            cout<<"Priority_queue is empty"<<endl;
            return -1;
        }
        return pq[0];
    }
};
int main(){
    priority_queue pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(10);
    pq.push(9);
    pq.push(5);
    pq.print();
    cout<<"pop: "<<pq.pop()<<endl;
    pq.print();
}
