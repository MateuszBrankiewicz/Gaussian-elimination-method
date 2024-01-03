#include <iostream>
#include "sideFunctions.h"
#include "gausFunctions.h"
using namespace std;

int main(){
  double** matrix = nullptr;
  double* values = nullptr;
  int* indexes = nullptr;
  int n = 0;
  bool done = false;
  do{
    cout<<"Select the gaus method"<<endl;
    cout<<"1 - Standard gaus"<<endl;
    cout<<"2 - Gaus with max in row"<<endl;
    cout<<"3 - Gaus with max in matrix"<<endl;
    int method;
    cin>>method;
    cout<<"What data you want to use"<<endl;
    cout<<"1 - Example"<<endl;
    cout<<"2 - User input"<<endl;
    int data;
    cin>>data;
    switch(data){
        case 1:
            n = exampleEquations(matrix, values, indexes);
        break;
        case 2:
            n = setData(matrix, values, indexes);
        break;
        default:
            cout<<"Wrong choice"<<endl;
            return 0;   
            break;    
    }
    
   
    switch(method){
        case 1:
            if(normalGaussMethod(matrix,n,values)){
                solveEquation(matrix,n,values,indexes);
                done = true;
            }
            else{
                cout<<"You have a zero in a main cross\n";
            }
            break;
        case 2:
            if(gausMethodWithMaxColumn(matrix,n,values,indexes)){
                solveEquation(matrix,n,values,indexes);
                done = true;
            }else{
                cout<<"Something went wrong"<<endl;
            }
            break;
        case 3:
            if(gausWithMax(matrix, n,values,indexes)){
                solveEquation(matrix,n,values,indexes);
                done = true;
            }else{
                cout<<"Something went wrong"<<endl;
            }
            break;
            default:
            cout<<"Wrong choice"<<endl;
    }
  }while (done ==false);
    delete[] matrix;
    delete[] values;
    delete[] indexes;
    return 0;
}