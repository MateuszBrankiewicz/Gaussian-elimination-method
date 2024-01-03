bool check(int n, double** matrix);
int setData(double**& matrix, double*& values, int*& indexes);
void printData(int n, double** matrix, double* values);
void findMaxColumn(double** matrix, int i, double* values,int n);
void findMaxInAllMatrix(double** matrix, int n,double* values, int i,int* indexes);
int exampleEquations(double**& matrix, double*& values, int*& indexes);
int copyData(double**& matrix, double*& values,double** matrixToCopy, double* valuesToCopy, int n, int*& indexes);
void bubbleSort(double* solution, int* indexes, int n);
double checkEpsilon(double* solution, int i);