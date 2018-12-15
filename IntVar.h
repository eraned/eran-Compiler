//
// Created by ise on 10/01/18.
//

#ifndef ASSIGN4_INTVAR_H
#define ASSIGN4_INTVAR_H
#include "Variable.h"
#include "BadVariableTypeException.h"


class IntVar: public Variable

{
protected:
    char* m_value = NULL;
public:
    IntVar(void):Variable(){};
    IntVar(char* name1,char* value):Variable(((char*)"IntVar"), name1){setValue(value);};
    IntVar(char* value1):Variable(((char*)"IntVar"), value1){setValue(value1);};

    virtual ~IntVar(void);
    virtual void setValue(const char* value);
    virtual void print() const;
    virtual const char* getValue()const{return m_value;} ;
    //virtual const char* getName()const{return m_name;};
    //virtual Variable& operator=(const Variable& other);
    virtual Variable& operator=(const char* other);

    //virtual void operator+=(const Variable& other);
    virtual Variable& operator+=(const char* other);
    //virtual bool  operator==(const Variable& other);
    virtual bool operator==(const char* other);
    //virtual char*  operator+(const Variable& other);
    virtual char* operator+(const char* other);
    virtual string getLbl(){return m_value;};

    //friend ostream& operator<<(ostream& out, IntVar& v);
};


#endif //ASSIGN4_INTVAR_H