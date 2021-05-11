#ifndef LAB2_MATRIX_H
#define LAB2_MATRIX_H
#include <iomanip>
#include <iostream>
#include <complex>
#endif //LAB2_MATRIX_H
#pragma once
#include "ArraySequence.h"


template <typename T> class DiagonalMatrix{
private:
    ArraySequence<T>* matrix;
public:

    //Constructor
    DiagonalMatrix(){
        matrix = new ArraySequence<T>;
    };
    DiagonalMatrix(T* items, int count){
        matrix = new ArraySequence<T>(items, count);
    }
    DiagonalMatrix(ArraySequence<T>* new_matrix){
        matrix = new_matrix;
    }
    DiagonalMatrix(DiagonalMatrix<T>* new_matrix){
        matrix = new_matrix->matrix;
    }

    //Destructor
    ~DiagonalMatrix(){
        matrix->Delete_ArraySequence();
    };
    void Delete_DynamicMatrix(){
        matrix->Delete_ArraySequence();
    };
    //Decomposition
    T GetElement(int row, int col){
        if (row < 0 || col < 0 || col >= this->GetDim() || row >= this->GetDim())
            throw out_of_range(INDEX_OUT_OF_RANGE1);
        if (row == col)
            return matrix->Get(row);
        else
            return (T)0;
    }
    int GetDim(){
        return matrix->GetLength();
    }
    //Operations
    void Append(T item){
        return matrix->Append(item);
    };
    void Set(T item, int index){
        return matrix->Set(item, index);
    };

    template<typename U>
    U MatrixNorm(){
        U sum = this->GetElement(0,0) * this->GetElement(0,0);
        for(int i = 1; i < this->GetDim(); i++)
            sum += this->GetElement(i, i) * this->GetElement(i, i);
        return sqrt(sum);
    }

    DiagonalMatrix<T>* MultOnScalar(T scalar){
        T item;
        DiagonalMatrix<T>* new_Matrix = new DiagonalMatrix<T>(matrix);
        for(int i = 0; i < this->GetDim(); i++){
            item = this->GetElement(i,i) * scalar;
            new_Matrix->matrix->Set(item, i);
        }
        return new_Matrix;
    };
    DiagonalMatrix<T>* SumOfMatrix(DiagonalMatrix<T>* matrix1){
        if(this->GetDim() != matrix1->GetDim())
            throw length_error("Dimension are not equal");
        DiagonalMatrix<T>* new_Matrix = new DiagonalMatrix<T>();
        T item;
        for(int i = 0; i < this->GetDim(); i++) {
            item = this->GetElement(i, i) + matrix1->GetElement(i, i);
            new_Matrix->Append(item);
        }
        return new_Matrix;
    }
    T Determinant(){
        T det = (T)1;
        for(int i = 0; i < this->GetDim(); i++)
            det *= this->GetElement(i, i);
        return det;
    }

    T operator[](int index){
        return this->GetElement(index, index);
    }
    static int number_of_digits(double n) {
        int m;
        ostringstream strs;
        strs << n;
        string str = strs.str();
        m = str.size();
        return m;
    }
    void ComplexMatrixPrint(){
        int max_len = 0;
        double re, im;
        int re_size, im_size;
        for(int i = 0; i < this->GetDim(); i++){
            re = this->GetElement(i, i).real();
            im = this->GetElement(i, i).imag();
            int num = number_of_digits(re) + number_of_digits(im);
            num += 3;
            if(num > max_len)
                max_len = num;
        }
        for (int i = 0; i < this->GetDim(); i++){
            cout << '|';
            for(int j = 0; j < this->GetDim(); j++){
                cout << setw(max_len) << this->GetElement(i, j);
                if(j != this->GetDim()-1)
                    cout << ' ';
            }
            cout << '|';
            cout << endl;
        }
    }
    friend ostream &operator << (ostream &cout, DiagonalMatrix<T>* matrix){
        int max_len = 0;
        for(int i = 0; i < matrix->GetDim(); i++){
            int num = number_of_digits(matrix->GetElement(i, i));
            if(num > max_len)
                max_len = num;
        }
        for (int i = 0; i < matrix->GetDim(); i++){
            cout << '|';
            for(int j = 0; j < matrix->GetDim(); j++){
                cout << setw(max_len) << matrix->GetElement(i, j);
                if(j != matrix->GetDim()-1)
                    cout << ' ';
            }
            cout << '|';
            cout << endl;
        }
        return cout;
    };

};