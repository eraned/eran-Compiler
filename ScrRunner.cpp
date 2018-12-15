//
// Created by ise on 11/01/18.
//
#include "ScrRunner.h"
#include <list>
using namespace std;


ValueType ScrRunner::GetValueType(const char* ValuePartLine)
{
    if (isdigit(ValuePartLine[0]))
        return intValue;
    else if (strlen(ValuePartLine) > 4 && (strcmp((((string)ValuePartLine).substr(0,5)).c_str(),"false") == 0)
             || (strcmp((((string)ValuePartLine).substr(0,4)).c_str(),"true") == 0))
        return boolValue;
    else if (isalpha(ValuePartLine[0]))
        return varNameValue;
    else if (ValuePartLine[0]=='"')
        return stringValue;
    else if (ValuePartLine[0]=='[')
        return arrayValue;
}

bool ScrRunner::VarExist(const char* name, Variable** tmp) {
    /* checks if array */
    bool isArray = false;
    int index = 0;
    string s = string(name);
    size_t found = s.find("[");
    if (found!=0)
    {
        size_t found1;
        if (found != string::npos)
        {
            found1 = s.find("]");
            string tmp = string(name, found+1, found1-1);
            if (isdigit(tmp[0]))
                index = atoi(tmp.c_str());
            else // if the index is init var. for example:
                /* a=2
                 * arr=[1,2,3]
                 * arr[a]=a
                 */
            {
                tmp = strtok(&tmp[0], "]");
                const char* checkIfLegal = GetValue(tmp.c_str());
                if (!isdigit(checkIfLegal[0]))
                    throw BadVariableTypeException();
                else
                    index = atoi(GetValue(tmp.c_str()));
            }
            name = strtok(&s[0], "[");
            isArray=true;
        }
    }

    vector<Variable*>::iterator it;
    for (it=VarsVector.begin(); it!=VarsVector.end(); ++it)
    {
        Variable* var;
        var=*(it);
        if (strcmp(name, var->getName()) == 0)
        {
            if (isArray==true)
            {
                ArrayVar* array = dynamic_cast<ArrayVar*>(*it);
                if (array)
                    *tmp = &array->getElement(index);
                //*tmp=&it[index][index];
                //Variable* tmp = &tmp[index];
               // (*(tmp))->operator[](index);

            } else
                *tmp=(*(it));
            return true;
        }
    }
    //free(&s[0]);
    return false;
}

/* This method accepts a string that should represent a value.
 * The method makes sure that the value returned is in its final state.
 * */
const char* ScrRunner::GetValue(const char* var)
{
    Variable *tmp;
    if(VarExist(var,&tmp))
    {
        const char* temp = tmp->getValue();
        //delete(&tmp);
        return temp;
    }
    else
    {
        //delete(&tmp);
        return var;
    }

}

void ScrRunner::AddVariable(Variable& var)
{
    VarsVector.push_back(&var);
}

/* This method analyzes a line after it is knows that this is an assign command.
 * @param line is the current line
 * @param i is the index of '=' in the current line*/
void ScrRunner::AnalyzeAssignCommand (char* var1, const char* value){
    int valueType;
    valueType = GetValueType(value);
    Variable *tmp;
    if(VarExist(var1,&tmp))
    {
        (*(tmp))=value;
        return;
    }
    char* tmpVal = strdup(value);
    char* tmpName = strdup(var1);
    try {
    if (valueType == intValue)
    {
        Variable* newIntVar;
        newIntVar = new IntVar(tmpName,tmpVal);
        AddVariable(*newIntVar);
    }
    else if (valueType == boolValue)
    {
        Variable* newBoolVar;
        newBoolVar = new BoolVar(tmpName, tmpVal);
        AddVariable(*newBoolVar);
    }
    else if (valueType == stringValue)
    {
        Variable* newStrVar;
        newStrVar = new StringVar(tmpName, tmpVal);
        AddVariable(*newStrVar);
    }
    else if (valueType == arrayValue)
    {
        string tmp = string(tmpVal);
        Variable* newArr;
        if (tmp.find('\"') != std::string::npos)
            newArr = new StringArr(tmpName, tmpVal);
        else if ((tmp.find("false") != std::string::npos) || (tmp.find("true") != std::string::npos))
            newArr = new BoolArr(tmpName, tmpVal);
        else
            newArr = new IntArr(tmpName, tmpVal);
        AddVariable(*newArr);
    }
        free(tmpVal);
        free(tmpName);
    }
    catch(RunnerException& e)
    {
        free(tmpVal);
        free(tmpName);
        throw e;
    }
}


