#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "vector.h"
#include "DiagonalMatrix.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
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
TEST_CASE("constructor_1_DA"){
    int arr[] = {1, 2, 3, 4, 5};
    auto* dynArray = new DynamicArray<int>(arr, 5);
    REQUIRE(dynArray->GetLen() == 5);
    REQUIRE(dynArray->GetSize() == 5);
    REQUIRE(dynArray->Get(3) == 4);
    dynArray->Resize(8);
    REQUIRE(dynArray->GetSize() == 8);
    REQUIRE(dynArray->GetLen() == 5);
    dynArray->Set(3, 10);
    REQUIRE(dynArray->Get(3) == 10);
    dynArray->Resize(0);
    REQUIRE(dynArray->GetLen() == 0);
    REQUIRE(dynArray->GetSize() == 0);
    dynArray->Delete_DynamicArray();
};
TEST_CASE("constructor_2_DA"){
    auto* arr = new DynamicArray<int>(10);
    REQUIRE(arr->GetSize() == 10);
    REQUIRE(arr->GetLen() == 10);
    arr->Delete_DynamicArray();
};
TEST_CASE("constructor_3_DA"){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int>* array = new DynamicArray<int>(arr, 5);
    DynamicArray<int>* newArr = new DynamicArray<int>(array);
    REQUIRE(newArr->GetSize() == 5);
    REQUIRE(newArr->Get(2) == 3);
    REQUIRE(newArr->Get(1) == 2);
    array->Delete_DynamicArray();
//    newArr->Delete_DynamicArray();
};
TEST_CASE("constructor_4_DA"){
    DynamicArray<int>* array = new DynamicArray<int>();
    REQUIRE(array->GetSize() == 0);
    REQUIRE(array->GetLen() == 0);
    array->Delete_DynamicArray();
};
TEST_CASE("Get_DA"){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    REQUIRE(array->Get(3) == 4);
    REQUIRE(array->Get(4) == 5);
    REQUIRE(array->Get(0) == 1);
    array->Delete_DynamicArray();
};
TEST_CASE("GetSize_DA"){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    REQUIRE(array->GetSize() == 5);
    array->Delete_DynamicArray();
};
TEST_CASE("GetLen_DA"){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    REQUIRE(array->GetLen() == 5);
    array->Delete_DynamicArray();
};
TEST_CASE("Set_DA"){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    array->Set(3, 100);
    REQUIRE(array->Get(3) == 100);
    REQUIRE(array->Get(2) == 3);
    array->Delete_DynamicArray();
};
TEST_CASE("Resize_DA"){
    int arr[] = {1, 2, 3, 4, 5};
    auto* array = new DynamicArray<int>(arr, 5);
    REQUIRE(array->GetSize() == 5);
    array->Resize(10);
    REQUIRE(array->GetSize() == 10);
    REQUIRE(array->GetLen() == 5);
    array->Delete_DynamicArray();
}

