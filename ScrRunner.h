//
// Created by ise on 11/01/18.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "Variable.h"
#include "StringVar.h"
#include "BoolVar.h"
#include "IntVar.h"
#include "ArrayVar.h"
#include "IntArr.h"
#include "BoolArr.h"
#include "StringArr.h"
#include <queue>
#include <algorithm>
#include "RunnerException.h"
#include "VariableNotFoundException.h"
#include "BadVariableTypeException.h"
#include "ArrayOutOfBoundException.h"
#ifndef ASSIGN4_SCRRUNNER_H
#define ASSIGN4_SCRRUNNER_H
#define NUM_OF_DELIMS 8
#define NUM_OF_OPERATORS 4
using namespace std;
enum ValueType{intValue, boolValue, stringValue, arrayValue, varNameValue};

class ScrRunner {

public:
    vector<Variable*> VarsVector;
    char delim[NUM_OF_DELIMS] = {'=', '+', '(', '{', '}', '\0'}; //')', ' ', ,  '[', ']'
    //string operators[NUM_OF_OPERATORS] = {"==", "+=", "=", "+"};
    ScrRunner(){};

    bool VarExist(const char* name, Variable** var);

    bool AnalyzeLineCommands(queue<char*> commands);

    bool SplitLine(char* line);

    void PrintCommand(const char* line);

    void AnalyzeAssignCommand(char* var, const char* value);

    void AnalyzeHelper(queue<char*>& commands, const char* lastValue);

    void AddVariable(Variable &var);

    const char* GetValue(const char* ValuePartLine);

    ValueType GetValueType(const char* ValuePartLine);

    string getOpsString(char *line);

    //void sendFile();

    void sendFile(char* file_);


};


#endif //ASSIGN4_SCRRUNNER_H
