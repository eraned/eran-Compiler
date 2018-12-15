//
// Created by ise on 16/01/18.
//

#include "StringArr.h"

void StringArr::createArray(queue<char*>& varValues){
    my_array = new Variable*[m_size];
    int i;
    try{
    for(i=0; i<m_size; i++)
    {
        my_array[i]=new StringVar(varValues.front());
        varValues.pop();
    }
    }
    catch (RunnerException& e)
    {
        setSize(i);
        for (int j = 0; j < i; j++)
        {
            delete &(getElement(j));
        }
        //free (m_name);
        delete[] my_array;
        throw e;
    }
}

Variable& StringArr::operator[](int i) {
    if (i < 0 || i > m_size - 1)
        throw ArrayOutOfBoundException();
    else
        return *(my_array[i]);
}

Variable& StringArr::getElement(int i) {
    return *my_array[i];
}

StringArr::~StringArr(void) {
    for (int i = 0; i < m_size; i++) {
        delete &getElement(i);
    }
    if (my_array)
        delete[] my_array;
}
