exe: Ensemble.o TEnsemble.o
	g++ -o exe Ensemble.o TEnsemble.o

Ensemble.o: Ensemble.h Ensemble.cpp
	g++ -c -Wall Ensemble.cpp

TEnsemble.o: TEnsemble.cpp
	g++ -c -Wall TEnsemble.cpp
