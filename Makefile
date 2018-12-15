scriptRunner: main.o ScrRunner.o ArrayVar.o BoolArr.o IntArr.o StringVar.o BoolVar.o IntVar.o Variable.o VariableNotFoundException.o BadVariableTypeException.o ArrayOutOfBoundException.o RunnerException.o 
	g++ -std=c++11 ScrRunner.o ArrayVar.o BoolArr.o IntArr.o StringVar.o BoolVar.o IntVar.o Variable.o VariableNotFoundException.o BadVariableTypeException.o 		ArrayOutOfBoundException.o RunnerException.o -o scriptRunner

main.o: main.cpp ScrRunner.h Variable.h RunnerException.h VariableNotFoundException.h BadVariableTypeException.h ArrayOutOfBoundException.h StringVar.h BoolVar.h IntVar.h ArrayVar.h IntArr.h
	g++ -std=c++11 main.cpp

ScrRunner.o: ScrRunner.cpp ScrRunner.h Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h StringVar.h BoolVar.h IntVar.h ArrayVar.h IntArr.h
	g++ -std=c++11 ScrRunner.cpp

BoolArr.o: BoolArr.cpp BoolArr.h ArrayVar.h Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h IntVar.h BoolVar.h StringVar.h
	g++ -std=c++11 BoolArr.cpp

IntArr.o: IntArr.cpp IntArr.h ArrayVar.h Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h IntVar.h BoolVar.h StringVar.h
	g++ -std=c++11 IntArr.cpp

ArrayVar.o: ArrayVar.cpp ArrayVar.h Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h IntVar.h BoolVar.h StringVar.h
	g++ -std=c++11 ArrayVar.cpp

StringVar.o: StringVar.cpp StringVar.h Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h
	g++ -std=c++11 StringVar.cpp

BoolVar.o: BoolVar.cpp BoolVar.h Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h
	g++ -std=c++11 BoolVar.cpp

IntVar.o: IntVar.cpp IntVar.h Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h
	g++ -std=c++11 IntVar.cpp

Variable.o: Variable.cpp Variable.h VariableNotFoundException.h RunnerException.h BadVariableTypeException.h ArrayOutOfBoundException.h
	g++ -std=c++11 Variable.cpp

VariableNotFoundException.o: VariableNotFoundException.h RunnerException.h
	g++ -std=c++11 VariableNotFoundException.cpp

BadVariableTypeException.o: BadVariableTypeException.h RunnerException.h
	g++ -std=c++11 BadVariableTypeException.cpp

ArrayOutOfBoundException.o: ArrayOutOfBoundException.h RunnerException.h
	g++ -std=c++11 ArrayOutOfBoundException.cpp

RunnerException.o: RunnerException.cpp RunnerException.h
	g++ -std=c++11 RunnerException.cpp

clean: 
	rm -rf *.o scriptRunner

