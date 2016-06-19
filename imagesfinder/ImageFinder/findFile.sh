#!/usr/local/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
shopt -s nocasematch
#echo -e "\e[96mList of images in $1"
declare -A number
i=0
for var in `find "$1" -name "*.mp3" -o -name "*.wav" -o -name "*.flac" -o -name "*.m4a"`
do
	if [[ "$var" =~ ^.*$2.*$ ]]
	then
	fileName=$(basename "$var")
	  if [ -z "${number[$fileName]}" ]
	  then
		  number[$fileName]=1		
	  else
		  number[$fileName]=$((${number[$fileName]}+1))
	  fi
        array[i]=$var
        i=$((i+1))
   	fi
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
    fileDateLong=$(stat -f "%B" "$var")
    echo $fileSize\;$fileDate\;$var\;$conflict\;$(basename "$var")\;$fileDateLong\;
done

exit 0
IFS=$SAVEIFS