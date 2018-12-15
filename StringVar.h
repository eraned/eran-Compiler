

#ifndef ASS4_STRINGVAR_H
#define ASS4_STRINGVAR_H

#include <algorithm>
#include "Variable.h"
#include "BadVariableTypeException.h"

class StringVar : public Variable{

protected:
    char* m_value = NULL;//str value
public:
    StringVar(void):Variable(){};
    StringVar(char* name1, char* value):Variable(((char*)"stringValue"), name1){setValue(value);};
    StringVar(char* value1):Variable(((char*)"StringVar"), value1){setValue(value1);};
    virtual ~StringVar(void);
    void setValue(const char* str);
    const char* getValue()const{return m_value;};
    virtual Variable& operator=(const char* other);
    virtual bool operator==(const char* other);
    virtual string getLbl();


    virtual void print() const;

};


#endif //ASS4_STRINGVAR_H