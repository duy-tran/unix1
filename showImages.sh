#!/usr/local/bin/bash
result=-1
declare -A number
#find "$1" -name "$2" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'
for var in `find "$1" -name "$2" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'`
do
	fileName=$(basename "$var")
	if [ -z "${number[$fileName]}" ]
	then
		number[$fileName]=1		
	else
		number[$fileName]=$((${number[$fileName]}+1))
	fi
	result=0
done
if [[ "$result" -eq -1 ]]
then	
	exit -1
fi

echo -e "\e[96mList of images in $1"
for var in `find "$1" -name "$2" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'`
do
	if [[ ${number[$(basename "$var")]} -gt 1 ]]
	then
		echo -e "\e[7;95m$var\e[0m"
	else
		echo $var
	fi
done

exit 0