//LinkedList Test
TEST_CASE("constructor_1_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    REQUIRE(list->GetLength() == 5);
    REQUIRE(round_float(list->Get(1), 1) == round_float(6.6, 1));
    list->Delete_LinkedList();
}
TEST_CASE("constructor_2_LL"){
    auto* list = new LinkedList<float>;
    REQUIRE(list->GetLength() == 0);
    list->Delete_LinkedList();
}
TEST_CASE("constructor_3_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    auto* list2 = new LinkedList<float>(list1);
    REQUIRE(list1->GetLength() == list2->GetLength());
    REQUIRE(list1->Get(3) == list2->Get(3));
    REQUIRE(list1->Get(0) == list2->Get(0));
    REQUIRE(list1->Get(2) == list2->Get(2));
}
TEST_CASE("GetFirst_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    REQUIRE(round_float(list->GetFirst(), 2) == round_float(5.5, 2));
    list->Delete_LinkedList();
}
TEST_CASE("GetLast_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    REQUIRE(round_float(list->GetLast(), 2) == round_float(0, 2));
    list->Delete_LinkedList();
}
TEST_CASE("Get_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list = new LinkedList<float>(arr, 5);
    REQUIRE(round_float(list->Get(0), 2) == round_float(5.5, 2));
    REQUIRE(round_float(list->Get(1), 2) == round_float(6.6, 2));
    REQUIRE(round_float(list->Get(3), 2) == round_float(-9.9, 2));
    list->Delete_LinkedList();
}
TEST_CASE("GetSubList_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    auto* list2 = list1->GetSublist(1, 4);
    REQUIRE(round_float(list2->Get(0), 2) == round_float(6.6, 2));
    REQUIRE(round_float(list2->Get(1), 2) == round_float(-7.8, 2));
    REQUIRE(round_float(list2->Get(2), 2) == round_float(-9.9, 2));
    REQUIRE(list2->GetLength() == 3);
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
}
TEST_CASE("GetLength_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    REQUIRE(list1->GetLength() == 5);
    list1->Delete_LinkedList();
}
TEST_CASE("Append_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    list1->Append(-10.5);
    REQUIRE(list1->GetLength() == 6);
    REQUIRE(round_float(list1->Get(5), 2) == round_float(-10.5, 2));
    REQUIRE(round_float(list1->Get(4), 2) == round_float(0, 2));
    auto* list2 = new LinkedList<int>();
    list2->Append(5);
    REQUIRE(list2->GetLength() == 1);
    REQUIRE(list2->Get(0) == 5);
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
}
TEST_CASE("Prepend_LL"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    list1->Prepend(3.5);
    REQUIRE(list1->GetLength() == 6);
    REQUIRE(round_float(list1->Get(0), 2) == round_float(3.5, 2));
    REQUIRE(round_float(list1->Get(1), 2) == round_float(5.5, 2));
    auto* list2 = new LinkedList<int>();
    list2->Prepend(5);
    REQUIRE(list2->GetLength() == 1);
    REQUIRE(list2->Get(0) == 5);
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
}
TEST_CASE("InsertAt"){
    float arr[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr, 5);
    list1->InsertAt(4, 3);
    REQUIRE(list1->GetLength() == 6);
    REQUIRE(round_float(list1->Get(3), 2) == round_float(4, 2));
    REQUIRE(round_float(list1->Get(2), 2) == round_float(-7.8, 2));
    REQUIRE(round_float(list1->Get(4), 2) == round_float(-9.9, 2));
    list1->Delete_LinkedList();
}
TEST_CASE("Concat"){
    float arr1[] = {5.5, 6.6, -7.8, -9.9, 0};
    auto* list1 = new LinkedList<float>(arr1, 5);
    float arr2[] = {1, 6.6, -7.8, -9.9, 0};
    auto* list2 = new LinkedList<float>(arr2, 5);
    auto* list3 = list1->Concat(list2);
    REQUIRE(list3->GetLength() == 10);
    REQUIRE(round_float(list3->Get(5), 2) == round_float(1, 2));
    list1->Delete_LinkedList();
    list2->Delete_LinkedList();
    list3->Delete_LinkedList();
}


