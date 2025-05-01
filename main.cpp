#include "sparseMatrix.h"
int main()
{
    SparseMatrixADT<int> matrix1(4, 4);
    matrix1.SetValue(0, 0, 5);
    matrix1.SetValue(1, 1, 10);
    matrix1.SetValue(2, 2, 15);
    matrix1.SetValue(3, 3, 20);
    matrix1.SetValue(1, 3, 30);
    int diagonalSum = matrix1.RecursiveDiagonalSum(0);
    cout << "Sum of diagonal elements: " << diagonalSum << endl;
    SparseMatrixADT<int> transposedMatrix = matrix1.Transpose();
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << transposedMatrix.GetValue(i, j) << " ";
        }
        cout << endl;
    }

    SparseMatrixADT<int> matrix2(2, 2);
    SparseMatrixADT<int> matrix3(2, 2);
    matrix2.SetValue(0, 0, 1);
    matrix2.SetValue(0, 1, 2);
    matrix3.SetValue(0, 0, 3);
    matrix3.SetValue(1, 0, 4);
    SparseMatrixADT<int> resultMatrix = matrix2.Multiply(matrix3);
    cout << "Resulting Matrix after Multiplication:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << resultMatrix.GetValue(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
