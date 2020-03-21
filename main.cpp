/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on 20 de marzo de 2020, 05:04 PM
 */

#include <cstdlib>
#include "mathTools.h"
#include "displayTools.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 * 
 */

void inversa(Matrix M, Matrix &inv){
    float det = determinant(M);
    if(det!=0){
        cout<<"determinante distinto a 0, podemos seguir.\n";
        Matrix cof, coftr, res;
        cofactors(M, cof);
        transpose(cof,coftr);
        productRealMatrix(1/det, coftr, res);
        cout<<"La matriz original es:\n";
        showMatrix(M);
        cout<<"Su inversa es:\n";
        showMatrix(res);
    } 
    else{
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    
    Matrix M, inv;
    
    zeroes(M, 3);
    
    M.at(0).at(0)=2;
    M.at(0).at(1)=2;
    M.at(0).at(2)=3;
    
    M.at(1).at(0)=4;
    M.at(1).at(1)=5;
    M.at(1).at(2)=6;
    
    M.at(2).at(0)=7;
    M.at(2).at(1)=8;
    M.at(2).at(2)=9;
 
    inversa(M, inv);

    return 0;
}

