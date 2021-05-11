#include "Test_DA_LL.h"
#include <cassert>
#include "iostream"
using namespace std;
float round_float(float num, int order){
    for (int i = 0; i < order; i++){
        num = num * 10;
    }
    num = (float)(int)num;
    for (int i = 0; i < order; i++){
        num = num / 10;
    }
    return num;
}

//DynamicArray Test
void constructor_1_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    auto* dynArray = new DynamicArray<int>(arr, 5);
    assert(dynArray->GetLen() == 5);
    assert(dynArray->GetSize() == 5);
    assert(dynArray->Get(3) == 4);
    dynArray->Resize(8);
    assert(dynArray->GetSize() == 8);
    assert(dynArray->GetLen() == 5);
    dynArray->Set(3, 10);
    assert(dynArray->Get(3) == 10);
    dynArray->Resize(0);
    assert(dynArray->GetLen() == 0);
    assert(dynArray->GetSize() == 0);
    dynArray->Delete_DynamicArray();
};
void constructor_2_DA(){
    auto* arr = new DynamicArray<int>(10);
    assert(arr->GetSize() == 10);
    assert(arr->GetLen() == 10);
    arr->Delete_DynamicArray();
};
void constructor_3_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int>* array = new DynamicArray<int>(arr, 5);
    DynamicArray<int>* newArr = new DynamicArray<int>(array);
    assert(newArr->GetSize() == 5);
    assert(newArr->Get(2) == 3);
    assert(newArr->Get(1) == 2);
    array->Delete_DynamicArray();
//    newArr->Delete_DynamicArray();
};
void constructor_4_DA(){
    DynamicArray<int>* array = new DynamicArray<int>();
    assert(array->GetSize() == 0);
    assert(array->GetLen() == 0);
    array->Delete_DynamicArray();
};
void Get_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    assert(array->Get(3) == 4);
    assert(array->Get(4) == 5);
    assert(array->Get(0) == 1);
    array->Delete_DynamicArray();
};
void GetSize_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    assert(array->GetSize() == 5);
    array->Delete_DynamicArray();
};
void GetLen_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    assert(array->GetLen() == 5);
    array->Delete_DynamicArray();
};
void Set_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    array->Set(3, 100);
    assert(array->Get(3) == 100);
    assert(array->Get(2) == 3);
    array->Delete_DynamicArray();
};
void Resize_DA(){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    assert(array->GetSize() == 5);
    array->Resize(10);
    assert(array->GetSize() == 10);
    assert(array->GetLen() == 5);
    array->Delete_DynamicArray();
}

//LinkedList Test
void constructor_1_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    assert(list->GetLength() == 5);
    assert(round_float(list->Get(1), 1) == round_float(6.6, 1));
    list->Delete_LinkedList();
}
void constructor_2_LL(){
    auto* list = new LinkedList<float>;
    assert(list->GetLength() == 0);
    list->Delete_LinkedList();
}
void constructor_3_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    auto* list2 = new LinkedList<float>(list1);
    assert(list1->GetLength() == list2->GetLength());
    assert(list1->Get(3) == list2->Get(3));
    assert(list1->Get(0) == list2->Get(0));
    assert(list1->Get(2) == list2->Get(2));
    list1->Delete_LinkedList();
//    list2->Delete_LinkedList();
}
void GetFirst_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    assert(round_float(list->GetFirst(), 2) == round_float(5.5, 2));
    list->Delete_LinkedList();
}
void GetLast_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    assert(round_float(list->GetLast(), 2) == round_float(0, 2));
    list->Delete_LinkedList();
}
void Get_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    assert(round_float(list->Get(0), 2) == round_float(5.5, 2));
    assert(round_float(list->Get(1), 2) == round_float(6.6, 2));
    assert(round_float(list->Get(3), 2) == round_float(-9.9, 2));
    list->Delete_LinkedList();
}
void GetSubList_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    auto* list2 = list1->GetSublist(1, 4);
    assert(round_float(list2->Get(0), 2) == round_float(6.6, 2));
    assert(round_float(list2->Get(1), 2) == round_float(-7.8, 2));
    assert(round_float(list2->Get(2), 2) == round_float(-9.9, 2));
    assert(list2->GetLength() == 3);
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
}
void GetLength_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    assert(list1->GetLength() == 5);
    list1->Delete_LinkedList();
}
void Append_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    list1->Append(-10.5);
    assert(list1->GetLength() == 6);
    assert(round_float(list1->Get(5), 2) == round_float(-10.5, 2));
    assert(round_float(list1->Get(4), 2) == round_float(0, 2));
    auto* list2 = new LinkedList<int>();
    list2->Append(5);
    assert(list2->GetLength() == 1);
    assert(list2->Get(0) == 5);
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
}
void Prepend_LL(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    list1->Prepend(3.5);
    assert(list1->GetLength() == 6);
    assert(round_float(list1->Get(0), 2) == round_float(3.5, 2));
    assert(round_float(list1->Get(1), 2) == round_float(5.5, 2));
    LinkedList<int>* list2;
    list2->Prepend(5);
    assert(list2->GetLength() == 1);
    assert(list2->Get(0) == 5);
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
}
void InsertAt(){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    list1->InsertAt(4, 3);
    assert(list1->GetLength() == 6);
    assert(round_float(list1->Get(3), 2) == round_float(4, 2));
    assert(round_float(list1->Get(2), 2) == round_float(-7.8, 2));
    assert(round_float(list1->Get(4), 2) == round_float(-9.9, 2));
    list1->Delete_LinkedList();
}
void Concat(){
    float arr1[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr1, 5);
    float arr2[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list2 = new LinkedList<float>(arr2, 5);
    auto* list3 = list1->Concat(list2);
    assert(list3->GetLength() == 10);
    assert(round_float(list3->Get(5), 2) == round_float(5.5, 2));
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
    list3->Delete_LinkedList();
}

void Tests_DA_LL(){
    constructor_1_DA();
    constructor_2_DA();
    constructor_3_DA();
    constructor_4_DA();
    Get_DA();
    GetSize_DA();
    GetLen_DA();
    Set_DA();
    Resize_DA();
    cout << "Dynamic Array passed all tests\n";
    constructor_1_LL();
    constructor_2_LL();
    constructor_3_LL();
    GetFirst_LL();
    GetLast_LL();
    Get_LL();
    GetSubList_LL();
    GetLength_LL();
    Append_LL();
    Prepend_LL();
    InsertAt();
    Concat();
    cout << "LinkedList passed all tests\n";
};