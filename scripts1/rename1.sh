#! /bin/bash
# rename .txt files to .doc

for s in `ls $1 | grep "\.txt$"`
do
	l=`echo $s | wc -c`
	l=`expr $l - 5`
	i=1
	name=""
	while [ $i -le $l ]
	do
		c=`echo $s | cut -c$i`
		name="$name$c"
		i=`expr $i + 1`
	done
	mv $1/$name.txt $1/$name.doc
done


