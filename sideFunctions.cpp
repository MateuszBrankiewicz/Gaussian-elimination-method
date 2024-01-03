#include "sideFunctions.h"
#include <iostream>
#include <cmath>
using namespace std;
#define EPSILON 1e-7
bool check(int n, double** matrix){
    if(matrix[n][n]==0){
        return false;
    }
    else{
        return true;
    }
}
int setData(double**& matrix, double*& values, int*& indexes){
    int n;
    cout<<"Enter the number of equations"<<endl;
    cin>>n;
    matrix = new double*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new double[n];
}
    values = new double[n];
    indexes = new int[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"Enter the element of the matrix"<<endl;
            cin>>matrix[i][j];
            if(j == n-1){
                cout<<"Enter the value of the equation"<<endl;
                cin>>values[i];
                indexes[i] = i;
            }
    }
    }
    return n;
}
void printData(int n, double** matrix, double* values){
    
    cout<<"The matrix is"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(matrix[i][j]) < EPSILON){
                cout<<"0 \t";
            }
            else cout<<matrix[i][j]<<"\t";
            if(j == n - 1){
                cout<<" | \t"<<values[i];
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
int exampleEquations(double**& matrix, double*& values, int*& indexes){
   int n = 0;
double** exEquation1 = new double*[4];
    for(int i = 0; i < 4; i++){
        exEquation1[i] = new double[4];
    }
double** exEquation2 = new double*[4];
    for(int i = 0; i < 4; i++){
        exEquation2[i] = new double[4];
    };
    double** exEquation3 = new double*[4];
    for(int i = 0; i < 4; i++){
        exEquation3[i] = new double[4];
    };
    double** exEquation4 = new double*[5];
    for(int i = 0; i < 5; i++){
        exEquation4[i] = new double[5];
    };
    double* exValues1 = new double[4];
    double* exValues2 = new double[4];
    double* exValues3 = new double[4];
    double* exValues4 = new double[5];
    exEquation1[0][0] = 1; exEquation1[0][1] = 1; exEquation1[0][2] = 0; exEquation1[0][3] = -3;
    exEquation1[1][0] = 1; exEquation1[1][1] = 4; exEquation1[1][2] = -1; exEquation1[1][3] = -4;
    exEquation1[2][0] = 0.5; exEquation1[2][1] = 0.5; exEquation1[2][2] = -3; exEquation1[2][3] = -5.5;
    exEquation1[3][0] = 1.5; exEquation1[3][1] = 3; exEquation1[3][2] = -5; exEquation1[3][3] = -9;
    exValues1[0] = 1; exValues1[1] = -2; exValues1[2] = 1.5; exValues1[3] = -0.5;
    exEquation2[0][0] = 2.25; exEquation2[0][1] = -2.5; exEquation2[0][2] = 4; exEquation2[0][3] = -5.25;
    exEquation2[1][0] = -3; exEquation2[1][1] = -7.5; exEquation2[1][2] = 6.5; exEquation2[1][3] = 0;
    exEquation2[2][0] = -6.25; exEquation2[2][1] = -12.5; exEquation2[2][2] = 0.25; exEquation2[2][3] = 5.25;
    exEquation2[3][0] = 9; exEquation2[3][1] = 10; exEquation2[3][2] = 7; exEquation2[3][3] = -21;
    exValues2[0] = -1; exValues2[1] = 17; exValues2[2] = 24.25; exValues2[3] = -33;
    exEquation3[0][0] = 1; exEquation3[0][1] = 2; exEquation3[0][2] = -1; exEquation3[0][3] = 2;
    exEquation3[1][0] = 1; exEquation3[1][1] = 0;  exEquation3[1][2] = -2; exEquation3[1][3] = 4;
    exEquation3[2][0] = 0; exEquation3[2][1] = -3; exEquation3[2][2] = 1.5;exEquation3[2][3] = 7;
    exEquation3[3][0] = 0; exEquation3[3][1] = -1; exEquation3[3][2] = 1; exEquation3[3][3] = 6;
    exValues3[0] = 0; exValues3[1] = 4; exValues3[2] = 0; exValues3[3] = -1;
    exEquation4[0][0] = 14; exEquation4[0][1] = -13; exEquation4[0][2] = 3; exEquation4[0][3] = -16; exEquation4[0][4] = -42;
    exEquation4[1][0] = 3.5; exEquation4[1][1] = -18; exEquation4[1][2] = 13; exEquation4[1][3] = -23.75; exEquation4[1][4] = -21;
    exEquation4[2][0] = 3.5; exEquation4[2][1] = 3; exEquation4[2][2] = -5.25; exEquation4[2][3] = 9.25; exEquation4[2][4] = 10.5;
    exEquation4[3][0] = 2; exEquation4[3][1] = 14.5; exEquation4[3][2] = -10.5; exEquation4[3][3] = 18.5; exEquation4[3][4] = 21;
    exEquation4[4][0] = 1.5; exEquation4[4][1] = 6.75; exEquation4[4][2] = -9.25; exEquation4[4][3] = 17; exEquation4[4][4] = -10.5;
    exValues4[0] = -37; exValues4[1] = -5.5; exValues4[2] = 12.5; exValues4[3] = 23.5; exValues4[4] = -45.25;
    
cout<< "1: "<<endl;
printData(4,exEquation1,exValues1);
cout<< "2: "<<endl;
printData(4,exEquation2,exValues2);
cout<< "3: "<<endl;
printData(4,exEquation3,exValues3);
cout<< "4: "<<endl;
printData(5,exEquation4,exValues4);
cout<< "Enter the number of the example equation"<<endl;
int choice = 0;
cin>>choice;
switch(choice){
    case 1:
    n =  copyData(matrix,values,exEquation1,exValues1,4,indexes);
    break;
    case 2:
    n = copyData(matrix,values,exEquation2,exValues2,4,indexes);
    break;
    case 3:
    n = copyData(matrix,values,exEquation3,exValues3,4,indexes);
    break;
    case 4:
    n = copyData(matrix,values,exEquation4,exValues4,5,indexes);
    break;
    default:
    cout<<"Invalid choice"<<endl;
    break;
}
    return n;
}

int copyData(double**& matrix, double*& values,double** matrixToCopy, double* valuesToCopy, int n, int*& indexes){
    matrix = new double*[n];
    for(int i=0; i<n; i++) {
    matrix[i] = new double[n]; 
}
  
    values = new double[n];
    indexes = new int[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = matrixToCopy[i][j];
           
        }
    }
    for(int i = 0; i < n; i++){
       values[i]=  valuesToCopy[i];
        indexes[i] = i+1;
    }
    return n;
}
void bubbleSort(double* solution, int* indexes, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(indexes[j] > indexes[j+1]){
                swap(solution[j],solution[j+1]);
                swap(indexes[j],indexes[j+1]);
            }
        }
    }
}
double checkEpsilon(double* solution, int i){
    if(abs(solution[i]) < EPSILON){
        return 0;
    }
    else return solution[i];
}