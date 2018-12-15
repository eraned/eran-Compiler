
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "RunnerException.h"

using namespace std;

#ifndef ASS4_VARIABLENOTFOUNDEXCEPTION_H
#define ASS4_VARIABLENOTFOUNDEXCEPTION_H


class VariableNotFoundException: public RunnerException{

public:
    VariableNotFoundException():RunnerException("VariableNotFoundException in Line:"){};
    //~VariableNotFoundException(){};
};


#endif //ASS4_VARIABLENOTFOUNDEXCEPTION_H