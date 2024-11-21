LargestRectangle: LargestRectangle.o
	g++ -g -o LargestRectangle.exe LargestRectangle.o -pthread    

LargestRectangle.o: LargestRectangle/LargestRectangle.cpp
	g++ -g  -c -pthread LargestRectangle/LargestRectangle.cpp