/* This method analyzes a rest of line after it is knows that this is a print command
 * The string this method gets is without the 'print' but with '(' ')' */
void ScrRunner::PrintCommand (const char* var) {
    std::queue<char *> printQueue;
    char *printPch;
    char *printTmp;
    printTmp = strdup(var);
    memmove(printTmp, printTmp+1, strlen(printTmp));
    printTmp = strtok(printTmp, ")");
    if (string(printTmp).find("==") != string::npos)
    {
        bool flag = SplitLine(printTmp);
        if (flag==false)
            cout<<"false"<<endl;
        else
            cout<<"true"<<endl;
        free(printTmp);
        return;
    }
    printPch = strtok(printTmp, delim);
    while (printPch != NULL) {
        printQueue.push(printPch);
        printPch = strtok(NULL, delim);
    }
    string retPrint = "";
    int sum = 0;
    try{
    if (isdigit(printQueue.front()[0]) || isdigit(GetValue(printQueue.front())[0]))
    {
        while (!printQueue.empty())
        {
            if (isdigit(printQueue.front()[0]))
            {
                sum += atoi(&(printQueue.front()[0]));
                printQueue.pop();
            }
            else
            {
                sum += atoi((GetValue(&(printQueue.front()[0]))));
                printQueue.pop();
            }
        }
        retPrint+=to_string(sum);
    }
    else if (isalpha(printQueue.front()[0]))
    {
        while (!printQueue.empty())
        {
            Variable* tmp;
            if(VarExist(printQueue.front(), &tmp))
            {
                retPrint+=tmp->getLbl();
                printQueue.pop();
            }
            else
            {
                if((GetValueType(GetValue(printQueue.front()))!=varNameValue))
                {
                    retPrint+=GetValue(printQueue.front());
                    printQueue.pop();
                }
                else
                {
                    free(printTmp);
                    throw VariableNotFoundException();
                }
            }
        }
    }
    else if ((printQueue.front()[0]) == '"')
    {
        string toPrint = printQueue.front();
        toPrint.erase(remove(toPrint.begin(), toPrint.end(), '\"'), toPrint.end());
        retPrint = toPrint;
    }
    cout<<retPrint<<endl;
    free(printTmp);
    }
    catch(RunnerException& e)
    {
        free(printTmp);
        throw e;
    }
}

void ScrRunner::AnalyzeHelper(queue<char*>& commands, const char* lastValue)
{
    queue<char*> tmpQueue;
    while (!commands.empty())
    {
        tmpQueue.push(commands.front());
        commands.pop();
    }
    commands.push(&(string(lastValue)[0]));
    while (!tmpQueue.empty())
    {
        commands.push(tmpQueue.front());
        tmpQueue.pop();
    }
}



