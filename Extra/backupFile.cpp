#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<myHeader.h>
using namespace std;
class Sort{

public:
	void swap(int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	}
	void insertionSort(vector<int>& arr, int start, int n){
		for(int i = start + 1; i < n; i++){
			for(int j = i; j >= start + 1 && arr[j-1] > arr[j]; j--){
				swap(arr[j-1], arr[j]);
			}
		}
	}
	void merge(vector<int>&arr, int low, int mid, int high){
		int l = low, r = mid;
		int temp[high - low + 1];
		int i = 0;
		while(l < mid && r <= high)
		{
			if(arr[l]<=arr[r])
			{
				temp[i]=arr[l];
				i++; l++;
			}
			else
			{
				temp[i]=arr[r];
				i++; r++;
			}
		}
		while(l<=mid)
		{
			temp[i]=arr[l];
			i++; l++;
		}
		while(r<=high)
		{
			temp[i]=arr[r];
			i++; r++;
		}

		for(i = low; i <= high; i++)
		{
			arr[i]=temp[i-low];
		}
	}
	void mergeSort(vector<int>&arr, int low, int high, int alpha){
		int mid= low+ (high-low)/2;  
		if(low >= high)
			return;
		if(high - low + 1 < alpha)
			insertionSort(arr, low, high);
		else{
			mergeSort(arr, low, mid, alpha);
			mergeSort(arr, mid+1, high, alpha);
			merge(arr, low, mid+1, high);
		}
	}
	void readFile(ifstream& fin, vector<int>&arr){
        int n = 0;
		cout<<"n: ";
        cin >> n;
        int data;
		for(int i = 0; i < n; i++){
            if(fin>>data)
                arr.push_back(data);
            else{
                cout<<"Failed to read element";
                return ;
            }
		}
	}
};
int main(int argc, char * argv[]){
	Sort obj;
	vector<int>arr;
	double time = 0;

    //input size
    int alpha = 0;
    cout<<"alpha: ";
    cin>>alpha;

	for(int i = 1; i < argc; i++){
		ifstream fin(argv[i]);
		if(!fin.is_open()){
			cout<<"Error opening file"<<endl;
			return 0;	
		}
		obj.readFile(fin, arr);
		clock_t t = clock();
		obj.mergeSort(arr, 0, arr.size()-1, alpha);
		t=clock()-t;
		time += (double)t/CLOCKS_PER_SEC;
		cout<<"t"<<i<<": "<<(double)t/CLOCKS_PER_SEC<<endl;
	}
	cout<<"Average time: "<<time/(argc-1)<<endl;
}
