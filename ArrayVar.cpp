//
// Created by ise on 10/01/18.
//

#include "ArrayVar.h"

void ArrayVar::setValue(const char *value) {
    int arraySize = 0;
    char *tmp = strdup(value);
    tmp = strtok(tmp, "]"); // removes '['
    memmove(tmp, tmp + 1, strlen(tmp)); // removes ']'
    std::queue<char*> VariablesValue;
    char *pch = strtok(tmp, ",");
    while (pch != NULL) {
        arraySize++;
        VariablesValue.push(pch);
        pch = strtok(NULL, ",");
    }
    setSize(arraySize);
    try{
        createArray(VariablesValue);
        free(tmp);
    }
    catch(RunnerException& e)
    {
        free(tmp);
        throw e;
    }

}

string ArrayVar::getLbl() {
    string retPrint;
    int i=0;
    for (i=0; i<m_size-1; i++){
        retPrint.append(getElement(i).getLbl());
        retPrint.append(", ");
    }
    retPrint.append(getElement(i).getLbl());
    return retPrint;
}

ArrayVar::~ArrayVar() {

}