//ArraySequence Test
TEST_CASE("constructors_array_sequence"){
    ArraySequence<int>* arraySequence1 = new ArraySequence<int>();
    srand(4541);
    REQUIRE(arraySequence1->GetLength() == 0);

    for (int i = 1; i < 10; i++){
        auto* arr = new int[i];
        for(int j = 0; j < i; j++){
            arr[j] = rand();
        }

        ArraySequence<int>* arraySequence2 = new ArraySequence<int>(arr, i);
        REQUIRE(arraySequence2->GetLength() == i);
        for(int k = 0; k < i; k++){
            REQUIRE(arraySequence2->Get(k) == arr[k]);
        }
        ArraySequence<int>* arraySequence3 = new ArraySequence<int>(arraySequence2);
        REQUIRE(arraySequence3->GetLength() == arraySequence2->GetLength());
        REQUIRE(arraySequence2->GetLength() == i);
        for(int k = 0; k < i; k++){
            REQUIRE(arraySequence3->Get(k) == arraySequence2->Get(k));
        }

        arraySequence3->Delete_ArraySequence();
        delete[] arr;
    }
    arraySequence1->Delete_ArraySequence();
};
TEST_CASE("decomposition_array_sequence"){
    srand(4541);
    for (int i = 1; i < 10; i++){
        auto array = new int[i];
        for(int j = 0; j < i; j++){
            array[j] = rand();
        }
        ArraySequence<int>* arraySequence = new ArraySequence<int>(array, i);
        REQUIRE(arraySequence->GetFirst() == array[0]);
        REQUIRE(arraySequence->GetLast() == array[i - 1]);
        REQUIRE(arraySequence->GetLength() == i);
        for (int k = 0; k < i; k++){
            REQUIRE(arraySequence->Get(k) == array[k]);
        }
        arraySequence->Delete_ArraySequence();
        delete[] array;
    }
}
TEST_CASE("function_array_sequence"){
    srand(4541);
    for (int i = 1; i < 10; i++){
        auto array = new int[i];
        for(int j = 0; j < i; j++){
            array[j] = rand();
        }
        ArraySequence<int>* arraySequence = new ArraySequence<int>(array, i);
        int item = rand();
        arraySequence->Append(item);
        REQUIRE(arraySequence->GetLength() == i + 1);
        REQUIRE(arraySequence->Get(i) == item);
        arraySequence->Prepend(item);
        REQUIRE(arraySequence->GetLength() == i + 2);
        REQUIRE(arraySequence->Get(0) == item);
        arraySequence->Delete_ArraySequence();
        delete[] array;
    }
}

//LinkedListSequence Test

TEST_CASE("constructors_listSequence"){
    ListSequence<int>* listSequence1 = new ListSequence<int>();
    REQUIRE(listSequence1->GetLength() == 0);
    srand(4540);

    for (int i = 1; i < 10; i++){
        auto array = new int[i];
        ListSequence<int>* listSequence2 = new ListSequence<int>();
        int num;
        for(int j = 0; j < i; j++){
            num = rand();
            listSequence2->Append(num);
            array[j] = num;
        }

        REQUIRE(listSequence2->GetLength() == i);
        for(int k = 0; k < i; k++){
            REQUIRE(listSequence2->Get(k) == array[k]);
        }
        ListSequence<int>* listSequence3 = new ListSequence<int>(listSequence2);
        REQUIRE(listSequence3->GetLength() == listSequence2->GetLength());
        for(int k = 0; k < i; k++){
            REQUIRE(listSequence3->Get(k) == listSequence2->Get(k));
        }

        listSequence2->Delete_LinkedListSequence();
        listSequence3->Delete_LinkedListSequence();
        delete[] array;
    }
    listSequence1->Delete_LinkedListSequence();
}
TEST_CASE("decomposition_listSequence"){
    srand(4541);
    for (int i = 1; i < 10; i++){
        auto array = new int[i];
        ListSequence<int>* listSequence = new ListSequence<int>();
        int num;
        for(int j = 0; j < i; j++){
            num = rand();
            listSequence->Append(num);
            array[j] = num;
        }
        REQUIRE(listSequence->GetFirst() == array[0]);
        REQUIRE(listSequence->GetLast() == array[i - 1]);
        REQUIRE(listSequence->GetLength() == i);
        for (int k = 0; k < i; k++){
            REQUIRE(listSequence->Get(k) == array[k]);
        }
        listSequence->Delete_LinkedListSequence();
        delete[] array;
    }
}
TEST_CASE("function_listSequence"){
    srand(4541);
    for (int i = 1; i < 10; i++){
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
        REQUIRE(listSequence->GetLength() == i + 1);
        REQUIRE(listSequence->Get(i) == item);
        listSequence->Prepend(item);
        REQUIRE(listSequence->GetLength() == i + 2);
        REQUIRE(listSequence->Get(0) == item);
        listSequence->Delete_LinkedListSequence();
        delete[] array;
    }
}





