#! /bin/bash

select item in "Create" "Rename" "Delete" "Copy"
do
	case $item in
		Create) 	echo "Filename:" 
				read a
				touch $a ;;
				
		Rename) 	echo "Old file:" 
				read a
				echo "New file:" 
				read b
				mv $a $b ;;
				
		Delete)		echo "Filename:" 
				read a
				rm $a ;;
				
		Copy)   	echo "Old file:" 
				read a
				echo "New file:" 
				read b 
				cp $a $b ;;
				
		*)	   	echo "Invalid option" ;;
	esac
done

