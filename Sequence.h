#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H
#pragma once
#endif //LAB2_SEQUENCE_H


template <class T> class Sequence {
public:
    //Decomposition
    virtual T GetFirst() = 0;//get el on first index
    virtual T GetLast() = 0;//get el on last index
    virtual T Get(int index) = 0;//get index of Node
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;//get list of el
    virtual int GetLength() = 0;// Length

    //Operations
    virtual void Append(T item) = 0; //add el at end
    virtual void Prepend(T item) = 0; //add el at head
    virtual void Set(T item, int index) = 0; // add el at index (replace)
    virtual void InsertAt(T item, int index) = 0; //add el at index
    virtual Sequence <T>* Concat(Sequence <T> *list) = 0; //concat two sequence

    //operators
    virtual T operator[] (int index) = 0;
};