bool ScrRunner::AnalyzeLineCommands(queue<char*> commands)
{
    bool flag;
    while (commands.size()>1)
    {

        if (strcmp(commands.front(),"print") == 0)
        {
            //delete(commands.front());
            commands.pop();
            char* var = commands.front();
            commands.pop();
            try
            {
                PrintCommand(var);
                free(var);
            }
            catch(RunnerException& e)
            {
                free(var);
                throw;
            }
        }
        else if (strcmp(commands.front(),"if") == 0)
        {
            commands.pop();
            char* condition = commands.front();
            commands.pop();
            memmove(condition, condition+1, strlen(condition));
            condition = strtok(condition, ")");
            if (SplitLine(condition))
            {
                char* if_Command = commands.front();
                commands.pop();
                SplitLine(if_Command);
                free(if_Command);
            }
            else
            {
                commands.pop();
                if(commands.size()>=1)
                { // there is 'else' command
                    SplitLine(commands.front());
                    commands.pop();
                }
            }
            //free(condition);
        }
        else if(strcmp(commands.front(),"true") == 0)
            return true;
        else if (strcmp(commands.front(),"false") == 0)
            return false;

            /* assign '=' '+=' / compare '==' */
        else
        {
            char *var1_name = commands.front();
            commands.pop();
            char *curr_op = commands.front();
            commands.pop();
            char *var2_ = commands.front();
            commands.pop();
            if (strcmp(curr_op, "=") == 0)
            {
                const char *value = GetValue(var2_);
                AnalyzeAssignCommand(var1_name, value);
            }

            else if (strcmp(curr_op,"+=") == 0) {
                commands.pop();
                const char *value = GetValue(var2_);
                Variable *var1;
                /* The variable to the left of the operator is exist as variable.  */
                if (VarExist(var1_name, &var1)) {
                    /*example: boolVar+=4 */
                    if (GetValueType(GetValue(var1_name)) != 0)
                        throw BadVariableTypeException();
                    /* example: initIntVar+=NotInitVar*/
                    else if (GetValueType(value) == varNameValue)
                        throw VariableNotFoundException();
                        /*example: intVar+=3
                         * The implementation of the operator '+=' in IntVar class will throw if var2 isn't int type*/
                    else
                        *var1 += value;
                }

                    /* The variable to the left of the operator isn't exist */

                    /* Enter if the value to the left of the operator is VarName. for example:
                     * NotInitVar+=4
                     * */
                else if (GetValueType(var1_name) == varNameValue)
                    throw VariableNotFoundException();
                    /*
                     * false+=4
                     */
                else if (GetValueType(var1_name) == boolValue)
                    throw BadVariableTypeException();

                    /* If we got to this point then var1 necessarily number */
                else {
                    IntVar *tmpInt = new IntVar(var1_name, var1_name);
                    *tmpInt += value;
                    //delete (tmpInt);
                }
            }

            else if (strcmp(curr_op,"==") == 0)
            {
                bool compareFlag;
                const char *value = GetValue(var2_);
                Variable *var1;
                if (!VarExist(var1_name, &var1))
                {
                    if(strcmp(var1_name, value) == 0)
                        compareFlag = true;
                }
                else
                    compareFlag = ((*(var1)==value));

                if ((commands.size()>1) && ((strcmp(commands.front(), "==")) == 0))
                {
                if (compareFlag)
                    AnalyzeHelper(commands, (char*)("true"));
                else
                    AnalyzeHelper(commands, (char*)("false"));
                }
                else return compareFlag;
            }// +
            else if (strcmp(curr_op,"+") == 0)
            {
                //commands.pop();
                const char *var2_value = GetValue(var2_);
                const char *var1_value = GetValue(var1_name);
                Variable *var1;
                if (VarExist(var1_name, &var1))
                {
                    const char* sumValue = *var1+var2_value;
                    //delete(var1);
                    if (!(commands.size()==1))
                        AnalyzeHelper(commands, sumValue);
                }
                else if ((GetValueType(var1_value) == 0) && (GetValueType(var2_value) == 0))
                {
                    const char* sumValue = (to_string(atoi(var1_value)+atoi(var2_value))).c_str();
                    if (!(commands.size()==1))
                        AnalyzeHelper(commands, sumValue);
                }
                /* If there is an attempt to use the operator '+' on non-int variables .*/
                else
                    throw BadVariableTypeException();
            }
        }
        if (commands.size()==1)
        {
            commands.pop();
            return flag;
        }
    }
}


string ScrRunner::getOpsString(char* tmp)
{
    string ops;
    int i = 0;
    while (tmp[i] != '#' && tmp[i] != '\0')
    {
        while (tmp[i] != '=' && tmp[i] != '#' && tmp[i] != '\0'
               && tmp[i] != '+')
        {
            i++;
        }
        if (tmp[i] == '#' || tmp[i] == '\0')
            break;
        if (tmp[i] == '+')
        {
            if (tmp[i+1] == '=')
            {
                ops+=" +=";
                i+=2;
            }
            else
            {
                ops+=" +";
                i+=1;
            }
        }
        else
        {
            if (tmp[i+1] == '='){
                ops+= " ==";
                i+=2;
            }
            else
            {
                ops+= " =";
                i+=1;
            }
        }
    }
    return ops;
}

