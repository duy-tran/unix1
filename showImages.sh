#!/bin/bash
find "$1" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'
for var in `find "$1" -type f -exec file {} \; | awk -F: '{if ($2 ~/image/) print $1}'`
do
	exit 0
done
exit -1