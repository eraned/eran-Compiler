#include <iostream>
#include "ScrRunner.h"

using namespace std;

int RunnerException::lineNumber = 1;

int main(int argc, char* argv[]) {
    ScrRunner* runner = new ScrRunner();
    runner->sendFile(argv[1]);
    //runner->sendFile();
    delete(runner);
    return 0;
}
