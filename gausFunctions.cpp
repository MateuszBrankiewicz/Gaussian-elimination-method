#include "gausFunctions.h"
#include "sideFunctions.h"
#include <iostream>
using namespace std;
double* solveEquation(double** matrix, int n, double* values,int* indexes){
    double* solution = new double[n];
    solution[n - 1] = values[n - 1]/matrix[n - 1][n - 1];
    for(int i = n - 2; i >= 0; i--){
        solution[i] = values[i];
        for(int j = i + 1; j < n; j++){
            solution[i] = solution[i] - matrix[i][j]*solution[j];
    }
    solution[i] = solution[i]/matrix[i][i];
    
}
for(int i = 0; i < n; i++){
        cout<<"x"<<indexes[i]<<" = "<<solution[i]<<endl;
    }
    return solution;
}
bool normalGaussMethod(double** matrix, int n,double* values){
    
    for(int i = 0; i < n; i++){
        if(check(i,matrix)){
            fundamentalGaus(matrix,i,values,n);
        }  
        else{
            return false;
        }    
}
    return true;
}
bool gausMethodWithMaxColumn(double** matrix, int n,double* values,int* indexes){
    cout<<"Wybierz kolumne z najwieksza wartoscia w kolumnie"<<endl;
    for(int i = 0; i < n; i++){
        findMaxColumn(matrix,n,values,i);
        fundamentalGaus(matrix,i,values,n);
        printData(n,matrix,values);
    }
    return true;
}
bool gausWithMax(double** matrix, int n,double* values,int* indexes){
    for(int i = 0; i < n; i++){
        findMaxInAllMatrix(matrix,n,values,i,indexes);
        cout<<"Po zamianie\n";
        printData(n,matrix,values);
        fundamentalGaus(matrix,i,values,n);
        printData(n,matrix,values);
    }
    return true;
}
void fundamentalGaus(double** matrix, int i,double* values, int n){
    for(int j = i + 1; j < n; j++){
            double ratio = matrix[j][i]/matrix[i][i]; //wyznaczanie p w kroku k 
            for(int k = 0; k < n; k++){
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k]; //zerowanie trojkata
                if(k == n - 1){
                values[j] = values[j] - ratio * values[i];
                }
            }
            }
}