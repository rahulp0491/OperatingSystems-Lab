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

function fact {
	if [ $1 -lt 2 ]
	then
		echo 1
	else
		y=`expr $1 - 1`
		echo `expr $1 \* $(fact $y)`
	fi
}

function pow {
	a=`expr $1 \* $1`
	b=`expr $1 \* $1`
	echo `expr $a \* $b`
}

function pow1 {
	i=0
	a=1
	while [ $i -lt $2 ]
	do
		a=`expr $1 \* $a`
		i=`expr $i + 1`
	done
	echo $a
}

echo "Operator: "
read op

case $op in 
	 +) echo "Operand 1: "
		read a
		echo "Operand 2: "
		read b
		echo "Result: "
		add $a $b ;;
	 -) echo "Operand 1: "
		read a
		echo "Operand 2: "
		read b
		echo "Result: "
		sub $a $b ;; 
	\*) echo "Operand 1: "
		read a
		echo "Operand 2: "
		read b
		echo "Result: "
		mul $a $b ;;
	 /) echo "Operand 1: "
		read a
		echo "Operand 2: "
		read b
		echo "Result: "
		div $a $b ;;
	 !) echo "Operand 1: "
		read a
		echo "Result: "
		fact $a ;;
	 ^) echo "Operand 1: "
		read a
		echo "Result: "
		pow $a;;
   pow)	echo "Operand 1: "
		read a
		echo "Operand 2: "
		read b
		echo "Result is: "
		pow1 $a $b ;;
	 *) echo "Invalid operation"	
esac 
