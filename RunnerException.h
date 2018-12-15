//
// Created by ise on 14/01/18.
//
#include <exception>
#include <string>
#include <iostream>
#include <string>

using namespace std;

#ifndef ASSIGN4_RUNNEREXCEPTION_H
#define ASSIGN4_RUNNEREXCEPTION_H

class RunnerException:public exception{
public:
    static int lineNumber;
    RunnerException(){};
    RunnerException(string massage){msg=string(massage)+to_string(getLineNumber());};
    //~RunnerException(){};
    static void plusLineNumber(){lineNumber++;};
    static int getLineNumber(){return lineNumber;};
    string msg;
    virtual void handle() const throw(){cout<<msg<<endl;};
};


#endif //ASSIGN4_RUNNEREXCEPTION_H
