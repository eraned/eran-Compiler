
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "RunnerException.h"

using namespace std;

#ifndef ASS4_BADVARIABLETYPEEXCEPTION_H
#define ASS4_BADVARIABLETYPEEXCEPTION_H


class BadVariableTypeException:public RunnerException {

public:
    BadVariableTypeException():RunnerException("BadVariableTypeException in Line:"){};
    //~BadVariableTypeException(){};
};


#endif //ASS4_BADVARIABLETYPEEXCEPTION_H