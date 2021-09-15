#!/bin/bash

input="./file.txt"
count=0
while IFS= read -r line || [ -n "$line" ];
do
	let count++
	if [ $count -eq 10 ]
	then
		echo $line
		exit 0
	fi
	lastLine=$line
done < $input

# another approach -> sed (stream editor) command
# sed -n 10p file.txt