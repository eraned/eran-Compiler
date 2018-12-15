//
// Created by ise on 16/01/18.
//
#include "ArrayVar.h"
#ifndef ASSIGN4_STRINGARR_H
#define ASSIGN4_STRINGARR_H


class StringArr: public ArrayVar {
public:
    StringArr(void):ArrayVar(){};
    StringArr(char* name1,char* value):ArrayVar(name1, value){setValue(value);};
    virtual ~StringArr(void);
    virtual Variable& getElement(int i);
    virtual void createArray(queue<char*>& varValues);
    virtual const char* getValue()const{};
    virtual Variable& operator[](int i);
};


#endif //ASSIGN4_STRINGARR_H
