#!/bin/bash

if [ $# -eq 1 ]; then
	if [ $1 == '-r' ]; then
		rm -f main.c main.gcno main.gcda main.c.gcov tmp_prog.exe
		rm -f output.txt tmp.txt
		exit 0
	fi
fi

cp -f ../../main.c ./
rm -f main.gcno main.gcda tmp_prog.exe
`gcc -std=c99 -Wall -Werror -Wpedantic -Wextra --coverage -O0 main.c -o tmp_prog.exe -lm`

for (( i=0; i<100; i++ )); do
        num=$i
        if [ $i -le 9 ]; then
                num='0'$num
        fi
        pos_path="../data/pos_"$num
        neg_path="../data/neg_"$num
	
	if [[ -f "$pos_path"_in.txt && -f "$pos_path"_out.txt && -r "$pos_path"_in.txt && -r "$pos_path"_out.txt ]]; then
		echo -n "Test_pos_"$num': '
                ./comp.sh "$pos_path"_in.txt "$pos_path"_out.txt
        fi
        if [[ -f "$neg_path"_in.txt && -f "$neg_path"_out.txt && -r "$neg_path"_in.txt && -r "$neg_path"_out.txt ]]; then
                echo -n "Test_neg_"$num': '
                ./comp.sh "$neg_path"_in.txt "$neg_path"_out.txt
        fi
done
