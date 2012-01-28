#! /bin/bash
# To check whether the two file contents are same or not. Given two file names as arguments.

if [ $# -ne 2 ]
then
	echo "Error: Insufficient arguments"
else
	if [ -r $1 -a -r $2 ] 
	then
		content1=`cat $1`
		content2=`cat $2`
	
		if [ "$content1" == "$content2" ]
		then
			echo "Contents are same"
		else
			echo "Contents are not the same"
		fi
	else
		echo "Can't read file"
	fi
fi

