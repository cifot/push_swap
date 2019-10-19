#!/bin/sh

echo "-Wall -Werror -Wextra\n"
ls -l|grep '^d'| awk '{print $9}' | while read dirs
do
echo $dirs
ls -l $dirs |grep '^-'| awk '{print $9}'| grep 'c$' | while read files
do
echo $files
done
echo "\n"
done
