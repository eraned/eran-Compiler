//
// Created by ise on 15/01/18.
//

#include "IntArr.h"

void IntArr::createArray(queue<char*>& varValues){
    my_array = new Variable*[m_size];
    for(int i=0; i<m_size; i++)
    {
        my_array[i]=new IntVar(varValues.front());
        varValues.pop();
    }
}
Variable& IntArr::operator[](int i) {
    if (i < 0 || i > m_size - 1)
        throw ArrayOutOfBoundException();
    else
        return *(my_array[i]);
}

Variable &IntArr::getElement(int i) {
    return *my_array[i];
}

IntArr::~IntArr(void) {
    for (int i = 0; i < m_size; i++)
    {
        delete my_array[i];
    }
    if (my_array)
        delete[] my_array;
}
