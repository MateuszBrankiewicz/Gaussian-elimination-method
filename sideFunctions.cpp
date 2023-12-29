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

void findMaxColumn(double** matrix,int n,double* values,int i){
    cout<<"The max element in the column is "<<abs(matrix[i][i])<<endl;
    double max = abs(matrix[i][i]);
     int index = i;
     for(int j = i; j < n; j++){
         if(abs(matrix[j][i]) > max){
             max = matrix[j][i];
             index = j;
         }
     } 
     if(index != i){
     for(int j = i;j<n;j++){
        swap(matrix[i][j],matrix[index][j]);
        swap(values[i],values[index]);
     }}
}
void findMaxInAllMatrix(double** matrix, int n, double* values, int i, int* indexes) {
    double max = abs(matrix[i][i]);
    int row = i;
    int column = i;

 
    for (int j = i; j < n; j++) {
        for (int k = i; k < n; k++) {
            if (abs(matrix[j][k]) > max) {
                max = matrix[j][k]; 
                row = j;
                column = k;
            }
        }
    }

   
    cout << "Max Element Index: (" << row << ", " << column << ")" << endl;


    if (row != i) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[row][j]);
        }
        swap(values[i], values[row]);
    }
   if (column != i) {
        for (int j = 0; j < n; j++) {
            swap(matrix[j][i], matrix[j][column]);
        }
        swap(indexes[i], indexes[column]);
    }
}