#include<iostream>
#include<vector>
using namespace std;

int inversionCount(vector<int>arr){
    int sum = 0;
    for(int i = 1; i < arr.size(); i++){
        int ind = i, j;
        for(j = i-1; j >= 0 && arr[j] > arr[ind]; j--){
            sum++;
            swap(arr[j], arr[ind]);
            ind = j;
        }
    }
    return sum;
}
int main()
{
    vector<int>arr = {5,6,2,3,1,4};
    cout<<"count: "<<inversionCount(arr)<<endl;
    return(0);
}
