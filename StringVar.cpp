
#include "StringVar.h"


Variable &StringVar::operator=(const char *other) {
    //needed more case check
    if ((other[0]=='"')&&(other[strlen(other)-1]=='"')) {
        setValue(other);
    } else throw BadVariableTypeException();
}

bool StringVar::operator==(const char *other) {
    if(other[0]=='"'){
        string myValue = getValue();
        return (myValue.compare(other) == 0);
    }
    else{
        throw BadVariableTypeException();
    }
}
/*
ostream& operator<<(ostream& out, Variable& v){
    out<<v.getValue();
}
*/
void StringVar::print() const {
    cout<<getValue()<<endl;;
}

void StringVar::setValue(const char *str) {
    if (str[0] == '"')
    {
        std::string s = string(str);
        char const *pchar = s.c_str();
        if (m_value)
            free(m_value);
        char* tmp;
        tmp = strdup(pchar);
        m_value = tmp;
    }
    else
    {
        throw BadVariableTypeException();
    }
}

string StringVar::getLbl() {
    string retPrint = string(m_value);
    retPrint.erase(remove(retPrint.begin(), retPrint.end(), '\"'), retPrint.end());
    return retPrint;

}

StringVar::~StringVar(void) {
    free(m_value);
    //free(m_name);
}
