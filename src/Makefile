
output: main.o osdetector.o
	g++ main.o osdetector.o -o output
	
main.o: main.cpp
	g++ -c main.cpp
	
osdetector.o: osdetector.cpp osdetector.h
	g++ -c osdetector.cpp
	
clean:
	rm *.o