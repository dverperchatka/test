#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Expected 2 arguements"
	exit 100
fi

baseline="$0"
./tmp_prog.exe < "$1" > output.txt
err_code="$?"
grep -Eo '[+-]?([0-9]*[.])?[0-9]+' output.txt > tmp.txt
if basename "$1" | grep -Eq 'pos'; then
	if [[ -z "$(diff tmp.txt "$2")" && "$?" == '0' ]]; then
		echo "PASS"
	else
		echo "FAIL"
	fi
else
	if ! [[ -s tmp.txt || "$err_code" != `cat "$2"` ]]; then
		echo "PASS"
	else
		echo "FAIL"
	fi
fi

rm -f output.txt tmp.txt
