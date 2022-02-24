#!/bin/bash

for (( i=100; i>=0; i-- )); do
	num=$i
	if [ $i -le 9 ]; then
		num='0'$num
	fi
	pos_path="../data/pos_"$num
	
	if [[ -f "$pos_path"_in.txt && -f "$pos_path"_out.txt && -w "$pos_path"_in.txt && -w "$pos_path"_out.txt ]]; then
		new_num=$((num+1))
		if [ $i -le 9 ]; then
			new_num='0'$new_num
		fi
		mv "$pos_path"_in.txt "../data/pos_"$new_num"_in.txt"
		mv "$pos_path"_out.txt "../data/pos_"$new_num"_out.txt"
	fi
done

for (( i=100; i>=0; i-- )); do
	num=$i
	if [ $i -le 9 ]; then
		num='0'$num
	fi
	neg_path="../data/neg_"$num
        
	if [[ -f "$neg_path"_in.txt && -f "$neg_path"_out.txt && -w "$neg_path"_in.txt && -w "$neg_path"_out.txt ]]; then		
		new_num=$((num+1))
		if [ $i -le 9 ]; then
			new_num='0'$new_num
		fi
		mv "$neg_path"_in.txt "../data/neg_"$new_num"_in.txt"
		mv "$neg_path"_out.txt "../data/neg_"$new_num"_out.txt"
	fi
done
