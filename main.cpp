#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include "myHeader.h"
using namespace std;
void readFile(ifstream& fin, vector<int>&arr){
        int n = 0;
		cout<<"n: ";
        cin >> n;
        int data;
		for(int i = 0; i < n; i++){
            if(fin>>data)
                arr.push_back(data);
            else{
                cout<<"Failed to read element"<<endl;
                exit(1) ;
            }
		}
	}
int main(int argc, char * argv[]){
	vector<int>arr;
	double time = 0;

    //input size
    int alpha = 0;
    cout<<"alpha: ";
    cin>>alpha;
	Solution obj;
	for(int i = 1; i < argc; i++){
		ifstream fin(argv[i]);
		if(!fin.is_open()){
			cout<<"Error opening file"<<endl;
			return 0;	
		}
		readFile(fin, arr);
		clock_t t = clock();
		obj.insertionSort(arr, 0, arr.size());
		t=clock()-t;
		time += (double)t/CLOCKS_PER_SEC;
		cout<<"t"<<i<<": "<<(double)t/CLOCKS_PER_SEC<<endl;
	}
	cout<<"Average time: "<<time/(argc-1)<<endl;
}
