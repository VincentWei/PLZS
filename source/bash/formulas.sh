#!/bin/bash

area_of_square() {
    let "area = $1 * $1"
    return $area
}

area_of_circle() {
    let "area = 3 * $1 * $1"
    return $area
}

clear
OPTIONS="Square Circle Quit"
echo "To calculate the area of a surface, please select one shape:"
select opt in $OPTIONS; do
    if [ "$opt" = "Quit" ]; then
        echo done
        exit 0
    elif [ "$opt" = "Square" ]; then
        echo Please input the lenght of a side of the square:
        read D
        area_of_square $D
        S=$?
        echo "area of the suare($D): "$S
        echo `date` ": $USER call area_of_square($D): $S" >> formulas.log
    elif [ "$opt" = "Circle" ]; then
        echo Please input the lenght of the radius of the circle:
        read R
        area_of_circle $R
        S=$?
        echo "area of the circle($R): "$S
        echo `date` ": $USER call area_of_circle($R): $S" >> formulas.log
    else
        echo Bad option
    fi
done

exit 0

