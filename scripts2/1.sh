#! /bin/bash 
# Display month name

if [ $1 -gt 12 ]
then
	echo "Invalid argument"
else
	date -d "01-$1-01" +%B
fi
