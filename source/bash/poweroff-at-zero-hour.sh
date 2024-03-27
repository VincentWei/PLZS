#!/bin/bash

while :
do
    hour=`date '+%H'`
    if [ $hour -eq 0 ]
    then
        poweroff
    else
        sleep 1
    fi
done
