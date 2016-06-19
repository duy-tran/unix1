#!/usr/local/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
#echo -e "\e[96mList of images in $1"
declare -A number
declare -A array
for var in `find "$1" -name "$2" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'`
do
	fileName=$(basename "$var")
	if [ -z "${number[$fileName]}" ]
	then
		number[$fileName]=1		
	else
		number[$fileName]=$((${number[$fileName]}+1))
	fi
done
for var in `find "$1" -name "$2" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'`
do
	conflict=0
	if [[ ${number[$(basename "$var")]} -gt 1 ]]
	then
		conflict=1
	fi
    fileSize=$(stat -f "%z" "$var")
    fileSize=$((fileSize/1024)) # <= in KB
    fileDate=$(stat -f "%SB" "$var")
    echo $fileSize\;$fileDate\;$var\;$conflict\;
done

exit 0
IFS=$SAVEIFS
