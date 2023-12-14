#include <iostream>
#include <cmath>
using namespace std;
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
void normalGaussMethod(double** matrix, int n,double* values){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double ratio = matrix[j][i]/matrix[i][i];
            for(int k = 0; k < n; k++){
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                if(k == n - 1){
                values[j] = values[j] - ratio * values[i];
                }
            }}}
}
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
    printData(n, matrix,values);
    normalGaussMethod(matrix, n,values);
    printData(n, matrix,values);
}