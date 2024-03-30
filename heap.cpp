#include<iostream>
#include<vector>
#include<climits>
using  namespace std;

class Heap{
	vector<int>arr;
	void Heapify(int i){
		int l = 2*i+1;
		int r = 2*i+2;	
		int largest = i;	
		if(l < arr.size() && arr[l] > arr[largest]) largest = l;
		if(r < arr.size() && arr[r] > arr[largest]) largest = r;
		if(largest != i){
			swap(arr[largest], arr[i]);
			Heapify(largest);
		}
	}
	void BuildHeap(){
		for(int i = arr.size()/2; i >= 0; i--){
			Heapify(i);
		}
	}
public:
	Heap(vector<int>v){
		arr = v;
		BuildHeap();
	}
	void increaseKey(int pos, int newVal){
		if(pos >= arr.size()){
			perror("Invalid Key");
		}
		arr[pos] = newVal;

		//reverse heapify
        int parent = (pos-1)/2;
        while(pos > 0 && arr[parent] < arr[pos]){
            swap(arr[parent], arr[pos]);
            pos = parent;
            parent = (pos-1)/2;
        }
	}
	void insert(int data){
	
		arr.push_back(INT_MIN);
		increaseKey(arr.size() - 1, data);
	}
			
	int remove(){
		if(arr.size() == 0){
			perror("heap is empty");
		}
		int data = arr[0];
		arr[0] = arr[arr.size() - 1];
		arr.pop_back();
		Heapify(0);
		return data;
	}
	int top(){
		return arr[0];
	}
	int size(){
		return arr.size();
	}
	void levelOrderTraversing(){
		cout<<"arr: ";
		for(int i = 0; i < arr.size(); i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	vector<int>arr = {1,2,3,4,5,6,7,8,9};
	Heap heap(arr);
	cout<<"heap.top: "<<heap.top()<<endl;
	heap.levelOrderTraversing();
	heap.increaseKey(4, 15);
	cout<<"heap.top: "<<heap.top()<<endl;
	heap.levelOrderTraversing();
	
}
 
