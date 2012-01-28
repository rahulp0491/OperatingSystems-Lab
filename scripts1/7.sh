#! /bin/bash
# To print numbers from 1 to 10 using until contruct.

num=1

until [ $num -gt 10 ]
do
	echo $num
	num=`expr $num + 1`
done
