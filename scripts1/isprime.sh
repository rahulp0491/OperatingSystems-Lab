#! /bin/bash
# Check if a number is prime

echo "Enter a number: "
read n
h=`expr $n / 2`
i=2

while [ $i -lt $h ]
do	
	a=`expr $n % $i`
	if [ $a -eq 0 ]
	then
		echo "Composite"
		break
	fi
	i=`expr $i + 1`
done

if [ $i -eq $h ]
then
	echo "Prime"
fi


