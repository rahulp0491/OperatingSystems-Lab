#! /bin/bash 
# bfs of directory tree with the first level of the tree marked as 0, second as 1 and so on...

if [ $# -ne 1 ]
then
	echo "Error: Insufficient arguments"
else
	level=0
	cd $1
	var=$PWD

	until [ "$var" == "" ]
	do
			echo "Level $level:"
			echo $var
			level=`expr $level + 1`
			var=$(find -maxdepth $level -mindepth $level -type d)
	done
fi
