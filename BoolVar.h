//
// Created by ise on 10/01/18.
//

#ifndef ASSIGN4_BOOLVAR_H
#define ASSIGN4_BOOLVAR_H
#include "Variable.h"


class BoolVar: public Variable {

protected:
    char* m_value; // true or false
public:
    BoolVar(void):Variable(){};
    BoolVar(char* name1, char* value):Variable(((char*)"BoolVar"), name1){setValue(value);};
    BoolVar(char* value1):Variable(((char*)"BoolVar"), value1){setValue(value1);};
    virtual ~BoolVar(void);
    void setValue(const char* flag);
    const char* getValue()const{return m_value;};
    virtual Variable& operator=(const char* other);
    virtual bool operator==(const char* other);
    virtual string getLbl(){return m_value;};
};


#endif //ASSIGN4_BOOLVAR_H