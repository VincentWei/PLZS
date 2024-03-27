#!/bin/bash

if [ $# -ne 2 ]
then
    echo 'Usage: change-postfix.sh org dst'
    exit 1
fi

for file in *.$1; do
    mv -- "$file" "${file%.$1}.$2"
done
