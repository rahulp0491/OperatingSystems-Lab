#! /bin/bash 
# To print the contents of a file from a given line number to another given line number.


if [ $# -ne 3 ]
then
	echo "Error: Insufficient arguments"
else
	lineCount=0
	while read line
	do	
		lineCount=`expr $lineCount + 1`
		if [ $lineCount -ge $2 -a $lineCount -le $3 ]
		then
			echo $line
		fi
	done < $1
fi
