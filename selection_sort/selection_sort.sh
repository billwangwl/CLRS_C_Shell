#!/bin/bash

A=( 7 8 6 4 3 2 1)

i=0

while [ $i -lt ${#A[*]} ]
do
	echo ${A[$i]}
	min=$i
	j=$(( $i + 1 ))
	while [ $j -lt ${#A[*]} ]
	do
		if [ ${A[$min]} -gt ${A[$j]} ]
		then
			min=$j
		fi
		j=$(( $j + 1 ))
	done

	if [ $min -ne $i ]
	then
		temp=${A[$i]}
		A[$i]=${A[$min]}
		A[$min]=$temp
	fi



	i=$(( $i + 1 ))
	
done
	
echo ${A[*]}
