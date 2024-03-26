#!/bin/bash

# Hello, world!
echo Hello, world!
echo - $USER@$HOSTNAME

FULLNAME='WEI Yongming'
echo - $FULLNAME@$HOSTNAME

for f in *.sh
do
    echo $f
done
