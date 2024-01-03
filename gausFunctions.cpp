#include "gausFunctions.h"
#include "sideFunctions.h"
#include <iostream>
using namespace std;
double* solveEquation(double** matrix, int n, double* values,int* indexes){
    double* solution = new double[n];
    cout<<"Matrix after n-1 steps: "<<endl;
    printData(n,matrix,values);
    if(!check(n-1,matrix)){
        if(values[n - 1] == 0){
            cout<<"Uklad tozsamosciowy"<<endl;
        }
        else{
        cout<<"Brak rozwiazania"<<endl;
        return 0;
        }
        
    }
    solution[n - 1] = values[n - 1]/matrix[n - 1][n - 1];
    for(int i = n - 2; i >= 0; i--){
        solution[i] = values[i];
        for(int j = i + 1; j < n; j++){
            solution[i] = solution[i] - matrix[i][j]*solution[j];
    }
    solution[i] = solution[i]/matrix[i][i];
    
}
    bubbleSort(solution,indexes,n);
    cout<<"x =[";
    for(int i = 0; i < n; i++){

        cout<<checkEpsilon(solution,i)<<" ";
    }
    cout<<"]^T"<<endl;
    for(int i = 0; i < n; i++){
            cout<<"x"<<indexes[i]<<" = "<<checkEpsilon(solution,i)<<endl;
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
        
    }
    return true;
}
bool gausWithMax(double** matrix, int n,double* values,int* indexes){
    for(int i = 0; i < n; i++){
        findMaxInAllMatrix(matrix,n,values,i,indexes);
        fundamentalGaus(matrix,i,values,n);
       
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