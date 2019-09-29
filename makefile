

Demo: Demo.cpp libPyString.so
	g++ Demo.cpp -I ./ -L ./ -l PyString -std=c++11 -Wall -o Demo

libPyString.so: PyString.cpp PyString.h 
	g++ PyString.cpp  -std=c++11 -fpic -shared -o libPyString.so


.PHONY: clear
clear:
	-rm Demo libPyString.so
	@echo "finish"

.PHONY: so
so: PyString.cpp
	g++ PyString.cpp  -std=c++11 -fpic -shared -o libPyString.so

