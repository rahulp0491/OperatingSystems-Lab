#! /bin/bash
# To compare two given numbers and print the largest. Give the numbers as input from the command line

echo "Enter the 1st number: "
read n1
echo "Enter the 2nd number: "
read n2

if [ $n1 -ne $n2 ] 
then	
	if [ $n1 -lt $n2 ]
	then 
		echo "The larger number is: $n2"
	else
		echo "The larger number is: $n1"
	fi
else
	echo "Both the numbers are equal"
fi
