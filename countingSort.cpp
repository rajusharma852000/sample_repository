#include<iostream>
#include<vector>
using namespace std;

vector<int> countingSort(vector<int>&A, int k){
    vector<int>C(k+1, 0);
    vector<int>B(A.size());
    for(int i = 0; i < A.size(); i++){
        C[A[i]]++;
    }
    for(int i =  1; i < k + 1; i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j = A.size() -1; j >= 0; j--){
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    return B;
}
int main(){
    vector<int>A = {2,2,0,0,3,1,2,3,4,1,4};
    vector<int>temp = countingSort(A, 4);
    for(int i = 0; i < temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
