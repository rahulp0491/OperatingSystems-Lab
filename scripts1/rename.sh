#! /bin/bash
# rename multiple files

cd $1
rename 's/\.txt$/.doc/' *.txt
