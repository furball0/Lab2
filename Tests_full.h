#ifndef LAB2_TESTS_FULL_H
#define LAB2_TESTS_FULL_H

#endif //LAB2_TESTS_FULL_H
#include "Test_Matrix_Vector.h"
#include "Test_AS_LLS.h"
#include "Test_DA_LL.h"
#include <iostream>
using namespace std;

void tests() {
    //ArraySequence Test
    constructors_array_sequence();
    decomposition_array_sequence();
    function_array_sequence();

    //LinkedListSequence Test
    constructors_listSequence();
    decomposition_listSequence();
    function_listSequence();


    Tests_DA_LL();

    constructors_Matrix();
    cout << "Constructors Matrix passed all tests" << endl;
    constructors_Vector();
    cout << "Constructors Vector passed all tests" << endl;

    operations_Vector();
    cout << "Operations Matrix passed all tests" << endl;
    operations_Matrix();
    cout << "Operations Matrix passed all tests" << endl;


}