bool ScrRunner::SplitLine(char* line) {
    std::queue<char*> namenumQueue;
    std::queue<char*> operatorsQueue;
    std::queue<char*> lineCommand;
    line = strtok(line, "#");
    char *pch;
    char* tmp;
    tmp = strdup(line);
    pch = strtok(line, delim);
    while (pch != NULL)
    {
        namenumQueue.push(pch);
        pch = strtok(NULL, delim);
    }
    string ops = getOpsString(tmp);
    char *opsToken;
    opsToken = strtok(&ops[0], " ");
    while (opsToken != NULL)
    {
        operatorsQueue.push(opsToken);
        opsToken = strtok(NULL, " ");
    }

    while(!namenumQueue.empty())
    {
        if (strcmp(namenumQueue.front(),"print") == 0)
        {
            lineCommand.push(namenumQueue.front());
            namenumQueue.pop();
            string toPrint = ((string(tmp).substr(string(tmp).find('('), string(tmp).find(')'))));
            //lineCommand.push(&toPrint[0]);
            lineCommand.push(strdup(toPrint.c_str()));
            while (((string)namenumQueue.front()).find(')') == std::string::npos)
                namenumQueue.pop();
            namenumQueue.pop();
        }
        else if(strcmp(namenumQueue.front(),"if") == 0)
        {
            lineCommand.push(namenumQueue.front());
            namenumQueue.pop();
            string tmpifCondition = ((string(tmp).substr(string(tmp).find('('), string(tmp).find(')'))));
            char* ifCondition = &(tmpifCondition[0]);
            lineCommand.push(&ifCondition[0]);
            string tmpifOperation = ((string(tmp).substr(string(tmp).find('{'), string(tmp).find('}'))));
            char* ifOperation = &(tmpifOperation[0]);
            ifOperation = strtok(ifOperation, "}"); // remove '{' of the if operation
            memmove(ifOperation, ifOperation+1, strlen(ifOperation)); // remove '}' of the if operation
            lineCommand.push(&ifOperation[0]);
            // if there is else statement
            size_t elseFound = string(tmp).find("else");
            if (elseFound != string::npos)
            {
                string elseCommand = ((string(tmp)).substr(elseFound+4, string::npos));
                char* elseOperation = strtok(&elseCommand[0], "}"); // remove '}' of the if operation
                memmove(&elseCommand[0], &elseCommand[0]+1, strlen(&elseCommand[0])); // remove '{' of the if operation
                lineCommand.push(&(string(elseCommand)[0]));
            }

            while(!namenumQueue.empty())
                namenumQueue.pop();
            while(!operatorsQueue.empty())
                operatorsQueue.pop();
            bool flag = AnalyzeLineCommands(lineCommand);
            free(tmp);
            return flag;
            break;
        }

        else
        {
            lineCommand.push(namenumQueue.front());
            namenumQueue.pop();
            lineCommand.push(operatorsQueue.front());
            operatorsQueue.pop();
        }
        //else if - if condition
    }
    try
    {
        bool flag = AnalyzeLineCommands(lineCommand);
        free(tmp);
        return flag;
    }
    catch(RunnerException& e)
    {
        free(tmp);
        throw e;
    }
}

void ScrRunner::sendFile(char* file_) {
    //file_ = "fib.txt";
    std::string line_;
    //file_+=".txt";
    ifstream file_c(file_);
    if (file_c.is_open()) {
        /* Sending line by line to analysis */
        while (getline(file_c, line_,'\n')) {
            //std::cout<<line_<<'\n'
            //cout << line_ << endl;
            try
            {
                SplitLine(&line_[0]);
            }
            catch(RunnerException& e)
            {
                e.handle();
                break;
            }
            RunnerException::plusLineNumber();
            //free(&line_);
        }
        file_c.close();
    } else cout << "Unable to open file";
    for (Variable* var : VarsVector)
        delete var;
    VarsVector.clear();
}


