#include "Test_AS_LLS.h"
#include <cassert>
#include <fstream>
#include "iostream"
using namespace std;
#include "ArraySequence.h"
#include "ListSequence.h"
#include <chrono>


void as_perfomance_test(){
    fstream fs;
    /*
    fs.open("array_sequence_perfomance.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 0; i < 50000; i++) {
        ArraySequence<int>* arr = new ArraySequence<int>;
        auto begin = std::chrono::steady_clock::now();
        for(int j = 0 ; j < i; j++)
            arr->Append(j);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }

    ArraySequence<int>* arr = new ArraySequence<int>(500000);
    for(int i = 0; i < 500000; i++) {
        arr->Set(i * i, i);
    }
    int j;
    fs.open("array_sequence_perfomance_get_i.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 0; i < 500000; i++) {
        auto begin = std::chrono::steady_clock::now();
        j = arr->Get(i);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }
     */
};
void ls_perfomance_test(){
    fstream fs;
/*
    fs.open("list_sequence_perfomance.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 0; i < 50000; i++) {
        ListSequence<int>* list = new ListSequence<int>;
        auto begin = std::chrono::steady_clock::now();
        for(int j = 0 ; j < i; j++)
            list->Prepend(j);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }

    ListSequence<int>* list = new ListSequence<int>;
    for(int i = 0; i < 500000; i++)
        list->Prepend(i*i);
    int k;
    fs.open("list_sequence_perfomance_get_i.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 0; i < 500000; i++) {
        auto begin = std::chrono::steady_clock::now();
        k = list->Get(i);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }
    */
};

//ArraySequence Test
void constructors_array_sequence(){
    ArraySequence<int>* arraySequence1 = new ArraySequence<int>();
    srand(4541);
    assert(arraySequence1->GetLength() == 0);

    for (int i = 1; i < 10000; i++){
        auto* arr = new int[i];
        for(int j = 0; j < i; j++){
            arr[j] = rand();
        }

        ArraySequence<int>* arraySequence2 = new ArraySequence<int>(arr, i);
        assert(arraySequence2->GetLength() == i);
        for(int k = 0; k < i; k++){
            assert(arraySequence2->Get(k) == arr[k]);
        }
        ArraySequence<int>* arraySequence3 = new ArraySequence<int>(arraySequence2);
        assert(arraySequence3->GetLength() == arraySequence2->GetLength());
        assert(arraySequence2->GetLength() == i);
        for(int k = 0; k < i; k++){
            assert(arraySequence3->Get(k) == arraySequence2->Get(k));
        }

        arraySequence3->Delete_ArraySequence();
        delete[] arr;
    }
    arraySequence1->Delete_ArraySequence();

    cout <<"Array Sequence Constructor Test passed 10000 tests" << endl;
};
void decomposition_array_sequence(){
    srand(4541);
    for (int i = 1; i < 1000; i++){
        auto array = new int[i];
        for(int j = 0; j < i; j++){
            array[j] = rand();
        }
        ArraySequence<int>* arraySequence = new ArraySequence<int>(array, i);
        assert(arraySequence->GetFirst() == array[0]);
        assert(arraySequence->GetLast() == array[i - 1]);
        assert(arraySequence->GetLength() == i);
        for (int k = 0; k < i; k++){
            assert(arraySequence->Get(k) == array[k]);
        }
        arraySequence->Delete_ArraySequence();
        delete[] array;
    }

    cout << "Array Sequence Decomposition Test passed 10000 tests" << endl;
}
void function_array_sequence(){
    srand(4541);
    for (int i = 1; i < 10000; i++){
        auto array = new int[i];
        for(int j = 0; j < i; j++){
            array[j] = rand();
        }
        ArraySequence<int>* arraySequence = new ArraySequence<int>(array, i);
        int item = rand();
        arraySequence->Append(item);
        assert(arraySequence->GetLength() == i + 1);
        assert(arraySequence->Get(i) == item);
        arraySequence->Prepend(item);
        assert(arraySequence->GetLength() == i + 2);
        assert(arraySequence->Get(0) == item);
        arraySequence->Delete_ArraySequence();
        delete[] array;
    }

    cout << "Array Sequence Functions Test passed 10000 tests" << endl;
}

//LinkedListSequence Test

void constructors_listSequence(){
    ListSequence<int>* listSequence1 = new ListSequence<int>();
    assert(listSequence1->GetLength() == 0);
    srand(4540);

    for (int i = 1; i < 1000; i++){
        auto array = new int[i];
        ListSequence<int>* listSequence2 = new ListSequence<int>();
        int num;
        for(int j = 0; j < i; j++){
            num = rand();
            listSequence2->Append(num);
            array[j] = num;
        }

        assert(listSequence2->GetLength() == i);
        for(int k = 0; k < i; k++){
            assert(listSequence2->Get(k) == array[k]);
        }
        ListSequence<int>* listSequence3 = new ListSequence<int>(listSequence2);
        assert(listSequence3->GetLength() == listSequence2->GetLength());
        for(int k = 0; k < i; k++){
            assert(listSequence3->Get(k) == listSequence2->Get(k));
        }

        listSequence2->Delete_LinkedListSequence();
        listSequence3->Delete_LinkedListSequence();
        delete[] array;
    }
    listSequence1->Delete_LinkedListSequence();

    cout << "Linked List Sequence Constructor Test passed 1000 tests" << endl;
}
void decomposition_listSequence(){
    srand(4541);
    for (int i = 1; i < 1000; i++){
        auto array = new int[i];
        ListSequence<int>* listSequence = new ListSequence<int>();
        int num;
        for(int j = 0; j < i; j++){
            num = rand();
            listSequence->Append(num);
            array[j] = num;
        }
        assert(listSequence->GetFirst() == array[0]);
        assert(listSequence->GetLast() == array[i - 1]);
        assert(listSequence->GetLength() == i);
        for (int k = 0; k < i; k++){
            assert(listSequence->Get(k) == array[k]);
        }
        listSequence->Delete_LinkedListSequence();
        delete[] array;
    }

    cout << "Linked List Sequence Decomposition Test passed 1000 tests" << endl;
}
void function_listSequence(){
    srand(4541);
    for (int i = 1; i < 1000; i++){
        auto array = new int[i];
        ListSequence<int>* listSequence = new ListSequence<int>();
        int num;
        for(int j = 0; j < i; j++){
            num = rand();
            listSequence->Append(num);
            array[j] = num;
        }
        int item = rand();
        listSequence->Append(item);
        assert(listSequence->GetLength() == i + 1);
        assert(listSequence->Get(i) == item);
        listSequence->Prepend(item);
        assert(listSequence->GetLength() == i + 2);
        assert(listSequence->Get(0) == item);
        listSequence->Delete_LinkedListSequence();
        delete[] array;
    }

    cout << "Linked List Sequence Functions Test passed 1000 tests" << endl;
}

