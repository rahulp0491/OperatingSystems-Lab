#! /bin/bash
# Move all hidden file from a given directory to a newly created directory.

fileCount=0

if [ $# -ne 2 ]
then
	echo "Error: Insufficient arguments"
else
	if [ -d $1 -a -d $2 ]
	then
		for file in `ls -a $1 | grep "^\."`
		do	
			if [ ! -d $file ]
			then
				fileCount=`expr $fileCount + 1`
				mv $file $2
				echo "$file moved"
			fi
		done
		echo "$fileCount files moved in total"
	else
		echo "Error: No such directory"
	fi
fi
