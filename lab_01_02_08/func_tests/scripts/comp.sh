#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Expected 2 arguements"
	exit 100
fi

baseline="$0"

./tmp_prog.exe < "$1" > output.txt
`grep -Eo '[+-]?([0-9]*[.])?[0-9]+' output.txt > tmp.txt`
# cat tmp.txt
if [ -z "$(diff tmp.txt "$2")" ]; then
	echo "PASS"
else
	echo "FAIL"
fi

rm -f output.txt tmp.txt
