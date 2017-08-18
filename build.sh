#!/bin/bash
g++ main.cpp -o notes -lncurses

if [ $? -eq 0 ]
then
	./notes
else
	echo "Build failed" >&2
fi
