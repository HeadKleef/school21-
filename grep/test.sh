#!/bin/bash

flags=(
    "-e"
    "-i"
    "-v"
    "-c"
    "-l"
    "-n"
    
)

patterns=(
    "1"
    "in"
    "-"
    "Word"
    "AND"
)

for i in "${flags[@]}"
    do
        for n in "${patterns}"
           do
            ./s21_grep $i  $n test_1.txt > test_2.txt
            grep $i $n test_1.txt > test_3.txt
            file_1=test_2.txt
            file_2=test_3.txt

        if  diff -w  test_2.txt test_3.txt  ;
        then 
            echo "flag :$i result :The files same " 
        else
             echo "flag :$i result :The files different"  
        fi
        done
done



