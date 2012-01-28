#! /bin/bash
# To read a directory name as a command line argument and delete all files in that directory whose size is 0 bytes

if [ $# -ne 1 ]
then
	echo "Error: Insufficient arguments"
else
	dir=$1
	fileCount=0

	if [ -d ${dir} ]
	then
		for file in `ls ${dir}`
		do	
			if [ -e ${dir}/$file -a -f ${dir}/$file ]
			then 
				if [ ! -s ${dir}/$file ]
				then
					fileCount=`expr $fileCount + 1`
					rm ${dir}/$file
					echo "Deleted ${dir}/$file"
				fi
			fi
		done
		echo "$fileCount files Deleted"
	else
		echo "Error: Not a valid directory"
	fi
fi
