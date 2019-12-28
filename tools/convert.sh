#!/bin/bash
FILENAME=$1
if [ "$FILENAME" ]
then
	make $FILENAME
else
	echo "Required filename"
fi