#include<iostream>
#include<vector>
#include<algorithm>
#include "myHeader.h"
using namespace std;


bool Solution::isSorted(vector<int>&arr){
    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}
void Solution::nextPermutation(vector<int>&arr){
    int ind = -1;
    for(int i = arr.size() -1; i > 0; i--){
        if(arr[i-1] < arr[i]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        int start = 0, end = arr.size() - 1;
        while(start < end){
            swap(arr[start++], arr[end--]);
        }
    }
    else{
        int i = arr.size() - 1;
        while(arr[i] < arr[ind-1]) i--;
        swap(arr[ind-1], arr[i]);
        sort(arr.begin() + ind, arr.end());
    }
}
void Solution::slowSort(vector<int>&arr){
    while(!isSorted(arr)){
        nextPermutation(arr);
    }
}
void Solution::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void Solution::insertionSort(vector<int>& arr, int start, int n){
    for(int i = start + 1; i < n; i++){
        for(int j = i; j >= start + 1 && arr[j-1] > arr[j]; j--){
            swap(arr[j-1], arr[j]);
        }
    }
}
void Solution::merge(vector<int>&arr, int low, int mid, int high){
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
void Solution::mergeSort(vector<int>&arr, int low, int high, int alpha){
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
void Solution::voidSort(){
    cout<<"Hello world"<<endl;
}
