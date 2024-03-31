#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> countingSort(vector<int>&A, int digit, int range){
    vector<int>dupA;
    for(int i = 0; i < A.size(); i++){
        int num = A[i] / pow(range, digit);
        num = num % range;
        dupA.push_back(num);
    }
    vector<int>C(range, 0);
    vector<int>B(A.size());
    for(int i = 0; i < A.size(); i++){
        C[dupA[i]] ++;
    }
    for(int i = 1; i < range; i ++){
        C[i] = C[i-1] + C[i];
    }
    for(int i = A.size() - 1; i >= 0; i--){
        B[C[dupA[i]] - 1] = A[i];
        C[dupA[i]]--;
    }
    return B;
}
vector<int> redixSort(vector<int>A, int d, int range){
    int n = A.size();
    for(int digit = 1; digit <= d; digit++){
        A = countingSort(A, digit, range);
    }
    return A;
}
int main()
{
    vector<int>A = {329, 22, 427, 617, 9999, 839, 436, 720, 365, 332};
    vector<int>res = redixSort(A, 4, 10);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return(0);
}
