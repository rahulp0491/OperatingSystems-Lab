#! /bin/bash


if [ $# -ne 1 ]
then
	echo "Error: Insufficient arguments"
else
	if [ ! -d $1 ]
	then
		if [ -f $1 ]
		then
			rm $1
		fi
		mkdir $1
	else
		echo "Directory already exists"
	fi
fi
