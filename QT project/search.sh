#!/usr/local/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
#echo -e "\e[96mList of images in $1"
declare -A number
i=0
for var in `find "$1" -name "$2" -type f -exec file {} \; | awk -F: '{if ($2 ~/.*kbps.*kHz.*/) print $1}'`
do
	fileName=$(basename "$var")
	if [ -z "${number[$fileName]}" ]
	then
		number[$fileName]=1		
	else
		number[$fileName]=$((${number[$fileName]}+1))
	fi
        array[i]=$var
        i=$((i+1))
done

for ((j=0;j<i;j++))
do
	var=${array[j]}
	conflict=0
	if [[ ${number[$(basename "$var")]} -gt 1 ]]
	then
		conflict=1
	fi
    fileSize=$(stat -f "%z" "$var")
    fileSize=$((fileSize/1024)) # <= in KB
    fileDate=$(stat -f "%SB" "$var")
    echo $fileSize\;$fileDate\;$var\;$conflict\;$(basename "$var")\;
done

exit 0
IFS=$SAVEIFS
