#!/bin/bash

while true 
do
     if ! [[ -e file.lock ]]
     then
        ln file file.lock
        break
     fi
done

resq=Hello
while read number
do
 res=$((number + 1))
done < "file"

echo $res >> file
rm file.lock
