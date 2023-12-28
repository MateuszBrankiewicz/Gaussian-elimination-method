#include <iostream>
#include "sideFunctions.h"
#include "gausFunctions.h"
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the matrix"<<endl;
    cin>>n;
    // double** matrix = setData(n);
  double** matrix = new double*[4];

for(int i=0; i<4; i++) {
    matrix[i] = new double[4]; 
}
  matrix[0][0] = 1;
  matrix[0][1] = 1;
  matrix[0][2] = 0;
  matrix[0][3] = -3;
  matrix[1][0] = 1;
  matrix[1][1] = 4;
  matrix[1][2] = -1;
  matrix[1][3] = -4;
  matrix[2][0] = 0.5;
  matrix[2][1] = 0.5;
  matrix[2][2] = -3;
  matrix[2][3] = -5.5;
  matrix[3][0] = 1.5;
  matrix[3][1] = 3;
  matrix[3][2] = -5;
  matrix[3][3] = -9;  

  double* values = new double[4];
  values[0] = 1;
  values[1] = -2;
  values[2] = 1.5;
  values[3] = -0.5;  
    int* indexes = new int[4];
    indexes[0] = 1;
    indexes[1] = 2;
    indexes[2] = 3;
    indexes[3] = 4;
    printData(n, matrix,values);
    if(gausMethodWithMaxRow(matrix, n,values,indexes)){
        printData(n, matrix,values);
        double* equation = solveEquation(matrix, n,values,indexes);
    }
    else{
        cout<<"You have a zero in a main cross\n";
    }
    delete[] matrix;
    delete[] values;
    delete[] indexes;
    return 0;
}