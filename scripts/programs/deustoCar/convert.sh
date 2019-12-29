#!/bin/bash
FILENAME=$1
if [ "$FILENAME" ]
then
	clang++ -std=c++11 -stdlib=libc++ $FILENAME.cpp && ./a.out
else
	echo "Required filename"
fi