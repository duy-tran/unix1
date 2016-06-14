#!/usr/local/bin/bash
#echo -e "\e[96mList of images in $1"
for var in `find "$1" -name "$2" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'`
do
	fileSize=$(stat -f "%z" "$var")
	fileSize=$((fileSize/1024))
	fileDate=$(stat -f "%SB" "$var")
	echo $var "$fileSize"KB $fileDate
done

exit 0