//
// Created by ise on 10/01/18.
//

#include "BoolVar.h"

void BoolVar::setValue(const char* flag)
{
    if (strcmp(flag, "true") == 0 || strcmp(flag, "false") == 0)
    {
        free(m_value);
        m_value = strdup(flag);
    }
    else
        throw BadVariableTypeException();
}


ostream& operator<<(ostream& out, Variable& v){
    out<<v.getValue();
}

/*void BoolVar::print() const
{
    cout<<getValue()<<endl;;
}*/

/*
Variable &BoolVar::operator=(const Variable &other) {
   if(other.m_type=="boolVale"){
       char* flag=other.getValue();
     setValue(other.getValue());
   }
    else throw BadVariableTypeException(000);
}
 */

Variable &BoolVar::operator=(const char* other)
{
    if (strcmp(other, "true") || strcmp(other, "false"))
    {
        setValue(other);
    }
    else{
        throw BadVariableTypeException();
    }
}

    bool BoolVar::operator==(const char *other)
{
    if ((strcmp(other, "true") == 0) || (strcmp(other, "false")==0))
    {
        string myValue = getValue();
        return (strcmp(other, myValue.c_str()) == 0);
    }
    else
    {
        throw BadVariableTypeException();
    }
}

BoolVar::~BoolVar(void) {
    free(m_value);
    //free(m_name);
}



