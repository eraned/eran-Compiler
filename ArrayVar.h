//
// Created by ise on 10/01/18.
//

#ifndef ASSIGN4_ARRAYVAR_H
#define ASSIGN4_ARRAYVAR_H
#include <algorithm>
#include <queue>
#include "Variable.h"
#include "IntVar.h"
#include "BoolVar.h"
#include "StringVar.h"
#include "ArrayOutOfBoundException.h"

class ArrayVar: public Variable
{

protected:
    int m_size;

public:
    Variable** my_array;
    ArrayVar():Variable(){};
    ArrayVar(char* name1,char* value):Variable(((char*)"ArrayVar"), name1){};
    virtual ~ArrayVar(void);
    virtual Variable& operator[](int i){};
    virtual void setValue(const char* value);
    virtual const void setSize(int size){m_size=size;}
    virtual void createArray(queue<char*>& varValues){};
    virtual Variable& getElement(int i){};
    virtual string getLbl();
};


#endif //ASSIGN4_ARRAYVAR_H
