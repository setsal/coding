#!/bin/sh

for file in * ; do 
	#echo $file | sed 's/\://g';
	#echo $file | sed 's/\?//g';
	mv -v "$file" "$(echo $file | sed 's/\://g')" ; 
	mv -v "$file" "$(echo $file | sed 's/\?//g')" ; 
done

