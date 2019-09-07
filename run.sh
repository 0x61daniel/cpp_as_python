#!/bin/bash


g++ split.cpp  -std=c++11 -fpic -shared -o libsplit.so

g++ test.cpp  -I ./ -L ./ -l split -o app -std=c++11
