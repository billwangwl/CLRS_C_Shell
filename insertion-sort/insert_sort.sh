#!/bin/bash

arr=(8 7 6 5 4 3 2 1)
i=1

while [ $i -lt ${#arr[*]} ]
do
	key=${arr[$i]}
	m=$i
	while [ $m -gt 0  ] && [ $key -lt ${arr[$(($m-1))]} ]
	do
		arr[$m]=${arr[$(($m-1))]}
		m=$(($m-1))
	done

	arr[$m]=$key;
	i=$(( $i + 1 ))
done

echo ${arr[*]}
