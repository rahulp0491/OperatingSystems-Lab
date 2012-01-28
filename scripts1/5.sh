#! /bin/bash
# To generate all combinations of 1, 2 and 3 using for loops.


for val1 in 1 2 3 
do
	for val2 in 1 2 3
	do
		for val3 in 1 2 3
		do
			if [ $val1 -ne $val2 -a $val2 -ne $val3 -a $val3 -ne $val1 ]
			then
				echo "$val1 $val2 $val3"
			fi
		done
	done
done
