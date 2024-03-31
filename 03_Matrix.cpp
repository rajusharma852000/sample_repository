#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Matrix{
	vector<int>mat;
	int _size;
public:
	//constructor
	Matrix(vector<int>M, int n){
		mat = M;
		_size = n;
	}
	Matrix(int n){
		mat.resize(n*n);
		_size = n;
	}
	
	//adding matrices
	Matrix operator+(Matrix M){
		for(int i = 0; i < mat.size(); i++){
			M.mat[i] += mat[i];
		}
		return M;
	}
	
	//subtracting matrices
	Matrix operator-(Matrix M){
		for(int i = 0; i < mat.size(); i++){
			M.mat[i] -= mat[i];
		}
		return M;
	}
	
	//product of the matrix
	Matrix operator*(Matrix M){
		int n = _size;
		Matrix temp(n);
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					temp.mat[k*n +i] += mat[k*n+j]*M.mat[j*n+i];
				}
			}
		}
		return temp;
	}
	
	//determinant of the matrix
	int det(){
		//base case
		int n = _size;
		if(n == 2){
			return mat[0]*mat[3] - mat[1]*mat[2];
		}
		
		//else
		int res = 0;
		for(int k = 0; k < n; k++){
			Matrix temp(n-1);
			int ind = 0;
			for(int i = 1; i < n; i++){
				for(int j = 0; j < n; j++){
					if(j != k){
						temp.mat[ind++] = mat[i*n+j];
					}
				}
			}
			int sign = 1 - 2*(k & 1);
			res += mat[k]*sign*temp.det();
		}
		return res;
	}
	
	//print the matrix
	void print(int n){
		cout<<"The matrix is: "<<endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<mat[i*n + j]<<"    ";
			cout<<endl;
		}
	}
	
	//size of the matrix
	int size(){
		return _size;
	}
};

int main(){
	vector<int>mat = {1,0,5,2,0,1,0,1,2,1,2,4,4,3,2,6};
	int n = sqrt(mat.size());
	Matrix M(mat, n);
	//M = M + M;
	//M.print(M.size());
	//M = M - M;
	//M.print(M.size());
	//M = M * M;
	M.print(M.size());
	cout<<"det: "<<M.det()<<endl;
	
}
