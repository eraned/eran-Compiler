//
// Created by ise on 15/01/18.
//

#include "BoolArr.h"

void BoolArr::createArray(queue<char*>& varValues){
    my_array = new Variable*[m_size];
    for(int i=0; i<m_size; i++)
    {
        my_array[i]=new BoolVar(varValues.front());
        varValues.pop();
    }
}
Variable& BoolArr::operator[](int i) {
    if (i < 0 || i > m_size - 1)
        throw ArrayOutOfBoundException();
    else
        return *(my_array[i]);
}

Variable &BoolArr::getElement(int i) {
    if (i < 0 || i > m_size - 1)
        throw ArrayOutOfBoundException();
    else
        return *(my_array[i]);
}

BoolArr::~BoolArr(void) {
    for (int i = 0; i < m_size; i++)
    {
        delete &getElement(i);
    }
    if (my_array)
        delete[] my_array;
}

