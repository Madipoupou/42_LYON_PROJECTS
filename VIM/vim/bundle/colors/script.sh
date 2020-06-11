#!/bin/sh

DIR=$( ls -l | rev | cut -f2 -d'.' | cut -f1 -d' ' | rev )
for name in $DIR
do
	mkdir $name
	mkdir $name/colors
	mv "$name.vim" $name/colors/
	echo OK
done
echo "END OF SCRIPT"
