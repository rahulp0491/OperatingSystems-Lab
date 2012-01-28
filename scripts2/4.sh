#! /bin/bash
# Calculator

function add {
	echo `expr $1 + $2`
}

function sub {
	echo `expr $1 - $2`
}

function mul {
	echo `expr $1 \* $2`
}

function div {
	echo `expr $1 / $2`
}

echo "Operator: "
read op
echo "Operand 1: "
read a
echo "Operand 2: "
read b
echo "Result: "

case $op in 
	 +) add $a $b ;;
	 -) sub $a $b ;; 
	\*) mul $a $b ;;
	 /) div $a $b ;;
	 *) echo "Invalid operation"	
esac 