TEST_CASE("constructors_Matrix"){
    int length = 100;
    int* items = new int[length];
    for (int i = 0; i < length; i++)
        items[i] = i * 3;
    auto* matrix1 = new DiagonalMatrix<int>;
    REQUIRE(matrix1->GetDim() == 0);

    auto* matrix2 = new DiagonalMatrix<int>(items, length);
    REQUIRE(matrix2->GetDim() == length);
    for (int i = 0; i < length; i++)
        REQUIRE(matrix2->GetElement(i, i) == i * 3);

    auto* matrix3 = new DiagonalMatrix<int>(matrix2);
    REQUIRE(matrix3->GetDim() == length);
    for (int i = 0; i < length; i++)
        REQUIRE(matrix3->GetElement(i, i) == i * 3);
};
TEST_CASE("operations_Matrix"){
    const int length = 3;

    int first_matrix_data[length] = {1, 2, 3};
    int second_matrix_data[length] = {4, 5, 6};

    int* pointer_first_data = new int[length];
    for (int i = 0; i < length; i++)
        pointer_first_data[i] = first_matrix_data[i];
    int* pointer_second_data = new int[length];
    for (int i = 0; i < length; i++)
        pointer_second_data[i] = second_matrix_data[i];

    int scalar = 2;

    int matrix_sum[length] = {5, 7, 9};
    int matrix1_MultOnScalar[length] = { 2, 4, 6};
    int matrix2_MultOnScalar[length] = { 8, 10, 12};

    auto* matrix1 = new DiagonalMatrix<int>(pointer_first_data, length);
    auto* matrix2 = new DiagonalMatrix<int>(pointer_second_data, length);
    auto* Sumofmatrixes = matrix1->SumOfMatrix(matrix2);
    auto* MultOnScalarmatrix1 = matrix1->MultOnScalar(scalar);
    auto* MultOnScalarmatrix2 = matrix2->MultOnScalar(scalar);

    for (int i = 0; i < length; i++){

        REQUIRE(Sumofmatrixes->GetElement(i, i) == matrix_sum[i]);
        REQUIRE(MultOnScalarmatrix1->GetElement(i, i) == matrix1_MultOnScalar[i]);
        REQUIRE(MultOnScalarmatrix2->GetElement(i, i) == matrix2_MultOnScalar[i]);
    }

};

TEST_CASE("constructors_Vector"){
    int length = 100;
    int* items = new int[length];
    for (int i = 0; i < length; i++)
        items[i] = i * 3;
    Vector<int>* vector1 = new Vector<int>;
    REQUIRE(vector1->GetDim() == 0);

    Vector<int>* vector2 = new Vector<int>(items, length);
    REQUIRE(vector2->GetDim() == length);
    for (int i = 0; i < length; i++)
        REQUIRE(vector2->GetCoord(i) == i * 3);

    Vector<int>* vector3 = new Vector<int>(vector2);
    REQUIRE(vector3->GetDim() == length);
    for (int i = 0; i < length; i++)
        REQUIRE(vector3->GetCoord(i) == i * 3);
}
TEST_CASE("operations_Vector"){
    const int length = 3;


    int first_vector_data[length] = {1, 2, 3};
    int second_vector_data[length] = {4, 5, 6};

    int* pointer_first_data = new int[length];
    for (int i = 0; i < length; i++)
        pointer_first_data[i] = first_vector_data[i];
    int* pointer_second_data = new int[length];
    for (int i = 0; i < length; i++)
        pointer_second_data[i] = second_vector_data[i];

    int scalar = 2;

    int vector_sum[length] = {5, 7, 9};
    int vectors_ScalarMult = 32;
    int vector1_MultOnScalar[length] = { 2, 4, 6};
    int vector2_MultOnScalar[length] = { 8, 10, 12};

    Vector<int>* vector1 = new Vector<int>(pointer_first_data, length);
    Vector<int>* vector2 = new Vector<int>(pointer_second_data, length);
    auto* Sumofvectors = vector1->SumOfVectors(vector2);
    auto* MultOnScalarVector1 = vector1->MultOnScalar(scalar);
    auto* MultOnScalarVector2 = vector2->MultOnScalar(scalar);
    int scalar_mult = vector1->ScalarMult(vector2);


    for (int i = 0; i < length; i++){
        REQUIRE(Sumofvectors->GetCoord(i) == vector_sum[i]);
        REQUIRE(MultOnScalarVector1->GetCoord(i) == vector1_MultOnScalar[i]);
        REQUIRE(MultOnScalarVector2->GetCoord(i) == vector2_MultOnScalar[i]);
        REQUIRE(scalar_mult == vectors_ScalarMult);
    }

}