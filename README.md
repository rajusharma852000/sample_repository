#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
class Sort{
	void swap(int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	}
	
public:
	void insertionSort(vector<int>& arr){
		int n = arr.size();
		for(int i = 1; i < n; i++){
			for(int j = i; j >= 1 && arr[j-1] > arr[j]; j--){
				swap(arr[j-1], arr[j]);
			}
		}
	}
	void readFile(ifstream& fin, vector<int>&arr){
		string txt;
		getline(fin, txt);
		int n = stoi(txt);
		while(n--){
			string text;
			getline(fin, text);
			if(!text.empty()){
				int data = stoi(text);
				arr.push_back(data);
			}
		}
	}
};
int main(int argc, char * argv[]){
	Sort obj;
	vector<int>arr;
	double time = 0;
	for(int i = 1; i < argc; i++){
		ifstream fin(argv[i]);
		if(!fin.is_open()){
			cout<<"can't open"<<endl;
			return 0;	
		}
		obj.readFile(fin, arr);
		clock_t t = clock();
		obj.insertionSort(arr);
		//time = (clock() - t)/CLOCKS_PER_SEC;
		t=clock()-t;
		time += (double)t/CLOCKS_PER_SEC;
		cout<<"t: "<<(double)t/CLOCKS_PER_SEC<<endl;
	}
	cout<<"time-taken: "<<time/argc<<endl;
}
