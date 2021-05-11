#ifndef LAB2_MENUFULL_H
#define LAB2_MENUFULL_H
#include "MenuDiagonalMatrix.h"
#pragma once
#include "MenuVector.h"
#endif //LAB2_MENUFULL_H


int menu(){
    while(true){
        int classType;
        cout << "Vector - 1 || Matrix - 2 || Exit - 0 ->" << endl;
        cin >> classType;
        cout << sep << endl;
        if (classType != 0 & classType != 1 & classType != 2){
            cout << "The number is incorrect. Please, enter the correct number" << endl;
        }
        if(classType == 1){
            //Vector
            MenuVector();
        }
        else if (classType == 2){
            //Matrix
            MenuMatrix();
        }
        else if (classType == 0){
            break;
        }

    }
    return 0;
};
