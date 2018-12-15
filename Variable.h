//
// Created by ise on 10/01/18.
//
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include "VariableNotFoundException.h"
#include "BadVariableTypeException.h"
#include "ArrayOutOfBoundException.h"
using namespace std;

#ifndef ASSIGN4_VARIABLE_H
#define ASSIGN4_VARIABLE_H


class Variable {

protected:
    char* m_type = NULL;
    char* m_name = NULL;

public:
    Variable(void){};
    Variable(char* type, char* name);
    virtual ~Variable(void);
    const char* getType();
    virtual const char* getName();
    virtual void setValue(const char* value){};
    virtual const char* getValue()const=0;
    virtual char* operator+(const char* other){};
    virtual bool operator==(const char* other){};
    virtual string getLbl(){};
    virtual Variable& operator=(const char* other_value){};
    virtual Variable& operator+=(const char* other_value){};
    virtual Variable& operator[](int i){};
    virtual void print(){};
    friend ostream& operator<<(ostream& out, const Variable& v);
};


#endif //ASSIGN4_VARIABLE_H
