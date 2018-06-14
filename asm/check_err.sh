#!/bin/bash

LOCATION=../test_files/err_files/*.s
FILECOUNT=0
DIRCOUNT=0



if [ "$#" -lt "1" ]
then
    echo "Usage: ./test2.sh <directory>"
    exit 0
fi

#echo "The said files: " $LOCATION
for item in $LOCATION
do
if [ -f "$item" ]
then
	FILECOUNT=$[$FILECOUNT+1]
elif [ -d "$item" ]
then
 	DIRCOUNT=$[$DIRCOUNT+1]
fi
done

echo "File count: " $FILECOUNT
echo "Directory count: " $DIRCOUNT

for item in $LOCATION
do
if [ -e asm ]
then
	./asm $item
else
	make
fi
done

for item in $LOCATION
do
if [ -e asm ]
then
	../vm_champs/./asm $item
else
	make
fi
done

rm -f *.cor

echo "If no segfault be HAPPY : \x1B[32m\x1B[1m[SUCCESS]\x1B[0m "
