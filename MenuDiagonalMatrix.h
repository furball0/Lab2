#ifndef LAB2_MENUDIAGONALMATRIX_H
#define LAB2_MENUDIAGONALMATRIX_H
#include "DiagonalMatrix.h"
#pragma once
#endif //LAB2_MENUDIAGONALMATRIX_H

const string sep = "-----------------------------------------";
int chooseTypeMatrix(){
    int type;
    cout << "Select type of numbers: \n"
         << "\t1: int\n"
         << "\t2: double\n"
         << "\t3: complex\n\n"
         << "\t0: Return to select class\n"
         << "Enter a number: ";
    cin >> type;
    cout << sep << endl;
    return type;
}
int chooseFunctionMatrix(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Sum of Matrixes\n"
         << "\t2: Multiplication of scalar and matrix\n"
         << "\t3: Matrix Norm\n"
         << "\t0: Return to select type\n"
         << "Enter a number: ";
    cin >> func;
    cout << sep << endl;
    return func;
}


template <typename T>
DiagonalMatrix<T>* inputMatrix(){
    int dim;
    cout << "Enter a dimension of matrix:";
    cin >> dim; cout << endl;
    DiagonalMatrix<T>* matrix = new DiagonalMatrix<T>();
    cout << "Enter Main Diagonal Coordinates (one by one):" << endl;
    T coord;
    for(int i = 0; i < dim; i++){
        cin >> coord;
        matrix->Append(coord);
    }
    return matrix;
}
DiagonalMatrix<complex<double>>* inputComplexMatrix() {
    int dim;
    cout << "Enter a dimension of Matrix:";
    cin >> dim; cout << endl;
    auto* matrix = new DiagonalMatrix<complex<double>>();
    cout << "Enter Main Diagonal Coordinates (one by one):" << endl;
    complex<double> coord;
    double real, im;
    for(int i = 0; i < dim; i++){
        cout << "Enter Real and Imaginary number (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex<double>(real, im);
        matrix->Append(coord);
    }
    return matrix;
}

void MenuMatrix(){
    while(true){
        int type = chooseTypeMatrix(); // 1 - int ; 2 - double ; 3 - complex ; 0 - return to select class
        if(type == 0){
            break;
        }
        else if (type == 1){
            while (true){
                int function = chooseFunctionMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter 1 matrix:" << endl;
                    auto* matrix1 = inputMatrix<int>();
                    cout << "Enter 2 matrix:" << endl;
                    auto* matrix2 = inputMatrix<int>();
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix 1 = " << endl << matrix1 << endl;
                        cout << "Matrix 2 = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of Matrix 1 and Matrix 2 = " << endl << sum << endl << sep << endl;
                    //sum of matrixes
                }
                else if (function == 2){
                    cout << "Enter Matrix:" << endl;
                    auto* matrix = inputMatrix<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl << sep << endl;
                    //mult scalar on matrix
                    //Matrix and scalar
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputMatrix<int>();
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<double>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                    //Matrix Norm
                }
                else if (function == 0) break;
                else
                    cout << "Enter the correct number!" << endl;
            }
        }
        else if (type == 2){
            while (true){
                int function = chooseFunctionMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter 1 matrix:" << endl;
                    auto* matrix1 = inputMatrix<double>();
                    cout << "Enter 2 matrix:" << endl;
                    auto* matrix2 = inputMatrix<double>();
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix 1 = " << endl << matrix1 << endl;
                        cout << "Matrix 2 = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of Matrix 1 and Matrix 2 = " << endl << sum << endl << sep << endl;
                    //sum of matrixes
                }
                else if (function == 2){
                    cout << "Enter Matrix:" << endl;
                    auto* matrix = inputMatrix<double>();
                    cout << "Enter scalar: " << endl;
                    double scalar;
                    cin >> scalar;
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl << sep << endl;
                    //mult scalar on matrix
                    //Matrix and scalar
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputMatrix<double>();
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<double>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                    //Matrix Norm
                }
                else if (function == 0) break;
                else
                    cout << "Enter the correct number!" << endl;
            }
        }
        else if (type == 3){
            while (true){
                int function = chooseFunctionMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter 1 matrix:" << endl;
                    auto* matrix1 = inputComplexMatrix();
                    cout << "Enter 2 matrix:" << endl;
                    auto* matrix2 = inputComplexMatrix();
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix 1 = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Matrix 2 = " << endl;
                        matrix2->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of Matrix 1 and Matrix 2 = " << endl;
                    sum->ComplexMatrixPrint();
                    cout << endl << sep << endl;
                    //sum of matrixes
                }
                else if (function == 2){
                    cout << "Enter Matrix:" << endl;
                    auto* matrix = inputComplexMatrix();
                    cout << "Enter scalar: " << endl;
                    complex<double> scalar;
                    double real, im;
                    cout << "Enter Real and Imaginary number (separated by a space): " << endl;
                    cin >> real >> im;
                    scalar = complex<double>(real, im);
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    MatrixMult->ComplexMatrixPrint();
                    cout << endl << sep << endl;
                    //mult scalar on matrix
                    //Matrix and scalar
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputComplexMatrix();
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<complex<double>>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                    //Matrix Norm
                }
                else if (function == 0) break;
                else
                    cout << "Enter the correct number!" << endl;
            }
        }
    }
}