//
// Created by ise on 10/01/18.
//

#include "IntVar.h"


ostream& operator<<(ostream& out, IntVar& v){
    out<<v.getValue();
    //out<<v.getValue();
}

void IntVar::setValue(const char* value) {
    if (isdigit(value[0])) {
        int intValue = atoi(value);
        std::string s = std::to_string(intValue);
        char const *pchar = s.c_str();
        if (m_value)
            free(m_value);
        char* tmp;
        tmp = strdup(pchar);
        m_value = tmp;
    }
    else{
        throw BadVariableTypeException();
    }
}

void IntVar::print() const {
    cout<<getValue()<<endl;
}


Variable &IntVar::operator=(const char* other) {
    if(isdigit(other[0]))
    {
        setValue(&other[0]);
    }
    else throw BadVariableTypeException();
}


Variable& IntVar::operator+=(const char* other) {
    if (isdigit(other[0])) {
        int myValue = atoi(getValue());
        int otherValue = atoi(&other[0]);
        int sumValue = myValue + otherValue;
        string stringSumValue = to_string(sumValue);
        setValue(&stringSumValue[0]);
    } else throw BadVariableTypeException();

}

bool IntVar::operator==(const char* other) {
    if (isdigit(other[0])) {
        int myValue = atoi(getValue());
        int otherValue = atoi(&other[0]);
        if (myValue == otherValue)
            return true;
        else
            return false;
    } else throw BadVariableTypeException();
}


char* IntVar::operator+(const char* other)
{
    if (isdigit(other[0]))
    {
        int myValue = atoi(getValue());
        int otherValue = atoi(&other[0]);
        int sumValue = myValue + otherValue;
        string stringSumValue = to_string(sumValue);
        return &(stringSumValue[0]);
    } else throw BadVariableTypeException();
}

IntVar::~IntVar(void) {
    free(m_value);
}







