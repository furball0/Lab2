#include "Test_Matrix_Vector.h"
#include "vector.h"
#include "DiagonalMatrix.h"
#include <cassert>


void constructors_Matrix(){
    int length = 100;
    int* items = new int[length];
    for (int i = 0; i < length; i++)
        items[i] = i * 3;
    auto* matrix1 = new DiagonalMatrix<int>;
    assert(matrix1->GetDim() == 0);

    auto* matrix2 = new DiagonalMatrix<int>(items, length);
    assert(matrix2->GetDim() == length);
    for (int i = 0; i < length; i++)
        assert(matrix2->GetElement(i, i) == i * 3);

    auto* matrix3 = new DiagonalMatrix<int>(matrix2);
    assert(matrix3->GetDim() == length);
    for (int i = 0; i < length; i++)
        assert(matrix3->GetElement(i, i) == i * 3);
};
void operations_Matrix(){
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

        assert(Sumofmatrixes->GetElement(i, i) == matrix_sum[i]);
        assert(MultOnScalarmatrix1->GetElement(i, i) == matrix1_MultOnScalar[i]);
        assert(MultOnScalarmatrix2->GetElement(i, i) == matrix2_MultOnScalar[i]);
    }

};


void constructors_Vector(){
    int length = 100;
    int* items = new int[length];
    for (int i = 0; i < length; i++)
            items[i] = i * 3;
    Vector<int>* vector1 = new Vector<int>;
    assert(vector1->GetDim() == 0);

    Vector<int>* vector2 = new Vector<int>(items, length);
    assert(vector2->GetDim() == length);
    for (int i = 0; i < length; i++)
        assert(vector2->GetCoord(i) == i * 3);

    Vector<int>* vector3 = new Vector<int>(vector2);
    assert(vector3->GetDim() == length);
    for (int i = 0; i < length; i++)
        assert(vector3->GetCoord(i) == i * 3);
}
void operations_Vector(){
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

        assert(Sumofvectors->GetCoord(i) == vector_sum[i]);
        assert(MultOnScalarVector1->GetCoord(i) == vector1_MultOnScalar[i]);
        assert(MultOnScalarVector2->GetCoord(i) == vector2_MultOnScalar[i]);
        assert(scalar_mult == vectors_ScalarMult);
    }

}