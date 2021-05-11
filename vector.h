#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H

#include <cmath>
#include <complex>
#include "ArraySequence.h"
#pragma once
#endif //LAB2_VECTOR_H

const string DIM_ERROR = "Dimensions are not the equal";

template <typename T> class Vector{
private:
    ArraySequence<T>* vector;
public:

    //Constructor
    Vector(){
        vector = new ArraySequence<T>;
    };
    Vector(T* coords, int count){
        vector = new ArraySequence<T>(coords, count);
    };
    Vector(ArraySequence<T>* new_vector){
        vector = new_vector;
    };
    Vector(Vector<T>* vector1){
        vector = vector1->vector;
    }

    //Destructor
    ~Vector(){
        vector->Delete_ArraySequence();
    }
    void Delete_Vector(){
        vector->Delete_ArraySequence();
    }

    //Decomposition
    T GetCoord(int index){
        return vector->Get(index);
    };
    int GetDim(){
        return vector->GetLength();
    };

    //Operations
    void Append(T item){
        return vector->Append(item);
    }
    void Set(T item, int index){
        return vector->Set(item, index);
    }
    Vector<T>* SumOfVectors(Vector<T>* v){
        if (this->GetDim() != v->GetDim())
            throw length_error(DIM_ERROR);
        auto* new_vector = new Vector<T>;
        T item;
        for(int i = 0; i < this->GetDim(); i++){
            item = this->vector->Get(i) + v->vector->Get(i);
            new_vector->Append(item);
        }
        return new_vector;
    };
    Vector<T>* MultOnScalar(T scalar){
        T item;
        auto* new_vector = new Vector<T>;
        for(int i = 0; i < this->GetDim(); i++){
            item = this->GetCoord(i) * scalar;
            new_vector->Append(item);
            }
        return new_vector;
    };
    T ScalarMult(Vector<T>* v){
        if (this->GetDim() != v->GetDim())
            throw out_of_range(DIM_ERROR);
        T sum = this->GetCoord(0) * v->GetCoord(0);
        for(int i = 1; i < this->GetDim(); i++){
            sum += this->GetCoord(i) * v->GetCoord(i);
        }
        return sum;
    };
//
    template<typename U>
    U NormOfVector(){
        U norm_sq = ScalarMult(this);
        return sqrt(norm_sq);
    };
    friend ostream &operator << (ostream &cout, Vector<T>* vector1){
        cout << '[';
        for(int i = 0; i < vector1->GetDim(); i ++){
            cout << vector1->GetCoord(i);
            if(i != vector1->GetDim()-1)
                cout << ", ";
        }
        cout << ']';
        return cout;
    };


};
