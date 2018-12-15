//
// Created by ise on 15/01/18.
//
#include "ArrayVar.h"
#ifndef ASSIGN4_INTARR_H
#define ASSIGN4_INTARR_H


class IntArr: public ArrayVar {

public:
    IntArr(void):ArrayVar(){};
    IntArr(char* name1,char* value):ArrayVar(name1, value){setValue(value);};
    virtual ~IntArr(void);
    //virtual void setValue(const char* value);
    //virtual void setElement(const )
    virtual Variable& getElement(int i);
    virtual void createArray(queue<char*>& varValues);
    virtual const char* getValue()const{};
    virtual Variable& operator[](int i);
};


#endif //ASSIGN4_INTARR_H
