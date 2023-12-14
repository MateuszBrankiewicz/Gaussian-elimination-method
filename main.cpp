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
void printData(int n, double** matrix){
    double epsilon = 1e-7;
    cout<<"The matrix is"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(matrix[i][j]) < epsilon){
                cout<<"0 ";
            }
            else cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void normalGaussMethod(double** matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double ratio = matrix[j][i]/matrix[i][i];
            for(int k = 0; k < n; k++){
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }}}
}
int main(){
    int n;
    cout<<"Enter the size of the matrix"<<endl;
    cin>>n;
    double** matrix = setData(n);
    printData(n, matrix);
    normalGaussMethod(matrix, n);
    printData(n, matrix);
}