
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "RunnerException.h"

using namespace std;

#ifndef ASS4_ARRAYOUTOFBOUNDEXCEPTION_H
#define ASS4_ARRAYOUTOFBOUNDEXCEPTION_H



class ArrayOutOfBoundException: public RunnerException {

public:
    ArrayOutOfBoundException():RunnerException("ArrayOutOfBoundException in Line:"){};
    //~ArrayOutOfBoundException(){};

};


#endif //ASS4_ARRAYOUTOFBOUNDEXCEPTION_H