#ifndef myHeader
#define myHeader
#endif

#include<vector>
#include<fstream>
using namespace std;
class Solution{
public:
    void nextPermutation(vector<int>&);
    bool isSorted(vector<int>&);
    void slowSort(vector<int>&);
    void mergeSort(vector<int>&, int, int, int );
    void merge(vector<int>&, int,int,int);
    void insertionSort(vector<int>&, int,int);
    void swap(int& ,int&);
    void voidSort();

};
