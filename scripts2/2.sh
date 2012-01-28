#! /bin/bash
# Find factorial of a number

function fact {
	if [ $1 -lt 2 ]
	then
		echo 1
	else
		y=`expr $1 - 1`
		echo `expr $1 \* $(fact $y)`
	fi
}

fact $1


