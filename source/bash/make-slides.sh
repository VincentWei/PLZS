#!/bin/bash

file=titles.txt

IFS=':'
while read -ra LINE; do
    html_file="${LINE[0]}.html"
    if [ -f $html_file ]
    then
        echo "Skip $html_file"
    else
        cp template.html $html_file
        sed -i '' -e "s/TITLE/${LINE[1]}/g" $html_file
        sed -i '' -e "s/FILENAME/${LINE[0]}/g" $html_file
    fi

    md_file="${LINE[0]}.md"
    if [ -f $md_file ]
    then
        echo "Skip $md_file"
    else
        echo "# ${LINE[1]}" > $md_file
    fi
done < "$file"
