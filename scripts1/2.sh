#! /bin/bash
# To find whether a given number is even or odd.

echo "Enter the number: "
read n

if [ `expr $n % 2` -eq 0 ]
then
	echo "Even"
else
	echo "Odd"
fi
