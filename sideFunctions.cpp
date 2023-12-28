#include "sideFunctions.h"
#include <iostream>
#include <cmath>
using namespace std;
bool check(int n, double** matrix){
    cout<<n;
    if(matrix[n][n]==0){
        return false;
    }
    else{
        return true;
    }
}
double** setData(int n){
  
    double** matrix = new double*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new double[n];
}
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"Enter the element of the matrix"<<endl;
            cin>>matrix[i][j];
    }
    }
    return matrix;
}
void printData(int n, double** matrix, double* values){
    double epsilon = 1e-7;
    cout<<"The matrix is"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(matrix[i][j]) < epsilon){
                cout<<"0 ";
            }
            else cout<<matrix[i][j]<<" ";
            if(j == n - 1){
                cout<<" | "<<values[i];
            }
        }
        cout<<endl;
    }
}

void bubblesort(double** matrix, int n, int row,int* indexes){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(matrix[row][j] > matrix[row][j + 1]){
                swap(matrix[row][j], matrix[row][j + 1]);
                swap(indexes[j], indexes[j + 1]);
            }
        }
    }
}