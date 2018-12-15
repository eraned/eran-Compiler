cmake_minimum_required(VERSION 3.9)
project(Assign4)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assign4 main.cpp Variable.cpp Variable.h StringVar.cpp StringVar.h BoolVar.cpp BoolVar.h IntVar.cpp IntVar.h ArrayVar.cpp ArrayVar.h ScrRunner.cpp ScrRunner.h BadVariableTypeException.h VariableNotFoundException.h ArrayOutOfBoundException.h RunnerException.cpp RunnerException.h IntArr.cpp IntArr.h BoolArr.cpp BoolArr.h StringArr.cpp StringArr.h)