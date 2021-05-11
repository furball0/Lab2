#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H
#include <string>
#include <sstream>
#pragma once
#endif //LAB2_DYNAMICARRAY_H
using namespace std;

const string SIZE_LESS_00 = "Size is less than 0";
const string INDEX_OUT_OF_RANGE0 = "Index out of range";

template <typename T>
class DynamicArray {
private:
    T* data = nullptr;
    int len;
    int size;

public:
    //Contructor
    DynamicArray(){
        len = 0;
        size = 0;
    };
    DynamicArray(int size){
        if(size < 0){
            throw length_error(SIZE_LESS_00);
        };
        data = new T[size];
        this->len = size;
        this->size = size;
    };
    DynamicArray(T* items, int count){
        if(count < 0){
            throw length_error(SIZE_LESS_00);
        };
        data = new T[count];
        len = count;
        size = count;
        for(int i = 0; i < count; i++)
            data[i] = items[i];
    };
    DynamicArray(DynamicArray <T> &dynamicArray){
        len = dynamicArray.len;
        data = new T[len];
        size = dynamicArray.size;
        for(int i = 0; i<len; i++){
            data[i] = dynamicArray.data[i];
        };
    };
    DynamicArray(DynamicArray<T>* dynArr){
        len = dynArr->len;
        size = dynArr->size;
        data = dynArr->data;
    }


    //Destructor
    ~DynamicArray(){
        delete[] data;
        len = 0;
        size = 0;
    };
    void Delete_DynamicArray(){
        delete[] data;
        len = 0;
        size = 0;
    }
    //Function for cast int to string
    string toString(int val)
    {
        ostringstream oss;
        oss << val;
        return oss.str();
    }
    //Decomposition
    T Get(int index){
        if(index < 0 || index >= len){
            string msg = INDEX_OUT_OF_RANGE0 + ". Get -> " + toString(index) + " but len -> " + toString(len);
            throw out_of_range(msg);
        };
        return data[index];
    };
    int GetLen(){
        return len;
    }
    int GetSize(){
        return size;
    }


    //Operations
    void Set(int index, T value){
        if (index < 0 || index >= len) {
            string msg = INDEX_OUT_OF_RANGE0 + ". Get -> " + toString(index) + " but len -> " + toString(len);
            throw out_of_range(msg);
        }
        data[index] = value;
    };
    void Resize(int newSize){
        if (newSize < 0){
            throw out_of_range(INDEX_OUT_OF_RANGE0);
        };// wrong len

        if (newSize == 0){
            delete[] data;
            data = nullptr;
            len = 0;
            size = 0;
            return;
        }// len = 0 => delete

        if (newSize == size){
            return;
        }// newSize is the same as len

        if (newSize < size){
            T* new_data = new T[newSize];
            for (int i = 0; i < newSize; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            size = newSize;
            if (len > newSize)
                len = newSize;
            data = new_data;
            return;
        }// shortening array

        if (newSize > 0 && size == 0){
            T* new_data = new T[newSize];
            delete[] data;
            size = newSize;
            data = new_data;
        }//

        if (newSize > size){
            T* new_data = new T[newSize];
            for (int i = 0; i < len; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            size = newSize;
            data = new_data;
            return;
        }// increase length of array
    };
    void Relen(int newLen){
        if(newLen > size || newLen < 0 || newLen < len){
            throw out_of_range(INDEX_OUT_OF_RANGE0);
        }
        len = newLen;
    }


    //Operators
    T operator[] (int index){
        if (index < 0 || index >= this->size){
            throw out_of_range(INDEX_OUT_OF_RANGE0);
        }
        return this->Get(index);
    };

};